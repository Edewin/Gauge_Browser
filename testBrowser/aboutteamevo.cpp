#include "aboutteamevo.h"
#include "ui_aboutteamevo.h"

AboutTeamEVO::AboutTeamEVO(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutTeamEVO)
{
    ui->setupUi(this);
}

AboutTeamEVO::~AboutTeamEVO()
{
    delete ui;
}
