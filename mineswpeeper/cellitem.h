#ifndef CELLITEM_H
#define CELLITEM_H
//实现每个格子的功能

#include <QPixmap>
#include <QGraphicsPixmapItem>

//每个小格子的行为
enum cellstatus {INITIAL,EXPLODE,FLAG,QUESTION,BLANK,DIGIT};

class cellitem : public QGraphicsPixmapItem {
public:
    cellitem(int x,int y,enum cellstatus status = INITIAL, QGraphicsItem *parent = Q_NULLPTR);
    ~cellitem();

    enum cellstatus getStatus(); //得到当前格子的状态
    void setStatus(enum cellstatus status,int digit = -2); //设置格子状态

    //static只初始化一次
    static QPixmap* _initial;
    static QPixmap* _explode;
    static QPixmap* _flag;
    static QPixmap* _question;
    static QPixmap* _blank;
    static QPixmap* _digits[9];
    /*初始化图片*/

    static int _refCount;

protected:
    int cx;
    int cy;// 每个格子类有的坐标
    enum cellstatus cell ;

};
#endif // CELLITEM_H
