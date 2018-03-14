//
//  GameScene.cpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

#include "GameScene.hpp"
#include "MapGrid.hpp"
#include "SimpleAudioEngine.h"

//测试thing.h
//#include "Thing.hpp"


GameScene::GameScene()
{
    
}

GameScene::~GameScene()
{
    
}

LoadingBar* GameScene::loadingBar = nullptr;//初始化进度条为空



bool GameScene::init()
{
    
    if(!Layer::init())
    {
        return false;
    }
    
    
    //获得显示区域尺寸
    
    auto size = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
  
    //加载背景音乐
    auto bgm = CocosDenshion::SimpleAudioEngine::getInstance();
    bgm->preloadEffect("bgmusic1.mov");
    
    //播放背景音乐
    bgm->playBackgroundMusic("bgmusic1.mov",true);
    
    //加载背景图
    m_bg = Sprite::create("bground1.png");
    m_bg->setAnchorPoint(Vec2(0,0));
    m_bg->setTag(100);//bground1,2,3,4 的tag分别为100,101,102,103
    //m_bg->setOpacity(200);//改变透明度
    this->addChild(m_bg);
    
    
    //加载网格地图背景
    auto board = Sprite::create("board.png");
    board->setAnchorPoint(Vec2(0,1));
    board->setPosition(Vec2(0,size.height));
    board->setOpacity(140);
    this->addChild(board);
    
    
    //加入容器节点
    mapGrid = MapGrid::create(10, 10);
    mapGrid->setAnchorPoint(Vec2(0,0));
    mapGrid->setPosition(16,size.height - mapGrid->getRow() * 32 + 16);
    log(" mapGrid 坐标");
    //log(mapGrid->getPositionX());
    //log(mapGrid->getPositionY());
    this->addChild(mapGrid);
    
    
    
      //退出label
    auto exitLabel = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 30);
    exitLabel->setColor(Color3B::BLACK);
    
    //Exit按钮
    auto exitButton = MenuItemLabel::create(exitLabel, CC_CALLBACK_1(GameScene::gameOver, this));
    exitButton->setPosition(Vec2(origin.x + size.width - 50,origin.y + exitButton->getContentSize().height/2 + 40));
    
    //创建菜单
    auto menu = Menu::create(exitButton, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    //计时条外框
    auto loadingRect = Sprite::create("bonusbar.png");
    loadingRect->setPosition(Vec2(size.width/2,loadingRect->getContentSize().height/2 + 10));
    loadingRect->setOpacity(200);//改变透明度
    this->addChild(loadingRect);
    
    //计时条bonusbar_fill.png
    loadingBar = LoadingBar::create("bonusbar_fill.png");
    loadingBar->setPercent(100);
    loadingBar->setPosition(loadingRect->getPosition());
    this->addChild(loadingBar);
    
    //设置一个定时器用来检测游戏时间是否结束，并随着时间变化改变游戏背景
    
    schedule(schedule_selector(GameScene::changeBackImage), 0.1);
    schedule(schedule_selector(GameScene::ifWintoOver), 0.1);
    
    
    return true;
}


//MARK:跳到游戏结束场景
void GameScene::goToGameOverScene(Ref *pSender)
{
    tsm->creteGameOverScene();
}


//MARK:游戏结束回调方法
void GameScene::gameOver(Ref *pSender)
{
    Director::getInstance()->end();
    exit(0);
}

//MARK:计时器进度条回调函数
void GameScene::changeBackImage(float dt)
{
    //定时改变进度条进度(每次减少5)
    //-0.1 共计1分40秒
    loadingBar->setPercent(loadingBar->getPercent() - 0.3);
    
    //通过判断MapGrid::win是否为true
    
    //倒计时结束，游戏结束
    if(loadingBar->getPercent() == 0)
    {
        //删除定时器
        //MapGrid::win = false;
        unschedule(schedule_selector(GameScene::changeBackImage));
        log("game Over by SCH");
        
       tsm->creteGameOverScene();
    }
    
    //设置背景切换效果
    auto fadein = FadeIn::create(0.1);//淡入
    auto fadeout = FadeOut::create(0.1);//淡出
    
    CallFunc *call = nullptr;
    //根据进度条改变背景
    //75 - 100
    if(loadingBar->getPercent() < 100 && loadingBar->getPercent() > 75)
    {
        /*此if判断如果进度条变长时如果是75-100范围内的背景图片则不需要改变背景
        不执行else语句*/
        if(m_bg->getTag() == 100)
        {
            call = nullptr;
        }
        else{
            //改变背景的闭包函数
            call = CallFunc::create([this](){
                m_bg->setTexture("bground1.png");
            });
            m_bg->setTag(100);
        }
    }
    
    //50 - 75
    if(loadingBar->getPercent() < 75 && loadingBar->getPercent() > 50)
    {
        /*此if判断如果进度条变长时如果是75-100范围内的背景图片则不需要改变背景
         不执行else语句*/
        if(m_bg->getTag() == 101)
        {
            call = nullptr;
        }
        else{
            //改变背景的闭包函数
            call = CallFunc::create([this](){
                m_bg->setTexture("bground2.png");
            });
            m_bg->setTag(101);
        }
    }
    
    //25 - 50
    if(loadingBar->getPercent() < 50 && loadingBar->getPercent() > 25)
    {
        /*此if判断如果进度条变长时如果是75-100范围内的背景图片则不需要改变背景
         不执行else语句*/
        if(m_bg->getTag() == 102)
        {
            call = nullptr;
        }
        else{
            //改变背景的闭包函数
            call = CallFunc::create([this](){
                m_bg->setTexture("bground3.png");
            });
            m_bg->setTag(102);
        }
    }

 //0 - 25
    if(loadingBar->getPercent() < 25)
    {
        /*此if判断如果进度条变长时如果是75-100范围内的背景图片则不需要改变背景
         不执行else语句*/
        if(m_bg->getTag() == 103)
        {
            call = nullptr;
        }
        else{
            //改变背景的闭包函数
            call = CallFunc::create([this](){
                m_bg->setTexture("bground4.png");
            });
            m_bg->setTag(103);
        }
    }

    //运行场景切换动画
    if(call)
    {
        m_bg->runAction(Sequence::create(fadeout,call,fadein, NULL));
    }
}


void GameScene::ifWintoOver(float dt)
{
    //如果isWin函数为真就交换场景
    if(mapGrid->isWin())
    {
        unschedule(schedule_selector(GameScene::ifWintoOver));
        tsm->creteGameOverScene();
    }
    
    return;
}







