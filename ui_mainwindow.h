/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QListWidget *list_tip;
    QLabel *label;
    QLineEdit *edt_wndName;
    QLabel *label_2;
    QLineEdit *edt_wndName2;
    QComboBox *cb_inputType;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *cb_opType;
    QLabel *label_5;
    QLineEdit *edt_vk;
    QPushButton *btn_addInput;
    QLabel *label_6;
    QLineEdit *edt_delay;
    QLabel *label_7;
    QLineEdit *edt_x;
    QLabel *label_8;
    QLineEdit *edt_y;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *edt_x2;
    QLineEdit *edt_y2;
    QLabel *label_11;
    QLineEdit *edt_repeat;
    QPushButton *btn_save;
    QLineEdit *edt_saveName;
    QLabel *label_12;
    QLabel *label_14;
    QLineEdit *edt_picPath;
    QLabel *label_15;
    QLineEdit *edt_rate;
    QLabel *label_16;
    QLineEdit *edt_cmpPic;
    QLabel *label_17;
    QLineEdit *edt_findPicOvertime;
    QLabel *label_18;
    QLineEdit *edt_succeedJump;
    QLabel *label_19;
    QLineEdit *edt_overtimeJump;
    QLabel *label_20;
    QLineEdit *edt_costTime;
    QLabel *label_21;
    QLineEdit *edt_insertIndex;
    QPushButton *btn_insertInput;
    QPushButton *btn_delAllInput_2;
    QLabel *label_22;
    QLineEdit *edt_overtimeJumpModule;
    QLabel *label_23;
    QLineEdit *edt_succeedJumpModule;
    QCheckBox *chk_cmpPicClick;
    QPushButton *btn_openFileDialog;
    QPushButton *btn_openFileDialog_picPath;
    QLabel *label_24;
    QLineEdit *edt_comment;
    QPushButton *btn_updateAllInput;
    QLabel *label_25;
    QLabel *label_26;
    QLineEdit *edt_wndWidth;
    QLineEdit *edt_wndHeight;
    QPushButton *btn_lisence;
    QLineEdit *edt_month;
    QLabel *label_29;
    QPushButton *btn_lisenceInfo;
    QLabel *label_30;
    QLineEdit *edt_mac;
    QTableView *tv_inputVec;
    QLabel *label_13;
    QLineEdit *edt_outputParam;
    QLabel *label_27;
    QLineEdit *edt_cmpParam;
    QComboBox *cb_resolutionRate;
    QPushButton *btn_getBattleTemplate;
    QPushButton *btn_startTimeCount;
    QPushButton *btn_endTimeCount;
    QLineEdit *edt_timeCount;
    QLabel *label_31;
    QLabel *label_32;
    QPushButton *btn_getBattleTemplate_2;
    QPushButton *btn_openMapTemplate;
    QLabel *label_28;
    QLineEdit *edt_search;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(932, 756);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_start = new QPushButton(centralWidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(840, 720, 81, 28));
        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(750, 720, 81, 28));
        list_tip = new QListWidget(centralWidget);
        list_tip->setObjectName(QString::fromUtf8("list_tip"));
        list_tip->setGeometry(QRect(10, 160, 331, 141));
        list_tip->setAutoScroll(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 72, 21));
        edt_wndName = new QLineEdit(centralWidget);
        edt_wndName->setObjectName(QString::fromUtf8("edt_wndName"));
        edt_wndName->setGeometry(QRect(90, 10, 211, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 61, 21));
        edt_wndName2 = new QLineEdit(centralWidget);
        edt_wndName2->setObjectName(QString::fromUtf8("edt_wndName2"));
        edt_wndName2->setGeometry(QRect(90, 40, 211, 21));
        cb_inputType = new QComboBox(centralWidget);
        cb_inputType->addItem(QString());
        cb_inputType->addItem(QString());
        cb_inputType->addItem(QString());
        cb_inputType->addItem(QString());
        cb_inputType->addItem(QString());
        cb_inputType->addItem(QString());
        cb_inputType->addItem(QString());
        cb_inputType->setObjectName(QString::fromUtf8("cb_inputType"));
        cb_inputType->setGeometry(QRect(450, 30, 81, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(450, 10, 61, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(550, 10, 61, 21));
        cb_opType = new QComboBox(centralWidget);
        cb_opType->addItem(QString());
        cb_opType->addItem(QString());
        cb_opType->addItem(QString());
        cb_opType->addItem(QString());
        cb_opType->addItem(QString());
        cb_opType->setObjectName(QString::fromUtf8("cb_opType"));
        cb_opType->setGeometry(QRect(550, 30, 81, 22));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(650, 10, 61, 21));
        edt_vk = new QLineEdit(centralWidget);
        edt_vk->setObjectName(QString::fromUtf8("edt_vk"));
        edt_vk->setGeometry(QRect(650, 30, 71, 21));
        btn_addInput = new QPushButton(centralWidget);
        btn_addInput->setObjectName(QString::fromUtf8("btn_addInput"));
        btn_addInput->setGeometry(QRect(670, 280, 81, 28));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(740, 10, 51, 21));
        edt_delay = new QLineEdit(centralWidget);
        edt_delay->setObjectName(QString::fromUtf8("edt_delay"));
        edt_delay->setGeometry(QRect(740, 30, 71, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(650, 60, 41, 21));
        edt_x = new QLineEdit(centralWidget);
        edt_x->setObjectName(QString::fromUtf8("edt_x"));
        edt_x->setGeometry(QRect(650, 80, 71, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(740, 60, 41, 21));
        edt_y = new QLineEdit(centralWidget);
        edt_y->setObjectName(QString::fromUtf8("edt_y"));
        edt_y->setGeometry(QRect(740, 80, 71, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(450, 60, 61, 21));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(550, 60, 61, 21));
        edt_x2 = new QLineEdit(centralWidget);
        edt_x2->setObjectName(QString::fromUtf8("edt_x2"));
        edt_x2->setGeometry(QRect(450, 80, 81, 21));
        edt_y2 = new QLineEdit(centralWidget);
        edt_y2->setObjectName(QString::fromUtf8("edt_y2"));
        edt_y2->setGeometry(QRect(550, 80, 81, 21));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(650, 210, 71, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_11->setFont(font);
        edt_repeat = new QLineEdit(centralWidget);
        edt_repeat->setObjectName(QString::fromUtf8("edt_repeat"));
        edt_repeat->setGeometry(QRect(650, 230, 61, 21));
        edt_repeat->setFont(font);
        btn_save = new QPushButton(centralWidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        btn_save->setGeometry(QRect(850, 220, 71, 28));
        edt_saveName = new QLineEdit(centralWidget);
        edt_saveName->setObjectName(QString::fromUtf8("edt_saveName"));
        edt_saveName->setGeometry(QRect(650, 180, 231, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(650, 160, 241, 20));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(650, 110, 61, 21));
        edt_picPath = new QLineEdit(centralWidget);
        edt_picPath->setObjectName(QString::fromUtf8("edt_picPath"));
        edt_picPath->setGeometry(QRect(650, 130, 231, 21));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(350, 210, 81, 21));
        edt_rate = new QLineEdit(centralWidget);
        edt_rate->setObjectName(QString::fromUtf8("edt_rate"));
        edt_rate->setGeometry(QRect(350, 230, 71, 21));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(450, 260, 61, 21));
        edt_cmpPic = new QLineEdit(centralWidget);
        edt_cmpPic->setObjectName(QString::fromUtf8("edt_cmpPic"));
        edt_cmpPic->setGeometry(QRect(450, 280, 71, 21));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(450, 210, 71, 21));
        label_17->setFont(font);
        edt_findPicOvertime = new QLineEdit(centralWidget);
        edt_findPicOvertime->setObjectName(QString::fromUtf8("edt_findPicOvertime"));
        edt_findPicOvertime->setGeometry(QRect(450, 230, 71, 21));
        edt_findPicOvertime->setFont(font);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(350, 110, 101, 21));
        label_18->setFont(font);
        edt_succeedJump = new QLineEdit(centralWidget);
        edt_succeedJump->setObjectName(QString::fromUtf8("edt_succeedJump"));
        edt_succeedJump->setGeometry(QRect(350, 130, 71, 21));
        edt_succeedJump->setFont(font);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(350, 159, 101, 21));
        label_19->setFont(font);
        edt_overtimeJump = new QLineEdit(centralWidget);
        edt_overtimeJump->setObjectName(QString::fromUtf8("edt_overtimeJump"));
        edt_overtimeJump->setGeometry(QRect(350, 180, 71, 20));
        edt_overtimeJump->setFont(font);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(550, 260, 101, 21));
        edt_costTime = new QLineEdit(centralWidget);
        edt_costTime->setObjectName(QString::fromUtf8("edt_costTime"));
        edt_costTime->setGeometry(QRect(550, 280, 101, 21));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(770, 280, 31, 28));
        edt_insertIndex = new QLineEdit(centralWidget);
        edt_insertIndex->setObjectName(QString::fromUtf8("edt_insertIndex"));
        edt_insertIndex->setGeometry(QRect(800, 280, 41, 28));
        btn_insertInput = new QPushButton(centralWidget);
        btn_insertInput->setObjectName(QString::fromUtf8("btn_insertInput"));
        btn_insertInput->setGeometry(QRect(850, 280, 71, 28));
        btn_delAllInput_2 = new QPushButton(centralWidget);
        btn_delAllInput_2->setObjectName(QString::fromUtf8("btn_delAllInput_2"));
        btn_delAllInput_2->setGeometry(QRect(10, 130, 71, 28));
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(450, 110, 91, 21));
        edt_overtimeJumpModule = new QLineEdit(centralWidget);
        edt_overtimeJumpModule->setObjectName(QString::fromUtf8("edt_overtimeJumpModule"));
        edt_overtimeJumpModule->setGeometry(QRect(450, 180, 191, 21));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(450, 160, 91, 21));
        edt_succeedJumpModule = new QLineEdit(centralWidget);
        edt_succeedJumpModule->setObjectName(QString::fromUtf8("edt_succeedJumpModule"));
        edt_succeedJumpModule->setGeometry(QRect(450, 130, 191, 21));
        chk_cmpPicClick = new QCheckBox(centralWidget);
        chk_cmpPicClick->setObjectName(QString::fromUtf8("chk_cmpPicClick"));
        chk_cmpPicClick->setGeometry(QRect(540, 220, 101, 19));
        chk_cmpPicClick->setChecked(true);
        btn_openFileDialog = new QPushButton(centralWidget);
        btn_openFileDialog->setObjectName(QString::fromUtf8("btn_openFileDialog"));
        btn_openFileDialog->setGeometry(QRect(890, 180, 31, 21));
        btn_openFileDialog_picPath = new QPushButton(centralWidget);
        btn_openFileDialog_picPath->setObjectName(QString::fromUtf8("btn_openFileDialog_picPath"));
        btn_openFileDialog_picPath->setGeometry(QRect(890, 130, 31, 21));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 70, 61, 21));
        edt_comment = new QLineEdit(centralWidget);
        edt_comment->setObjectName(QString::fromUtf8("edt_comment"));
        edt_comment->setGeometry(QRect(90, 70, 251, 21));
        btn_updateAllInput = new QPushButton(centralWidget);
        btn_updateAllInput->setObjectName(QString::fromUtf8("btn_updateAllInput"));
        btn_updateAllInput->setGeometry(QRect(640, 720, 101, 28));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(310, 10, 51, 21));
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(310, 40, 51, 21));
        edt_wndWidth = new QLineEdit(centralWidget);
        edt_wndWidth->setObjectName(QString::fromUtf8("edt_wndWidth"));
        edt_wndWidth->setGeometry(QRect(360, 10, 61, 21));
        edt_wndHeight = new QLineEdit(centralWidget);
        edt_wndHeight->setObjectName(QString::fromUtf8("edt_wndHeight"));
        edt_wndHeight->setGeometry(QRect(360, 40, 61, 21));
        btn_lisence = new QPushButton(centralWidget);
        btn_lisence->setObjectName(QString::fromUtf8("btn_lisence"));
        btn_lisence->setGeometry(QRect(100, 130, 71, 23));
        edt_month = new QLineEdit(centralWidget);
        edt_month->setObjectName(QString::fromUtf8("edt_month"));
        edt_month->setGeometry(QRect(20, 100, 31, 21));
        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(50, 100, 31, 21));
        btn_lisenceInfo = new QPushButton(centralWidget);
        btn_lisenceInfo->setObjectName(QString::fromUtf8("btn_lisenceInfo"));
        btn_lisenceInfo->setGeometry(QRect(180, 130, 71, 23));
        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(100, 100, 31, 21));
        edt_mac = new QLineEdit(centralWidget);
        edt_mac->setObjectName(QString::fromUtf8("edt_mac"));
        edt_mac->setGeometry(QRect(130, 100, 141, 21));
        tv_inputVec = new QTableView(centralWidget);
        tv_inputVec->setObjectName(QString::fromUtf8("tv_inputVec"));
        tv_inputVec->setGeometry(QRect(10, 310, 911, 401));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(840, 10, 61, 21));
        edt_outputParam = new QLineEdit(centralWidget);
        edt_outputParam->setObjectName(QString::fromUtf8("edt_outputParam"));
        edt_outputParam->setEnabled(true);
        edt_outputParam->setGeometry(QRect(840, 80, 71, 21));
        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(840, 60, 71, 21));
        edt_cmpParam = new QLineEdit(centralWidget);
        edt_cmpParam->setObjectName(QString::fromUtf8("edt_cmpParam"));
        edt_cmpParam->setGeometry(QRect(840, 30, 71, 21));
        cb_resolutionRate = new QComboBox(centralWidget);
        cb_resolutionRate->addItem(QString());
        cb_resolutionRate->addItem(QString());
        cb_resolutionRate->setObjectName(QString::fromUtf8("cb_resolutionRate"));
        cb_resolutionRate->setGeometry(QRect(360, 70, 61, 22));
        btn_getBattleTemplate = new QPushButton(centralWidget);
        btn_getBattleTemplate->setObjectName(QString::fromUtf8("btn_getBattleTemplate"));
        btn_getBattleTemplate->setGeometry(QRect(10, 720, 81, 28));
        btn_startTimeCount = new QPushButton(centralWidget);
        btn_startTimeCount->setObjectName(QString::fromUtf8("btn_startTimeCount"));
        btn_startTimeCount->setGeometry(QRect(286, 720, 81, 28));
        btn_endTimeCount = new QPushButton(centralWidget);
        btn_endTimeCount->setObjectName(QString::fromUtf8("btn_endTimeCount"));
        btn_endTimeCount->setGeometry(QRect(376, 720, 81, 28));
        edt_timeCount = new QLineEdit(centralWidget);
        edt_timeCount->setObjectName(QString::fromUtf8("edt_timeCount"));
        edt_timeCount->setGeometry(QRect(234, 720, 31, 28));
        label_31 = new QLabel(centralWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(270, 725, 16, 21));
        label_32 = new QLabel(centralWidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(200, 724, 31, 21));
        btn_getBattleTemplate_2 = new QPushButton(centralWidget);
        btn_getBattleTemplate_2->setObjectName(QString::fromUtf8("btn_getBattleTemplate_2"));
        btn_getBattleTemplate_2->setGeometry(QRect(100, 720, 81, 28));
        btn_openMapTemplate = new QPushButton(centralWidget);
        btn_openMapTemplate->setObjectName(QString::fromUtf8("btn_openMapTemplate"));
        btn_openMapTemplate->setGeometry(QRect(760, 220, 81, 28));
        label_28 = new QLabel(centralWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(350, 260, 61, 21));
        edt_search = new QLineEdit(centralWidget);
        edt_search->setObjectName(QString::fromUtf8("edt_search"));
        edt_search->setGeometry(QRect(350, 280, 71, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(btn_start, SIGNAL(clicked()), MainWindow, SLOT(OnBtnStartClick()));
        QObject::connect(btn_stop, SIGNAL(clicked()), MainWindow, SLOT(OnBtnStopClick()));
        QObject::connect(btn_addInput, SIGNAL(clicked()), MainWindow, SLOT(OnBtnAddInput()));
        QObject::connect(btn_save, SIGNAL(clicked()), MainWindow, SLOT(OnBtnSaveClick()));
        QObject::connect(btn_insertInput, SIGNAL(clicked()), MainWindow, SLOT(OnBtnInsertInputClick()));
        QObject::connect(btn_delAllInput_2, SIGNAL(clicked()), MainWindow, SLOT(OnBtnClearTipInfo()));
        QObject::connect(btn_openFileDialog, SIGNAL(clicked()), MainWindow, SLOT(OnBtnOpenFileDialog()));
        QObject::connect(btn_openFileDialog_picPath, SIGNAL(clicked()), MainWindow, SLOT(OnBtnOpenFileDialog_PicPath()));
        QObject::connect(btn_updateAllInput, SIGNAL(clicked()), MainWindow, SLOT(OnBtnUpdateAllInput()));
        QObject::connect(btn_lisence, SIGNAL(clicked()), MainWindow, SLOT(OnBtnLisence()));
        QObject::connect(btn_lisenceInfo, SIGNAL(clicked()), MainWindow, SLOT(OnBtnLisenceInfo()));
        QObject::connect(edt_wndWidth, SIGNAL(returnPressed()), MainWindow, SLOT(OnReturnPressedResolutionRateX()));
        QObject::connect(edt_wndHeight, SIGNAL(returnPressed()), MainWindow, SLOT(OnReturnPressedResolutionRateY()));
        QObject::connect(btn_getBattleTemplate, SIGNAL(clicked()), MainWindow, SLOT(OnBtnGetBattleTemplate()));
        QObject::connect(btn_startTimeCount, SIGNAL(clicked()), MainWindow, SLOT(OnBtnStartTimeCount()));
        QObject::connect(btn_endTimeCount, SIGNAL(clicked()), MainWindow, SLOT(OnBtnEndTimeCount()));
        QObject::connect(btn_getBattleTemplate_2, SIGNAL(clicked()), MainWindow, SLOT(OnBtnGetBattleTemplate2()));
        QObject::connect(btn_openMapTemplate, SIGNAL(clicked()), MainWindow, SLOT(OnBtnOpenMapTemplate()));
        QObject::connect(edt_search, SIGNAL(returnPressed()), MainWindow, SLOT(OnSearchEnterPressed()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\217\221\351\200\201", nullptr));
        btn_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\217\221\351\200\201", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\252\227\345\217\243\345\220\215\347\247\260", nullptr));
        edt_wndName->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\345\255\220\347\252\227\345\217\243\345\220\215", nullptr));
        edt_wndName2->setText(QString());
        cb_inputType->setItemText(0, QApplication::translate("MainWindow", "\351\274\240\346\240\207\350\276\223\345\205\245", nullptr));
        cb_inputType->setItemText(1, QApplication::translate("MainWindow", "\351\224\256\347\233\230\350\276\223\345\205\245", nullptr));
        cb_inputType->setItemText(2, QApplication::translate("MainWindow", "\345\233\276\347\211\207\350\257\206\345\210\253", nullptr));
        cb_inputType->setItemText(3, QApplication::translate("MainWindow", "\345\201\234\346\255\242\350\204\232\346\234\254", nullptr));
        cb_inputType->setItemText(4, QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227", nullptr));
        cb_inputType->setItemText(5, QApplication::translate("MainWindow", "\345\221\275\344\273\244\350\267\263\350\275\254", nullptr));
        cb_inputType->setItemText(6, QApplication::translate("MainWindow", "\347\255\211\345\276\205", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\347\261\273\345\236\213", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\347\261\273\345\236\213", nullptr));
        cb_opType->setItemText(0, QApplication::translate("MainWindow", "\347\202\271\345\207\273", nullptr));
        cb_opType->setItemText(1, QApplication::translate("MainWindow", "\346\214\211\344\275\217", nullptr));
        cb_opType->setItemText(2, QApplication::translate("MainWindow", "\347\247\273\345\212\250", nullptr));
        cb_opType->setItemText(3, QApplication::translate("MainWindow", "\351\207\212\346\224\276", nullptr));
        cb_opType->setItemText(4, QApplication::translate("MainWindow", "\346\273\232\350\275\256", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "\350\231\232\346\213\237\346\214\211\351\224\256\345\200\274", nullptr));
        edt_vk->setText(QApplication::translate("MainWindow", "G", nullptr));
        btn_addInput->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\276\223\345\205\245", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\345\273\266\350\277\237ms", nullptr));
        edt_delay->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\351\274\240\346\240\207X", nullptr));
        edt_x->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\351\274\240\346\240\207Y", nullptr));
        edt_y->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\351\274\240\346\240\207X_2", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\351\274\240\346\240\207Y_2", nullptr));
        edt_x2->setText(QApplication::translate("MainWindow", "1", nullptr));
        edt_y2->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\351\207\215\345\244\215\346\254\241\346\225\260", nullptr));
        edt_repeat->setText(QApplication::translate("MainWindow", "1", nullptr));
        btn_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        edt_saveName->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\344\275\215\347\275\256\357\274\232\351\273\230\350\256\244\344\277\235\345\255\230\345\234\250D:/QtSave\344\270\213", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\350\267\257\345\276\204", nullptr));
        edt_picPath->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\347\233\270\344\274\274\345\272\246", nullptr));
        edt_rate->setText(QString());
        label_16->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\214\207\344\273\244", nullptr));
        edt_cmpPic->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\350\266\205\346\227\266", nullptr));
        edt_findPicOvertime->setText(QApplication::translate("MainWindow", "-1", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\346\210\220\345\212\237\350\267\263\350\275\254", nullptr));
        edt_succeedJump->setText(QApplication::translate("MainWindow", "-1", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\350\266\205\346\227\266\350\267\263\350\275\254", nullptr));
        edt_overtimeJump->setText(QApplication::translate("MainWindow", "-1", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\350\200\227\346\227\266(\347\274\251\346\224\276)", nullptr));
        edt_costTime->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "\347\264\242\345\274\225", nullptr));
        edt_insertIndex->setText(QString());
        btn_insertInput->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245\350\276\223\345\205\245", nullptr));
        btn_delAllInput_2->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\217\220\347\244\272", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\346\210\220\345\212\237\346\250\241\345\235\227", nullptr));
#ifndef QT_NO_TOOLTIP
        edt_overtimeJumpModule->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        edt_overtimeJumpModule->setText(QApplication::translate("MainWindow", "./QtSave/", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\350\266\205\346\227\266\346\250\241\345\235\227", nullptr));
#ifndef QT_NO_TOOLTIP
        edt_succeedJumpModule->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        edt_succeedJumpModule->setText(QApplication::translate("MainWindow", "./QtSave/", nullptr));
        chk_cmpPicClick->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\345\220\216\347\202\271\345\207\273", nullptr));
        btn_openFileDialog->setText(QApplication::translate("MainWindow", "...", nullptr));
        btn_openFileDialog_picPath->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\346\263\250\351\207\212", nullptr));
        edt_comment->setText(QString());
        btn_updateAllInput->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\346\211\200\346\234\211\345\221\275\344\273\244", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\347\252\227\345\217\243\345\256\275", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\347\252\227\345\217\243\351\253\230", nullptr));
        edt_wndWidth->setText(QApplication::translate("MainWindow", "960", nullptr));
        edt_wndHeight->setText(QApplication::translate("MainWindow", "540", nullptr));
        btn_lisence->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\350\256\270\345\217\257", nullptr));
        edt_month->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "\344\270\252\346\234\210", nullptr));
        btn_lisenceInfo->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\256\270\345\217\257", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "MAC", nullptr));
        edt_mac->setText(QApplication::translate("MainWindow", "D8D0900B8F6D", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\345\257\271\346\257\224\345\217\202\346\225\260", nullptr));
        edt_outputParam->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\217\202\346\225\260", nullptr));
        edt_cmpParam->setText(QApplication::translate("MainWindow", "0", nullptr));
        cb_resolutionRate->setItemText(0, QApplication::translate("MainWindow", "16:9", nullptr));
        cb_resolutionRate->setItemText(1, QApplication::translate("MainWindow", "16:10", nullptr));

        btn_getBattleTemplate->setText(QApplication::translate("MainWindow", "\346\210\230\346\226\227\346\250\241\347\211\2101", nullptr));
        btn_startTimeCount->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\256\241\346\227\266", nullptr));
        btn_endTimeCount->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\350\256\241\346\227\266", nullptr));
        edt_timeCount->setText(QApplication::translate("MainWindow", "999", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\347\247\222", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "\347\255\211\345\276\205", nullptr));
        btn_getBattleTemplate_2->setText(QApplication::translate("MainWindow", "\346\210\230\346\226\227\346\250\241\347\211\2102", nullptr));
        btn_openMapTemplate->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\234\260\345\233\276\346\250\241\347\211\210", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\220\215\347\247\260", nullptr));
        edt_search->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
