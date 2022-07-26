#include "mainwindow.h"

#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

MainWindow::MainWindow()
{
    this->setWindowTitle(tr("Enter Your Age"));
    sbox_ = new QSpinBox(this);
    sbox_->setRange(0, 130);

    slider_ = new QSlider(Qt::Horizontal, this);
    slider_->setRange(0, 130);

   QObject::connect(sbox_, SIGNAL(valueChanged(int)), slider_, SLOT(setValue(int)));

   QObject::connect(slider_, SIGNAL(valueChanged(int)), sbox_, SLOT(setValue(int)));

   sbox_->setValue(35);

   QHBoxLayout *layout = new QHBoxLayout;
   layout->addWidget(sbox_);
   layout->addWidget(slider_);
   this->setLayout(layout);

   this->show();
}

MainWindow::~MainWindow()
{}
