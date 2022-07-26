#include "dialog.h"

#include <QStringListModel>
#include <QListView>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

Dialog::Dialog(const QStringList &slist, QWidget *parent)
    : QDialog(parent)
{
    model_ = new QStringListModel;
    model_->setStringList(slist);

    view_ = new QListView;
    view_->setModel(model_);
    view_->setEditTriggers(QAbstractItemView::AnyKeyPressed
                            | QAbstractItemView::DoubleClicked);

    addbt_ = new QPushButton("Add Row");
    delbt_ = new QPushButton("Del Row");
    connect(addbt_, SIGNAL(clicked()), this, SLOT(insert()));
    connect(delbt_, SIGNAL(clicked()), this, SLOT(del()));

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(addbt_);
    vlayout->addWidget(delbt_);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(view_);
    layout->addLayout(vlayout);
    setLayout(layout);
    view_->show();
    show();
}

Dialog::~Dialog()
{
}

void Dialog::insert() {
    int row = view_->currentIndex().row();
    model_->insertRows(row, 1);
    QModelIndex i = model_->index(row);
    view_->setCurrentIndex(i);
    view_->edit(i);
}
void Dialog::del() {
   model_->removeRows(view_->currentIndex().row(), 1);
}
