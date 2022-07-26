#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<QPointF> *plist = new QList<QPointF>;
    *plist << QPointF(3.14f, 3.21f) << QPointF(3.23f, 4.32f) << QPointF(0.31f, 8.31f);
    Dialog w(plist);
    w.show();
    return a.exec();
}
