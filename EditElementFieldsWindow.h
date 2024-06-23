#ifndef EDITELEMENTFIELDSWINDOW_H
#define EDITELEMENTFIELDSWINDOW_H

#include <QDialog>
#include <ElementIDErrorWindow.h>

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

    ElementIDErrorWindow elementIDErrorWindow;
};

#endif // EDITELEMENTFIELDSWINDOW_H
