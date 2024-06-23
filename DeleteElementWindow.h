#ifndef DELETEELEMENTWINDOW_H
#define DELETEELEMENTWINDOW_H

#include <QDialog>
#include <QException>
#include <ElementIDErrorWindow.h>
#include <Menu/Menu.h>

namespace Ui {
class DeleteElementWindow;
}

class DeleteElementWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteElementWindow(QWidget *parent = nullptr);
    ~DeleteElementWindow();

private slots:
    void on_deleteButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::DeleteElementWindow *ui;

    ElementIDErrorWindow elementIDErrorWindow;
};

#endif // DELETEELEMENTWINDOW_H
