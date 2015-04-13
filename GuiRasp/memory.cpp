#include "memory.h"
#include "ui_memory.h"

#include <iostream>
using namespace std;

/**
 * @brief Memory::Memory
 * @param parent
 */

Memory::Memory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Memory)
{
    ui->setupUi(this);
    connect(ui->BackMem,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackMem,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->refreshButton, &QPushButton::clicked, this, &Memory::refresh);
    connect(ui->volumeComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Memory::update);

    ui->BackMem->setStyleSheet("QPushButton{background: transparent;}");
    ui->refreshButton->setStyleSheet("QPushButton{background: white;}");
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
    ui->volumeComboBox->clear();
    QStorageInfo volume;
    int numberOfVolumes = QStorageInfo::mountedVolumes().size();

    for (int i = 0; i<numberOfVolumes; i++) {
        // Store the path as data value for the combobox.
        volume = QStorageInfo::mountedVolumes()[i];
        ui->volumeComboBox->addItem(volume.displayName(), QVariant(volume.rootPath()));
    }
}


void Memory::update()
{
    QStorageInfo volume;
    // The path is stored in the data value of the combobox.
    volume.setPath(ui->volumeComboBox->currentData().toString());

    if (volume.isValid())
    {
        ui->deviceLabel->setText(volume.device());
        ui->rootPathLabel->setText(volume.rootPath());
        ui->typeLabel->setText(volume.fileSystemType());
        ui->bytesAvailableLabel->setText(QString::number(volume.bytesAvailable() / 1073741824) + tr(" GiB"));
    }

    else
    {
        ui->deviceLabel->setText(tr("invalid"));
        ui->rootPathLabel->setText(tr("invalid"));
        ui->typeLabel->setText(tr("invalid"));
        ui->bytesAvailableLabel->setText(tr("invalid"));
    }
}
