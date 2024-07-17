#include <MainWindow.h>
#include <ui_MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, database.getDatabase());
    model->setTable("TransportDatabase");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->tableView->setModel(model);

    menu.setMap(*database.download());
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::on_addNewElementButton_clicked()
{
    editElementFieldsWindow.show();
    editElementFieldsWindow.setActionForRealizationThisWnd("add");

    model->insertRow(model->rowCount());
}

void MainWindow::on_editElementButton_clicked()
{
    searchElementWindow.show();
    //editElementFieldsWindow.setActionForRealizationThisWnd("edit");
}

void MainWindow::on_deleteElementButton_clicked()
{
    deleteElementWindow.show();

    model->removeRow(deleteElementWindow.getID());
}

void MainWindow::on_loadDatabaseButton_clicked()
{
    menu.setMap(*database.download());
}

void MainWindow::on_saveDataBaseButton_clicked()
{
    database.upload(menu.getMap());
}

void MainWindow::on_exitButton_clicked()
{
    database.upload(menu.getMap());
    this->close();
}

void MainWindow::reloadDatabase()
{
    //database.upload(menu.getMap());
    //database.download();
}
