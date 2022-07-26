#include "cdialog.h"
#include <QMessageBox>
#include <QHBoxLayout>
#include <QPushButton>

cdialog::cdialog()
{
    QMap<int, QString> map;
    map[1] = "A";
    map[2] = "B";
    map[3] = "C";
    dialog_ = new Dialog(map);
    okb_ = new QPushButton("Ok");
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(dialog_);
    layout->addWidget(okb_);
    setLayout(layout);
    connect(dialog_, SIGNAL(finished(int)), this, SLOT(done(int)));
}

void cdialog::done(int r) {
   if (r == QDialog::Accepted) {
        int id = dialog_->getid();
        QMessageBox(QMessageBox::Information, QString("Select Icon"),
                        QString("Your Icon ID: %1").arg(id), QMessageBox::Ok).exec();
   } else if (r == QDialog::Rejected) {
        QMessageBox(QMessageBox::Warning, QString("Select Icon"),
                    QString("No Icon Seleteced"), QMessageBox::Ok).exec();
   }
   QDialog::done(r);
}
