/**
 * \class Sett
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
 * \author  $Author: Camilla Lambrocco $
 *
 * \version $Revision: 1.1 $
 *
 * \date $Date: 4/12/2015 $
 *
 *
 */

#ifndef SETT_H
#define SETT_H

#include <QDialog>
#include <QDesktopWidget>
#include <QRect>
#include <iostream>
#include <QStringList>
#include "usr.h"
#include "cpu.h"
#include "memory.h"



namespace Ui {
class Sett;
}

class Sett : public QDialog
{
    Q_OBJECT

public:
    explicit Sett(QWidget *parent = 0);
    ~Sett();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void centerWindow();

private slots:

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void on_MemBtn_clicked();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void on_CPUBtn_clicked();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void on_UsrBtn_clicked();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void on_BackMenu_clicked();

private:
    Ui::Sett *ui;
    Memory *mem;
    Usr *usr;
    CPU *cpu;
};

#endif // SETT_H
