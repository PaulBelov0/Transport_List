#ifndef SEARCHELEMENTWINDOW_H
#define SEARCHELEMENTWINDOW_H

#include <QDialog>
#include <QException>

#include "EditElementFieldsWindow.h"
#include "Controller/Controller.h"
#include "MessageToUserWindow.h"

namespace Ui {
class SearchElementWindow;
}

class SearchElementWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchElementWindow(Controller* controller, QWidget *parent = nullptr);
    ~SearchElementWindow();

    QString &getElement();

private slots:
    void on_exitButton_clicked();

    void on_okButton_clicked();

private:
    Ui::SearchElementWindow *ui;

    Controller* controller;
    EditElementFieldsWindow* editElementFieldsWindow;
    MessageToUserWindow* messageToUserWindow;
    QString outputText;
};

#endif // SEARCHELEMENTWINDOW_H
