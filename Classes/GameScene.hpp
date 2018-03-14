//
//  GameScene.hpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include "SceneManger.hpp"
#include "cocos2d.h"
#include "ui/CocosGUI.h"//引入UI库文件
USING_NS_CC;
using namespace ui;

class MapGrid;

class GameScene :public Layer
{
public:
    GameScene();
    ~GameScene();
    CREATE_FUNC(GameScene);
    virtual bool init();
    SceneManger *tsm;//场景控制器指针
   
public:
    //跳到游戏结束场景的回调函数
    void goToGameOverScene(Ref *pSender);
    
    //游戏结束的回调函数
    void gameOver(Ref *pSender);
    
    //计时器进度条回调函数
    void changeBackImage(float dt);
    
    //是否输赢判断器
    void ifWintoOver(float dt);
    
private:
    Sprite *m_bg;//背景图片指针
    static LoadingBar *loadingBar;
    MapGrid *mapGrid;
    
};


#endif /* GameScene_hpp */
