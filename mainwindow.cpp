#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QDialog)
{
    ui->setupUi(this);

    connect(ui->addNewElementButton, SIGNAL(clicked()), this, SLOT(startPressed()));
    connect(ui->deleteElementButton, SIGNAL(clicked()), this, SLOT(startPressed()));
    connect(ui->editElementButton, SIGNAL(clicked()), this, SLOT(startPressed()));
    connect(ui->showElementButton, SIGNAL(clicked()), this, SLOT(startPressed()));
    connect(ui->saveDatabaseButton, SIGNAL(clicked()), this, SLOT(startPressed()));
    connect(ui->loadDatabaseButton, SIGNAL(clicked()), this, SLOT(startPressed()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(startPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showElement(TransportMap& databaseElement, uint32_t index)
{
    ui->textBrowser->setText(*databaseElement.print(index));
}

void MainWindow::showElement(std::string& output)
{
    const QString& text = QString::fromStdString(output);
    ui->textBrowser->setText(text);
}

void MainWindow::on_addNewElementButton_clicked()
{

}

void MainWindow::on_deleteElementButton_clicked()
{

}

void MainWindow::on_editElementButton_clicked()
{

}

void MainWindow::on_showElementButton_clicked()
{

}

void MainWindow::on_saveDatabaseButton_clicked()
{

}

void MainWindow::on_loadDatabaseButton_clicked(){

}

void MainWindow::on_exitButton_clicked()
{

}

