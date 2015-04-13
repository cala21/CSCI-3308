/**
 * \class MainWindow
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QBasicTimer>
#include <QDesktopWidget>
#include "sett.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
    void on_pushButton_clicked();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void showTime();

private:
    Ui::MainWindow *ui;
    Sett *sett;
};

#endif // MAINWINDOW_H
