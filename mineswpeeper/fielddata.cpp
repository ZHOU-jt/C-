#include <fielddata.h>
#include <cstdlib>
#include <ctime>

FieldData* _ins = nullptr; //先初始化为空指针，方便创造单例

FieldData::FieldData(){
    reset();
    srand(time(nullptr));
};

void FieldData::reset(){
    _cells.clear();
    initCells();
    deployMines();
    _visited.clear();
    initVisited();
}; //清空

void FieldData::initCells(){
    switch(_diff){
    case normal :
        _width = 9;
        _height = 9;
        _mines = 10;
        break;
    case medium :
        _width = 16;
        _height =16;
        _mines = 40;
        break;
    case hard :
        _width = 30;
        _height = 16;
        _mines = 100;
        break;
    }
    FieldData::_cells.resize(_width);
    for(int i = 0;i<_width;i++){
        FieldData::_cells[i].resize(_height);
        for(int j = 0;j<_height;j++){
            FieldData::_cells[i][j] = 0;
        }
    }
};//初始化，申请空间

void FieldData::deployMines(){
    int cmines = _mines;
    int randomwidth;
    int randomheight;
    switch(_diff){
    case normal :
        while(cmines){
            randomwidth = rand()%_width;
            randomheight = rand()%_height;
            if(_cells[randomwidth][randomheight] != -1){
                _cells[randomwidth][randomheight] = -1;
            }
            cmines--;
            updateSurrounding(randomheight-1,randomwidth);
            updateSurrounding(randomheight-1,randomwidth-1);
            updateSurrounding(randomheight-1,randomwidth +1);
            updateSurrounding(randomheight,randomwidth-1);
            updateSurrounding(randomheight,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
        }

        //每个格子，也是周围八个格子
        break;
    case medium :
        while(cmines){
            randomwidth = rand()%_width;
            randomheight = rand()%_height;
            if(_cells[randomwidth][randomheight] != -1){
                _cells[randomwidth][randomheight] = -1;
            }
            cmines--;
            updateSurrounding(randomheight-1,randomwidth);
            updateSurrounding(randomheight-1,randomwidth-1);
            updateSurrounding(randomheight-1,randomwidth +1);
            updateSurrounding(randomheight,randomwidth-1);
            updateSurrounding(randomheight,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
        }

        break;
    case hard :
        while(cmines){
            randomwidth = rand()%_width;
            randomheight = rand()%_height;
            if(_cells[randomwidth][randomheight] != -1){
                _cells[randomwidth][randomheight] = -1;
            }
            cmines--;
            updateSurrounding(randomheight-1,randomwidth);
            updateSurrounding(randomheight-1,randomwidth-1);
            updateSurrounding(randomheight-1,randomwidth +1);
            updateSurrounding(randomheight,randomwidth-1);
            updateSurrounding(randomheight,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
            updateSurrounding(randomheight+1,randomwidth+1);
        }
        break;
    }
};
//布雷

void FieldData::initVisited(){
    for(int i = 0;i<_width;i++){
        FieldData::_visited[i].resize(_height);
        for(int j = 0;j<_height;j++){
            FieldData::_visited[i][j] = 0;
        }
    }
};//初始化visited

/*void FieldData::customizeWHM(int cw, int ch, int cm){
     _width = cw;
     _height = ch;
     _mines = cm;
};//每次点击后更新,用户自定义的传入
*/

void FieldData::updateSurrounding(int x, int y){
    if(x >= 0 && x < _width && y >= 0 && y < _height) {
        if(_cells[x][y] != -1) {
            ++_cells[x][y];
        }
    }

};
//若这个格子不是雷，那他的个数就加一，表示周围雷的个数，即使以后变成雷，也没有影响
FieldData* FieldData::getInstance(){
    if(_ins == nullptr){
         _ins = new FieldData();
       }
       return _ins;
}
//若是_ins = nullptr，则没有创建，创建一个

