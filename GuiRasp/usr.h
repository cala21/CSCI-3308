#ifndef USR_H
#define USR_H

#include <QDialog>

namespace Ui {
class Usr;
}

class Usr : public QDialog
{
    Q_OBJECT

public:
    explicit Usr(QWidget *parent = 0);
    ~Usr();

private:
    Ui::Usr *ui;
};

#endif // USR_H
