#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "dragtabwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    dragTabWidget *dtab1_;
    dragTabWidget *dtab2_;
};
#endif // WIDGET_H
