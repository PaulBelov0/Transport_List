#ifndef MESSAGETOUSERWINDOW_H
#define MESSAGETOUSERWINDOW_H

#include <QDialog>

namespace Ui {
class MessageToUserWindow;
}

class MessageToUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MessageToUserWindow(QWidget *parent = nullptr);
    ~MessageToUserWindow();

    void setTextMessage(const QString& textMessage);

private slots:
    void on_okButton_clicked();

private:
    Ui::MessageToUserWindow *ui;
};

#endif // MESSAGETOUSERWINDOW_H
