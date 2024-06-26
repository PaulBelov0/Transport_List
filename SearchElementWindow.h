#ifndef SEARCHELEMENTWINDOW_H
#define SEARCHELEMENTWINDOW_H

#include <QDialog>
#include <ElementIDErrorWindow.h>
#include <Menu/Menu.h>
#include <QException>

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

    ElementIDErrorWindow elementIDErrorWindow;
    QString outputText;
};

#endif // SEARCHELEMENTWINDOW_H
