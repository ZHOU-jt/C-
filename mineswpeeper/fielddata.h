#ifndef FIELDDATA_H
#define FIELDDATA_H

#include <vector>
using namespace std;

enum GameDifficulty {normal,medium,hard};
//hard: 16*30 100  medium:16*16 40 normal: 9*9 10

#define Field (FieldData::getInstance())

typedef vector<int> CellColumn; //储存每个格子（整型数）的列
typedef vector<CellColumn> CellMatrix; //所有列变成行

class FieldData
{
public:
    ~FieldData();
    static FieldData * getInstance(); // ？

    inline int getWidth(){return _width;}
    inline int getHeight(){return _height;}
    inline int getMines(){return _mines;}
    const CellMatrix & getCells(){return _cells;}

    void reset(); //有什么用
    void initCells();//初始化，申请空间
    void deployMines();//布雷
    void initVisited();//初始化_visited

    void customizeWHM(int cw, int ch, int cm);//每次点击后更新（参数：宽，高，雷）

    //void dump();//布雷之后打印

    CellMatrix _cells;  // 是所有格子
    CellMatrix _visited;//是否已经扫过(扫过则为1，否则为0)

protected:
    int _width;
    int _height;
    int _mines;
    //    CellMatrix _cells;
    enum GameDifficulty _diff ;
    void updateSurrounding(int x, int y);

private:
    FieldData(); //单例模式,只有一个实际上
    static FieldData *_ins; //有什么用
};

#endif // FIELDDATA_H
