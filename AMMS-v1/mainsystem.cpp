#include "mainsystem.h"
#include "ui_mainsystem.h"
#include<QPalette>
#include"widget.h"
#include"storage_in.h"
#include<QString>
#include<QTableView>
#include"settings.h"
#include<QDateTime>
#include"modify.h"
#include"database.h"


//MainSystem* MainSystem::myMainSystem=nullptr;

MainSystem::MainSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainSystem)
{
    ui->setupUi(this);
//    myMainSystem = this;
 database myDatabase;
    myDatabase.getConnection();

//    QPalette palette(this->palette());
//    palette.setColor(QPalette::background(),Qt::black);
//    this->setPalette(palette);
    //吧窗口背景设置为透明
    setAttribute(Qt::WA_TintedBackground);
//    //去掉边框窗口
//     setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    this->dataTableModel=new QStandardItemModel();

   this->setTableInfo();

    //ui->tableView->setCurrentIndex(1);

    QDateTime nowtime=QDateTime::currentDateTime();
    QString mytime=nowtime.toString("yyyy.MM.dd hh:mm:ss.zzz ddd")+"---登陆系统";
ui->listWidget->addItem(mytime);

}

MainSystem::~MainSystem()
{
    delete ui;
}

void MainSystem::on_return_log_clicked()
{
    close();
    Widget * log_again = new Widget;
    log_again->show();

}

void MainSystem::on_pushButton_clicked()
{
//    storage_in * new_in=new storage_in;
//    new_in->show();
//    QDateTime nowtime=QDateTime::currentDateTime();
//    QString mytime=nowtime.toString("yyyy.MM.dd hh:mm:ss.zzz ddd")+"---入库操作";

//    ui->listWidget->addItem(mytime);
}

void MainSystem::setTableInfo()
{




//    ui->tableView->setColumnWidth(0,150);
//    ui->tableView->setColumnWidth(1,150);
//    ui->tableView->setColumnWidth(2,150);
//    ui->tableView->setColumnWidth(3,150);
//    ui->tableView->setColumnWidth(4,150);
//    ui->tableView->setColumnWidth(5,150);
//     ui->tableView->setColumnWidth(6,150);


     this->dataTableModel->setHorizontalHeaderItem(0,new QStandardItem("航材ID"));
     this->dataTableModel->setHorizontalHeaderItem(1,new QStandardItem("航材名称"));
    this->dataTableModel->setHorizontalHeaderItem(2,new QStandardItem("航材折旧度"));
    this->dataTableModel->setHorizontalHeaderItem(3,new QStandardItem("航材状态"));
    this->dataTableModel->setHorizontalHeaderItem(4,new QStandardItem("航材寿命"));
    this->dataTableModel->setHorizontalHeaderItem(5,new QStandardItem("航材来源"));
    this->dataTableModel->setHorizontalHeaderItem(6,new QStandardItem("航材使用时间"));



     this->dataTableModel->setHorizontalHeaderItem(7,new QStandardItem("仓库编号"));
     this->dataTableModel->setHorizontalHeaderItem(8,new QStandardItem("货架编号"));
     this->dataTableModel->setHorizontalHeaderItem(9,new QStandardItem("货架层号"));
     this->dataTableModel->setHorizontalHeaderItem(10,new QStandardItem("托盘编号"));



     this->getdatabaseInfo();

     ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

     ui->tableView->setModel(this->dataTableModel);
     

}

