
#include "sett.h"
#include "ui_sett.h"

//#include "cpu.cpp"
using namespace std;


/**
 * @brief Sett::Sett
 * @param parent
 */




Sett::Sett(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sett)
{
    ui->setupUi(this);

    ui->StorageLabel->setStyleSheet("QLabel{background: transparent;}");
    ui->CPUlabel->setStyleSheet("QLabel{background: transparent;}");
    ui->UserLabel->setStyleSheet("QLabel{background: transparent;}");

    ui->MemBtn->setStyleSheet("QPushButton{background: transparent;}");
    ui->CPUBtn->setStyleSheet("QPushButton{background: transparent;}");
    ui->UsrBtn->setStyleSheet("QPushButton{background: transparent;}");
    ui->BackMenu->setStyleSheet("QPushButton{background: transparent;}");

    connect(ui->MemBtn,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->CPUBtn,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->UsrBtn,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->BackMenu,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackMenu,SIGNAL(clicked()),this,SLOT(hide()));

    centerWindow();


}

Sett::~Sett()
{
    delete ui;
}

void Sett::centerWindow()
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-320) / 2;
    int y = (screenGeometry.height()-240) / 2;
    this->move(x, y);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->show();
}

void Sett::on_MemBtn_clicked()
{

    mem = new Memory(this);
    mem->show();
}

void Sett::on_CPUBtn_clicked()
{
    cpu = new CPU(this);
    cpu->show();
}

void Sett::on_UsrBtn_clicked()
{
    usr = new Usr(this);
    usr->show();
}


void Sett::on_BackMenu_clicked()
{

}
