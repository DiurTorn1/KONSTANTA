#include "serialport.h"
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>

SerialPort::SerialPort(QString portName) : portName(portName)
{

}

SerialPort::~SerialPort(){
    serial->close();
    delete serial;
}

void SerialPort::run(){
    serial = new QSerialPort(this);
    serial->setPortName("com10");
    serial->setBaudRate(209700);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open((QIODevice::ReadWrite));
    serial->write("2");
    connect(serial, SIGNAL(readyRead()), this, SLOT(serialReceive()));
}

void SerialPort::serialReceive(){
    QByteArray ba;
    ba = serial->readAll();
    qDebug() << ba.toHex();
}
