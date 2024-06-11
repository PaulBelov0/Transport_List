#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TransportList.h"

class TransportList : public QMainWindow
{
    Q_OBJECT

public:
    TransportList(QWidget *parent = nullptr);
    ~TransportList();

private:
    Ui::TransportListClass ui;
};
