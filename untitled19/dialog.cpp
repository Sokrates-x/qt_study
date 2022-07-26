#include "dialog.h"

#include <QTreeWidget>
#include <QSettings>
#include <QTreeWidgetItem>
#include <QHBoxLayout>
#include <QHeaderView>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    tree_ = new QTreeWidget;
    tree_->setColumnCount(2);
    tree_->header()->setSectionResizeMode(QHeaderView::Stretch);
    setWindowTitle("Setting Viewer");
    read_settings();

}

Dialog::~Dialog()
{
}

void Dialog::read_settings() {
    QSettings settings("Trolltech", "Designer");

    tree_->clear();
    add_child_settings(settings, nullptr, "");
    tree_->sortByColumn(0, Qt::SortOrder::AscendingOrder);
    tree_->setFocus();
    QTreeWidgetItem *item = new QTreeWidgetItem(tree_->invisibleRootItem());
    item->setText(0, "X");
    item->setText(1, "Y");
    QTreeWidgetItem *subitem = new QTreeWidgetItem(item);
    subitem->setText(0, "Z");
    subitem->setText(1, "Z");
    setWindowTitle(QString("Settings Viewer - %1 by %2").arg("Trolltech").arg("Designer"));
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(tree_);
    setLayout(layout);
    tree_->show();
    show();
}

void Dialog::add_child_settings(QSettings &s, QTreeWidgetItem *p, const QString &str) {
  if (!p)
      p = tree_->invisibleRootItem();
    QTreeWidgetItem *item;
    s.beginGroup(str);
    foreach (QString key, s.childKeys()) {
        item = new QTreeWidgetItem(p);
        item->setText(0, key);
        item->setText(1, s.value(key).toString());
    }
    foreach (QString grp, s.childGroups()) {
        item = new QTreeWidgetItem(p);
        item->setText(0, grp);
        add_child_settings(s, item, grp);
    }
    s.endGroup();
}
