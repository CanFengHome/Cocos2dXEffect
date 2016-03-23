//
//  LayerAnimationStudy04.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#include "LayerAnimationStudy04.h"

USING_NS_CC;
bool LayerAnimationStudy04::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pTargetSprite = Sprite::create("res/ui/jar.png");
    addChild(pTargetSprite);
    pTargetSprite->setRotation(-90.0f);
    pTargetSprite->setPosition(winSize.width-pTargetSprite->getContentSize().width*0.5f-50,
                               winSize.height-pTargetSprite->getContentSize().height*0.5f-50);
    
    Sprite* pItemSprite = Sprite::create("res/ui/coin.png");
    pItemSprite->setPosition(300.0f,300.0f);
    addChild(pItemSprite);
    
    float itemWidth = pItemSprite->getContentSize().width;
    float itemHeight = pItemSprite->getContentSize().height;
    float randomX = RandomHelper::random_real(itemWidth,winSize.width-itemWidth);
    float randomY = RandomHelper::random_real(300.0f, 300.0f+itemHeight*0.5f*9);
    pItemSprite->setPosition(randomX,randomY);
    
    // create collect bezier
    Vec2 bottleneck = Vec2(pTargetSprite->getPositionX()-pTargetSprite->getContentSize().width*0.5f,pTargetSprite->getPositionY());
    
    ccBezierConfig bezierConfig;
    bezierConfig.endPosition = bottleneck;
    bezierConfig.controlPoint_1 = pItemSprite->getPosition()+Vec2(-200.0f,0.0f);
    bezierConfig.controlPoint_2 = bottleneck+Vec2(-50.0f,-50.0f);
    BezierTo* pBezier = BezierTo::create(3.0f, bezierConfig);
    
    pItemSprite->runAction(Sequence::create(pBezier,MoveTo::create(0.3f, pTargetSprite->getPosition()), nullptr));
    
    DrawNode* pDrawNode = DrawNode::create();
    addChild(pDrawNode);
    pDrawNode->drawCubicBezier(pItemSprite->getPosition(), bezierConfig.controlPoint_1, bezierConfig.controlPoint_2, bottleneck, 100, Color4F::GREEN);
    
//    createPointSprite(bezierConfig.endPosition);
//    createPointSprite(bezierConfig.controlPoint_1);
//    createPointSprite(bezierConfig.controlPoint_2);
//    createPointSprite(pItemSprite->getPosition());
    
    return true;
}

void LayerAnimationStudy04::createPointSprite(cocos2d::Vec2 position)
{
    Sprite* pSprite = Sprite::create();
    pSprite->setTextureRect(Rect(0,0,10,10));
    pSprite->setPosition(position);
    pSprite->setColor(Color3B::RED);
    addChild(pSprite);
}























