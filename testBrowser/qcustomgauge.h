#ifndef QCUSTOMGAUGE_H
#define QCUSTOMGAUGE_H

#include "qcgaugewidget.h"

class qCustomGauge
{
public:
    qCustomGauge();

    static void createSpeedGauge(QcGaugeWidget* qGauge, QcNeedleItem** qNeedle);

    static void createRPMgauge(QcGaugeWidget* qGauge, QcNeedleItem** qNeedle);

    static void createBatteryGauge(QcGaugeWidget* qGauge, QcNeedleItem** qNeedle);


};

#endif // QCUSTOMGAUGE_H
