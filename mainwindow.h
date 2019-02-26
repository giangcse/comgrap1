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
    void on_Btn_0_clicked();

    void on_Btn_2_clicked();

    void on_Btn_1_clicked();

    void on_Btn_3_clicked();

    void on_Btn_4_clicked();

    void on_Btn_5_clicked();

    void on_Btn_6_clicked();

    void on_Btn_7_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
