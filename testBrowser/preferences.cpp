#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);

    //serial port info
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            ui->comboBox->addItem(info.portName());
        }

    getIp = new QLineEdit(this);
    getPort = new QLineEdit(this);

    getIp->setVisible(false);  // show only the ui->lineEdit
    getPort->setVisible(false);

    connect(ui->lineEdit, SIGNAL(textChanged(QString)), getIp, SLOT(setText(QString)));
    connect(ui->lineEdit_Port, SIGNAL(textChanged(QString)), getPort, SLOT(setText(QString)));
}

Preferences::~Preferences()
{
    delete ui;
}

void Preferences::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->lineEdit->setText(arg1);
}

void Preferences::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_Port->setText(arg1);
}

void Preferences::on_comboBox_activated(const QString &arg1)
{
//
}
