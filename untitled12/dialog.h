#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QComboBox;
class QTextEdit;
class QListWidget;
class QSplitter;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:

    QListWidget *list_;

    QTextEdit *ed1_;
    QTextEdit *ed2_;
    QTextEdit *ed3_;
    QSplitter *sp_;
};
#endif // DIALOG_H
