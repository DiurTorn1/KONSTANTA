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

    void on_btn_send_clicked();

    void on_btn_clearSend_clicked();

    void serialPort_readyRead();
    void on_pb_get_clicked();

    void on_pb_load_clicked();

signals:
    void serialDataSend(const QByteArray data);
public slots:
    void handleResults(QByteArray result);
private:
    void InitSerialPortName();
    QString ByteArrayToHexString(QByteArray data);
    QByteArray HexStringTyByteArray(QString HexString);
    int cmd, len_cmd = 0;


private:
    Ui::MainWindow *ui;
    QSerialPort serial_1;
    QThread serialThread_1;
};
#endif // MAINWINDOW_H
