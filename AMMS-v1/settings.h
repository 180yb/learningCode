#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Settings *ui;

//    static QSqlDatabase db;//定义静态变量未数据库实例
//    static QSqlQuery * sql;//定义静态变量为数据库执行语言实例
};

#endif // SETTINGS_H
