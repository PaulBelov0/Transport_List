#include <MainWindow.h>
#include <ui_MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    database = new Database();
    ui->setupUi(this);

    model = new QSqlTableModel(this, database->getDatabase());
    model->setTable("TransportDatabase");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->tableView->setModel(model);

    controller = new Controller();
}

MainWindow::~MainWindow()
{
    database->upload(controller->getStorage().getList());
    delete model;
    delete database;
    delete controller;
    delete ui;
}

void MainWindow::on_addNewElementButton_clicked()
{
    editElementFieldsWindow->show();
    editElementFieldsWindow->setActionForRealizationThisWnd("add");

    model->insertRow(model->rowCount());
}

void MainWindow::on_editElementButton_clicked()
{
    searchElementWindow->show();
    editElementFieldsWindow->setActionForRealizationThisWnd("edit");
}

void MainWindow::on_deleteElementButton_clicked()
{
    deleteElementWindow->show();

    model->removeRow(deleteElementWindow->getID());
}

void MainWindow::on_loadDatabaseButton_clicked()
{
    controller->setList(database->download());
}

void MainWindow::on_saveDataBaseButton_clicked()
{
    database->upload(controller->getStorage().getList());
}

void MainWindow::on_exitButton_clicked()
{
    database->upload(controller->getStorage().getList());
    this->close();
}

