/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *choosePorts;
    QComboBox *baud_value;
    QPushButton *connect_button;
    QTextBrowser *browser_dataReceive;
    QComboBox *box_stopBit;
    QComboBox *box_dataBits;
    QComboBox *box_parityBit;
    QLineEdit *le_ADC_PORT_1;
    QLineEdit *le_ADC_PORT_2;
    QLineEdit *le_AMP1;
    QLineEdit *le_AMP2;
    QLineEdit *le_adccalpause;
    QLabel *ADC_Port_1_lb;
    QLabel *ADC_Port_2_lb;
    QLabel *AMP1_l;
    QLabel *AMP2_l;
    QLabel *ADCCALPAUSE_l;
    QLabel *AutoOffTime;
    QLabel *AdcDiv;
    QLabel *AdcSmp;
    QLineEdit *lo_adcckmode;
    QLineEdit *leAutoOffTime;
    QLabel *DacDiv;
    QLineEdit *le_DacDiv;
    QLineEdit *le_ADCDiv;
    QLabel *AdcCkmode_l;
    QLineEdit *le_AdcSmp;
    QLabel *MathAvr;
    QLabel *Kdft;
    QLabel *Ndft;
    QLineEdit *le_TimDiv;
    QLineEdit *le_MathAvr;
    QLabel *OPAHSM1;
    QLineEdit *le_OPAHSM1;
    QLineEdit *le_Kdft;
    QLabel *TimDiv;
    QLineEdit *le_Ndft;
    QLabel *Offse2;
    QLabel *OPAHCM3;
    QLabel *Offset1;
    QLineEdit *le_OPAHSM2;
    QLineEdit *le_offset2;
    QLabel *PGA_CAIN1;
    QLineEdit *le_PGA_CAIN1;
    QLineEdit *le_OPAHSM3;
    QLabel *OPAHSM2;
    QLineEdit *le_Offset1;
    QLabel *RefHiz;
    QLabel *PGA_CAIN3;
    QLabel *RefEnvr;
    QLineEdit *le_PGA_CAIN2;
    QLineEdit *le_RefHiz;
    QLabel *RefVrs;
    QLineEdit *le_RefVrs;
    QLineEdit *le_PGA_CAIN3;
    QLabel *ADC_Port_1_lb_5;
    QLineEdit *le_RefEnvr;
    QLabel *ADC_Port_2_lb_6;
    QLabel *_DAC2;
    QLineEdit *le_Tpp;
    QLineEdit *le_DAC1;
    QLabel *Tpp;
    QLineEdit *le_DAC2;
    QPushButton *pb_get;
    QPushButton *pb_load;
    QLineEdit *le_ADC1;
    QLabel *_DAC2_2;
    QLineEdit *le_ADC2;
    QLabel *ADC_Port_2_lb_7;
    QPushButton *pb_loadPort;
    QPushButton *pb_loadAmp;
    QPushButton *pb_loadAdc;
    QPushButton *pb_loadMath;
    QPushButton *pb_loadOPAHSM;
    QPushButton *pb_loadOffset;
    QPushButton *pb_loadPGA;
    QPushButton *pb_loadRef;
    QPushButton *pb_loadDac;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1031, 712);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        choosePorts = new QComboBox(centralwidget);
        choosePorts->setObjectName(QString::fromUtf8("choosePorts"));
        choosePorts->setGeometry(QRect(820, 20, 191, 22));
        baud_value = new QComboBox(centralwidget);
        baud_value->addItem(QString());
        baud_value->addItem(QString());
        baud_value->addItem(QString());
        baud_value->setObjectName(QString::fromUtf8("baud_value"));
        baud_value->setGeometry(QRect(820, 50, 191, 22));
        connect_button = new QPushButton(centralwidget);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));
        connect_button->setGeometry(QRect(820, 200, 191, 28));
        browser_dataReceive = new QTextBrowser(centralwidget);
        browser_dataReceive->setObjectName(QString::fromUtf8("browser_dataReceive"));
        browser_dataReceive->setGeometry(QRect(10, 20, 801, 31));
        box_stopBit = new QComboBox(centralwidget);
        box_stopBit->addItem(QString());
        box_stopBit->addItem(QString());
        box_stopBit->addItem(QString());
        box_stopBit->setObjectName(QString::fromUtf8("box_stopBit"));
        box_stopBit->setGeometry(QRect(820, 90, 191, 22));
        box_dataBits = new QComboBox(centralwidget);
        box_dataBits->addItem(QString());
        box_dataBits->addItem(QString());
        box_dataBits->addItem(QString());
        box_dataBits->addItem(QString());
        box_dataBits->setObjectName(QString::fromUtf8("box_dataBits"));
        box_dataBits->setGeometry(QRect(820, 130, 191, 22));
        box_parityBit = new QComboBox(centralwidget);
        box_parityBit->addItem(QString());
        box_parityBit->addItem(QString());
        box_parityBit->addItem(QString());
        box_parityBit->setObjectName(QString::fromUtf8("box_parityBit"));
        box_parityBit->setGeometry(QRect(820, 170, 191, 22));
        le_ADC_PORT_1 = new QLineEdit(centralwidget);
        le_ADC_PORT_1->setObjectName(QString::fromUtf8("le_ADC_PORT_1"));
        le_ADC_PORT_1->setGeometry(QRect(10, 90, 113, 22));
        le_ADC_PORT_2 = new QLineEdit(centralwidget);
        le_ADC_PORT_2->setObjectName(QString::fromUtf8("le_ADC_PORT_2"));
        le_ADC_PORT_2->setGeometry(QRect(10, 140, 113, 22));
        le_AMP1 = new QLineEdit(centralwidget);
        le_AMP1->setObjectName(QString::fromUtf8("le_AMP1"));
        le_AMP1->setGeometry(QRect(10, 220, 113, 22));
        le_AMP2 = new QLineEdit(centralwidget);
        le_AMP2->setObjectName(QString::fromUtf8("le_AMP2"));
        le_AMP2->setGeometry(QRect(10, 270, 113, 22));
        le_adccalpause = new QLineEdit(centralwidget);
        le_adccalpause->setObjectName(QString::fromUtf8("le_adccalpause"));
        le_adccalpause->setGeometry(QRect(140, 90, 113, 22));
        ADC_Port_1_lb = new QLabel(centralwidget);
        ADC_Port_1_lb->setObjectName(QString::fromUtf8("ADC_Port_1_lb"));
        ADC_Port_1_lb->setGeometry(QRect(30, 70, 71, 16));
        ADC_Port_2_lb = new QLabel(centralwidget);
        ADC_Port_2_lb->setObjectName(QString::fromUtf8("ADC_Port_2_lb"));
        ADC_Port_2_lb->setGeometry(QRect(30, 120, 71, 16));
        AMP1_l = new QLabel(centralwidget);
        AMP1_l->setObjectName(QString::fromUtf8("AMP1_l"));
        AMP1_l->setGeometry(QRect(30, 200, 71, 16));
        AMP2_l = new QLabel(centralwidget);
        AMP2_l->setObjectName(QString::fromUtf8("AMP2_l"));
        AMP2_l->setGeometry(QRect(30, 250, 71, 16));
        ADCCALPAUSE_l = new QLabel(centralwidget);
        ADCCALPAUSE_l->setObjectName(QString::fromUtf8("ADCCALPAUSE_l"));
        ADCCALPAUSE_l->setGeometry(QRect(160, 70, 81, 16));
        AutoOffTime = new QLabel(centralwidget);
        AutoOffTime->setObjectName(QString::fromUtf8("AutoOffTime"));
        AutoOffTime->setGeometry(QRect(160, 270, 71, 16));
        AdcDiv = new QLabel(centralwidget);
        AdcDiv->setObjectName(QString::fromUtf8("AdcDiv"));
        AdcDiv->setGeometry(QRect(160, 170, 71, 16));
        AdcSmp = new QLabel(centralwidget);
        AdcSmp->setObjectName(QString::fromUtf8("AdcSmp"));
        AdcSmp->setGeometry(QRect(160, 220, 71, 16));
        lo_adcckmode = new QLineEdit(centralwidget);
        lo_adcckmode->setObjectName(QString::fromUtf8("lo_adcckmode"));
        lo_adcckmode->setGeometry(QRect(140, 140, 113, 22));
        leAutoOffTime = new QLineEdit(centralwidget);
        leAutoOffTime->setObjectName(QString::fromUtf8("leAutoOffTime"));
        leAutoOffTime->setGeometry(QRect(140, 290, 113, 22));
        DacDiv = new QLabel(centralwidget);
        DacDiv->setObjectName(QString::fromUtf8("DacDiv"));
        DacDiv->setGeometry(QRect(290, 70, 81, 16));
        le_DacDiv = new QLineEdit(centralwidget);
        le_DacDiv->setObjectName(QString::fromUtf8("le_DacDiv"));
        le_DacDiv->setGeometry(QRect(270, 90, 113, 22));
        le_ADCDiv = new QLineEdit(centralwidget);
        le_ADCDiv->setObjectName(QString::fromUtf8("le_ADCDiv"));
        le_ADCDiv->setGeometry(QRect(140, 190, 113, 22));
        AdcCkmode_l = new QLabel(centralwidget);
        AdcCkmode_l->setObjectName(QString::fromUtf8("AdcCkmode_l"));
        AdcCkmode_l->setGeometry(QRect(160, 120, 71, 16));
        le_AdcSmp = new QLineEdit(centralwidget);
        le_AdcSmp->setObjectName(QString::fromUtf8("le_AdcSmp"));
        le_AdcSmp->setGeometry(QRect(140, 240, 113, 22));
        MathAvr = new QLabel(centralwidget);
        MathAvr->setObjectName(QString::fromUtf8("MathAvr"));
        MathAvr->setGeometry(QRect(290, 270, 71, 16));
        Kdft = new QLabel(centralwidget);
        Kdft->setObjectName(QString::fromUtf8("Kdft"));
        Kdft->setGeometry(QRect(290, 170, 71, 16));
        Ndft = new QLabel(centralwidget);
        Ndft->setObjectName(QString::fromUtf8("Ndft"));
        Ndft->setGeometry(QRect(290, 220, 71, 16));
        le_TimDiv = new QLineEdit(centralwidget);
        le_TimDiv->setObjectName(QString::fromUtf8("le_TimDiv"));
        le_TimDiv->setGeometry(QRect(270, 140, 113, 22));
        le_MathAvr = new QLineEdit(centralwidget);
        le_MathAvr->setObjectName(QString::fromUtf8("le_MathAvr"));
        le_MathAvr->setGeometry(QRect(270, 290, 113, 22));
        OPAHSM1 = new QLabel(centralwidget);
        OPAHSM1->setObjectName(QString::fromUtf8("OPAHSM1"));
        OPAHSM1->setGeometry(QRect(420, 70, 81, 16));
        le_OPAHSM1 = new QLineEdit(centralwidget);
        le_OPAHSM1->setObjectName(QString::fromUtf8("le_OPAHSM1"));
        le_OPAHSM1->setGeometry(QRect(400, 90, 113, 22));
        le_Kdft = new QLineEdit(centralwidget);
        le_Kdft->setObjectName(QString::fromUtf8("le_Kdft"));
        le_Kdft->setGeometry(QRect(270, 190, 113, 22));
        TimDiv = new QLabel(centralwidget);
        TimDiv->setObjectName(QString::fromUtf8("TimDiv"));
        TimDiv->setGeometry(QRect(290, 120, 71, 16));
        le_Ndft = new QLineEdit(centralwidget);
        le_Ndft->setObjectName(QString::fromUtf8("le_Ndft"));
        le_Ndft->setGeometry(QRect(270, 240, 113, 22));
        Offse2 = new QLabel(centralwidget);
        Offse2->setObjectName(QString::fromUtf8("Offse2"));
        Offse2->setGeometry(QRect(420, 310, 71, 16));
        OPAHCM3 = new QLabel(centralwidget);
        OPAHCM3->setObjectName(QString::fromUtf8("OPAHCM3"));
        OPAHCM3->setGeometry(QRect(420, 170, 71, 16));
        Offset1 = new QLabel(centralwidget);
        Offset1->setObjectName(QString::fromUtf8("Offset1"));
        Offset1->setGeometry(QRect(420, 260, 71, 16));
        le_OPAHSM2 = new QLineEdit(centralwidget);
        le_OPAHSM2->setObjectName(QString::fromUtf8("le_OPAHSM2"));
        le_OPAHSM2->setGeometry(QRect(400, 140, 113, 22));
        le_offset2 = new QLineEdit(centralwidget);
        le_offset2->setObjectName(QString::fromUtf8("le_offset2"));
        le_offset2->setGeometry(QRect(400, 330, 113, 22));
        PGA_CAIN1 = new QLabel(centralwidget);
        PGA_CAIN1->setObjectName(QString::fromUtf8("PGA_CAIN1"));
        PGA_CAIN1->setGeometry(QRect(550, 70, 81, 16));
        le_PGA_CAIN1 = new QLineEdit(centralwidget);
        le_PGA_CAIN1->setObjectName(QString::fromUtf8("le_PGA_CAIN1"));
        le_PGA_CAIN1->setGeometry(QRect(530, 90, 113, 22));
        le_OPAHSM3 = new QLineEdit(centralwidget);
        le_OPAHSM3->setObjectName(QString::fromUtf8("le_OPAHSM3"));
        le_OPAHSM3->setGeometry(QRect(400, 190, 113, 22));
        OPAHSM2 = new QLabel(centralwidget);
        OPAHSM2->setObjectName(QString::fromUtf8("OPAHSM2"));
        OPAHSM2->setGeometry(QRect(420, 120, 71, 16));
        le_Offset1 = new QLineEdit(centralwidget);
        le_Offset1->setObjectName(QString::fromUtf8("le_Offset1"));
        le_Offset1->setGeometry(QRect(400, 280, 113, 22));
        RefHiz = new QLabel(centralwidget);
        RefHiz->setObjectName(QString::fromUtf8("RefHiz"));
        RefHiz->setGeometry(QRect(550, 310, 71, 16));
        PGA_CAIN3 = new QLabel(centralwidget);
        PGA_CAIN3->setObjectName(QString::fromUtf8("PGA_CAIN3"));
        PGA_CAIN3->setGeometry(QRect(550, 170, 71, 16));
        RefEnvr = new QLabel(centralwidget);
        RefEnvr->setObjectName(QString::fromUtf8("RefEnvr"));
        RefEnvr->setGeometry(QRect(550, 260, 71, 16));
        le_PGA_CAIN2 = new QLineEdit(centralwidget);
        le_PGA_CAIN2->setObjectName(QString::fromUtf8("le_PGA_CAIN2"));
        le_PGA_CAIN2->setGeometry(QRect(530, 140, 113, 22));
        le_RefHiz = new QLineEdit(centralwidget);
        le_RefHiz->setObjectName(QString::fromUtf8("le_RefHiz"));
        le_RefHiz->setGeometry(QRect(530, 330, 113, 22));
        RefVrs = new QLabel(centralwidget);
        RefVrs->setObjectName(QString::fromUtf8("RefVrs"));
        RefVrs->setGeometry(QRect(550, 360, 81, 16));
        le_RefVrs = new QLineEdit(centralwidget);
        le_RefVrs->setObjectName(QString::fromUtf8("le_RefVrs"));
        le_RefVrs->setGeometry(QRect(530, 380, 113, 22));
        le_PGA_CAIN3 = new QLineEdit(centralwidget);
        le_PGA_CAIN3->setObjectName(QString::fromUtf8("le_PGA_CAIN3"));
        le_PGA_CAIN3->setGeometry(QRect(530, 190, 113, 22));
        ADC_Port_1_lb_5 = new QLabel(centralwidget);
        ADC_Port_1_lb_5->setObjectName(QString::fromUtf8("ADC_Port_1_lb_5"));
        ADC_Port_1_lb_5->setGeometry(QRect(550, 120, 71, 16));
        le_RefEnvr = new QLineEdit(centralwidget);
        le_RefEnvr->setObjectName(QString::fromUtf8("le_RefEnvr"));
        le_RefEnvr->setGeometry(QRect(530, 280, 113, 22));
        ADC_Port_2_lb_6 = new QLabel(centralwidget);
        ADC_Port_2_lb_6->setObjectName(QString::fromUtf8("ADC_Port_2_lb_6"));
        ADC_Port_2_lb_6->setGeometry(QRect(700, 120, 71, 16));
        _DAC2 = new QLabel(centralwidget);
        _DAC2->setObjectName(QString::fromUtf8("_DAC2"));
        _DAC2->setGeometry(QRect(700, 170, 71, 16));
        le_Tpp = new QLineEdit(centralwidget);
        le_Tpp->setObjectName(QString::fromUtf8("le_Tpp"));
        le_Tpp->setGeometry(QRect(680, 90, 113, 22));
        le_DAC1 = new QLineEdit(centralwidget);
        le_DAC1->setObjectName(QString::fromUtf8("le_DAC1"));
        le_DAC1->setGeometry(QRect(680, 140, 113, 22));
        Tpp = new QLabel(centralwidget);
        Tpp->setObjectName(QString::fromUtf8("Tpp"));
        Tpp->setGeometry(QRect(700, 70, 71, 16));
        le_DAC2 = new QLineEdit(centralwidget);
        le_DAC2->setObjectName(QString::fromUtf8("le_DAC2"));
        le_DAC2->setGeometry(QRect(680, 190, 113, 22));
        pb_get = new QPushButton(centralwidget);
        pb_get->setObjectName(QString::fromUtf8("pb_get"));
        pb_get->setEnabled(false);
        pb_get->setGeometry(QRect(860, 240, 93, 28));
        pb_load = new QPushButton(centralwidget);
        pb_load->setObjectName(QString::fromUtf8("pb_load"));
        pb_load->setEnabled(false);
        pb_load->setGeometry(QRect(20, 390, 93, 28));
        le_ADC1 = new QLineEdit(centralwidget);
        le_ADC1->setObjectName(QString::fromUtf8("le_ADC1"));
        le_ADC1->setGeometry(QRect(10, 480, 113, 22));
        _DAC2_2 = new QLabel(centralwidget);
        _DAC2_2->setObjectName(QString::fromUtf8("_DAC2_2"));
        _DAC2_2->setGeometry(QRect(30, 510, 71, 16));
        le_ADC2 = new QLineEdit(centralwidget);
        le_ADC2->setObjectName(QString::fromUtf8("le_ADC2"));
        le_ADC2->setGeometry(QRect(10, 530, 113, 22));
        ADC_Port_2_lb_7 = new QLabel(centralwidget);
        ADC_Port_2_lb_7->setObjectName(QString::fromUtf8("ADC_Port_2_lb_7"));
        ADC_Port_2_lb_7->setGeometry(QRect(30, 460, 71, 16));
        pb_loadPort = new QPushButton(centralwidget);
        pb_loadPort->setObjectName(QString::fromUtf8("pb_loadPort"));
        pb_loadPort->setEnabled(false);
        pb_loadPort->setGeometry(QRect(20, 170, 93, 28));
        pb_loadAmp = new QPushButton(centralwidget);
        pb_loadAmp->setObjectName(QString::fromUtf8("pb_loadAmp"));
        pb_loadAmp->setEnabled(false);
        pb_loadAmp->setGeometry(QRect(20, 300, 93, 28));
        pb_loadAdc = new QPushButton(centralwidget);
        pb_loadAdc->setObjectName(QString::fromUtf8("pb_loadAdc"));
        pb_loadAdc->setEnabled(false);
        pb_loadAdc->setGeometry(QRect(150, 320, 93, 28));
        pb_loadMath = new QPushButton(centralwidget);
        pb_loadMath->setObjectName(QString::fromUtf8("pb_loadMath"));
        pb_loadMath->setEnabled(false);
        pb_loadMath->setGeometry(QRect(270, 320, 93, 28));
        pb_loadOPAHSM = new QPushButton(centralwidget);
        pb_loadOPAHSM->setObjectName(QString::fromUtf8("pb_loadOPAHSM"));
        pb_loadOPAHSM->setEnabled(false);
        pb_loadOPAHSM->setGeometry(QRect(410, 220, 93, 28));
        pb_loadOffset = new QPushButton(centralwidget);
        pb_loadOffset->setObjectName(QString::fromUtf8("pb_loadOffset"));
        pb_loadOffset->setEnabled(false);
        pb_loadOffset->setGeometry(QRect(410, 360, 93, 28));
        pb_loadPGA = new QPushButton(centralwidget);
        pb_loadPGA->setObjectName(QString::fromUtf8("pb_loadPGA"));
        pb_loadPGA->setEnabled(false);
        pb_loadPGA->setGeometry(QRect(540, 220, 93, 28));
        pb_loadRef = new QPushButton(centralwidget);
        pb_loadRef->setObjectName(QString::fromUtf8("pb_loadRef"));
        pb_loadRef->setEnabled(false);
        pb_loadRef->setGeometry(QRect(540, 410, 93, 28));
        pb_loadDac = new QPushButton(centralwidget);
        pb_loadDac->setObjectName(QString::fromUtf8("pb_loadDac"));
        pb_loadDac->setEnabled(false);
        pb_loadDac->setGeometry(QRect(690, 220, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1031, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        baud_value->setItemText(0, QApplication::translate("MainWindow", "9600", nullptr));
        baud_value->setItemText(1, QApplication::translate("MainWindow", "115200", nullptr));
        baud_value->setItemText(2, QApplication::translate("MainWindow", "209700", nullptr));

        connect_button->setText(QApplication::translate("MainWindow", "Open the serial port", nullptr));
        box_stopBit->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        box_stopBit->setItemText(1, QApplication::translate("MainWindow", "1.5", nullptr));
        box_stopBit->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));

        box_dataBits->setItemText(0, QApplication::translate("MainWindow", "8", nullptr));
        box_dataBits->setItemText(1, QApplication::translate("MainWindow", "7", nullptr));
        box_dataBits->setItemText(2, QApplication::translate("MainWindow", "6", nullptr));
        box_dataBits->setItemText(3, QApplication::translate("MainWindow", "5", nullptr));

        box_parityBit->setItemText(0, QApplication::translate("MainWindow", "None", nullptr));
        box_parityBit->setItemText(1, QApplication::translate("MainWindow", "Even", nullptr));
        box_parityBit->setItemText(2, QApplication::translate("MainWindow", "Odd", nullptr));

        ADC_Port_1_lb->setText(QApplication::translate("MainWindow", "ADC Port 1", nullptr));
        ADC_Port_2_lb->setText(QApplication::translate("MainWindow", "ADC Port 2", nullptr));
        AMP1_l->setText(QApplication::translate("MainWindow", "AMP1", nullptr));
        AMP2_l->setText(QApplication::translate("MainWindow", "AMP2", nullptr));
        ADCCALPAUSE_l->setText(QApplication::translate("MainWindow", "AdcCalPause", nullptr));
        AutoOffTime->setText(QApplication::translate("MainWindow", "AutoOffTime", nullptr));
        AdcDiv->setText(QApplication::translate("MainWindow", "AdcDiv", nullptr));
        AdcSmp->setText(QApplication::translate("MainWindow", "AdcSmp", nullptr));
        DacDiv->setText(QApplication::translate("MainWindow", "DacDiv", nullptr));
        AdcCkmode_l->setText(QApplication::translate("MainWindow", "AdcCkmode", nullptr));
        MathAvr->setText(QApplication::translate("MainWindow", "MathAvr", nullptr));
        Kdft->setText(QApplication::translate("MainWindow", "Kdft", nullptr));
        Ndft->setText(QApplication::translate("MainWindow", "Ndft", nullptr));
        OPAHSM1->setText(QApplication::translate("MainWindow", "OPAHSM1", nullptr));
        TimDiv->setText(QApplication::translate("MainWindow", "TimDiv", nullptr));
        Offse2->setText(QApplication::translate("MainWindow", "Offset2", nullptr));
        OPAHCM3->setText(QApplication::translate("MainWindow", "OPAHSM3", nullptr));
        Offset1->setText(QApplication::translate("MainWindow", "Offset1", nullptr));
        PGA_CAIN1->setText(QApplication::translate("MainWindow", "PGA_CAIN1", nullptr));
        OPAHSM2->setText(QApplication::translate("MainWindow", "OPAHSM2", nullptr));
        RefHiz->setText(QApplication::translate("MainWindow", "RefHiz", nullptr));
        PGA_CAIN3->setText(QApplication::translate("MainWindow", "PGA_CAIN3", nullptr));
        RefEnvr->setText(QApplication::translate("MainWindow", "RefEnvr", nullptr));
        RefVrs->setText(QApplication::translate("MainWindow", "RefVrs", nullptr));
        ADC_Port_1_lb_5->setText(QApplication::translate("MainWindow", "PGA_CAIN2", nullptr));
        ADC_Port_2_lb_6->setText(QApplication::translate("MainWindow", "_DAC1", nullptr));
        _DAC2->setText(QApplication::translate("MainWindow", "_DAC2", nullptr));
        Tpp->setText(QApplication::translate("MainWindow", "Tpp", nullptr));
        pb_get->setText(QApplication::translate("MainWindow", "GET", nullptr));
        pb_load->setText(QApplication::translate("MainWindow", "LOAD", nullptr));
        _DAC2_2->setText(QApplication::translate("MainWindow", "ADC2", nullptr));
        ADC_Port_2_lb_7->setText(QApplication::translate("MainWindow", "ADC1", nullptr));
        pb_loadPort->setText(QApplication::translate("MainWindow", "Load Port", nullptr));
        pb_loadAmp->setText(QApplication::translate("MainWindow", "Load Amp", nullptr));
        pb_loadAdc->setText(QApplication::translate("MainWindow", "Load ADC", nullptr));
        pb_loadMath->setText(QApplication::translate("MainWindow", "Load Math", nullptr));
        pb_loadOPAHSM->setText(QApplication::translate("MainWindow", "Load OPAHSM", nullptr));
        pb_loadOffset->setText(QApplication::translate("MainWindow", "Load Offset", nullptr));
        pb_loadPGA->setText(QApplication::translate("MainWindow", "Load PGA", nullptr));
        pb_loadRef->setText(QApplication::translate("MainWindow", "Load Ref", nullptr));
        pb_loadDac->setText(QApplication::translate("MainWindow", "Load DAC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
