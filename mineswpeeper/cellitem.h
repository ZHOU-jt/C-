#ifndef CELLITEM_H
#define CELLITEM_H
//实现每个格子的功能

#include <QPixmap>
#include <QGraphicsPixmapItem>

//每个小格子的行为
enum status {INITIAL,EXPLODE,FLAG,QUESTION,BLANK,DIGIT};

class cellitem {
public:
    cellitem(int x,int y,enum status cell_status = INITIAL, QGraphicsItem *parent = Q_NULLPTR);
    ~cellitem();

    enum status getStatus(); //得到当前格子的状态
    void setStatus(enum status s,int digit = -2); //设置格子状态

    //static只初始化一次
    /*初始化图片*/

protected:
    int cx;
    int cy; // 每个格子类有的坐标
    enum status cell ;


};
#endif // CELLITEM_H
