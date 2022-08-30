#ifndef MODIFY_H
#define MODIFY_H

#include <QWidget>

namespace Ui {
class modify;
}

class modify : public QWidget
{
    Q_OBJECT

public:
    explicit modify(QWidget *parent = 0);
    ~modify();

private:
    Ui::modify *ui;
};

#endif // MODIFY_H
