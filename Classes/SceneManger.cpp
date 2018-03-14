//
//  SceneManger.cpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

#include "SceneManger.hpp"
#include "LoadScene.hpp"
#include "GameScene.hpp"
#include "GameOverScene.hpp"


void SceneManger::createLoadScene()
{
    loadScene = Scene::create();
    
    auto layer = LoadScene::create();
    
    loadScene->addChild(layer);
    layer->tsm = this;
    
}

void SceneManger::createGameScene()
{
    //开启深度检测
    Director::getInstance()->setDepthTest(true);
    
    gameScene = Scene::create();
    
    auto layer = GameScene::create();
    
    gameScene->addChild(layer);
    
    layer->tsm = this;
    
    //创建场景切换效果
    //TransitionScene *ccts = TransitionCrossFade::create(2, gameScene);
    
    log("游戏场景");
    //切换场景
    Director::getInstance()->replaceScene(TransitionFade::create(2, gameScene));
    
}

void SceneManger::creteGameOverScene()
{
     //开启深度检测
    Director::getInstance()->setDepthTest(true);
    
    gameOverScene = Scene::create();
    
    auto layer = GameOverScene::create();
    
    gameOverScene->addChild(layer);
    
    layer->tsm = this;
    
    //创建场景切换效果
   // TransitionScene *ccts = TransitionCrossFade::create(2,gameOverScene);
    
    //切换场景
    Director::getInstance()->replaceScene(TransitionFade::create(2, gameOverScene));
    
}



