#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    qCustomGauge::createSpeedGauge(ui->gauge, &needle);


    qCustomGauge::createBatteryGauge(ui->battery, &needle1);


    qCustomGauge::createRPMgauge(ui->rotation, &needle2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_valueChanged(int value)
{
    needle2->setCurrentValue(value);
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_ElectroMobility_triggered()
{
    AboutElectromobility infoElectroMobility;
    infoElectroMobility.setModal(true);
    infoElectroMobility.exec();
}

void MainWindow::on_toolBox_currentChanged(int index)
{
    QMessageBox msg;
    QString buf;

    switch (index) {
    case 0:
        buf = "<b>Autonomous Mode</b>";
        break;
    case 1:
        buf = "<b>Manual Mode</b>";
        break;
    default:
        buf = "<b>Test Mode</b>";
        break;
    }

    buf = "Selected mode is: " + buf;
    msg.setText(buf);
    msg.setWindowTitle("Selected mode changed");
    msg.exec();
}

void MainWindow::on_actionAbout_TeamEVO_triggered()
{
    AboutTeamEVO infoEVO;
    infoEVO.setModal(true);
    infoEVO.exec();
}

void MainWindow::on_pushButton_TestDirection_clicked()
{
    QMessageBox msg;
    msg.setText("Direction is under test. Please wait");
    msg.setWindowTitle("Test Direction");
    msg.exec();
}

void MainWindow::on_pushButton_TestMotor_clicked()
{
    QMessageBox msg;
    msg.setText("Motor is under test. Please wait");
    msg.setWindowTitle("Test Motor");
    msg.exec();
}

void MainWindow::on_dial_Battery_valueChanged(int value)
{
    needle1->setCurrentValue(value);
}

void MainWindow::on_dial_Speed_valueChanged(int value)
{
    needle->setCurrentValue(value);
}
