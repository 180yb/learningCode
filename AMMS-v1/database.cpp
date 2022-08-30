#include "database.h"
#include<QMessageBox>
QSqlDatabase database::db=QSqlDatabase::addDatabase("QODBC");//创建静态6数据库实例
QSqlQuery* database::sql= NULL;
database::database()
{

}

bool database::getConnection()
{

    //数据库连接
    db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("AMMS32");
        db.setUserName("root");
        db.setPassword("hxh1540398363");
        if(!db.open())
        {
            //QMessageBox::warning(this,QStringLiteral("message"),db.lastError().text());
            qDebug()<<"DataBase Error";
            qDebug()<<db.lastError().text();
            return false;

        }
        else
        {
           // QMessageBox::information(this,QStringLiteral("message"),"success!");
            qDebug()<<"connect successed";
            return true;
        }
}





