#include "dialog.h"
#include "hexspinbox.h"

#include <QSpinBox>
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    spinBox_ = new QSpinBox(this);
    spinBox_->setDisplayIntegerBase(16);

    spinBox_2 = new HexSpinBox(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(spinBox_);
    layout->addWidget(spinBox_2);
    this->setLayout(layout);
    this->setFixedHeight(sizeHint().height());

    this->show();
}

Dialog::~Dialog()
{
}

