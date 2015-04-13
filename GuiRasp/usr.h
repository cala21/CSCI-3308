/**
 * \class Usr
 *
 *
 * \brief Provide an example
 *
 * This class is meant as an example.  It is not useful by itself
 * rather its usefulness is only a function of how much it helps
 * the reader.  It is in a sense defined by the person who reads it
 * and otherwise does not exist in any real form.
 *
 * \note Attempts at zen rarely work.
 *
 * \author Camilla Lambrocco
 *
 * \version 1.1
 *
 * \date 4/12/2015
 *
 *
 */

#ifndef USR_H
#define USR_H

#include <QDialog>
#include <QDesktopWidget>

namespace Ui {
class Usr;
}

class Usr : public QDialog
{
    Q_OBJECT

public:
    explicit Usr(QWidget *parent = 0);
    ~Usr();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void centerWindow();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void findUsers();


private:
    Ui::Usr *ui;
};

#endif // USR_H
