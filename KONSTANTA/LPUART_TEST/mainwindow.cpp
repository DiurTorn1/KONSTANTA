#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDateTime>
#include "serialworker.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitSerialPortName();

    SerialWorker *serialWoker = new SerialWorker(&serial_1);
    serialWoker->moveToThread(&serialThread_1);

    connect(&serialThread_1, &QThread::finished, serialWoker, &QObject::deleteLater);
    connect(this, &MainWindow::serialDataSend, serialWoker, &SerialWorker::doDataSendWork);
    connect(&serial_1, &QSerialPort::readyRead, serialWoker, &SerialWorker::doDataReceiveWork);
    connect(serialWoker, &SerialWorker::sendResultToGui, this, &MainWindow::handleResults);

    serialThread_1.start();
    //connect(&serial_1, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);

}

MainWindow::~MainWindow()
{
    serialThread_1.quit();
    serialThread_1.wait();
    delete ui;
}

void MainWindow::InitSerialPortName(){
    ui->choosePorts->clear();

    foreach(const QSerialPortInfo &info, QSerialPortInfo:: availablePorts()){
        QString showName = info.portName()+":"+info.description();
        qDebug()<<showName.length();
        ui->choosePorts->addItem(showName);
    }
}
void MainWindow::on_connect_button_clicked()
{
    if(ui->connect_button->text()==QString("Open the serial port")){
        //Set serial port name
        QString portName = (ui->choosePorts->currentText()).split(":").at(0);
        qDebug() << portName;
        serial_1.setPortName(portName);
        //Set baud rate
        serial_1.setBaudRate(ui->baud_value->currentText().toInt());
        //Set stop bit
        if(ui->box_stopBit->currentText() == "1") serial_1.setStopBits(QSerialPort::OneStop);
        if(ui->box_stopBit->currentText() == "1.5") serial_1.setStopBits(QSerialPort::OneAndHalfStop);
        if(ui->box_stopBit->currentText() == "2") serial_1.setStopBits(QSerialPort::TwoStop);
        //Set the number of data bits
        if(ui->box_dataBits->currentText() == "8") serial_1.setDataBits(QSerialPort::Data8);
        if(ui->box_dataBits->currentText() == "7") serial_1.setDataBits(QSerialPort::Data7);
        if(ui->box_dataBits->currentText() == "6") serial_1.setDataBits(QSerialPort::Data6);
        if(ui->box_dataBits->currentText() == "5") serial_1.setDataBits(QSerialPort::Data5);
        //set parity
        if(ui->box_parityBit->currentText() == "None") serial_1.setParity(QSerialPort::NoParity);
        if(ui->box_parityBit->currentText() == "Even") serial_1.setParity(QSerialPort::EvenParity);
        if(ui->box_parityBit->currentText() == "Odd") serial_1.setParity(QSerialPort::OddParity);
        //Set stream control
        serial_1.setFlowControl(QSerialPort::NoFlowControl);
        //Open serial port
        if(!serial_1.open(QIODevice::ReadWrite)){
            QMessageBox::about(NULL, "promt", "Can't open the serial port!");
            return;
        }

        //drop down menu control fault
        ui->choosePorts->setEnabled(false);
        ui->baud_value->setEnabled(false);
        ui->box_dataBits->setEnabled(false);
        ui->box_parityBit->setEnabled(false);
        ui->box_stopBit->setEnabled(false);

        ui->connect_button->setText(QString("Close the serial port"));
        ui->pb_get->setEnabled(true);
        ui->pb_load->setEnabled(true);
        ui->pb_loadAdc->setEnabled(true);
        ui->pb_loadAmp->setEnabled(true);
        ui->pb_loadDac->setEnabled(true);
        ui->pb_loadMath->setEnabled(true);
        ui->pb_loadOPAHSM->setEnabled(true);
        ui->pb_loadOffset->setEnabled(true);
        ui->pb_loadPGA->setEnabled(true);
        ui->pb_loadPort->setEnabled(true);
        ui->pb_loadRef->setEnabled(true);

    } else {
        //Turn off serial port
        serial_1.close();
        //drop down menu control enable
        ui->choosePorts->setEnabled(true);
        ui->baud_value->setEnabled(true);
        ui->box_dataBits->setEnabled(true);
        ui->box_parityBit->setEnabled(true);
        ui->box_stopBit->setEnabled(true);
        ui->connect_button->setText(QString("Open the serial port"));
        ui->pb_get->setEnabled(false);
        ui->pb_load->setEnabled(false);
        ui->pb_loadAdc->setEnabled(false);
        ui->pb_loadAmp->setEnabled(false);
        ui->pb_loadDac->setEnabled(false);
        ui->pb_loadMath->setEnabled(false);
        ui->pb_loadOPAHSM->setEnabled(false);
        ui->pb_loadOffset->setEnabled(false);
        ui->pb_loadPGA->setEnabled(false);
        ui->pb_loadPort->setEnabled(false);
        ui->pb_loadRef->setEnabled(false);
    }
}

