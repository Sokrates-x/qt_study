#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidget>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QMap<int, QString> &, QWidget *parent = nullptr);
    ~Dialog();

    int getid() const { return id_; }

protected:
    void done(int);

private:
    QListWidget *list_;
    int id_;
    QPushButton *okb_;
    QPushButton *clb_;
};
#endif // DIALOG_H
