#include "mainwindow.h"
#include "ui_mainwindow.h"


/**
 * @brief MainWindow::MainWindow
 * @param parent
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->centralWidget->setStyleSheet("background-image: url(:/Images/BuffLogo.png)");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(hide()));

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    QDate date = QDate::currentDate();
    QString dateString = date.toString();
    ui->dtLab->setText(dateString);

    centerWindow();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::centerWindow()
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-320) / 2;
    int y = (screenGeometry.height()-240) / 2;
    this->move(x, y);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->show();
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString timeString = time.toString("hh:mm");
    ui->tLab->setText(timeString);
}



void MainWindow::on_pushButton_clicked()
{
    setStyleSheet("background-image: url(:/Images/BuffLogo3.png)");
    sett = new Sett(this);
    sett->show();
}
