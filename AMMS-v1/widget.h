#ifndef WIDGET_H
#define WIDGET_H
#include<bfsign.h>

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void sign_in();
protected:

    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::Widget *ui;

    QPoint p;
};

#endif // WIDGET_H
