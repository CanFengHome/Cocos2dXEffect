//
//  LayerAnimationStudy01.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#include "LayerAnimationStudy01.h"

// Layer01Test

USING_NS_CC;
bool LayerAnimationStudy01::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    // 沿着X轴错切30度
    Sprite* pSprite1 = Sprite::create();
    pSprite1->setTextureRect(Rect(0.0f, 0.0f, 100.0f, 100.0f));
    pSprite1->setColor(Color3B::RED);
    pSprite1->setPosition(Vec2(winSize*0.5f)-Vec2(200.0f,0.0f));
    addChild(pSprite1);
    pSprite1->runAction(SkewTo::create(2.0f, 30.0f, 0.0f));
    
    // 沿着X轴错切30度 沿着Y轴错切30度
    Sprite* pSprite2 = Sprite::create();
    pSprite2->setTextureRect(Rect(0.0f, 0.0f, 100.0f, 100.0f));
    pSprite2->setColor(Color3B::BLUE);
    pSprite2->setPosition(winSize*0.5f);
    addChild(pSprite2);
    pSprite2->runAction(SkewTo::create(2.0f, 30.0f, 30.0f));

    // 沿着Y轴错切30度
    Sprite* pSprite3 = Sprite::create();
    pSprite3->setTextureRect(Rect(0.0f, 0.0f, 100.0f, 100.0f));
    pSprite3->setColor(Color3B::GREEN);
    pSprite3->setPosition(Vec2(winSize*0.5f)+Vec2(200.0f,0.0f));
    addChild(pSprite3);
    pSprite3->runAction(SkewTo::create(2.0f, 0.0f, 30.0f));
    
    return true;
}
