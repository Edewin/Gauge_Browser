#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcgaugewidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

#include "qcustomgauge.h"

#include "aboutelectromobility.h"
#include "aboutteamevo.h"
#include "preferences.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void update();     // timer handler

    void on_dial_valueChanged(int value);

    void on_actionQuit_triggered();

    void on_actionAbout_ElectroMobility_triggered();

    void on_toolBox_currentChanged(int index);

    void on_actionAbout_TeamEVO_triggered();

    void on_pushButton_TestDirection_clicked();

    void on_pushButton_TestMotor_clicked();

    void on_dial_Battery_valueChanged(int value);

    void on_dial_Speed_valueChanged(int value);

    void on_actionPreferences_triggered();

    void on_actionConnect_triggered();

    void on_actionDisconnect_triggered();

    void on_pushButton_STOP_clicked();

    void on_pushButton_Start_clicked();

private:
    Ui::MainWindow *ui;

    QTimer* timer;
    QTime* elapsedTime;

    bool flag;

    QcNeedleItem* needle;
    QcNeedleItem* needle1;
    QcNeedleItem* needle2;

};

#endif // MAINWINDOW_H
