#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QSysInfo>  //get info about OS
 #include <QLocale> //get info locale

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using counter_t = unsigned int;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /* EX8 */
    void setStartUpLocaleEX8();

private slots:
    /* Ex2 */
    void on_checkValue_clicked();

    /* Ex4 */
    void on_checkAnswer_b_clicked();

    /* Ex7 */
    void on_checkInfo_OS_clicked();

    /* EX8 */
    void on_setLocale_box_activated(int index);

    /* EX9 */
    void on_formInputValue_returnPressed();
    void on_printArr_b_clicked();
    void on_clearArr_b_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
