//
//  MapGrid.cpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/20.
//
//

#include "MapGrid.hpp"
#include "Map.hpp"
#include "Thing.hpp"
//#include "GameScene.hpp"



MapGrid::MapGrid()
{
    mouse = nullptr;
    win = false;
}



MapGrid * MapGrid::create(int row,int col)
{
    auto mapgrid = new MapGrid();
    if(mapgrid && mapgrid->init(row, col))
    {
        mapgrid->autorelease();
        return mapgrid;
    }
    else{
        CC_SAFE_DELETE(mapgrid);
        return nullptr;
    }
}




bool MapGrid::init(int row,int col)
{
    Node::init();
    log("mapGrid init");
    m_row = row;
    m_col = col;
    mapdata = nullptr;
    
    thingBox.resize(m_row);
    for(auto &vec : thingBox)
    {
        vec.resize(m_col);
    }
    
    //创建地图
    createAThing();
    
    //注册键盘事件
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(MapGrid::onMyKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(MapGrid::onMyKeyReleased,this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    
    return true;
}

void MapGrid::createAThing()
{
    // - 1 选择第一张地图
    mapdata = setMap(1);
    Thing *thing = nullptr;
    for(int i = 0;i < m_row;i++)
    {
        for(int j = 0;j < m_col;j++)
        {
            if(mapdata[i * m_row + j] == M_WALL)
            {
                log("创建墙");
                //创建墙-0
                thing = Thing::createByType(M_WALL,i,j);
                setThingPixPos(thing, i, j);
                thingBox[i][j] = thing;//向盒子中同样位置装入对象
                this->addChild(thing);
            }
            
            if(mapdata[i * m_row + j] == M_WAY)
            {
                //创建路-1
                log("创建路");
                thing = Thing::createByType(M_WAY,i,j);
                setThingPixPos(thing, i, j);
                thingBox[i][j] = thing;//向盒子中同样位置装入对象
                this->addChild(thing);
            }
            
            if(mapdata[i * m_row + j] == M_MOUSE)
            {
                //创建鼠-2
                log("创建鼠");
                thing = Thing::createByType(M_MOUSE, i, j);
                setThingPixPos(thing, i, j);
                thingBox[i][j] = thing;
                this->addChild(thing);
            }
            
            if(mapdata[i * m_row + j] == M_FOOD)
            {
                log("创建食物");
                thing = Thing::createByType(M_FOOD,i,j);
                setThingPixPos(thing, i, j);
                thingBox[i][j] = thing;//向盒子中同样位置装入对象
                this->addChild(thing);
        
         }
    
        }
    }
}



void MapGrid::setThingPixPos(Thing * thing,int x,int y)
{
    thing->setPosition(x * 32,y * 32);
}



//MARK:-键盘回调方法
//键盘按下回调方法
void MapGrid::onMyKeyPressed(EventKeyboard::KeyCode keycode,Event * event)
{
    log("按下键盘");
    //通过遍历thing向量组来获得mouse
    for(int i = 0;i < m_row;i++)
    {
        for(int j = 0;j < m_col;j++)
        {
            if(thingBox[i][j]->getType() == M_MOUSE)
            {
                mouse = thingBox[i][j];
                log("%d, %d",mouse->getX(),mouse->getY());
                break;
            }
        }
    }
    
    //W向上移动
    if(keycode == EventKeyboard::KeyCode::KEY_W||keycode ==EventKeyboard::KeyCode::KEY_CAPITAL_W)
    {
        
        log("W");
        int x = mouse->getX();
        int y = mouse->getY();
        if(thingBox[x][y+1]->getType() == M_WAY)
        {
            log("移动W");
            thingBox[x][y+1]->setTexture("mouse.png");
            thingBox[x][y+1]->setType(M_MOUSE);
            thingBox[x][y+1]->setOpacity(225);
          
            mouse->setTexture("Way.png");
            mouse->setOpacity(0);
            mouse->setType(M_WAY);
        }
        else{log("这是墙，不能移动");}
        
        if(thingBox[x][y+1]->getType() == M_FOOD)
        {
            log("YOU WIN");
            thingBox[x][y+1]->setTexture("mouse.png");
            mouse->setTexture("Way.png");
            mouse->setOpacity(0);
            mouse->setType(M_WAY);
            win = true;
        }

        
        
    }
    
    //向下移动
    if(keycode == EventKeyboard::KeyCode::KEY_S||keycode ==EventKeyboard::KeyCode::KEY_CAPITAL_S)
    {
        
        log("S");
        int x = mouse->getX();
        int y = mouse->getY();
        if(thingBox[x][y-1]->getType() == M_WAY)
        {
            log("移动W");
            thingBox[x][y-1]->setTexture("mouse.png");
            thingBox[x][y-1]->setType(M_MOUSE);
            thingBox[x][y-1]->setOpacity(225);
            
            mouse->setTexture("Way.png");
            mouse->setOpacity(0);
            mouse->setType(M_WAY);
        }
        else{log("这是墙，不能移动");}
        
         if(thingBox[x][y-1]->getType() == M_FOOD)
         {
             log("YOUWIN");
             thingBox[x][y-1]->setTexture("mouse.png");
             mouse->setTexture("Way.png");
             mouse->setOpacity(0);
             mouse->setType(M_WAY);

             win = true;
             
         }
        
    }

    //向左移动
    if(keycode == EventKeyboard::KeyCode::KEY_A||keycode ==EventKeyboard::KeyCode::KEY_CAPITAL_A)
    {
        
        log("A");
        int x = mouse->getX();
        int y = mouse->getY();
        if(thingBox[x-1][y]->getType() == M_WAY)
        {
            log("移动W");
            thingBox[x-1][y]->setTexture("mouse.png");
            thingBox[x-1][y]->setType(M_MOUSE);
            thingBox[x-1][y]->setOpacity(225);
            
            mouse->setTexture("Way.png");
            mouse->setOpacity(0);
            mouse->setType(M_WAY);
        }
        else{log("这是墙，不能移动");}
       
        if(thingBox[x-1][y]->getType() == M_FOOD)
        {
            log("YOU WIN");
            thingBox[x-1][y]->setTexture("mouse.png");
            mouse->setTexture("Way.png");
            mouse->setOpacity(0);
            mouse->setType(M_WAY);

            win = true;
        }

    }

    // 向右移动
    if(keycode == EventKeyboard::KeyCode::KEY_D||keycode ==EventKeyboard::KeyCode::KEY_CAPITAL_D)
    {
        
        log("D");
        int x = mouse->getX();
        int y = mouse->getY();
        if(thingBox[x+1][y]->getType() == M_WAY)
        {
            log("移动W");
            thingBox[x+1][y]->setTexture("mouse.png");
            thingBox[x+1][y]->setType(M_MOUSE);
            thingBox[x+1][y]->setOpacity(225);
            
            mouse->setTexture("Way.png");
            mouse->setOpacity(0);
            mouse->setType(M_WAY);
        }
        else{log("这是墙，不能移动");}
        
        if(thingBox[x+1][y]->getType() == M_FOOD)
        {
            log("YOU WIN");
            thingBox[x+1][y]->setTexture("mouse.png");
            mouse->setTexture("Way.png");
            mouse->setOpacity(0);
            mouse->setType(M_WAY);

            win = true;
        }
    }

}

//键盘释放回调方法
void MapGrid::onMyKeyReleased(EventKeyboard::KeyCode keycode,Event *event)
{
    log("释放键盘");
    
}















