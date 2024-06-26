#ifndef SUCCESSDELETING_H
#define SUCCESSDELETING_H

#include <QDialog>

namespace Ui {
class SuccessDeleting;
}

class SuccessDeleting : public QDialog
{
    Q_OBJECT

public:
    explicit SuccessDeleting(QWidget *parent = nullptr);
    ~SuccessDeleting();

private slots:
    void on_Ok_clicked();

private:
    Ui::SuccessDeleting *ui;
};

#endif // SUCCESSDELETING_H
