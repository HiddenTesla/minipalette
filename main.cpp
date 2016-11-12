#include "minipalette.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MiniPalette w;
    w.show();

    return a.exec();
}
