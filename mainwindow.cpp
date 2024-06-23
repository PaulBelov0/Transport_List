#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_addNewElementButton_clicked()
{

}


void MainWindow::on_editElementButton_clicked()
{

}


void MainWindow::on_deleteElementButton_clicked()
{
    deleteElementWindow;
}


void MainWindow::on_showElementButton_clicked()
{

}


void MainWindow::on_loadDatabaseButton_clicked()
{

}


void MainWindow::on_saveDataBaseButton_clicked()
{

}


void MainWindow::on_exitButton_clicked()
{

}

