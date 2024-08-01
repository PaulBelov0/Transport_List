#ifndef EDITELEMENTFIELDSWINDOW_H
#define EDITELEMENTFIELDSWINDOW_H

#include <QDialog>

#include "MessageToUserWindow.h"
#include "TransportStorage/TransportStorage.h"
#include "Transport/Transport.h"

namespace Ui {
class EditElementFieldsWindow;
}

class EditElementFieldsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditElementFieldsWindow(std::vector<std::string>* args, QWidget *parent = nullptr);

    ~EditElementFieldsWindow();

    void setElementByID(const uint32_t &ID);

    void setActionForRealizationThisWnd(std::string action);

private slots:

    void on_okButton_clicked();

    void on_cancelButton_clicked();

signals:

private:

    Ui::EditElementFieldsWindow *ui;

    std::unique_ptr<TransportStorage> transportStorage;
    std::string actionWithDB = "add";
    MessageToUserWindow messageToUserWindow;

    std::vector<std::string>* args;
};

#endif // EDITELEMENTFIELDSWINDOW_H