QString MainWindow::ByteArrayToHexString(QByteArray data){
    QString ret(data.toHex().toUpper());
    int len = ret.length()/2;
    qDebug()<<len;
    for(int i=1;i<len;i++) ret.insert(2*i+i-1," ");

    return ret;
}

QByteArray MainWindow::HexStringTyByteArray(QString HexString){
    bool ok;
    QByteArray ret;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    QStringList sl = HexString.split(" ");
    foreach (QString s, sl){
        if(!s.isEmpty()){
            char c = s.toInt(&ok, 16)&0xFF;
            if(ok){
                ret.append(c);
            } else {
                qDebug() << "Illegal 16 credit characters:" <<s;
                QMessageBox::about(0, tr("error:"), QString("Illegal 16 credit characters: \"%1 \"").arg(s));
            }
        }
    }

    return ret;
}

void MainWindow::serialPort_readyRead(){
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString dateStr = current_date_time.toString("[yyyy-MM-dd hh:mm::ss.zzz]");

    QByteArray buffer = serial_1.readAll();
    QString bufferStr = ByteArrayToHexString(buffer);

    QString displayStr = dateStr+"\n"+bufferStr+"\n";
    QString oldString = ui->browser_dataReceive->toPlainText();
    oldString = oldString + QString(displayStr);
    ui->browser_dataReceive->clear();
    ui->browser_dataReceive->append(oldString);
}

void MainWindow::handleResults(QByteArray result){
    QString res = result;
    qDebug() << "The main thread receives the result data:" << res << "Thread ID:" << QThread::currentThreadId();
    //QDateTime current_date_time = QDateTime::currentDateTime();
    //QString dateStr = current_date_time.toString("[yyyy-MM-dd hh:mm::ss.zzz]");
    //QString bufferStr;

    //QByteArray buffer;
    switch(cmd){
    case 0:

        break;
    case 1:{
        //ui->le_ADC_PORT_1->clear();
        int stop = 42;
        //bufferStr = ByteArrayToHexString(result);
        for(auto ll : result) {data[len_cmd] = ll; len_cmd++;}
        if(len_cmd>=stop){
            for(int i = 0; i <result.length();i++)qDebug()<<data[i];
            //ui->le_ADC_PORT_1->setText(QString("%1").arg(data[0]));
            ui->le_ADC_PORT_2->setText(QString("%1").arg(data[1]));
            quint16 amp1 = (data[3] << 8) | data[2];
            ui->le_AMP1->setText(QString("%1").arg(amp1));
            quint16 amp2 = (data[5] << 8) | data[4];
            ui->le_AMP2->setText(QString("%1").arg(amp2));
            quint16 AdcCalPause = (data[7] << 8) | data[6];
            ui->le_adccalpause->setText(QString("%1").arg(AdcCalPause));
            ui->lo_adcckmode->setText(QString("%1").arg(data[8]));
            quint16 AdcDiv = (data[10] << 8) | data[9];
            ui->le_ADCDiv->setText(QString("%1").arg(AdcDiv));
            ui->le_AdcSmp->setText(QString("%1").arg(data[11]));
            quint16 AutoOffTime = (data[13] << 8) | data[12];
            ui->leAutoOffTime->setText(QString("%1").arg(AutoOffTime));
            quint16 DacDiv = (data[15] << 8) | data[14];
            ui->le_DacDiv->setText(QString("%1").arg(DacDiv));
            quint16 TimDiv = (data[17] << 8) | data[16];
            ui->le_TimDiv->setText(QString("%1").arg(TimDiv));
            quint16 Kdft = (data[19] << 8) | data[18];
            ui->le_Kdft->setText(QString("%1").arg(Kdft));
            ui->le_Ndft->setText(QString("%1").arg(data[20]));
            ui->le_MathAvr->setText(QString("%1").arg(data[21]));
            ui->le_OPAHSM1->setText(QString("%1").arg(data[22]));
            ui->le_OPAHSM2->setText(QString("%1").arg(data[23]));
            ui->le_OPAHSM3->setText(QString("%1").arg(data[24]));
            quint16 Offset1 = (data[26] << 8) | data[25];
            ui->le_Offset1->setText(QString("%1").arg(Offset1));
            quint16 Offset2 = (data[28] << 8) | data[27];
            ui->le_offset2->setText(QString("%1").arg(Offset2));
            ui->le_PGA_CAIN1->setText(QString("%1").arg(data[29]));
            ui->le_PGA_CAIN2->setText(QString("%1").arg(data[30]));
            ui->le_PGA_CAIN3->setText(QString("%1").arg(data[31]));
            ui->le_RefEnvr->setText(QString("%1").arg(data[32]));
            ui->le_RefHiz->setText(QString("%1").arg(data[33]));
            ui->le_RefVrs->setText(QString("%1").arg(data[34]));
            quint16 Tpp = (data[36] << 8) | data[35];
            ui->le_Tpp->setText(QString("%1").arg(Tpp));
            quint16 _DAC1 = (data[38] << 8) | data[37];
            ui->le_DAC1->setText(QString("%1").arg(_DAC1));
            quint16 _DAC2 = (data[40] << 8) | data[39];
            ui->le_DAC2->setText(QString("%1").arg(_DAC2));
            ui->le_ADC_PORT_1->setText(QString("%1").arg(data[41]));
            len_cmd=0;
        }
    }
        break;
    case 2:{

           cmd = 0;
    }
        break;
    case 3:{
        int in = 0;
        QByteArray data_c;
        data_c[0] = 3;
        emit serialDataSend(data_c);
        for(auto ll : qAsConst(result)) {data[in] = ll; in++;}
        quint16 adc1 = (data[1] << 8) | data[0];
        ui->le_ADC1->setText(QString("%1").arg(adc1));
        //quint16 amp2 = (data[5] << 8) | data[4];
    }
        break;

    }

    //QString displayStr = bufferStr;//dateStr+"\n"+bufferStr+"\n";
    //QString oldString = ui->browser_dataReceive->toPlainText();
    //oldString = oldString + QString(displayStr);
    //ui->browser_dataReceive->clear();
    //ui->browser_dataReceive->append(oldString);
}

