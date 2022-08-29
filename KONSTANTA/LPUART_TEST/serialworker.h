#ifndef SERIALWORKER_H
#define SERIALWORKER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class SerialWorker : public QObject
{
    Q_OBJECT
public:
    explicit SerialWorker(QSerialPort *ser, QObject *parent = nullptr);

signals:
    void sendResultToGui(QByteArray result);
public slots:
    void doDataSendWork(const QByteArray data);
    void doDataReceiveWork();
private:
    QSerialPort *serial;
};

#endif // SERIALWORKER_H
