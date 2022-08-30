#include "settings.h"
#include "ui_settings.h"
#include"database.h"
#include"mainsystem.h"
//extern  static QSqlDatabase database::db;


Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

//void Settings::on_pushButton_clicked()
//{
//    close();
//}

void Settings::on_pushButton_clicked()
{
//     QString hostname = ui->hostname->text();\
//     QString database = ui->databasename->text();
//     QString username = ui->username->text();
//     QString password = ui->password->text();


//    db.setHostName(hostname);
//        db.setPort(3306);
//        db.setDatabaseName(database);
//        db.setUserName(username);
//        db.setPassword(password);

//        if(!db.open())
//        {
//            ui->state->setText("数据库连接失败");
//            qDebug()<<"DataBase Error";
//            qDebug()<<db.lastError().text();
//            return false;

//        }
//        else
//        {
//            ui->state->setText("数据库连接成功");
//           // qDebug()<<"connect successed";
//            return true;
//        }
    close();
}

void Settings::on_pushButton_2_clicked()
{

}
