#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //needle = new QcNeedleItem(this);

   // createGauge(ui->gauge, &needle);

    qCustomGauge::createSpeedGauge(ui->gauge, &needle);

    //createGauge(ui->battery, &needle1);

    qCustomGauge::createBatteryGauge(ui->battery, &needle1);

//    createGauge(ui->rotation, &needle2);

    qCustomGauge::createRPMgauge(ui->rotation, &needle2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGauge(QcGaugeWidget *qGauge, QcNeedleItem **qNeedle)
{
   /* QcBackgroundItem *bkg0 = qGauge->addBackground(65);
    bkg0->clearrColors();
    bkg0->addColor(0.1, 0x2EFEF7);  //0x58ACFA
    bkg0->addColor(0.5, 0x58ACFA);
    bkg0->addColor(0.9, 0x2EFEF7);


    QcBackgroundItem *bkg1 = qGauge->addBackground(63);
    bkg1->clearrColors();
    bkg1->addColor(0.1,0x0B0B3B);

    QcBackgroundItem *bkg2 = qGauge->addBackground(17);
    bkg2->clearrColors();
    bkg2->addColor(0.1, 0x2EFEF7);  //0x58ACFA
    bkg2->addColor(0.5, 0x58ACFA);
    bkg2->addColor(0.9, 0x2EFEF7);

    QcBackgroundItem *bkg3 = qGauge->addBackground(15);
    bkg3->clearrColors();
    bkg3->addColor(0.1,0x0B173B);
    //bkg3->addColor(1.0,Qt::white);

*/
    QcDegreesItem* primaryDegrees = qGauge->addDegrees(63);
    primaryDegrees->setColor(Qt::white);
    primaryDegrees->setMinDegree(45);
    primaryDegrees->setMaxDegree(140);
    primaryDegrees->setValueRange(0,8);
    primaryDegrees->setStep(1);



    QcColorBand* color = qGauge->addColorBand(62);
    color->setMaxDegree(145);
    color->setMinDegree(45);

    QList<QPair<QColor,float> > mBandColors;
    QColor tmpColor;
    tmpColor.setAlphaF(0.1);
    QPair<QColor,float> pair;

    pair.first = Qt::red;
    pair.second = 20;
    mBandColors.append(pair);


    pair.first = Qt::green;
    pair.second = 100;
    mBandColors.append(pair);

    color->setColors(mBandColors);

    //qGauge->addArc()->setColor(0xA9E2F3);

    *qNeedle = qGauge->addNeedle(65);

    (*qNeedle)->setColor(Qt::white);
    (*qNeedle)->setMaxDegree(145);
    (*qNeedle)->setMinDegree(45);

    //return qNeedle;

}

void MainWindow::on_dial_valueChanged(int value)
{
    needle->setCurrentValue(value);
    needle1->setCurrentValue(value);
    needle2->setCurrentValue(value/2);
}
