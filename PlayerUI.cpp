#include "PlayerUI.h"
#include "ui_player.h"
#include "mainwindow.h"
#include "PreDef.h"

PlayerUI::PlayerUI(MainWindow *wnd) :
	m_ui(new Ui::PlayerUI)
	, m_mainWnd(wnd)
	, m_threadMapStatus(this)
	, m_threadMapRecognize(this)
	, m_threadMapPosSelect(this)
	, m_threadNextStep(this)
	, m_bRunThreadFlag(true)
	, m_bPauseMapStatusFlag(true)
	, m_bPauseMapRecognizeFlag(true)
	, m_bPauseMapPosSelectFlag(true)
	, m_bPauseNextStepFlag(true)

	, m_specificLevelScriptMap({
		{Nefud_1E, QString(DEFAULT_PATH).append("zz_map_nefud-1e")},
		{Hecate_1E, QString(DEFAULT_PATH).append("zz_map_hecate-1e")},
		{WOLT_50, QString(DEFAULT_PATH).append("zz_map_fb_wolt50")},
		{WOLT_60, QString(DEFAULT_PATH).append("zz_map_fb_wolt60")},
		{Evelyn_50, QString(DEFAULT_PATH).append("zz_map_fb_evelyn_50")},
		{Evelyn_60, QString(DEFAULT_PATH).append("zz_map_fb_evelyn_60")},
		})

	, m_specificDelegateScriptMap({
		{Slowest, QString(DEFAULT_PATH).append("delegate_slowest")},
		})

	, m_specificDevScriptMap({
		{Limit, QString(DEFAULT_PATH).append("dev_limit")},
		{Normal10, QString(DEFAULT_PATH).append("dev_normal_10")},
		{Normal20, QString(DEFAULT_PATH).append("dev_normal_20")},
		})
	, m_mapStatusCmpParam(-1)
	, m_mapStatusOutputParam(0)
	, m_lastStatusParam(-1)
	, m_bInBattleFlag(false)
	, m_bInitFlag(false)
	, m_bToBattleMainFlag(false)
	, m_bToBattleRewardFlag( false )
	, m_bToBattleDailyFlag(false)
	, m_bToDev20(false)
	, m_bToBattleEmergencyFlag(false)
{
	m_ui->setupUi(this);
}

PlayerUI::~PlayerUI()
{
	delete m_ui;

	m_bRunThreadFlag = false;
	m_bPauseMapStatusFlag = true;
	m_threadMapStatus.quit();
	m_threadMapStatus.wait();

	m_threadMapRecognize.quit();
	m_threadMapRecognize.wait();

	m_threadMapPosSelect.quit();
	m_threadMapPosSelect.wait();

	m_threadNextStep.quit();
	m_threadNextStep.wait();
}

void PlayerUI::Init()
{
	if ( m_bInitFlag )
	{
		return;
	}

	connect( &m_threadMapStatus, &ThreadMapStatus::resultReady, this, &PlayerUI::handleResults );
	connect( &m_threadMapStatus, &ThreadMapStatus::finished, &m_threadMapStatus, &QObject::deleteLater );
	m_threadMapStatus.start();

	connect( &m_threadMapRecognize, &ThreadMapRecognize::resultReady, this, &PlayerUI::handleResults );
	connect( &m_threadMapRecognize, &ThreadMapRecognize::finished, &m_threadMapRecognize, &QObject::deleteLater );
	m_threadMapRecognize.start();

	connect( &m_threadMapPosSelect, &ThreadMapPosSelect::resultReady, this, &PlayerUI::handleResults );
	connect( &m_threadMapPosSelect, &ThreadMapPosSelect::finished, &m_threadMapPosSelect, &QObject::deleteLater );
	m_threadMapPosSelect.start();

	connect( &m_threadNextStep, &ThreadNextStep::resultReady, this, &PlayerUI::handleResults );
	connect( &m_threadNextStep, &ThreadNextStep::finished, &m_threadNextStep, &QObject::deleteLater );
	m_threadNextStep.start();

	m_bInitFlag = true;
}

void PlayerUI::UpdateAllScript()
{
// 	DWORD time = GetTickCount();
	UpdateMapStatusRecognizeScript();
	UpdateMapPositionSelectScript();
	UpdateAllMapRecognizeAndBattleScript();
	UpdateNextStepScript();
// 	m_mainWnd->AddTipInfo(std::string("整个更新耗时：").append(std::to_string(GetTickCount() - time)).c_str());
}

