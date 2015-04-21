#include "usr.h"
#include "ui_usr.h"
#include <QProcess>
#include <QScrollArea>


/**
 * @brief Usr::Usr
 * @param parent
 */

Usr::Usr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usr)
{
    ui->setupUi(this);
    ui->BackUsr->setStyleSheet("QPushButton{background: transparent;}");
    connect(ui->BackUsr,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackUsr,SIGNAL(clicked()),this,SLOT(hide()));

    findUsers();
    centerWindow();
}

Usr::~Usr()
{
    delete ui;
}

void Usr::centerWindow()
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-320) / 2;
    int y = (screenGeometry.height()-240) / 2;
    this->move(x, y);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->show();
}

void Usr::findUsers()
{
    QProcess *process = new QProcess;
    process->start("bash", QStringList() << "-c" << "cat /etc/passwd | grep /home |cut -d: -f1");
    process->waitForBytesWritten();
    process->waitForFinished();
    QString found_users = process->readAll();

    QFont myFont( "Purisa", 12, QFont::Bold);
    QLabel *labelUsers = new QLabel;
    labelUsers->setText(found_users);
    labelUsers->setFont(myFont);
    labelUsers->setContentsMargins(5,40,0,0);
    ui->scrollUsers->setWidget(labelUsers);

}
