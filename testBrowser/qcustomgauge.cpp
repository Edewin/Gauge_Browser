#include "qcustomgauge.h"

qCustomGauge::qCustomGauge()
{

}

void qCustomGauge::createSpeedGauge(QcGaugeWidget *qGauge, QcNeedleItem **qNeedle)
{
    QcBackgroundItem *bkg0 = qGauge->addBackground(97);
    bkg0->clearrColors();
    bkg0->addColor(0.1, 0x2EFEF7);  //0x58ACFA
    bkg0->addColor(0.5, 0x58ACFA);
    bkg0->addColor(0.9, 0x2EFEF7);

    QcBackgroundItem *bkg1 = qGauge->addBackground(92);
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

    QcValuesItem* values = qGauge->addValues(63);
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

    QcLabelItem* label = qGauge->addLabel(73);
    label->setColor(Qt::white);
    label->setText("km/h");

  /*  QcValuesItem* secondValues = qGauge->addValues(36);
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
    subSecondDegrees->setColor(Qt::white);*/

    qGauge->addArc(87)->setColor(0xA9E2F3);

    *qNeedle = qGauge->addNeedle(85);

    (*qNeedle)->setColor(Qt::white);
}

void qCustomGauge::createRPMgauge(QcGaugeWidget *qGauge, QcNeedleItem **qNeedle)
{
    QcBackgroundItem *bkg0 = qGauge->addBackground(97);
    bkg0->clearrColors();
    bkg0->addColor(0.1, 0x2EFEF7);  //0x58ACFA
    bkg0->addColor(0.5, 0x58ACFA);
    bkg0->addColor(0.9, 0x2EFEF7);

    QcBackgroundItem *bkg1 = qGauge->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,0x0B0B3B);

    QcBackgroundItem *bkg2 = qGauge->addBackground(17);
    bkg2->clearrColors();
    bkg2->addColor(0.1, 0x2EFEF7);  //0x58ACFA
    bkg2->addColor(0.5, 0x58ACFA);
    bkg2->addColor(0.9, 0x2EFEF7);


    QcColorBand* color = qGauge->addColorBand(89);
    color->setMinDegree(145);

    QcBackgroundItem *bkg3 = qGauge->addBackground(15);
    bkg3->clearrColors();
    bkg3->addColor(0.1,0x0B173B);
    //bkg3->addColor(1.0,Qt::white);

    QcValuesItem* values = qGauge->addValues(63);
    values->setColor(Qt::white);
    values->setStep(1);
    values->setValueRange(0,8);

    QcDegreesItem* primaryDegrees = qGauge->addDegrees(89);
    primaryDegrees->setColor(Qt::white);
    primaryDegrees->setValueRange(0,8);
    primaryDegrees->setStep(0.5);

    QcDegreesItem* degrees = qGauge->addDegrees(91);
    degrees->setValueRange(0,8);
    degrees->setSubDegree(true);
    degrees->setStep(0.5);
    degrees->setColor(Qt::white);

    QcLabelItem* label = qGauge->addLabel(73);
    label->setColor(Qt::white);
    label->setText("x 1000 RPM");


   /* QList<QPair<QColor,float> > mBandColors;
    QColor tmpColor;
    tmpColor.setAlphaF(0.1);
    QPair<QColor,float> pair;

    pair.first = Qt::red;
    pair.second = 20;
    mBandColors.append(pair);



    color->setColors(mBandColors);
*/
    qGauge->addArc(87)->setColor(0xA9E2F3);

    *qNeedle = qGauge->addNeedle(85);

    (*qNeedle)->setColor(Qt::white);


}

void qCustomGauge::createBatteryGauge(QcGaugeWidget *qGauge, QcNeedleItem **qNeedle)
{
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
    pair.second = 80;
    mBandColors.append(pair);

    pair.first = Qt::darkGreen;
    pair.second = 100;
    mBandColors.append(pair);

    color->setColors(mBandColors);

    QcLabelItem* label = qGauge->addLabel(25);
    label->setText("Battery Level");
    label->setColor(Qt::white);

    *qNeedle = qGauge->addNeedle(65);

    (*qNeedle)->setColor(Qt::white);
    (*qNeedle)->setMaxDegree(145);
    (*qNeedle)->setMinDegree(45);
}

