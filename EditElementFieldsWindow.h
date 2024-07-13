#ifndef EDITELEMENTFIELDSWINDOW_H
#define EDITELEMENTFIELDSWINDOW_H

#include <QDialog>
#include <Menu/Menu.h>
#include <MessageToUserWindow.h>
#include <TransportMap/transportmap.h>
#include <Database/Database.h>

namespace Ui {
class EditElementFieldsWindow;
}

class EditElementFieldsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditElementFieldsWindow(QWidget *parent = nullptr);
    ~EditElementFieldsWindow();

    void setElementByID(const uint32_t &ID);
    void setActionForRealizationThisWnd(std::string action);
    void menuInitialization(Menu &menu);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::EditElementFieldsWindow *ui;

    Menu menu;
    std::unique_ptr<TransportMap> transportMap;
    std::string actionWithDB = "add";
    MessageToUserWindow messageToUserWindow;
    Database db;

    uint32_t ID;
    QString type;
    QString brand;
    QString model;
    uint32_t year;
    uint32_t weight;
    uint32_t firstSpecialField;
    QString secondSpecialField;
};

#endif // EDITELEMENTFIELDSWINDOW_H
