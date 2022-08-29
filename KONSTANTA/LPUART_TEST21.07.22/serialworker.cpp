#include "serialworker.h"
#include <QDebug>
#include <QThread>

SerialWorker::SerialWorker(QSerialPort *ser, QObject *parent) : QObject(parent), serial(ser)
{

}

void SerialWorker::doDataSendWork(const QByteArray data){
    qDebug() << "Subline slot function sends data:" << data << "Thread ID:" << QThread::currentThreadId();
    serial->write(data);
}

void SerialWorker::doDataReceiveWork(){
    QByteArray buffer = serial->readAll();

    QString resultStr = buffer;
    qDebug() << "Sub thread received data:" << resultStr << "Thread ID:" << QThread::currentThreadId();

    emit sendResultToGui(buffer);
}
