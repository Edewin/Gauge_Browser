#ifndef ABOUTELECTROMOBILITY_H
#define ABOUTELECTROMOBILITY_H

#include <QDialog>

namespace Ui {
class AboutElectromobility;
}

class AboutElectromobility : public QDialog
{
    Q_OBJECT

public:
    explicit AboutElectromobility(QWidget *parent = 0);
    ~AboutElectromobility();

private:
    Ui::AboutElectromobility *ui;
};

#endif // ABOUTELECTROMOBILITY_H
