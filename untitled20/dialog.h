#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
class QStringListModel;
class QListView;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(const QStringList &slist = QStringList() << "A" << "B" << "C" << "D", QWidget *parent = nullptr);
    ~Dialog();

protected slots:

    void insert();
    void del();

private:
    QStringListModel *model_;
    QListView *view_;
    QPushButton *addbt_;
    QPushButton *delbt_;
};
#endif // DIALOG_H
