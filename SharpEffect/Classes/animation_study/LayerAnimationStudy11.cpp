//
//  LayerAnimationStudy11.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#include "LayerAnimationStudy11.h"

USING_NS_CC;
bool LayerAnimationStudy11::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pItemSprite = Sprite::create("res/ui/coin.png");
    pItemSprite->setPosition(100.0f,300.0f);
    pItemSprite->setLocalZOrder(2);
    addChild(pItemSprite);
    
    PointArray* pPtArray = PointArray::create(10);
    pPtArray->addControlPoint(Vec2(winSize.width*0.5f, 50));
    pPtArray->addControlPoint(Vec2(winSize.width-80.0f,120));
    pPtArray->addControlPoint(Vec2(winSize.width-80,winSize.height-150));
    pPtArray->addControlPoint(Vec2(50.0f,winSize.height-150));
    pPtArray->addControlPoint(Vec2(50.0f, 120));
    pPtArray->addControlPoint(Vec2(winSize.width*0.5f, 50));
    
    int referenceCount = 6;//pPtArray->getReferenceCount();
    for (int i=0; i<referenceCount; ++i)
    {
        Vec2 ptItem = pPtArray->getControlPointAtIndex(i);
        createControlPoint(ptItem);
    }
    
    pItemSprite->setPosition(pPtArray->getControlPointAtIndex(0));
    
    float tension = 0.0f;
    DrawNode* pDrawNode = DrawNode::create();
    addChild(pDrawNode);
    pDrawNode->drawCardinalSpline(pPtArray, tension, 100, Color4F::GREEN);
    //    pDrawNode->setVisible(false);
    
    TargetedAction* pTargetAction = TargetedAction::create(pItemSprite, CardinalSplineTo::create(3.0f, pPtArray, tension));
    this->runAction(Sequence::create(DelayTime::create(1.0f), pTargetAction, nullptr));
    
    return true;
}

void LayerAnimationStudy11::createControlPoint(cocos2d::Vec2& pt)
{
    Sprite* pSprite = Sprite::create();
    pSprite->setTextureRect(Rect(0.0f,0.0f,10.0f,10.0f));
    pSprite->setColor(Color3B::RED);
    pSprite->setPosition(pt);
    addChild(pSprite);
    
    //    pSprite->setVisible(false);
}
















