#include "usr.h"
#include "ui_usr.h"

Usr::Usr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usr)
{
    ui->setupUi(this);
    connect(ui->BackUsr,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackUsr,SIGNAL(clicked()),this,SLOT(hide()));

    ui->BackUsr->setStyleSheet("QPushButton{background: transparent;}");
}

Usr::~Usr()
{
    delete ui;
}
