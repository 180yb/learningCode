#ifndef DATABASE_H
#define DATABASE_H
#include<QtSql/QSql>
#include<QDebug>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include <QWidget>

//namespace Ui {
//class database;
//}
class database
{
   // Q_OBJECT
public:
//    explicit database(QWidget *parent = 0);
//    ~database();
    database();
    static  QSqlDatabase db;//定义静态变量未数据库实例
    static QSqlQuery * sql;//定义静态变量为数据库执行语言实例

    //数据库连接函数
    static bool getConnection();//获取数据库连接
    static void quitConnection();//断开数据库连接
//private:
//    Ui::database *ui;
};

#endif // DATABASE_H