void MainWindow::on_pb_get_clicked()
{
    QByteArray data;
    data[0] = 1;
    cmd = 1;
    emit serialDataSend(data);
}


void MainWindow::on_pb_load_clicked()
{
}


void MainWindow::on_pb_loadPort_clicked()
{
    QByteArray ba;
    QString str;
    ba.append(2);
    ba.append(1);
    ba.append(HexStringTyByteArray( ui->le_ADC_PORT_1->text() ));
    ba.append(HexStringTyByteArray( ui->le_ADC_PORT_2->text() ));
    emit serialDataSend(ba);
}


void MainWindow::on_pb_loadAmp_clicked()
{
    QByteArray ba;
    QString str;
    quint16 ret;
    quint8 rec[2];
    ba.append(2);
    ba.append(2);
    str = ui->le_AMP1->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    str = ui->le_AMP2->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    emit serialDataSend(ba);
}


void MainWindow::on_pb_loadAdc_clicked()
{
    QByteArray ba;
    QString str;
    quint16 ret;
    quint8 rec[2];
    ba.append(2);
    ba.append(3);
    str = ui->le_adccalpause->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    ba.append(HexStringTyByteArray( ui->lo_adcckmode->text() ));
    str = ui->le_ADCDiv->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    ba.append(HexStringTyByteArray( ui->le_AdcSmp->text() ));
    str = ui->leAutoOffTime->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    emit serialDataSend(ba);
}


void MainWindow::on_pb_loadMath_clicked()
{
    QByteArray ba;
    QString str;
    quint16 ret;
    quint8 rec[2];
    ba.append(2);
    ba.append(4);
    str = ui->le_DacDiv->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    str = ui->le_TimDiv->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    str = ui->le_Kdft->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    ba.append(HexStringTyByteArray( ui->le_Ndft->text() ));
    ba.append(HexStringTyByteArray( ui->le_MathAvr->text() ));
    emit serialDataSend(ba);
}


void MainWindow::on_pb_loadOPAHSM_clicked()
{
    QByteArray ba;
    QString str;
    ba.append(2);
    ba.append(5);
    ba.append(HexStringTyByteArray( ui->le_OPAHSM1->text() ));
    ba.append(HexStringTyByteArray( ui->le_OPAHSM2->text() ));
    ba.append(HexStringTyByteArray( ui->le_OPAHSM3->text() ));
    emit serialDataSend(ba);
}


void MainWindow::on_pb_loadOffset_clicked()
{
    QByteArray ba;
    QString str;
    quint16 ret;
    quint8 rec[2];
    ba.append(2);
    ba.append(6);
    str = ui->le_Offset1->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    str = ui->le_offset2->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    emit serialDataSend(ba);
}


void MainWindow::on_pb_loadPGA_clicked()
{
    QByteArray ba;
    QString str;
    ba.append(2);
    ba.append(7);
    ba.append(HexStringTyByteArray( ui->le_PGA_CAIN1->text() ));
    ba.append(HexStringTyByteArray( ui->le_PGA_CAIN2->text() ));
    ba.append(HexStringTyByteArray( ui->le_PGA_CAIN3->text() ));
    emit serialDataSend(ba);
}


void MainWindow::on_pb_loadRef_clicked()
{
    QByteArray ba;
    QString str;
    ba.append(2);
    ba.append(8);
    ba.append(HexStringTyByteArray( ui->le_RefEnvr->text() ));
    ba.append(HexStringTyByteArray( ui->le_RefHiz->text() ));
    ba.append(HexStringTyByteArray( ui->le_RefVrs->text() ));
    emit serialDataSend(ba);
}


void MainWindow::on_pb_loadDac_clicked()
{
    QByteArray ba;
    QString str;
    quint16 ret;
    quint8 rec[2];
    ba.append(2);
    ba.append(9);
    str = ui->le_Tpp->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    str = ui->le_DAC1->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    str = ui->le_DAC2->text();
    ret = str.toInt(); rec[0] = ret & 0xFF; rec[1] = ret >> 8;
    ba.append(rec[0]); ba.append(rec[1]);
    ba.append(HexStringTyByteArray( ui->le_ADC_PORT_1->text() ));
    emit serialDataSend(ba);
}

