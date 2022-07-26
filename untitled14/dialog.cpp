#include "dialog.h"

#include <QtGui>
#include <QSplitter>
#include "draglistwidget.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    dlist1_ = new dragListWidget(this);
    for (int i = 1; i != 6; ++i)
        dlist1_->addItem(QString("Left %1").arg(i));
    dlist2_ = new dragListWidget(this);
    for (int i = 1; i != 5; ++i)
        dlist2_->addItem(QString("Right %1").arg(i));

    sp_ = new QSplitter(Qt::Horizontal, this);
    sp_->addWidget(dlist1_);
    sp_->addWidget(dlist2_);
    sp_->show();

}

Dialog::~Dialog()
{
}

