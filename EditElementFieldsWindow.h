#ifndef EDITELEMENTFIELDSWINDOW_H
#define EDITELEMENTFIELDSWINDOW_H

#include <QDialog>

#include "Controller/Controller.h"
#include "MessageToUserWindow.h"
#include "TransportStorage/TransportStorage.h"

namespace Ui {
class EditElementFieldsWindow;
}

class EditElementFieldsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditElementFieldsWindow(Controller* controller, QWidget *parent = nullptr);
    ~EditElementFieldsWindow();

    void setElementByID(const uint32_t &ID);
    void setActionForRealizationThisWnd(std::string action);
    void menuInitialization(Controller &Controller);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:

    Ui::EditElementFieldsWindow *ui;

    Controller* controller;
    std::unique_ptr<TransportStorage> transportStorage;
    std::string actionWithDB = "add";
    MessageToUserWindow messageToUserWindow;
};

#endif // EDITELEMENTFIELDSWINDOW_H
