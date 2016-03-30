#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = 0);
    ~Preferences();

    QLineEdit* getIp;
    QLineEdit* getPort;

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Preferences *ui;

    QDoubleSpinBox* doubleSpin;
};

#endif // PREFERENCES_H