void PlayerUI::UpdateMapStatusRecognizeScript()
{
	UpdateMapStatusInputDataVector(m_mapStatusCmpParam);

	//根据状态开始和关闭对应的timer执行脚本，提高效率，减少错误点击
	if ( !NotInBattleFlag() )
	{
		if (!m_bInBattleFlag)
		{
			m_bInBattleFlag = true;

			//因为战斗脚本完成后，现在都会停止，不会跳转回地图查找，这样处理比较简单，否则还涉及到跳转回地图查找后又进入战斗脚本的问题，具体游戏这边的脚本更新都有所改动，停止脚本不再停止timer，而是把inputVec清空，所以当我们需要再次开启地图识别的时候，我们需要先加载识别文件（因为这时候vec是空）
			m_mainWnd->LoadScriptModuleFileToSpecificInputVec(std::string(DEFAULT_PATH).append("zz_map_recognize").c_str(), m_mapRecognizeInputVec);
			m_mainWnd->AddTipInfo( "已进入战斗场景--------" );

			//只要进入了战斗场景则重置所有战斗外的地图选择标记
			ResetPosSelectFlags();

			//战斗场景中，暂停跳转地图，开启识别地图，降低cpu消耗
			m_bPauseMapPosSelectFlag = true;
			m_bPauseMapRecognizeFlag = false;
		}

	}
	else if (NotInBattleFlag())
	{
		if (m_bInBattleFlag)
		{
			m_bInBattleFlag = false;

			m_mainWnd->AddTipInfo("已从战斗场景退出--------");

			//战斗场景中，开启跳转地图，暂停识别地图，降低cpu消耗
			m_bPauseMapPosSelectFlag = false;
			m_bPauseMapRecognizeFlag = true;
		}
	}
}

void PlayerUI::UpdateNextStepScript()
{
	if (m_nextStepInputVec.size())
	{
		UpdateNormalInputDataVector(-1, m_nextStepInputVec);
	}
}

void PlayerUI::UpdateMapPositionSelectScript()
{
	//根据游戏状态，动态加载切换各个脚本

	//情景发生变化时，才替换一次脚本
	if (m_lastStatusParam != m_mapStatusOutputParam)
	{
		m_lastStatusParam = m_mapStatusOutputParam;

		//if从上到下优先级依次递减，赏金最低，也就是其他操作都执行完毕后再执行赏金--------------------------

		if ( m_ui->chk_dev->isChecked() 
			&& m_devSetting.bShouldExecFlag
			&& !m_bInBattleFlag )//开发----
		{
			if ( ZZ_Map_Param::Battle_Main == m_mapStatusOutputParam )
			{
				GotoDev20();
			}
			else if ( NotInBattleFlag()
				&& m_mapStatusOutputParam != ZZ_Map_Param::Battle_Main
				&& !m_bToDev20)
			{
				GotoBattleMain();
			}
			else if ( ZZ_Map_Param::Dev_ing == m_mapStatusOutputParam )
			{
				m_devSetting.Reset();
				ResetPosSelectFlags();
			}
		}
		else if ( m_ui->chk_emergency->isChecked()//紧急任务----
			&& m_emergencySetting.bShouldExecFlag
			&& !m_bInBattleFlag )
		{
			if ( ZZ_Map_Param::Battle_Main == m_mapStatusOutputParam )
			{
				GotoEmergency();
				m_emergencySetting.Reset();
			}
			else if ( NotInBattleFlag()
				&& m_mapStatusOutputParam != ZZ_Map_Param::Battle_Main
				&& !m_bToBattleEmergencyFlag )
			{
				GotoBattleMain();
			}
		}
		else if ( m_ui->chk_daily->isChecked() )//每日任务----
		{
			if ( ZZ_Map_Param::Battle_Main == m_mapStatusOutputParam )
			{
				GotoDailyFirstIcon();
			}
			else if ( NotInBattleFlag()
				&& m_mapStatusOutputParam != ZZ_Map_Param::Battle_Main
				&& !m_bToBattleDailyFlag)
			{
				GotoBattleMain();
			}
		}
		//赏金（优先级低，先进行开发招募等需求）
		else if (m_ui->chk_reward->isChecked())//赏金任务----
		{
			if (ZZ_Map_Param::Battle_Main == m_mapStatusOutputParam
				&& !m_bToBattleRewardFlag)
			{
				GotoRewardFirstIcon();
			}
			else if (NotInBattleFlag()
				&& m_mapStatusOutputParam != ZZ_Map_Param::Battle_Main )
			{
				GotoBattleMain();
			}
			else
			{
				if (0 != m_lastStatusParam)
				{
					m_mainWnd->AddTipInfo(std::string("当前界面无法跳转执行赏金任务_").append(std::to_string(m_lastStatusParam)).c_str());
				}
			}
		}
	}

	if (m_mapPosSelectInputVec.size())
	{
		UpdateNormalInputDataVector(-1, m_mapPosSelectInputVec);
	}
}

