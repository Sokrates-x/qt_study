#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QTreeWidget;
class QTreeWidgetItem;
class QSettings;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    void read_settings();
    void add_child_settings(QSettings &, QTreeWidgetItem *, const QString &);
    QTreeWidget *tree_;
};
#endif // DIALOG_H
