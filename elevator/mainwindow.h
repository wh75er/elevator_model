#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//    void on_button_1_clicked();
//    void on_button_2_clicked();
//    void on_button_3_clicked();
//    void on_button_4_clicked();
//    void on_button_5_clicked();

//    void on_lift_button_1_clicked();
//    void on_lift_button_2_clicked();
//    void on_lift_button_3_clicked();
//    void on_lift_button_4_clicked();
//    void on_lift_button_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
