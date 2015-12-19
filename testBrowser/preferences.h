#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QLineEdit>
#include <QDoubleSpinBox>

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = 0);
    ~Preferences();

    QLineEdit* editMe;

private:
    Ui::Preferences *ui;

    QDoubleSpinBox* doubleSpin;


};

#endif // PREFERENCES_H
