#include "datetime.h"
#include "ui_datetime.h"

DateTime::DateTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateTime)
{
    ui->setupUi(this);
    connect(ui->BackDt,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackDt,SIGNAL(clicked()),this,SLOT(hide()));

    ui->BackDt->setStyleSheet("QPushButton{background: transparent;}");
}

DateTime::~DateTime()
{
    delete ui;
}

void DateTime::on_BackDt_clicked()
{

}
