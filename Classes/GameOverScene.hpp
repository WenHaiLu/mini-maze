//
//  GameOverScene.hpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

#ifndef GameOverScene_hpp
#define GameOverScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManger.hpp"
USING_NS_CC;

class GameOverScene : public Layer
{
public:
    GameOverScene();
    ~GameOverScene();
    CREATE_FUNC(GameOverScene);
    virtual bool init();
    SceneManger *tsm;//场景控制器指针
    
public:
    //返回游戏场景的回调函数
    void goToGameScene(Ref * pSender);
    //结束游戏的回调函数
    void gameOver(Ref *pSender);

private:
    Sprite *backImage;//游戏背景图片
    
};


#endif /* GameOverScene_hpp */
