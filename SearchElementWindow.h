#ifndef SEARCHELEMENTWINDOW_H
#define SEARCHELEMENTWINDOW_H

#include <QDialog>
#include <MessageToUserWindow.h>
#include <QException>
#include <Menu/Menu.h>

namespace Ui {
class SearchElementWindow;
}

class SearchElementWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchElementWindow(QWidget *parent = nullptr);
    ~SearchElementWindow();

    QString& getElement();

private slots:
    void on_exitButton_clicked();

    void on_okButton_clicked();

private:
    Ui::SearchElementWindow *ui;

    MessageToUserWindow messageToUserWindow;
    QString outputText;
};

#endif // SEARCHELEMENTWINDOW_H
