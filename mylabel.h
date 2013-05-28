#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QKeyEvent>
#define JPG_PATH ":/jpg/"

class MyLabel : public QLabel //自己定义一个Mylabel类，继承自QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    
signals:
    
public slots:
protected:
    void mousePressEvent(QMouseEvent *ev);
    void keyPressEvent(QKeyEvent *ev);
    QStringList fileNames;
    int displayNum;
    QString name;
};

#endif // MYLABEL_H
