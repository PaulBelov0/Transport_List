#ifndef ELEMENTIDERRORWINDOW_H
#define ELEMENTIDERRORWINDOW_H

#include <QDialog>

namespace Ui {
class ElementIDErrorWindow;
}

class ElementIDErrorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ElementIDErrorWindow(QWidget *parent = nullptr);
    ~ElementIDErrorWindow();

private slots:
    void on_closeButton_clicked();

private:
    Ui::ElementIDErrorWindow *ui;
};

#endif // ELEMENTIDERRORWINDOW_H
