#include "mainwindow.h"
#include "log.h"
#include "crypt.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    //coin(nom,mot);
    QApplication a(argc, argv);
    MainWindow w,z;
    w.show();
    return a.exec();
}
