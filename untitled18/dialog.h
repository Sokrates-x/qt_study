#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
template <typename T>
class QList;
class QTableWidget;
class QPointF;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QList<QPointF> *, QWidget *parent = nullptr);
    ~Dialog();
protected:
    void done(int);

private slots:
    void add_row();
    void del_row();

private:
    QList<QPointF> *corrs_;
    QTableWidget *table_;
    QPushButton *addbt_;
    QPushButton *delbt_;
};
#endif // DIALOG_H
