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
        ui->btn_send->setEnabled(true);
        ui->pb_get->setEnabled(true);
        ui->pb_load->setEnabled(true);

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
        ui->btn_send->setEnabled(false);
        ui->pb_get->setEnabled(false);
        ui->pb_load->setEnabled(false);
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

void MainWindow::on_btn_send_clicked()
{
    QByteArray data;
    if(ui->check_hexSend->isCheckable() == true)
        data = HexStringTyByteArray(ui->edit_dataSend->toPlainText());
    else
        data = ui->edit_dataSend->toPlainText().toUtf8();
    //serial_1.write(data);

    emit serialDataSend(data);
    qDebug() << "Main thread send signal, thread ID:" << QThread::currentThreadId();
}


void MainWindow::on_btn_clearSend_clicked()
{
    ui->edit_dataSend->clear();
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
    bool ok = false;
    qDebug() << "The main thread receives the result data:" << res << "Thread ID:" << QThread::currentThreadId();
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString dateStr = current_date_time.toString("[yyyy-MM-dd hh:mm::ss.zzz]");

    //QByteArray buffer;
    QString bufferStr = ByteArrayToHexString(result);
    quint8 data[41];// = result.toInt(&ok, 16);
    for(auto ll : result) {data[len_cmd] = ll; len_cmd++;}
    if(len_cmd>=41){for(auto ii : data)qDebug()<<ii;}

    QString displayStr = dateStr+"\n"+bufferStr+"\n";
    QString oldString = ui->browser_dataReceive->toPlainText();
    oldString = oldString + QString(displayStr);
    ui->browser_dataReceive->clear();
    ui->browser_dataReceive->append(oldString);
}

void MainWindow::on_pb_get_clicked()
{
    QByteArray data;
    data[0] = 1;
    emit serialDataSend(data);
}


void MainWindow::on_pb_load_clicked()
{

}

