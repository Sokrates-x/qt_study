#include "dialog.h"

#include<QCheckBox>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLineEdit>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    cbox_ = new QCheckBox(this);
    cbox_->setText(tr("Find &forward"));

    cbox2_ = new QCheckBox(this);
    cbox2_->setText(tr("Find &backward"));

    QVBoxLayout *boxlayout = new QVBoxLayout;
    boxlayout->addWidget(cbox_);
    boxlayout->addWidget(cbox2_);

    label_ = new QLabel(tr("Find what"),this);

    line_ = new QLineEdit(this);
    line_->clear();

    QHBoxLayout *linelayout = new QHBoxLayout;
    linelayout->addWidget(label_);
    linelayout->addWidget(line_);

    QVBoxLayout *coblayout = new QVBoxLayout;
    coblayout->addLayout(linelayout);
    coblayout->addLayout(boxlayout);

    find_ = new QPushButton(this);
    find_->setText(tr("&Find"));

    close_ = new QPushButton(this);
    close_->setText(tr("Close"));

    QVBoxLayout *butlayout = new QVBoxLayout;
    butlayout->addWidget(find_);
    butlayout->addWidget(close_);
    butlayout->addStretch();

    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addLayout(coblayout);
    mainlayout->addLayout(butlayout);

    this->setLayout(mainlayout);

    this->show();
}

Dialog::~Dialog()
{
}

