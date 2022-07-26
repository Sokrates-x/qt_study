#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class dragListWidget;
class QSplitter;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    dragListWidget *dlist1_;
    dragListWidget *dlist2_;
    QSplitter *sp_;
};
#endif // DIALOG_H
