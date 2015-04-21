#include "memory.h"
#include "ui_memory.h"
#include <boost/any.hpp>
#include <qcombobox.h>
#include <boost/filesystem.hpp>
#include <boost/operators.hpp>
#include <iostream>
using namespace boost::filesystem;
using namespace std;

/**
 * @brief Memory::Memory
 * @param parent
 */

QString *comboHelper(string myPath)
{
    path volumePath (myPath);
    space_info volumeSpace = space(volumePath);
    quint64 FreeStorage = volumeSpace.available;
    quint64 TotalStorage = volumeSpace.capacity;
    QString *storage = new QString[2];
    storage[0] = QString::number(FreeStorage/ 1073741824) + " GiB";
    storage[1] = QString::number(TotalStorage / 1073741824) + " GiB";
    return storage;
}

Memory::Memory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Memory)
{
    ui->setupUi(this);
    connect(ui->BackMem,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackMem,SIGNAL(clicked()),this,SLOT(hide()));


    ui->volumeComboBox->addItem("home");
    ui->volumeComboBox->addItem("RAID");
    ui->BackMem->setStyleSheet("QPushButton{background: transparent;}");
    ui->refreshButton->setStyleSheet("QPushButton{background: white;}");
    connect(ui->volumeComboBox,SIGNAL(currentIndexChanged(QString)),this ,SLOT(update()));
    connect(ui->refreshButton, SIGNAL(clicked()), this,SLOT(refresh()));


    centerWindow();
    refresh();
    update();

}


Memory::~Memory()
{
    delete ui;
}

void Memory::centerWindow()
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-320) / 2;
    int y = (screenGeometry.height()-240) / 2;
    this->move(x, y);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->show();
}


void Memory::refresh()
{
    ui->volumeComboBox->setCurrentIndex(0);
    ui->rootPathLabel->setText("/home");
    ui->bytesAvailableLabel->setText(comboHelper("/home")[0]);
    ui->totalStorageLabel->setText(comboHelper("/home")[1]);

}


void Memory::update()
{

    ui->deviceLabel->setText(ui->volumeComboBox->currentText());
    if (ui->volumeComboBox->currentText() == "home")
    {
        ui->rootPathLabel->setText("/home");
        ui->bytesAvailableLabel->setText(comboHelper("/home")[0]);
        ui->totalStorageLabel->setText(comboHelper("/home")[1]);
    }

    if (ui->volumeComboBox->currentText() == "RAID")
    {
        ui->rootPathLabel->setText("/var/www/RAID");
        ui->bytesAvailableLabel->setText(comboHelper("/var/www/RAID")[0]);
        ui->totalStorageLabel->setText(comboHelper("/var/www/RAID")[1]);
    }


  }