void PlayerUI::UpdateAllMapRecognizeAndBattleScript()
{
	if (m_mapRecognizeInputVec.size())
	{
		//这里的参数根据用户的勾选变换，目前暂时为-1
		UpdateNormalInputDataVector(-1, m_mapRecognizeInputVec);
	}
}

void PlayerUI::handleResults(const QString &)
{

}

void PlayerUI::UpdateMapStatusInputDataVector(int cmpParam)
{
	if (m_mapStatusInputVec.size() == 0)
	{
		m_mainWnd->AddTipInfo("脚本中命令数为0，线程退出...");
		return;
	}

	//获取最新的游戏窗口大小，通过比例来进行鼠标点击，可以保证窗口任意大小都能点击正确
	m_mainWnd->UpdateGameWindowSize();

	bool bAllFinishedFlag = true;
	int index = -1;
	for (auto &input : m_mapStatusInputVec)
	{
		++index;
		//判断操作已经完成
		if ((input.bFinishFlag && input.type != Pic)
			|| (input.type == Pic && (input.bFindPicFlag || input.bFindPicOvertimeFlag))
			|| (-1 != cmpParam && input.cmpParam != cmpParam))
		{
			continue;
		}

		//初始化输入开始时间
		if (!input.bInitStartTimeFlag)
		{
			input.bInitStartTimeFlag = true;
			input.startTime = GetTickCount();
		}

		bAllFinishedFlag = false;

		//判断延迟
		DWORD dwTime = GetTickCount() - input.startTime;
		if (GetTickCount() - input.startTime < (DWORD)input.delay)
			break;

		//等待类型的话，则继续判断是否已到时间
		if (input.type == Wait && GetTickCount() - input.startTime < (DWORD)(input.waitTime * 1000))
			break;

		switch (input.type)
		{
		case Mouse:
			m_mainWnd->HandleMouseInput(input);
			break;
		case Keyboard:
			m_mainWnd->HandleKeyboardInput(input);
			break;
		case Pic:
			m_mainWnd->HandleGameImgCompare(input);
			break;
		case StopScript:
		{
			m_mainWnd->AddTipInfo("脚本已运行完毕，请手动选择其他脚本执行");
		}
		break;
		case Log:
		{
			m_mainWnd->AddTipInfo(input.comment);
		}
		break;
		default:
			break;
		}

		//查询图片是否超时---放在执行之后，这样保证至少先执行一次对比才会超时
		dwTime = GetTickCount() - input.startTime;
		if ( input.findPicOvertime != -1
			&& InputType::Pic == input.type
			&& ( GetTickCount() - input.startTime > ( DWORD )( input.findPicOvertime + input.delay ) )
			&& !input.bFindPicFlag )
		{
// 			m_mainWnd->AddTipInfo(std::string("cost time:").append(std::to_string(dwTime)).c_str());
			input.bFindPicOvertimeFlag = true;
			//判断超时指令跳转
			if (-1 != input.findPicOvertimeJumpIndex)
			{
				(0xffff != input.findPicOvertimeJumpIndex) ? m_mainWnd->JumpInput(input.findPicOvertimeJumpIndex, m_mapStatusInputVec) :
					(m_mainWnd->LoadScriptModuleFileToSpecificInputVec(input.findPicOvertimeJumpModule, m_mapStatusInputVec));
				break;
			}
			continue;
		}

		//如果没有找到图片就跳过，继续处理这一项
		if (InputType::Pic == input.type && !input.bFindPicFlag)
		{
			break;
		}
		//图片对比成功指令跳转
		else if (InputType::Pic == input.type && input.bFindPicFlag && -1 != input.findPicSucceedJumpIndex)
		{
			m_mapStatusOutputParam = input.outputParam;

			(0xffff != input.findPicSucceedJumpIndex) ? m_mainWnd->JumpInput(input.findPicSucceedJumpIndex, m_mapStatusInputVec) :
				m_mainWnd->LoadScriptModuleFileToSpecificInputVec(input.findPicSucceedJumpModule, m_mapStatusInputVec);
			break;
		}
		else if (InputType::Pic == input.type && input.bFindPicFlag)
		{
			m_mapStatusOutputParam = input.outputParam;
		}

		//处理完后，如果已重复次数等于需要重复的次数，就标记为处理完毕（目前重复次数不对图片对比流程生效）
		input.alreadyRepeatCount += 1;
		if (input.alreadyRepeatCount >= input.repeatCount)
		{
			input.bFinishFlag = true;
		}
		else
		{
			//没有达到重复次数时，重置开始时间，并判断是否跳转后，break继续判断延迟
			input.startTime = GetTickCount();
			//这里借用了找图成功跳转索引的变量，因为找图我们都不会使用多次，我也就不想再多加结构体变量了，目前的多次重复命令都用于延迟上
			if (-1 != input.findPicSucceedJumpIndex && 0xffff != input.findPicSucceedJumpIndex)
			{
				m_mainWnd->JumpInput(input.findPicSucceedJumpIndex, m_mapStatusInputVec);
			}
			break;
		}
	}

	if (bAllFinishedFlag)
	{
		m_mainWnd->ResetAllInputFinishFlag(m_mapStatusInputVec);
	}
}

