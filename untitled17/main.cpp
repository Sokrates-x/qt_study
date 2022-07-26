#include "cdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cdialog w;
    w.show();
    return a.exec();
}
