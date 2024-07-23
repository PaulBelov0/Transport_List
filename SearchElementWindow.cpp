#include <SearchElementWindow.h>
#include <ui_SearchElementWindow.h>

SearchElementWindow::SearchElementWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchElementWindow)
{
    ui->setupUi(this);
}

SearchElementWindow::~SearchElementWindow()
{
    delete ui;
}

void SearchElementWindow::on_exitButton_clicked()
{
    this->close();
}

void SearchElementWindow::on_okButton_clicked()
{
    if (ui->plainTextEdit != NULL) {
        uint32_t index;
        QString qString = ui->plainTextEdit->toPlainText();
        std::string text = qString.toStdString();
        try {
            index = std::stoi(text);
        } catch (QException &e) {
            messageToUserWindow.show();
            messageToUserWindow.setTextMessage("Error! Wrong input data!");
        }
        Controller controller;
        bool checkResult = controller.checkElementAvilable(index);

        if (checkResult == true) {
            editElementFieldsWindow.show();
            editElementFieldsWindow.setActionForRealizationThisWnd("edit");
            editElementFieldsWindow.setElementByID(index);
        } else {
            messageToUserWindow.show();
            messageToUserWindow.setTextMessage("Error! \nNo one element have this ID!");
        }
    } else {
        messageToUserWindow.show();
        messageToUserWindow.setTextMessage("Error! Wrong input data!");
    }
}

QString &SearchElementWindow::getElement()
{
    std::unique_ptr<QString> text;
    for (int i = 0; i < 7; i++) {
        *text += outputText[i];
        *text += "\n";
    }
    QString &output = *text;
    return output;
}