void PlayerUI::UpdateNormalInputDataVector(int cmpParam, std::vector<InputData> &inputVec)
{
	if (inputVec.size() == 0)
	{
		m_mainWnd->AddTipInfo("脚本中命令数为0，线程退出...");
		return;
	}

	//获取最新的游戏窗口大小，通过比例来进行鼠标点击，可以保证窗口任意大小都能点击正确
	m_mainWnd->UpdateGameWindowSize();

	bool bAllFinishedFlag = true;
	int index = -1;
	for (auto &input : inputVec)
	{
		++index;
		//判断操作已经完成
		if ((input.bFinishFlag && input.type != Pic)
			|| (input.type == Pic && (input.bFindPicFlag || input.bFindPicOvertimeFlag))
			|| (-1 != cmpParam && input.cmpParam != cmpParam))
			continue;

		//初始化输入开始时间
		if (!input.bInitStartTimeFlag)
		{
			input.bInitStartTimeFlag = true;
			input.startTime = GetTickCount();
		}

		bAllFinishedFlag = false;

		//判断延迟
		if (GetTickCount() - input.startTime < (DWORD)input.delay)
			break;

		//等待类型的话，则继续判断是否已到时间
		if (input.type == Wait && GetTickCount() - input.startTime < (DWORD)(input.waitTime * 1000))
			break;

		switch (input.type)
		{
		case Mouse:
			m_mainWnd->HandleMouseInput(input);
			break;
		case Keyboard:
			m_mainWnd->HandleKeyboardInput(input);
			break;
		case Pic:
			m_mainWnd->HandleGameImgCompare(input);
			break;
		case StopScript:
		{
			inputVec.clear();
			m_mainWnd->AddTipInfo("脚本已运行完毕，请手动选择其他脚本执行");
			return;
		}
		break;
		case Log:
		{
			m_mainWnd->AddTipInfo(input.comment);
		}
		break;
		case Jump:
		{
			if (0xffff == input.findPicSucceedJumpIndex)
			{
				m_mainWnd->LoadScriptModuleFileToSpecificInputVec(input.findPicSucceedJumpModule, inputVec);
				break;
			}
			else
			{
				if (-1 != input.findPicSucceedJumpIndex)
				{
					m_mainWnd->JumpInput(input.findPicSucceedJumpIndex, inputVec);
				}
			}
		}
		break;
		default:
			break;
		}

		//查询图片是否超时---放在执行之后，这样保证至少先执行一次对比才会超时
		if ( input.findPicOvertime != -1
			&& InputType::Pic == input.type
			&& ( GetTickCount() - input.startTime > ( DWORD )( input.findPicOvertime + input.delay ) )
			&& !input.bFindPicFlag )
		{
			input.bFindPicOvertimeFlag = true;
			//判断超时指令跳转
			if (-1 != input.findPicOvertimeJumpIndex)
			{
				(0xffff != input.findPicOvertimeJumpIndex) ? m_mainWnd->JumpInput(input.findPicOvertimeJumpIndex, inputVec) :
					(m_mainWnd->LoadScriptModuleFileToSpecificInputVec(input.findPicOvertimeJumpModule, inputVec));
				break;
			}
			continue;
		}

		//如果没有找到图片就跳过，继续处理这一项
		if (InputType::Pic == input.type && !input.bFindPicFlag)
		{
			break;
		}
		//图片对比成功指令跳转
		else if (InputType::Pic == input.type && input.bFindPicFlag && -1 != input.findPicSucceedJumpIndex)
		{
			(0xffff != input.findPicSucceedJumpIndex) ? m_mainWnd->JumpInput(input.findPicSucceedJumpIndex, inputVec) :
				m_mainWnd->LoadScriptModuleFileToSpecificInputVec(input.findPicSucceedJumpModule, inputVec);
			break;
		}

		//处理完后，如果已重复次数等于需要重复的次数，就标记为处理完毕（目前重复次数不对图片对比流程生效）
		input.alreadyRepeatCount += 1;
		if (input.alreadyRepeatCount >= input.repeatCount)
		{
			input.bFinishFlag = true;
		}
		else
		{
			//没有达到重复次数时，重置开始时间，并判断是否跳转后，break继续判断延迟
			input.startTime = GetTickCount();
			//这里借用了找图成功跳转索引的变量，因为找图我们都不会使用多次，我也就不想再多加结构体变量了，目前的多次重复命令都用于延迟上
			if (-1 != input.findPicSucceedJumpIndex && 0xffff != input.findPicSucceedJumpIndex)
			{
				m_mainWnd->JumpInput(input.findPicSucceedJumpIndex, inputVec);
			}
			break;
		}
	}

	if (bAllFinishedFlag)
	{
		m_mainWnd->ResetAllInputFinishFlag(inputVec);
	}
}

