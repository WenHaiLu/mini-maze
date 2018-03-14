//
//  LoadScene.hpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

#ifndef LoadScene_hpp
#define LoadScene_hpp

#include <stdio.h>
#include "SceneManger.hpp"
#include "cocos2d.h"
USING_NS_CC;


class LoadScene :public Layer
{
public:
    CREATE_FUNC(LoadScene);
    LoadScene();
    ~LoadScene();
    virtual bool init();//加载场景初始化
    SceneManger *tsm;
    
    
public:
    //跳到游戏场景的回调
    void goToGameScene(Ref *pSender);
    
    //退出游戏的回调
    void exitGame(Ref *pSender);
  
    
};

#endif /* LoadScene_hpp */
