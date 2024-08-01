#ifndef DELETEELEMENTWINDOW_H
#define DELETEELEMENTWINDOW_H

#include <QDialog>
#include <QException>

#include "MessageToUserWindow.h"

namespace Ui {
class DeleteElementWindow;
}

class DeleteElementWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteElementWindow(uint32_t* args, QWidget *parent = nullptr);
    ~DeleteElementWindow();

private slots:
    void on_deleteButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::DeleteElementWindow *ui;

    uint32_t* args;
};

#endif // DELETEELEMENTWINDOW_H