void PlayerUI::StopScritp()
{
	m_bPauseMapStatusFlag = true;
	m_bPauseMapRecognizeFlag = true;
	m_bPauseMapPosSelectFlag = true;
	m_bPauseNextStepFlag = true;

	m_mapStatusOutputParam = 0;
	m_lastStatusParam = -1;

	m_emergencySetting.Stop();
	m_devSetting.Stop();
	m_delegateSetting.Stop();
	m_recruitSetting.Stop();

	//设置指定的模拟器类型
	int index = m_ui->cmb_sim->currentIndex();
	m_mainWnd->SetSimWndType((SimWndType)index);
	m_mainWnd->AddTipInfo("脚本已停止运行");
}

void PlayerUI::StartScript()
{
	Init();

	//start时重新获取一次挂机设置的延迟
	m_emergencySetting.interval = m_ui->edt_emergencyInterval->text().toInt();
	m_devSetting.interval = m_ui->edt_devInterval->text().toInt();
	m_delegateSetting.interval = m_ui->edt_delegateInterval->text().toInt();
	m_recruitSetting.interval = m_ui->edt_recruitInterval->text().toInt();

	m_emergencySetting.StartAutoHandle();
	m_devSetting.StartAutoHandle();
	m_delegateSetting.StartAutoHandle();
	m_recruitSetting.StartAutoHandle();

	m_mainWnd->LoadScriptModuleFileToSpecificInputVec(std::string(DEFAULT_PATH).append("map_status_recognize").c_str(), m_mapStatusInputVec);
	m_mainWnd->LoadScriptModuleFileToSpecificInputVec(std::string(DEFAULT_PATH).append("next_step").c_str(), m_nextStepInputVec);
	m_mainWnd->LoadScriptModuleFileToSpecificInputVec(std::string(DEFAULT_PATH).append("zz_map_recognize").c_str(), m_mapRecognizeInputVec);

	m_bPauseMapStatusFlag = false;
	m_bPauseMapRecognizeFlag = false;
	m_bPauseMapPosSelectFlag = false;
	m_bPauseNextStepFlag = false;

	ResetPosSelectFlags();
} 

void PlayerUI::ResetPosSelectFlags()
{
	m_bToBattleMainFlag = false;
	m_bToBattleRewardFlag = false;
	m_bToBattleDailyFlag = false;
	m_bToBattleEmergencyFlag = false;
	m_bToDev20 = false;
}

void PlayerUI::GotoBattleMain()
{
	if ( m_bToBattleMainFlag
		|| m_bToBattleRewardFlag
		|| m_bToBattleDailyFlag )
	{
		return;
	}

	m_bToBattleMainFlag = true;
	m_bToBattleRewardFlag = false;
	m_bToBattleDailyFlag = false;
	m_mainWnd->LoadScriptModuleFileToSpecificInputVec( std::string( DEFAULT_PATH ).append( "to_battle_main" ).c_str(), m_mapPosSelectInputVec );
}

