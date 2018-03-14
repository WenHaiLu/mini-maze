//
//  Thing.cpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/20.
//
//

#include "Thing.hpp"

Thing* Thing::createByType(int type,int x,int y)
{
    Thing * thing = new Thing();
    if(thing && thing->init(type, x, y))
    {
        log("creatething");
        thing->autorelease();
        return thing;
    }
    else{
        CC_SAFE_DELETE(thing);
        return nullptr;
    }
    
}



bool Thing::init(int type, int x, int y)
{
    m_type = type;
    m_x = x;
    m_y = y;
    
    this->setAnchorPoint(Vec2(0,0));
    //0为墙
    if(m_type == 0)
    {
        log("纹理墙");
        this->initWithFile("wall.png");
    }
    
    //1为路
    if(m_type == 1)
    {
        log("纹理路");
        this->initWithFile("Way.png");
        this->setOpacity(0);
        //this->s("Way.png");
    }
    
    //2为老鼠
    if(m_type == 2)
    {
        log("纹理鼠");
        this->initWithFile("mouse.png");
        
    }
    
    
    //3为食物
    if(m_type == 3)
    {
        log("纹理食物");
        this->initWithFile("goal.png");
        //this->setTexture("goal.png");
    }
    
    
    
    
    return true;
}





