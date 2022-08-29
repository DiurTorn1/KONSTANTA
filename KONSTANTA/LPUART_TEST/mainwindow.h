#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connect_button_clicked();

    void serialPort_readyRead();
    void on_pb_get_clicked();

    void on_pb_load_clicked();

    void on_pb_loadPort_clicked();

    void on_pb_loadAmp_clicked();

    void on_pb_loadAdc_clicked();

    void on_pb_loadMath_clicked();

    void on_pb_loadOPAHSM_clicked();

    void on_pb_loadOffset_clicked();

    void on_pb_loadPGA_clicked();

    void on_pb_loadRef_clicked();

    void on_pb_loadDac_clicked();

signals:
    void serialDataSend(const QByteArray data);
public slots:
    void handleResults(QByteArray result);
private:
    void InitSerialPortName();
    QString ByteArrayToHexString(QByteArray data);
    QByteArray HexStringTyByteArray(QString HexString);
    int cmd, len_cmd = 0;
    quint8 *data;


private:
    Ui::MainWindow *ui;
    QSerialPort serial_1;
    QThread serialThread_1;
};
#endif // MAINWINDOW_H
