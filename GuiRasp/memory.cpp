#include "memory.h"
#include "ui_memory.h"

Memory::Memory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Memory)
{
    ui->setupUi(this);
    connect(ui->BackMem,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackMem,SIGNAL(clicked()),this,SLOT(hide()));

    ui->BackMem->setStyleSheet("QPushButton{background: transparent;}");
}

Memory::~Memory()
{
    delete ui;
}
