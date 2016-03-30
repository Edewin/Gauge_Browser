#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer = new QTimer(this);
    elapsedTime = new QTime();

    /*************Serial Port***************/

    serial = new QSerialPort(this);

    /**************************************/

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));


    qCustomGauge::createSpeedGauge(ui->gauge, &needle);


    qCustomGauge::createBatteryGauge(ui->battery, &needle1);


    qCustomGauge::createRPMgauge(ui->rotation, &needle2);
}

MainWindow::~MainWindow()
{
    if(serial->isOpen())
    {
        serial->close();
    }
    delete ui;
}

void MainWindow::update()   // timer handler
{
    ui->lcdNumber_Time->display( elapsedTime->elapsed() );

    if(needle->currentValue() > 99 )
    {
        needle->setCurrentValue( 0 );
    }


     needle->setCurrentValue( (needle->currentValue()) + 0.2 );

     needle1->setCurrentValue( (needle1->currentValue()) - 0.1  );

    flag = false;
     if(needle2->currentValue() > 70)
     {
        flag = true;
        //needle2->setCurrentValue(0);
     }

     if(flag == true)
     {
         needle2->setCurrentValue((needle2->currentValue()) - 50.0);
     }

     if(flag == false)
     {
         needle2->setCurrentValue((needle2->currentValue()) + 0.6);
     }
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

    buf = "Selected mode is now: " + buf;
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

void MainWindow::on_actionPreferences_triggered()
{
 //   Preferences pref(this);

    Preferences *pref = new Preferences(this);
    if(pref->exec())
    {
        SerialPort = pref->getIp->text();
        SerialBaudRate = pref->getPort->text();

        QString str = pref->getIp->text() + " : " + pref->getPort->text();
        qDebug() << str;

        ui->actionConnect->setEnabled(true);
    }
    delete pref;
}

void MainWindow::on_actionConnect_triggered()
{
    serial->setPortName(SerialPort);

    if(SerialBaudRate == "115200")
    {
        serial->setBaudRate(QSerialPort::Baud115200);
        qDebug()<< "115200 baudrate";
    }
    else
    {
        serial->setBaudRate(QSerialPort::Baud9600);
        qDebug()<< "9600 baudrate";
    }

    serial->open(QSerialPort::ReadWrite);

    if(serial->isOpen())
    {
        ui->pushButton_Start->setEnabled(true);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);

        QMessageBox msg;
        msg.setText("<b><c>Connected</c></b>  ");
        msg.setWindowTitle("Conection Status...   ");
        msg.exec();
    }
    else
    {
        QMessageBox msg;
        msg.setText("<b><c>Cannot Connect...Try again...</c></b>  ");
        msg.setWindowTitle("Conection Status...   ");
        msg.exec();
    }


    needle1->setCurrentValue(100);  // baterry level
}

void MainWindow::on_actionDisconnect_triggered()
{
    if(serial->isOpen())
    {
        serial->close();
        qDebug()<<"serial closed...";
    }
    ui->actionDisconnect->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->pushButton_Start->setEnabled(false);

    needle1->setCurrentValue(0);    // baterry level
}

void MainWindow::on_pushButton_STOP_clicked()
{
    ui->pushButton_Start->setEnabled(true);
    ui->pushButton_STOP->setEnabled(false);

    timer->stop();
    elapsedTime->restart();

    needle->setCurrentValue(0);
    needle1->setCurrentValue(0);
    needle2->setCurrentValue(0);

    ui->label_WheelStatus->setText("Stopped");
}

void MainWindow::on_pushButton_Start_clicked()
{
    ui->pushButton_Start->setEnabled(false);
    ui->pushButton_STOP->setEnabled(true);

    needle1->setCurrentValue(100);  // baterry level

    timer->start(10);
    elapsedTime->start();

    ui->label_WheelStatus->setText("Forward");
}
