#include "aboutelectromobility.h"
#include "ui_aboutelectromobility.h"

AboutElectromobility::AboutElectromobility(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutElectromobility)
{
    ui->setupUi(this);
}

AboutElectromobility::~AboutElectromobility()
{
    delete ui;
}
