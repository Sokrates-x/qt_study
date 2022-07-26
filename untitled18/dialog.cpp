#include "dialog.h"
#include <QTableWidget>
#include <QList>
#include <QPointF>
#include <QPushButton>
#include <QHBoxLayout>

Dialog::Dialog(QList<QPointF> *c, QWidget *parent)
    : QDialog(parent)
{
    corrs_ = c;

    table_ = new QTableWidget(0, 2);
    table_->setHorizontalHeaderLabels(QStringList() << "X" << "Y");
    for (int r = 0; r < c->count(); ++r) {
        QPointF p = c->at(r);
        add_row();
        table_->item(r, 0)->setText(QString::number(p.x()));
        table_->item(r, 1)->setText(QString::number(p.y()));
    }

    addbt_ = new QPushButton("Add Row");
    delbt_ = new QPushButton("Del Row");

    connect(addbt_, SIGNAL(clicked()), this, SLOT(add_row()));
    connect(delbt_, SIGNAL(clicked()), this, SLOT(del_row()));

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(addbt_);
    vlayout->addWidget(delbt_);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table_);
    layout->addLayout(vlayout);

    setLayout(layout);
    show();
}

Dialog::~Dialog()
{
}

void Dialog::add_row() {
    int r = table_->rowCount();
    table_->insertRow(r);
    QTableWidgetItem *iteml = new QTableWidgetItem;
    iteml->setTextAlignment(Qt::AlignCenter);
    table_->setItem(r, 0, iteml);

    QTableWidgetItem *itemr = new QTableWidgetItem;
    itemr->setTextAlignment(Qt::AlignCenter);
    table_->setItem(r, 1, itemr);
    table_->setCurrentItem(iteml);
}

void Dialog::del_row() {
    int r = table_->currentRow();
    table_->removeRow(r);
    table_->setCurrentItem(table_->item(r - 1 >= 0 ? r - 1 : 0, 0));
}

void Dialog::done(int r) {
    if (r == QDialog::Accepted) {
        corrs_->clear();
        for (int r = 0; r != table_->rowCount(); ++r) {
            double x = table_->item(r, 0)->text().toDouble();
            double y = table_->item(r, 1)->text().toDouble();
            corrs_->append(QPointF(x, y));
        }
    }
    QDialog::done(r);
}
