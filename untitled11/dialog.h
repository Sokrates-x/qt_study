#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QListWidget;
class QWidget;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();


private:

    QListWidget *list_;

    QWidget *page1_;
    QWidget *page2_;
    QWidget *page3_;
};

#endif // DIALOG_H
