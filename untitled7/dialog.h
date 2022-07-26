#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QSpinBox;
class HexSpinBox;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QSpinBox *spinBox_;
    HexSpinBox *spinBox_2;

};
#endif // DIALOG_H
