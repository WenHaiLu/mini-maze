//
//  LoadScene.cpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

//屏幕大小320 * 480

#include "LoadScene.hpp"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

LoadScene::LoadScene()
{
    
}

LoadScene::~LoadScene()
{
    
}

bool LoadScene::init()
{
    //调用父类初始化
    if(!Layer::init())
    {
        return false;
    }
    
    //获取当前可视区域尺寸
    auto size = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    //加载背景音乐
    auto bgm = CocosDenshion::SimpleAudioEngine::getInstance();
    bgm->preloadEffect("bgmusic1.mov");
    
    //播放背景音乐
    bgm->playBackgroundMusic("bgmusic1.mov",true);

    
    //获取背景图
    auto backImage = Sprite::create("bground3.png");
    backImage->setAnchorPoint(Vec2(0,0));
    this->addChild(backImage);
    
    
    auto label = Label::createWithSystemFont("迷你迷宫", "Arial", 40);
    label->setPosition(Vec2(size.width/2,size.height/4 * 3 + 40));
   // label->setColor(Color3B::BLACK);
    this->addChild(label);
    
    //按钮部分
    //1.退出按钮
    //2.测试按钮
    
    //退出Label
   // auto closeLabel = Label::createWithSystemFont("退出", "Arial", 20);
    //closeLabel->setColor(Color3B::BLACK);
    
    //测试Label
    auto testLabel = Label::createWithSystemFont("开始游戏", "Arial", 25);
   // testLabel->setColor(Color3B::BLACK);
    
    //退出按钮
    //auto closeButton = MenuItemLabel::create(closeLabel, CC_CALLBACK_1(LoadScene::exitGame, this));
   // closeButton->setPosition(Vec2(origin.x + size.width - closeButton->getContentSize().width/2 ,origin.y + closeButton->getContentSize().height/2));
    
    
    //测试按钮
    auto testButton = MenuItemLabel::create(testLabel, CC_CALLBACK_1(LoadScene::goToGameScene, this));
    testButton->setPosition(Vec2(size.width/2,size.height/4));
    
    //创建一个菜单
    auto menu = Menu::create(testButton, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    
    
    
    return true;
}





void LoadScene::goToGameScene(Ref *pSender)
{
    tsm->createGameScene();
}

void LoadScene::exitGame(Ref *pSender)
{
    log("exit");
}








