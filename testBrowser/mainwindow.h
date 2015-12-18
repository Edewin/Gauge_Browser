#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcgaugewidget.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    QcNeedleItem* createGauge(QcGaugeWidget* qGauge);

private slots:
    void on_dial_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    QcGaugeWidget* gauge;
    QcNeedleItem* needle;
    QcNeedleItem* needle1;
    QcNeedleItem* needle2;
    QcColorBand* colBand;
   /* QcDegreesItem* degrees;
    QcDegreesItem* primaryDegrees;
    QcDegreesItem* secondDegrees;
    QcDegreesItem* subSecondDegrees;
    QcValuesItem* values;
    QcValuesItem* secondValues;*/
};

#endif // MAINWINDOW_H
