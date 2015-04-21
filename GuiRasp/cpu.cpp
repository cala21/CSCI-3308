#include "cpu.h"
#include "ui_cpu.h"




/**
 * @brief CPU::CPU
 * @param parent
 */

float total_proc1,work_proc1,total_proc2,work_proc2,work_over_period,total_over_period,cpu_stat;

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


CPU::CPU(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CPU)
{
    ui->setupUi(this);
    ui->BackCPU->setStyleSheet("QPushButton{background: transparent;}");
    connect(ui->BackCPU,SIGNAL(clicked()),this->parent(),SLOT(show()));
    connect(ui->BackCPU,SIGNAL(clicked()),this,SLOT(on_BackCPU_clicked()));



    // Update cpu stats
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showStats()));
    timer->start(1200); //time specified in ms

    centerWindow();

}

CPU::~CPU()
{
    delete ui;
}


void CPU::centerWindow()
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-320) / 2;
    int y = (screenGeometry.height()-240) / 2;
    this->move(x, y);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->show();
}

void CPU::on_BackCPU_clicked()
{
    this->hide();
}


void CPU::showStats()
{

    QFile file("/proc/stat");
    QTextStream in(&file);
    if(!file.open(QIODevice::ReadOnly)) {

        QMessageBox::information(0, "error", file.errorString());
    }

    QString line = in.readLine();
    QStringList fields = line.split(' ');


    //Hard coded because information always stored in same position
    total_proc1 = fields[1].toFloat()+fields[2].toFloat()+fields[3].toFloat()+fields[4].toFloat()+fields[5].toFloat()+fields[6].toFloat()+fields[7].toFloat();
    work_proc1 = fields[1].toFloat()+fields[2].toFloat()+fields[3].toFloat();
    delay();
    in.seek(0);
    line = in.readLine();
    fields = line.split(' ');
    total_proc2 = fields[1].toFloat()+fields[2].toFloat()+fields[3].toFloat()+fields[4].toFloat()+fields[5].toFloat()+fields[6].toFloat()+fields[7].toFloat();
    work_proc2 = fields[1].toFloat()+fields[2].toFloat()+fields[3].toFloat();
    work_over_period = work_proc1 - work_proc2;
    total_over_period = total_proc1 - total_proc2;
    cpu_stat = work_over_period / (total_over_period+1) * 100;
    QString cpu_statString = QString::number(cpu_stat);

    ui->CPUStats->setText(cpu_statString+'%');
    ui->CPUStats->setContentsMargins(0,30,0,0);

    file.close();


}
