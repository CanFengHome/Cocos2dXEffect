//
//  LayerJellyStudy01.cpp
//  SharpEffect
//
//  Created by ccf on 16/5/31.
//
//

#include "LayerJellyStudy01.h"

USING_NS_CC;
bool LayerJellyStudy01::init()
{
    if (!LayerColor::initWithColor(Color4B::GRAY))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();

    Sprite* pRectSprite = Sprite::create();
    pRectSprite->setTextureRect(Rect(0.0f, 0.0f, 25.0f, 25.0f));
    addChild(pRectSprite);
    pRectSprite->setColor(Color3B::BLUE);
    pRectSprite->setPosition(winSize*0.5f);
    
    Sprite* pDiscountSprite = Sprite::create("res/jelly_study/icon/icon_discount.png");
    addChild(pDiscountSprite);
    pDiscountSprite->setPosition(winSize*0.5f);
    pDiscountSprite->setAnchorPoint(Vec2(1.0f, 1.0f));
    ActionInterval* pSwingAction = Sequence::create(EaseIn::create(RotateTo::create(0.5f, -30), 2.0),
                                                    EaseOut::create(RotateTo::create(0.5f, -60), 2.0),
                                                    EaseIn::create(RotateTo::create(0.5f, -30), 2.0),
                                                    EaseOut::create(RotateTo::create(0.5f, 0), 2.0),
                                                    nullptr);
    pDiscountSprite->runAction(RepeatForever::create(pSwingAction));
    
    return true;
}