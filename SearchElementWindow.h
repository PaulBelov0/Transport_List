#ifndef SEARCHELEMENTWINDOW_H
#define SEARCHELEMENTWINDOW_H

#include <QDialog>
#include <ElementIDErrorWindow.h>

namespace Ui {
class SearchElementWindow;
}

class SearchElementWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchElementWindow(QWidget *parent = nullptr);
    ~SearchElementWindow();

private slots:
    void on_exitButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::SearchElementWindow *ui;

    ElementIDErrorWindow deleteErrorWindow;
};

#endif // SEARCHELEMENTWINDOW_H
