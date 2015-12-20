#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);

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
