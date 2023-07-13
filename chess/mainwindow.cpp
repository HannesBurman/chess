#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

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


void MainWindow::on_pushButton_A1_clicked()
{

}

void MainWindow::on_pushButton_A2_clicked()
{
    qDebug() << "wasa";
}

void MainWindow::on_pushButton_A3_clicked()
{
    qDebug() << "wasa";
}
