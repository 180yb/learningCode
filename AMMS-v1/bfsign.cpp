#include "bfsign.h"
#include "ui_bfsign.h"
#include<QFile>
#include<QTextStream>
#include<QPushButton>

bfsign::bfsign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bfsign)
{
    ui->setupUi(this);
//QCommendPushButton:commandLinkButton{
//background-color: #00FFFFFF;
//color:white;
//}

    //去掉边框窗口
     setWindowFlags(Qt::FramelessWindowHint | windowFlags());

     //吧窗口背景设置为透明
     setAttribute(Qt::WA_TintedBackground);

    connect(ui->btn_check,&QPushButton::clicked,[=](){
        register_check();
    });

}

bfsign::~bfsign()
{
    delete ui;








}

void bfsign::on_toolButton_clicked()
{
    close();
}

void bfsign::register_check()
{
    //get user's information
    QString name=ui->line_name->text();
    QString key=ui->line_key->text();
    QString akey=ui->line_akey->text();


    //record information
    QFile file("userInfo.csv");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QStringList tempOption;

    bool user_repeat=false;
    if(name==""||key==""||akey=="")
        ui->state->setText("请补全信息！");
    else
    {
        while(!in.atEnd())
        {
            tempOption=in.readLine().split(",");
            if(name==tempOption[0])
            {
                ui->state->setText("账户已存在!");
                {
                    user_repeat=true;
                    break;
                }
            }
        }
        file.close();
        if(!user_repeat)
        {
            if(key!=akey)
                ui->state->setText("二次密码错误！");
            else
            {
                QFile file("userInfo.csv");
                file.open(QIODevice::Append);
                file.write((name+","+key+","+"\r\n").toLocal8Bit());
                ui->state->setText("注册成功!");
            }
        }
    }







}
