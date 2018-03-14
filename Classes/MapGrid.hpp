//
//  MapGrid.hpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/20.
//
//

#ifndef MapGrid_hpp
#define MapGrid_hpp

#include "cocos2d.h"
//#include "GameOverScene.hpp"
#include <vector>
using namespace std;
USING_NS_CC;


#define M_WALL 0//墙为0
#define M_WAY 1//路为1
#define M_MOUSE 2//鼠为2
#define M_FOOD 3//食物为3

//宽度
#define M_GRIDWIDTH 32

class Thing;

class MapGrid : public Node
{
public:
    MapGrid();
    //根据行列布局
    static MapGrid* create(int row,int col);
    bool init(int row,int col);
    //CREATE_FUNC(MapGrid);
    int getRow(){return m_row;}
    int getCol(){return m_col;}
    
public:
    //创建thing对象
    void createAThing();
    
    //设置thing的实践位置
    void setThingPixPos(Thing * thing,int x,int y);
    
public:
    //键盘按下回调方法
    void onMyKeyPressed(EventKeyboard::KeyCode keycode,Event * event);
    
    //键盘释放回调方法
    void onMyKeyReleased(EventKeyboard::KeyCode keycode,Event *event);
    
    //输赢判断
    bool win;
    bool isWin()
    {
        if(win)
        {
            return true;
        }
        else{
            return false;
        }
    }
    
private:
    int m_row;//设置行数
    int m_col;//设置列数
    
    //存放容器
    vector<vector<Thing *>> thingBox;
    int *mapdata;//地图数组数据
    //定义一个鼠类型的指针；
    Thing* mouse;
    
};



#endif /* MapGrid_hpp */
