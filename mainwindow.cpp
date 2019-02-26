#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_0_clicked()
{
    ui->widget->mode = 1;
    ui->widget->repaint();
    ui->widget->mode = 0;
}

void MainWindow::on_Btn_2_clicked()
{
    ui->widget->mode = 3;
    ui->widget->repaint();
    ui->widget->mode = 0;
}

void MainWindow::on_Btn_1_clicked()
{
    ui->widget->mode = 2;
    ui->widget->repaint();
    ui->widget->mode = 0;
}

void MainWindow::on_Btn_3_clicked()
{
    ui->widget->mode = 4;
    ui->widget->repaint();
    ui->widget->mode = 0;
}

void MainWindow::on_Btn_4_clicked()
{
    ui->widget->mode = 5;
    ui->widget->repaint();
    ui->widget->mode = 0;
}

void MainWindow::on_Btn_5_clicked()
{
    ui->widget->mode = 6;
    ui->widget->repaint();
    ui->widget->mode = 0;
}

void MainWindow::on_Btn_6_clicked()
{
    ui->widget->mode = 7;
    ui->widget->repaint();
    ui->widget->mode = 0;
}

void MainWindow::on_Btn_7_clicked()
{
    ui->widget->mode = 8;
    ui->widget->repaint();
    ui->widget->mode = 0;
}
