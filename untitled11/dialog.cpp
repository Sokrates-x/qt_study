#include "dialog.h"
#include <QListWidget>
#include <QStackedLayout>
#include <QLabel>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    list_ = new QListWidget(this);
    list_->addItem("Page1");
    list_->addItem("Page2");
    list_->addItem("Page3");

    page1_ = new QWidget(this);
    QLabel *label1_ = new QLabel("I'm Page1", page1_);
    page2_ = new QWidget(this);
    QLabel *label2_ = new QLabel("I'm Page2", page2_);
    page3_ = new QWidget(this);
    QLabel *label3_ = new QLabel("I'm Page3", page3_);

    QStackedLayout *slayout = new QStackedLayout;
    slayout->addWidget(page1_);
    slayout->addWidget(page2_);
    slayout->addWidget(page3_);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(list_);
    layout->addLayout(slayout);
    this->setLayout(layout);

    connect(list_, SIGNAL(currentRowChanged(int)), slayout, SLOT(setCurrentIndex(int)));
    list_->setCurrentRow(0);
    sizeHint();
}

Dialog::~Dialog()
{
}

