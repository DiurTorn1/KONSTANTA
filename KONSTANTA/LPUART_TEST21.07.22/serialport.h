#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class SerialPort : public QThread
{
public:
    explicit SerialPort(QString comPort);
    ~SerialPort();

    void run();

private slots:
    void serialReceive();

private:
    QString portName;
    QSerialPort *serial;
};

#endif // SERIALPORT_H
