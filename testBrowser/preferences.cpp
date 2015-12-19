#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);

    editMe = new QLineEdit(this);

    editMe->setVisible(false);  // show only the ui->lineEdit

    connect(ui->lineEdit, SIGNAL(textChanged(QString)), editMe, SLOT(setText(QString)));
}

Preferences::~Preferences()
{
    delete ui;
}
