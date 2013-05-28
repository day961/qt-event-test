#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mylabel.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private:
    Ui::Dialog *ui;
    MyLabel *label;
};

#endif // DIALOG_H
