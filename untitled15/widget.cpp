#include "widget.h"
#include <QtGui>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    dtab1_ = new dragTabWidget(this);
    dtab1_->setColumnCount(10);
    dtab1_->setRowCount(10);
    dtab2_ = new dragTabWidget(this);
    dtab2_->setColumnCount(10);
    dtab2_->setRowCount(10);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(dtab1_);
    layout->addWidget(dtab2_);
    setLayout(layout);
    show();
}

Widget::~Widget()
{
}

