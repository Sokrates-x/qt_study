#include "dialog.h"

#include <QTextEdit>
#include <QListWidget>
#include <QStackedLayout>
#include <QSplitter>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    ed1_= new QTextEdit;
    ed1_->setText("I'm Editor 1");
    ed2_= new QTextEdit;
    ed3_= new QTextEdit;

    sp_ = new QSplitter(Qt::Horizontal, this);
    sp_->addWidget(ed1_);
    sp_->addWidget(ed2_);
    sp_->addWidget(ed3_);
    sp_->show();
}

Dialog::~Dialog()
{
}