void MainSystem::getdatabaseInfo()
{
    QSqlQuery sql;
    sql.prepare("select * from itemsinfo");
    sql.exec();
    this->dataTableModel->clear();
    int row=0;
    while(sql.next())
    {

        this->dataTableModel->setItem(row,0,new QStandardItem(sql.value("item_ID").toString()));
        this->dataTableModel->setItem(row,1,new QStandardItem(sql.value("item_Name").toString()));
        this->dataTableModel->setItem(row,2,new QStandardItem(sql.value("item_DepreciationDegree").toString()));
        this->dataTableModel->setItem(row,3,new QStandardItem(sql.value("item_State").toString()));
        this->dataTableModel->setItem(row,4,new QStandardItem(sql.value("item_Age").toString()));
        this->dataTableModel->setItem(row,5,new QStandardItem(sql.value("item_Source").toString()));
        this->dataTableModel->setItem(row,6,new QStandardItem(sql.value("item_UsageTime").toString()));



        this->dataTableModel->setItem(row,7,new QStandardItem(sql.value("item_StoreNum").toString()));
        this->dataTableModel->setItem(row,8,new QStandardItem(sql.value("item_ShelfNum").toString()));
        this->dataTableModel->setItem(row,9,new QStandardItem(sql.value("item_FloorNum").toString()));
        this->dataTableModel->setItem(row,10,new QStandardItem(sql.value("item_PalletNum").toString()));
        //this->dataTableModel->setItem(row,6,new QStandardItem(sql.value("item_Note").toString()));
        row++;
    }
    sql.clear();
}

void MainSystem::on_pushButton_4_clicked()
{
    this->setTableInfo();
    QDateTime nowtime=QDateTime::currentDateTime();
    QString mytime=nowtime.toString("hh:mm:ss ")+"---刷新成功";

    ui->listWidget->addItem(mytime);

}

void MainSystem::on_pushButton_5_clicked()
{
    Settings * setting = new Settings;
    setting->show();
}

void MainSystem::on_pushButton_6_clicked()
{
    modify * mod=new modify;
    mod->show();
}

void MainSystem::on_btn_back_clicked()
{

}

void MainSystem::on_btn_in_clicked()
{
    QString itemID = ui->itemID->text();
    QString itemName = ui->itemName->text();
            QString itemStoreNum=ui->itemStoreNum->text();
            QString itemShelfNum=ui->itemShelfNum->text();
            QString itemFloorNum=ui->itemFloorNum->text();
            QString itemPalletNum=ui->itemPalletNum->text();

            QString itemOld = ui->old->currentText();
            QString itemstate = ui->state->currentText();
            QString itemage =ui ->age->currentText();
            QString itemsource = ui->source->text();
            QString itemusagetime =ui->usagetime->text();
//            QString itemName->text();
            qDebug()<<itemID;

            QSqlQuery sql;

            sql.prepare("insert into itemsinfo(item_ID,item_Name,item_StoreNum,item_ShelfNum,item_FloorNum,item_PalletNum,item_DepreciationDegree,item_State,item_Age,item_Source,item_UsageTime) values(:item_ID,:itemName,:itemStoreNum,:itemShelfNum,:itemFloorNum,:itemPalletNum,:itemOld,:itemState,:itemAge,:itemSource,:item_UsageTime)");
            sql.bindValue(":item_ID",itemID);
            sql.bindValue(":itemName",itemName);
            sql.bindValue(":itemStoreNum",itemStoreNum);
            sql.bindValue(":itemShelfNum",itemShelfNum);
            sql.bindValue(":itemFloorNum",itemFloorNum);
            sql.bindValue(":itemPalletNum",itemPalletNum);

          //  sql.prepare("insert into itemsinfo(item_DepreciationDegree,item_State,item_Age,item_Source,item_UsageTime) values(:itemOld,:itemState,:itemAge,:itemSource,:item_UsageTime)");
            sql.bindValue(":itemOld",itemOld);
            sql.bindValue(":itemState",itemstate);
            sql.bindValue(":itemAge",itemage);
            sql.bindValue(":itemSource",itemsource);
            sql.bindValue(":item_UsageTime",itemusagetime);

//数据库查询语言要写在一个QSqlQuery里面，不然查询不了

            bool addIF =sql.exec();
QDateTime nowtime=QDateTime::currentDateTime();

            if(addIF)
            {

QString information=nowtime.toString("hh:mm:ss ")+"航材ID："+itemID+"入库成功！";

//mainwin->ui->listWidget->addItem(information);
                ui->listWidget->addItem(information);
            }
            else
            {

QString information2=nowtime.toString("hh:mm:ss ")+"航材ID："+itemID+"入库失败，请检查信息！";
//mainwin->ui->listWidget->addItem(information2);
                ui->listWidget->addItem(information2);

            }
            sql.clear();
}

