#include "widget.h"
#include <QApplication>
#include"database.h"
#include<QLibrary>

int main(int argc, char *argv[])
{
    QLibrary libmysql("libmysql.all");
    libmysql.load();
    QApplication::addLibraryPath("strPluginsPath");
    QApplication a(argc, argv);
    Widget w;
    w.show();


    return a.exec();
}
