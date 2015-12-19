#ifndef ABOUTTEAMEVO_H
#define ABOUTTEAMEVO_H

#include <QDialog>

namespace Ui {
class AboutTeamEVO;
}

class AboutTeamEVO : public QDialog
{
    Q_OBJECT

public:
    explicit AboutTeamEVO(QWidget *parent = 0);
    ~AboutTeamEVO();

private:
    Ui::AboutTeamEVO *ui;
};

#endif // ABOUTTEAMEVO_H
