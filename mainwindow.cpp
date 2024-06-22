#include <mainwindow.h>
#include <ui_mainwindow.h>

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

void MainWindow::showElement(std::unique_ptr<std::map<uint32_t, TransportBase&>> databaseElement)
{
    ui->textBrowser->setText(databaseElement);
}

