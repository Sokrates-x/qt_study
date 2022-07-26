#ifndef CDIALOG_H
#define CDIALOG_H

#include <QDialog>
#include "dialog.h"

class cdialog : public QDialog
{
public:
    cdialog();

protected:
    void done(int);

private:
    Dialog *dialog_;
    QPushButton *okb_;
};

#endif // CDIALOG_H
