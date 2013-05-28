#include "mylabel.h"
#include <QDir>
#include <QMouseEvent>

#include <QDebug>

MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{

    QDir dir(JPG_PATH);
    QStringList filter;//使用一个QStringList作为过滤器
    filter<<"*.jpg";

    fileNames = dir.entryList(filter,QDir::Files);
    //返回QDir中的文件名（通过filter过滤后）

    displayNum = 0;

    setScaledContents(true);//设置自动伸缩

    setFocusPolicy(Qt::StrongFocus);//强制键盘专注
}

void MyLabel::keyPressEvent(QKeyEvent *ev){
    name = JPG_PATH + fileNames[displayNum];
    if(ev->key()==Qt::Key_Left)
    {
        displayNum--;
        if(displayNum<0)
            displayNum = fileNames.count()-1;
    }else if(ev->key()==Qt::Key_Right)
    {
        displayNum++;
        if(displayNum>=fileNames.count())
            displayNum = 0;
    }
    setPixmap(QPixmap(name));//显示位图
}

void MyLabel::mousePressEvent(QMouseEvent *ev){
    name = JPG_PATH + fileNames[displayNum];
   // setPixmap(QPixmap(name));
    if(ev->x()>240&&ev->button()==Qt::LeftButton)
    {
        displayNum++;
        if(displayNum>=fileNames.count())
            displayNum = 0;
    }else if(ev->x()<=240&&ev->button()==Qt::LeftButton){
        displayNum--;
        if(displayNum<0)
            displayNum = fileNames.count()-1;
    }
    setPixmap(QPixmap(name));//显示位图

    qDebug()<<QString::number(ev->x())
           <<ev->button()<<displayNum;
}
