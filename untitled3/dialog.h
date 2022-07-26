#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QCheckBox;
class QLineEdit;
class QLabel;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:

    QCheckBox *cbox_;
    QCheckBox *cbox2_;
    QLabel *label_;
    QPushButton *find_;
    QPushButton *close_;
    QLineEdit *line_;

};
#endif // DIALOG_H
