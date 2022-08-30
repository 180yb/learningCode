#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include<QMouseEvent>
#include<QPushButton>
#include<QFile>
#include<QStringList>
#include<QTextStream>
#include<QDialog>
#include<QMessageBox>
#include<QDebug>
#include<QTextCodec>
#include"bfsign.h"
#include"mainsystem.h"

bool success_pass = false;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

   //去掉边框窗口
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //吧窗口背景设置为透明
    setAttribute(Qt::WA_TintedBackground);


    connect(ui->forget,&QPushButton::clicked,[=](){
        bfsign* bf1=new bfsign;
        bf1->show();
    });

    connect(ui->log_in,&QPushButton::clicked,[=](){
       Widget::sign_in();
    });





    QFile file("userInfo.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);


    QString s_name;
    QString s_key;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {

        p=e->globalPos()-this->frameGeometry().topLeft();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::LeftButton)
    {

        move(e->globalPos()-p);
    }
}

void Widget::on_toolButton_2_clicked()
{
    close();
}

void Widget::on_toolButton_clicked()
{
    showMinimized();
}
void Widget::sign_in()
{
    QString s_name = ui->username->text();
    QString s_key = ui->password->text();
    QFile file("userInfo.csv");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QStringList tempOption;
    while (!in.atEnd())
    {
        tempOption=in.readLine().split(",");
        if(s_name==tempOption[0])
        {
            if(s_key==tempOption[1])
                success_pass = true;
            break;
        }
    }
    file.close();
  if(success_pass)
  {
this->close();
      this->close();
      MainSystem * mysystem=new MainSystem;
      mysystem->showMaximized();

  }
}
