#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLabel;
class QCheckBox;
class  QTreeWidget;
class QLineEdit;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:

    QLabel *named_label_;
    QLabel *lookin_label_;
    QLineEdit *named_line_;
    QLineEdit *lookin_line_;

    QCheckBox *include_cbox_;
    QTreeWidget *table_;
    QLabel *mlabel_;

    QPushButton *find_btn_;
    QPushButton *stop_btn_;
    QPushButton *close_btn_;
    QPushButton *help_btn_;

};
#endif // DIALOG_H
