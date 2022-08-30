#ifndef BFSIGN_H
#define BFSIGN_H

#include <QWidget>

namespace Ui {
class bfsign;
}

class bfsign : public QWidget
{
    Q_OBJECT

public:
    explicit bfsign(QWidget *parent = 0);
    ~bfsign();

private slots:
    void on_toolButton_clicked();


public slots:
    void register_check();

private:
    Ui::bfsign *ui;
};

#endif // BFSIGN_H
