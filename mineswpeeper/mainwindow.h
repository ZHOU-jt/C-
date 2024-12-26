#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cellitem.h>

#define cellitem_width 30;
#define cellitem_hight 30;
#define start_x 100;
#define start_y 100;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initalization();//初始化
    void clearit();//清理内存
    void newgame();//新游戏
    void overgame();//游戏结束
    bool findall();//找到所有
    void paintevent(QPaintEvent*);//绘制图形
    void mousepressevent(QMouseEvent *e);//鼠标操作
    void drawboard();//绘制整个布局
    void drawitems();//绘制方格
    void drawitem(QPainter &painter,cellitem *pitem);//绘制单个方格
    void checkblankitem(QPoint pt);//查找周围空格
    bool pointinarea(QPoint pt);//是否在区域内

    QMenu *menu1;//菜单栏1
    QMenu *menu2;//菜单栏2

    QAction *easy;//简单
    QAction *normal;//正常
    QAction *hard;//困难
    
public :
    void solt_newgame();//新游戏
    void solt_easy_game();//简单
    void solt_normal_game();//正常
    void solt_hard_game();//困难





private:
    Ui::MainWindow *ui;
    
    QPixmap _flag;
    QPixmap _explode;
    
    int rows;//行数
    int cols;//列数
    int mine;//雷数
    QVector<QPoint>Mines;
    QVector<QVector<cellitem>> cellitems;
    bool iffail;//是否输
};


#endif // MAINWINDOW_H
