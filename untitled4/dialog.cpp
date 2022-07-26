#include "dialog.h"
#include "ui_dialog.h"

#include <QPushButton>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}

