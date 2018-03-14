//
//  SceneManger.hpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

#ifndef SceneManger_hpp
#define SceneManger_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class SceneManger
{
public:
    Scene *loadScene;//加载场景
    void createLoadScene();//创建加载场景
    Scene *gameScene;//游戏场景
    void createGameScene();//创建游戏场景
    Scene *gameOverScene; //游戏结束场景
    void creteGameOverScene();//创建游戏结束场景
    
};

#endif /* SceneManger_hpp */
