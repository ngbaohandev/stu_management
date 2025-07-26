#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    ui->lbl_Notification->setText("Minh");
}


void MainWindow::on_pushButton_released()
{
    ui->lbl_Notification->setText("Ngoc Anh");
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{

}

