#ifndef EDITELEMENTFIELDSWINDOW_H
#define EDITELEMENTFIELDSWINDOW_H

#include <QDialog>
#include <Menu/Menu.h>
#include <MessageToUserWindow.h>
#include <TransportMap/transportmap.h>

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
    TransportMap transportMap;
    std::string actionWithDB = "add";
    MessageToUserWindow messageToUserWindow;
};

#endif // EDITELEMENTFIELDSWINDOW_H
