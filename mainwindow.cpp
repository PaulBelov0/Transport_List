#include <mainwindow.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, *menu.getDatabaseFromSource());
    model->setTable("TransportDatabase");
    model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow() { delete model;  delete ui; }


void MainWindow::on_addNewElementButton_clicked()
{
    editElementFieldsWindow.show();
    editElementFieldsWindow.setActionForRealizationThisWnd("add");
}


void MainWindow::on_editElementButton_clicked()
{
    searchElementWindow.show();
}


void MainWindow::on_deleteElementButton_clicked()
{
    deleteElementWindow.show();
}


void MainWindow::on_loadDatabaseButton_clicked()
{
    menu.loadDatabase();
}


void MainWindow::on_saveDataBaseButton_clicked()
{
    menu.saveDatabase();
}


void MainWindow::on_exitButton_clicked()
{
    on_saveDataBaseButton_clicked();
    this->close();
}

