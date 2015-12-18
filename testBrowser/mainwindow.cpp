#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //needle = new QcNeedleItem(this);

    needle = createGauge(ui->gauge);

    needle1 = createGauge(ui->battery);

    needle2 = createGauge(ui->rotation);

//    needle->setCurrentValue(50);

   // createGauge(ui->battery, needle1 );

//    QcBackgroundItem *bkg0 = ui->gauge->addBackground(97);
//    bkg0->clearrColors();
//    bkg0->addColor(0.1, 0x2EFEF7);  //0x58ACFA
//    bkg0->addColor(0.5, 0x58ACFA);
//    bkg0->addColor(0.9, 0x2EFEF7);

//    QcBackgroundItem *bkg1 = ui->gauge->addBackground(92);
//    bkg1->clearrColors();
//    bkg1->addColor(0.1,0x0B0B3B);


//    QcBackgroundItem *bkg2 = ui->gauge->addBackground(15);
//    bkg2->clearrColors();
//    bkg2->addColor(0.1,0x0B173B);
//    //bkg2->addColor(1.0,Qt::white);

//    values = ui->gauge->addValues(70);
//    values->setColor(Qt::white);
//    values->setStep(20);
//    values->setValueRange(0,160);

//    primaryDegrees = ui->gauge->addDegrees(89);
//    primaryDegrees->setColor(Qt::white);
//    primaryDegrees->setValueRange(0,160);
//    primaryDegrees->setStep(20);

//    degrees = ui->gauge->addDegrees(91);
//    degrees->setValueRange(0,160);
//    degrees->setSubDegree(true);
//    degrees->setStep(5);
//    degrees->setColor(Qt::white);

//    secondValues = ui->gauge->addValues(36);
//    secondValues->setColor(Qt::white);
//    secondValues->setStep(20);
//    secondValues->setValueRange(0,260);

//    secondDegrees = ui->gauge->addDegrees(50);
//    secondDegrees->setColor(Qt::white);
//    secondDegrees->setValueRange(0,260);
//    secondDegrees->setStep(20);

//    subSecondDegrees = ui->gauge->addDegrees(51);
//    subSecondDegrees->setValueRange(0,260);
//    subSecondDegrees->setSubDegree(true);
//    subSecondDegrees->setStep(10);
//    subSecondDegrees->setColor(Qt::white);

//    ui->gauge->addArc(87)->setColor(0xA9E2F3);

//    needle = ui->gauge->addNeedle(85);
//    needle->setColor(Qt::white);

   // colBand = ui->gauge->addColorBand(87);
   // colBand->setMinDegree(145);
   // colBand->setMinValue(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QcNeedleItem* MainWindow::createGauge(QcGaugeWidget *qGauge)
{
    QcBackgroundItem *bkg0 = qGauge->addBackground(97);
    bkg0->clearrColors();
    bkg0->addColor(0.1, 0x2EFEF7);  //0x58ACFA
    bkg0->addColor(0.5, 0x58ACFA);
    bkg0->addColor(0.9, 0x2EFEF7);

    QcBackgroundItem *bkg1 = qGauge->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,0x0B0B3B);


    QcBackgroundItem *bkg2 = qGauge->addBackground(15);
    bkg2->clearrColors();
    bkg2->addColor(0.1,0x0B173B);
    //bkg2->addColor(1.0,Qt::white);

    QcValuesItem* values = qGauge->addValues(70);
    values->setColor(Qt::white);
    values->setStep(20);
    values->setValueRange(0,160);

    QcDegreesItem* primaryDegrees = qGauge->addDegrees(89);
    primaryDegrees->setColor(Qt::white);
    primaryDegrees->setValueRange(0,160);
    primaryDegrees->setStep(20);

    QcDegreesItem* degrees = qGauge->addDegrees(91);
    degrees->setValueRange(0,160);
    degrees->setSubDegree(true);
    degrees->setStep(5);
    degrees->setColor(Qt::white);

    QcValuesItem* secondValues = qGauge->addValues(36);
    secondValues->setColor(Qt::white);
    secondValues->setStep(20);
    secondValues->setValueRange(0,260);

   QcDegreesItem* secondDegrees = qGauge->addDegrees(50);
    secondDegrees->setColor(Qt::white);
    secondDegrees->setValueRange(0,260);
    secondDegrees->setStep(20);

   QcDegreesItem* subSecondDegrees = qGauge->addDegrees(51);
    subSecondDegrees->setValueRange(0,260);
    subSecondDegrees->setSubDegree(true);
    subSecondDegrees->setStep(10);
    subSecondDegrees->setColor(Qt::white);

    qGauge->addArc(87)->setColor(0xA9E2F3);

    QcNeedleItem* qNeedle = qGauge->addNeedle(85);
    qNeedle->setColor(Qt::white);

    return qNeedle;

}

void MainWindow::on_dial_valueChanged(int value)
{
    needle->setCurrentValue(value);
    needle1->setCurrentValue(value);
    needle2->setCurrentValue(value);
}