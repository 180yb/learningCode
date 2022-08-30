#ifndef MAINSYSTEM_H
#define MAINSYSTEM_H

#include <QWidget>
#include"database.h"
#include<QStandardItemModel>

namespace Ui {
class MainSystem;
}

class MainSystem : public QWidget
{
    Q_OBJECT

public:
    Ui::MainSystem *ui;
    explicit MainSystem(QWidget *parent = 0);
    ~MainSystem();


//   static MainSystem *myMainSystem;



   void setTableInfo();

   void getdatabaseInfo();

   QStandardItemModel* dataTableModel;

private slots:
    void on_return_log_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_btn_back_clicked();

    void on_btn_in_clicked();

    void on_delete_2_clicked();

    void on_search_clicked();

    void on_modify_clicked();

    void on_pushButton_2_clicked();

private:
   // Ui::MainSystem *ui;
};

#endif // MAINSYSTEM_H
