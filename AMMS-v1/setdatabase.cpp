#include "setdatabase.h"
#include "ui_setdatabase.h"

setdatabase::setdatabase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setdatabase)
{
    ui->setupUi(this);
}

setdatabase::~setdatabase()
{
    delete ui;
}
