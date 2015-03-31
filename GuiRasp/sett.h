#ifndef SETT_H
#define SETT_H

#include <QDialog>
#include "usr.h"
#include "datetime.h"
#include "memory.h"

namespace Ui {
class Sett;
}

class Sett : public QDialog
{
    Q_OBJECT

public:
    explicit Sett(QWidget *parent = 0);
    ~Sett();

private slots:
    void on_MemBtn_clicked();

    void on_DateTimeBtn_clicked();

    void on_UsrBtn_clicked();

    void on_BackMenu_clicked();

private:
    Ui::Sett *ui;
    Memory *mem;
    Usr *usr;
    DateTime *Dt;
};

#endif // SETT_H
