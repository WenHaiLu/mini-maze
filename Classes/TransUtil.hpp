//
//  TransUtil.hpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/16.
//
//

//第三方场景切换UI库
#ifndef TransUtil_hpp
#define TransUtil_hpp

#include <stdio.h>
#include "cocos2d.h"

#define MAX_LAYER 41
static int SceneIdx = 0;

TransitionScene* createTransition(int nSceneIdx, float t, Scene* s)
{
    Director::getInstance()->setDepthTest(false);
    
    switch(nSceneIdx)
    {
        case 0: return TransitionJumpZoom::create(t, s);//±æ≥°æ∞Ã¯∂Øœ˚ ß∫Û¡Ì“ª≥°æ∞Ã¯∂Ø≥ˆœ÷
            
        case 1: return TransitionProgressRadialCCW::create(t, s);//±æ≥°æ∞ƒÊ ±’Îœ˚ ßµΩ¡Ì“ª≥°æ∞
        case 2: return TransitionProgressRadialCW::create(t, s);//±æ≥°æ∞À≥ ±’Îœ˚ ßµΩ¡Ì“ª≥°æ∞
        case 3: return TransitionProgressHorizontal::create(t, s); //±æ≥°æ∞¥”◊ÛµΩ”“œ˚ ßÕ¨ ±¡Ì“ª≥°æ∞≥ˆœ÷
        case 4: return TransitionProgressVertical::create(t, s);//±æ≥°æ∞¥”…œµΩœ¬œ˚ ßÕ¨ ±¡Ì“ª≥°æ∞≥ˆœ÷
        case 5: return TransitionProgressInOut::create(t, s);//±æ≥°æ∞¥”÷–º‰µΩÀƒ÷‹œ˚ ßÕ¨ ±¡Ì“ª≥°æ∞≥ˆœ÷
        case 6: return TransitionProgressOutIn::create(t, s); //±æ≥°æ∞¥”Àƒ÷‹µΩ÷–º‰œ˚ ßÕ¨ ±¡Ì“ª≥°æ∞≥ˆœ÷
            
        case 7: return TransitionCrossFade::create(t,s); //¬˝¬˝µ≠ªØµΩ¡Ì“ª≥°æ∞
            
        case 8: {
            Director::getInstance()->setDepthTest(true);
            return TransitionPageTurn::create(t, s, false);
        }//œÚ∫Û∑≠“≥«–ªª
        case 9:{
            Director::getInstance()->setDepthTest(true);
            return TransitionPageTurn::create(t, s, true);
        }//œÚ«∞∑≠“≥«–ªª
        case 10: return TransitionFadeTR::create(t, s);//±æ≥°æ∞◊Ûœ¬Ω«µΩ”“…œΩ«∑ΩøÈœ˚ ßµΩ¡Ì“ª≥°æ∞
        case 11: return TransitionFadeBL::create(t, s);//±æ≥°æ∞”“…œΩ«µΩ◊Ûœ¬Ω«∑ΩøÈœ˚ ßµΩ¡Ì“ª≥°æ∞
        case 12: return TransitionFadeUp::create(t, s);//±æ≥°æ∞¥”œ¬µΩ…œ∫·Ãıœ˚ ßµΩ¡Ì“ª≥°æ∞
        case 13: return TransitionFadeDown::create(t, s);//±æ≥°æ∞¥”…œµΩœ¬∫·Ãıœ˚ ßµΩ¡Ì“ª≥°æ∞
            
        case 14: return TransitionTurnOffTiles::create(t, s);//±æ≥°æ∞–°∑ΩøÈœ˚ ßµΩ¡Ì“ª≥°æ∞
            
        case 15: return TransitionSplitRows::create(t, s);//±æ≥°æ∞»˝æÿ–Œ◊Û”“œ˚ ß∫Û¡Ì“ª≥°æ∞»˝æÿ–Œ◊Û”“≥ˆœ÷
        case 16: return TransitionSplitCols::create(t, s);//±æ≥°æ∞»˝æÿ–Œ…œœ¬œ˚ ß∫Û¡Ì“ª≥°æ∞»˝æÿ–Œ…œœ¬≥ˆœ÷
            
        case 17: return TransitionFade::create(t, s);//±æ≥°æ∞±‰∞µœ˚ ß∫Û¡Ì“ª≥°æ∞¬˝¬˝≥ˆœ÷
        case 18: return TransitionFade::create(t, s, Color3B::WHITE);//±æ≥°æ∞±‰¡¡œ˚ ß∫Û¡Ì“ª≥°æ∞¬˝¬˝≥ˆœ÷
            
        case 19: return TransitionFlipX::create(t, s, TransitionScene::Orientation::LEFT_OVER);//◊ÛœÚ”“∑≠◊™
        case 20: return TransitionFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);//”“œÚ◊Û∑≠◊™
        case 21: return TransitionFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);//…œœÚœ¬∑≠◊™
        case 22: return TransitionFlipY::create(t, s, TransitionScene::Orientation::DOWN_OVER);//œ¬œÚ…œ∑≠◊™
        case 23: return TransitionFlipAngular::create(t, s, TransitionScene::Orientation::LEFT_OVER);//◊Ûœ¬Ω«œÚ”“…œΩ«∑≠◊™
        case 24: return TransitionFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);//”“…œΩ«œÚ◊Ûœ¬Ω«
            
        case 25: return TransitionZoomFlipX::create(t, s, TransitionScene::Orientation::LEFT_OVER);//◊ÛœÚ”“∑≠◊™
        case 26: return TransitionZoomFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);//”“œÚ◊Û∑≠◊™
        case 27: return TransitionZoomFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);//œÚœ¬∑≠◊™
        case 28: return TransitionZoomFlipY::create(t, s, TransitionScene::Orientation::DOWN_OVER);//œÚ…œ∑≠◊™
        case 29: return TransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::LEFT_OVER);//◊Ûœ¬Ω«œÚ”“…œΩ«∑≠◊™
        case 30: return TransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);//”“…œΩ«œÚ◊Ûœ¬Ω«
            
        case 31: return TransitionShrinkGrow::create(t, s);//±æ≥°æ∞¬˝¬˝ ’Àıœ˚ ß∫Û¡Ì“ª≥°æ∞¬˝¬˝±‰¥Û∫Û≥ˆœ÷
        case 32: return TransitionRotoZoom::create(t, s);//±æ≥°æ∞–˝◊™œ˚ ß∫Û¡Ì“ª≥°æ∞–˝◊™≥ˆœ÷
            
        case 33: return TransitionMoveInL::create(t, s);//¡Ì“ª≥°æ∞”…’˚ÃÂ¥”◊Û√Ê≥ˆœ÷
        case 34: return TransitionMoveInR::create(t, s); //¡Ì“ª≥°æ∞”…’˚ÃÂ¥””“√Ê≥ˆœ÷
        case 35: return TransitionMoveInT::create(t, s);//¡Ì“ª≥°æ∞”…’˚ÃÂ¥”…œ√Ê≥ˆœ÷
        case 36: return TransitionMoveInB::create(t, s);//¡Ì“ª≥°æ∞”…’˚ÃÂ¥”œ¬√Ê≥ˆœ÷
            
        case 37: return TransitionSlideInL::create(t, s);//±æ≥°æ∞œÚ”“ª¨∂ØµΩ¡Ì“ª≥°æ∞
        case 38: return TransitionSlideInR::create(t, s);//±æ≥°æ∞œÚ◊Ûª¨∂ØµΩ¡Ì“ª≥°æ∞
        case 39: return TransitionSlideInT::create(t, s);//±æ≥°æ∞œÚœ¬ª¨∂ØµΩ¡Ì“ª≥°æ∞
        case 40: return TransitionSlideInB::create(t, s);//±æ≥°æ∞œÚ…œª¨∂ØµΩ¡Ì“ª≥°æ∞
            
        default: break;
    }
    return NULL;
}

#endif /* TransUtil_hpp */
