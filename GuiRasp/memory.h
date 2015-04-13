/**
 * \class Memory
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

#ifndef MEMORY_H
#define MEMORY_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QDesktopWidget>
#include <QStorageInfo>
#include <QDebug>

namespace Ui {
class Memory;
}

class Memory : public QDialog
{
    Q_OBJECT

public:
    explicit Memory(QWidget *parent = 0);
    ~Memory();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void update();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void refresh();

    /** @brief Writes the current foreground and background
     *         color of characters printed on the console
     *         into the argument color.
     *  @return Void.
     */
    void centerWindow();

private slots:

private:
    Ui::Memory *ui;
};

#endif // MEMORY_H
