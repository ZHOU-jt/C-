#include "cellitem.h"
#include <fielddata.h>

int cellitem::_refCount = 0;

QPixmap* cellitem::_blank = nullptr;
QPixmap* cellitem::_explode = nullptr;
QPixmap* cellitem::_flag = nullptr;
QPixmap* cellitem::_initial = nullptr;
QPixmap* cellitem::_question = nullptr;
QPixmap* cellitem::_digits[9] = {nullptr};

// 初始化

cellitem::cellitem(int x,int y,enum cellstatus status , QGraphicsItem *parent)
    :
        QGraphicsPixmapItem(parent){
    cx = x;
    cy = y;
    cell = status;
    ++_refCount;//创建第一个cellItem时加载所有图片,并不是每个格子的图片，只是先加载，之后再赋给每个格子

    if(_refCount == 1) {//引用计数，保证只new一次
        _initial   =   new QPixmap("://images/initial.png");
        _flag       =   new QPixmap("://images/flag.png");
        _question   =   new QPixmap("://images/question.png");
        _blank      =   new QPixmap("://images/blank.png");
        _explode    =   new QPixmap("://images/explode.png");
        // 要改成具体地址

        QString prefix = "://images/";
        QString num;
        QString suffix = ".png";


        for(int i=1;i<9;++i){
            QString fileName;
            fileName+= prefix;
            fileName+=num.setNum(i);
            fileName+=suffix;
            _digits[i] = new QPixmap(fileName);
        }
    }
    setPixmap (*_initial);
    //qDebug()<<this<<endl;
}

cellitem::~cellitem(){
    //释放所有cellItem后，释放图片
    if(--_refCount == 0){
        delete _initial   ;
        delete _flag      ;
        delete _question  ;
        delete _blank     ;
        delete _explode   ;
        for(int i=0;i<9;++i){
            delete _digits[i];
        }
    }
}

enum cellstatus cellitem::getStatus(){
    return cell;
}

void cellitem::setStatus(enum cellstatus status,int digit){
    cell =status;
    switch(cell){
    case INITIAL:
        setPixmap(*_initial);
        break;
    case FLAG:
        setPixmap(*_flag);
        break;
    case QUESTION:
        setPixmap(*_question);
        break;
    case EXPLODE:
        setPixmap(*_explode);
        break;
    case DIGIT:
        setPixmap(*_digits[digit]);
        break;
    case BLANK:
        setPixmap(*_blank);
        break;
    default:
        break;
    }
}
//每个格子设置图片
