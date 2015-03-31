#include "sett.h"
#include "ui_sett.h"

Sett::Sett(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sett)
{
    ui->setupUi(this);

    ui->Storage->setStyleSheet("QLabel{background: transparent;}");
    ui->Dt->setStyleSheet("QLabel{background: transparent;}");
    ui->User->setStyleSheet("QLabel{background: transparent;}");

    ui->MemBtn->setStyleSheet("QPushButton{background: transparent;}");
    ui->DateTimeBtn->setStyleSheet("QPushButton{background: transparent;}");
    ui->UsrBtn->setStyleSheet("QPushButton{background: transparent;}");
    ui->BackMenu->setStyleSheet("QPushButton{background: transparent;}");

    connect(ui->MemBtn,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->DateTimeBtn,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->UsrBtn,SIGNAL(clicked()),this,SLOT(hide()));


    connect(ui->BackMenu,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackMenu,SIGNAL(clicked()),this,SLOT(hide()));
}

Sett::~Sett()
{
    delete ui;
}

void Sett::on_MemBtn_clicked()
{

    mem = new Memory(this);
    mem->show();
}

void Sett::on_DateTimeBtn_clicked()
{
    Dt = new DateTime(this);
    Dt->show();

}

void Sett::on_UsrBtn_clicked()
{
    usr = new Usr(this);
    usr->show();
}

void Sett::on_BackMenu_clicked()
{

}
