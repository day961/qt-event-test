#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    label = new MyLabel(this);
    label->setGeometry(10,10,480,320);
    label->setText("Click this!");
    //label->setPixmap(QPixmap(":/jpg/Koala.jpg"));
}

Dialog::~Dialog()
{
    delete ui;
}