void MainSystem::on_delete_2_clicked()
{
    QString name=ui->mod_ID->text();

    QSqlQuery sql;
    sql.prepare("delete from itemsinfo where item_ID =:name");
    sql.bindValue(":name",name);
    sql.exec();
    bool deleteif=sql.exec();
    if(deleteif)
    {
        QDateTime nowtime=QDateTime::currentDateTime();
        QString information=nowtime.toString("hh:mm:ss ")+"航材ID："+name+"删除成功！";
         ui->listWidget->addItem(information);
    }
    else
    {
        QDateTime nowtime=QDateTime::currentDateTime();
        QString information=nowtime.toString("hh:mm:ss ")+"航材ID："+name+"删除失败！";
         ui->listWidget->addItem(information);
    }
    sql.clear();
}



void MainSystem::on_modify_clicked()
{
    QString itemID=ui->mod_ID->text();
    QString itemName = ui->mod_itemName->text();
    QString itemOld = ui->mod_old->currentText();
    QString itemstate = ui->mod_state->currentText();
    QString itemage =ui ->mod_age->currentText();
    QString itemsource = ui->mod_source->text();
    QString itemusagetime =ui->mod_usagetime->text();

    QString itemStoreNum=ui->itemStoreNum->text();
    QString itemShelfNum=ui->itemShelfNum->text();
    QString itemFloorNum=ui->itemFloorNum->text();
    QString itemPalletNum=ui->itemPalletNum->text();


    QSqlQuery sql;
    sql.prepare("update itemsinfo set item_Name =:name,item_DepreciationDegree =:degree,item_State=:state,item_Age=:age,item_Source=:source,item_UsageTime=:uagetime,item_StoreNum=:site1,item_ShelfNum=:site2,item_FloorNum=:site3,item_PalletNum=:site4 where item_ID=:modID");
    sql.bindValue(":modID",itemID);
    sql.bindValue(":name",itemName);
    sql.bindValue(":degree",itemOld);
    sql.bindValue(":state",itemstate);
    sql.bindValue(":age",itemage);
    sql.bindValue(":source",itemsource);
    sql.bindValue(":uagetime",itemusagetime);
    sql.bindValue(":site1",itemStoreNum);
    sql.bindValue(":site2",itemShelfNum);
    sql.bindValue(":site3",itemFloorNum);
    sql.bindValue(":site4",itemPalletNum);
    bool addif=sql.exec();
    if(addif)
    {
        QDateTime nowtime=QDateTime::currentDateTime();
        QString information=nowtime.toString("hh:mm:ss ")+"航材ID："+itemID+"修改成功！";
         ui->listWidget->addItem(information);
    }
    else
    {
        QDateTime nowtime=QDateTime::currentDateTime();
        QString information=nowtime.toString("hh:mm:ss ")+"航材ID："+itemID+"修改失败！";
         ui->listWidget->addItem(information);
    }
    sql.clear();
}

void MainSystem::on_search_clicked()
{
    if(ui->mod_ID->text()=="")
    {
        this->setTableInfo();
    }
    else{
        QSqlQuery sql;
        sql.prepare("select * from itemsinfo where item_ID = :modID");
        sql.bindValue(":modID",ui->mod_ID->text());
        sql.exec();
        while(sql.next())
        {
            ui->mod_itemName->setText(sql.value("item_Name").toString());
            ui->mod_source->setText(sql.value("item_Source").toString());
            ui->mod_usagetime->setText(sql.value("item_UsageTime").toString());

        }
        bool addif=sql.exec();
        if(addif)
        {
            QDateTime nowtime=QDateTime::currentDateTime();
            QString information=nowtime.toString("hh:mm:ss ")+"航材ID："+ui->mod_ID->text()+"检索成功！";
             ui->listWidget->addItem(information);
        }
        else
        {
            QDateTime nowtime=QDateTime::currentDateTime();
            QString information=nowtime.toString("hh:mm:ss ")+"航材ID："+ui->mod_ID->text()+"检索失败！";
             ui->listWidget->addItem(information);
        }
        sql.clear();
    }

}

void MainSystem::on_pushButton_2_clicked()
{

}
