//
//  GameOverScene.cpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

#include "GameOverScene.hpp"

GameOverScene::GameOverScene()
{
    
}

GameOverScene::~GameOverScene()
{
    
}

bool GameOverScene::init()
{
    if(!Layer::init())
    {
        return true;
    }
    
    //获得场景可视区域大小和原点坐标
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //初始化场景加入背景图片
    backImage = Sprite::create("gameover.png");
    backImage->setAnchorPoint(Vec2(0,0));
    backImage->setPosition(Vec2(0,0));
    //backImage->setOpacity(200);
    this->addChild(backImage);
    
    //场景切换效果
    auto fadein = FadeIn::create(0.2);
    backImage->runAction(fadein);
    
    
    //游戏返回label
    auto backLabel = Label::createWithTTF("Try Agian", "fonts/Marker Felt.ttf", 40);
    backLabel->setColor(Color3B::BLACK);
    
    //游戏结束label
    auto exitLabel = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 40);
    exitLabel->setColor(Color3B::BLACK);
    
    //游戏返回按钮
    auto backButton = MenuItemLabel::create(backLabel, CC_CALLBACK_1(GameOverScene::goToGameScene, this));
    backButton->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    
     //游戏结束按钮
    auto exitButton = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(GameOverScene::gameOver, this));
    exitButton->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2 - 60));
    
    
    //菜单类
    auto menu  = Menu::create(backButton,exitButton,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    
    return true;
}


//MARK:返回游戏场景的回调函数
void GameOverScene::goToGameScene(Ref * pSender)
{
    //动画切换效果
    //auto fadeout = FadeOut::create(1);
   // backImage->runAction(fadeout);
    tsm->createGameScene();
}



//MARK:结束游戏的回调函数
void GameOverScene::gameOver(Ref *pSender)
{
           Director::getInstance()->end();
    exit(0);
}





