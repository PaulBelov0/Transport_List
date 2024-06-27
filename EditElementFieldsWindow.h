#ifndef EDITELEMENTFIELDSWINDOW_H
#define EDITELEMENTFIELDSWINDOW_H

#include <QDialog>
#include <MessageToUserWindow.h>
#include <Menu/Menu.h>
#include <MessageToUserWindow.h>

namespace Ui {
class EditElementFieldsWindow;
}

class EditElementFieldsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditElementFieldsWindow(QWidget *parent = nullptr);
    ~EditElementFieldsWindow();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::EditElementFieldsWindow *ui;

    MessageToUserWindow messageToUserWindow;
};

#endif // EDITELEMENTFIELDSWINDOW_H
