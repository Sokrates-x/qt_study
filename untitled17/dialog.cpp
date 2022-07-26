#include "dialog.h"
#include <QtGui>
#include <QMap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

Dialog::Dialog(QMap<int, QString> &m, QWidget *parent)
    : QDialog(parent)
{
    id_ = -1;

    list_ = new QListWidget(this);
    list_->setIconSize(QSize(32, 32));

    QMapIterator i(m);
    while (i.hasNext())
    {
        i.next();
        QListWidgetItem	*item = new QListWidgetItem(i.value(), list_);
        item->setIcon(QIcon(":/cat.jpg"));
        item->setData(Qt::UserRole, i.key());
    }
    okb_ = new QPushButton("Ok", this);
    clb_ = new QPushButton("Close", this);

    connect(okb_, SIGNAL(clicked()), this, SLOT(accept()));
    connect(clb_, SIGNAL(clicked()), this, SLOT(reject()));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(okb_);
    layout->addWidget(clb_);
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(list_);
    vlayout->addLayout(layout);
    setLayout(vlayout);
    show();
}

Dialog::~Dialog()
{
}

void Dialog::done(int r) {
   id_ = -1;
   if (r == QDialog::Accepted) {
       QListWidgetItem *item = list_->currentItem();
       if (item)
           id_ = item->data(Qt::UserRole).toInt();
   }
   QDialog::done(r);
}
