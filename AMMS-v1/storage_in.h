#ifndef STORAGE_IN_H
#define STORAGE_IN_H

#include <QWidget>
#include"mainsystem.h"
#include"ui_mainsystem.h"

namespace Ui {
class storage_in;
}

class storage_in : public QWidget
{
    Q_OBJECT

public:
    explicit storage_in(QWidget *parent = 0);
    ~storage_in();

//    Ui::MainSystem *ui=MainSystem::myMainSystem->ui;
 

private slots:
    void on_btn_in_clicked();

private:
    Ui::storage_in *ui;
    MainSystem *mainwin;
};

#endif // STORAGE_IN_H
