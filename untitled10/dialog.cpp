#include "dialog.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QTreeWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    named_label_ = new QLabel(QString(tr("Named:")), this);
    lookin_label_ = new QLabel(QString(tr("Look in:")), this);
    named_line_ = new QLineEdit(this);
    lookin_line_ = new QLineEdit(this);
    named_label_->setBuddy(named_line_);
    lookin_label_->setBuddy(lookin_label_);

    include_cbox_ = new QCheckBox(this);
    include_cbox_->setText(QString(tr("Include Subdirectories")));

    table_ = new QTreeWidget;
    table_->setColumnCount(1);
    QList<QTreeWidgetItem *> twi_list;
    for (int i = 1; i <= 10; ++i)
        twi_list.append(new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr), QStringList(QString("item: %1").arg(i))));
    table_->insertTopLevelItems(0, twi_list);

    mlabel_ = new QLabel(QString(tr("0 files found")), this);

    find_btn_ = new QPushButton("Find", this);
    stop_btn_ = new QPushButton("Stop", this);
    close_btn_ = new QPushButton("Close", this);
    help_btn_ = new QPushButton("Help", this);

    QGridLayout *glayout = new QGridLayout;
    glayout->addWidget(named_label_, 0, 0);
    glayout->addWidget(named_line_, 0, 1);
    glayout->addWidget(lookin_label_, 1, 0);
    glayout->addWidget(lookin_line_, 1, 1);

    glayout->addWidget(include_cbox_, 2, 0, 1, 2);
    glayout->addWidget(table_, 3, 0, 1, 2);
    glayout->addWidget(mlabel_, 4, 0, 1, 2);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(find_btn_);
    vlayout->addWidget(stop_btn_);
    vlayout->addWidget(close_btn_);
    vlayout->addStretch();
    vlayout->addWidget(help_btn_);

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addLayout(glayout);
    hlayout->addLayout(vlayout);

    this->setLayout(hlayout);

}

Dialog::~Dialog()
{
}

