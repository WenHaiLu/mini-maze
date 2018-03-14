//
//  Thing.hpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/20.
//
//

#ifndef Thing_hpp
#define Thing_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class Thing : public Sprite
{
public:
    static Thing * createByType(int type,int x,int y);
    //Thing(int type,int x,int y);
    bool init(int type,int x,int y);
    
    
public:
    //获得类型和坐标
    int getType(){return m_type;}
    int getX(){return m_x;}
    int getY(){return m_y;}
    
    //设置坐标和类型
    void setX(int x){m_x = x;}
    void setY(int y){m_y = y;}
    void setType(int type){m_type = type;}
    
private:
    //类型和坐标
    int m_type;
    int m_x;
    int m_y;
    
};


#endif /* Thing_hpp */