void PlayerUI::GotoRewardFirstIcon()
{
	if ( m_bToBattleRewardFlag )
	{
		return;
	}

	ResetPosSelectFlags();
	m_bToBattleRewardFlag = true;

	m_mainWnd->LoadScriptModuleFileToSpecificInputVec( std::string( DEFAULT_PATH ).append( "to_battle_main_reward_firstIcon" ).c_str(), m_mapPosSelectInputVec );
}

void PlayerUI::GotoDailyFirstIcon()
{
	if ( m_bToBattleDailyFlag )
	{
		return;
	}

	ResetPosSelectFlags();
	m_bToBattleDailyFlag = true;

	m_mainWnd->LoadScriptModuleFileToSpecificInputVec( std::string( DEFAULT_PATH ).append( "to_battle_main_daily_firstIcon" ).c_str(), m_mapPosSelectInputVec );
}

void PlayerUI::GotoEmergency()
{
	if ( m_bToBattleEmergencyFlag )
	{
		return;
	}

	ResetPosSelectFlags();
	m_bToBattleEmergencyFlag = true;

	m_mainWnd->LoadScriptModuleFileToSpecificInputVec( std::string( DEFAULT_PATH ).append( "to_battle_main_emergency" ).c_str(), m_mapPosSelectInputVec );
}

void PlayerUI::GotoDev20()
{
	if ( m_bToDev20 )
	{
		return;
	}

	ResetPosSelectFlags();
	m_bToDev20 = true;

	m_mainWnd->LoadScriptModuleFileToSpecificInputVec( std::string( DEFAULT_PATH ).append( "to_dev20" ).c_str(), m_mapPosSelectInputVec );
}

void PlayerUI::OnBtnStop()
{
	StopScritp();
}

void PlayerUI::OnBtnStartAuto()
{
	StopScritp();
	StartScript();
}


void PlayerUI::OnBtnToggleBattleOptions()
{
	m_ui->chk_emergency->toggle();
	m_ui->chk_daily->toggle();
	m_ui->chk_reward->toggle();
}

void PlayerUI::OnBtnToggleNoneBattleOptions()
{
	m_ui->chk_delegate->toggle();
	m_ui->chk_dev->toggle();
	m_ui->chk_recruit->toggle();
}

void PlayerUI::OnBtnHuodong1()
{
	Init();
	m_mainWnd->LoadScriptModuleFileToSpecificInputVec(std::string(DEFAULT_PATH).append("huodong_t_1_5").c_str(), m_nextStepInputVec);

	m_bPauseNextStepFlag = false;

	ResetPosSelectFlags();
}

void ThreadMapStatus::run()
{
	QString result;
	/* ... here is the expensive or blocking operation ... */
	while (m_parent->GetRunThreadFlag())
	{
		while (!m_parent->GetPauseMapStatusFlag())
		{
			m_parent->UpdateMapStatusRecognizeScript();
// 			m_parent->UpdateAllScript();
			msleep( 100 );
		}

		msleep( 1000 );
	}

	emit resultReady(result);
}

void ThreadMapRecognize::run()
{
	QString result;
	/* ... here is the expensive or blocking operation ... */
	while ( m_parent->GetRunThreadFlag() )
	{
		while (!m_parent->GetPauseMapRecognizeFlag())
		{
			m_parent->UpdateAllMapRecognizeAndBattleScript();
			msleep( 1 );
		}

		msleep( 1000 );
	}

	emit resultReady( result );
}

void ThreadNextStep::run()
{
	QString result;
	/* ... here is the expensive or blocking operation ... */
	while ( m_parent->GetRunThreadFlag() )
	{
		while (!m_parent->GetPauseNextStepFlag())
		{
			m_parent->UpdateNextStepScript();
			msleep( 100 );
		}

		msleep( 1000 );
	}

	emit resultReady( result );
}

void ThreadMapPosSelect::run()
{
	QString result;
	/* ... here is the expensive or blocking operation ... */
	while ( m_parent->GetRunThreadFlag() )
	{
		while (!m_parent->GetPauseMapPosSelectFlag())
		{
			m_parent->UpdateMapPositionSelectScript();

			msleep( 50 );
		}

		msleep( 1000 );
	}

	emit resultReady( result );
}
