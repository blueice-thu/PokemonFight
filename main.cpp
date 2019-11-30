#include "wargame.h"
#include "nextlevel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WarGame w;
    w.show();

    return a.exec();
}
