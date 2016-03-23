//
//  LayerAnimationStudy03.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#include "LayerAnimationStudy03.h"

USING_NS_CC;
bool LayerAnimationStudy03::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pRoleSprite = Sprite::create("res/role/role1.png");
    pRoleSprite->setPosition(pRoleSprite->getContentSize().width*0.5f,winSize.height*0.5f);
    addChild(pRoleSprite);
//    pRoleSprite->setScale(0.5f);
    
    ActionInterval* pJumpBy = JumpBy::create(2.0f, Vec2(300.0f,0.0f), 200.0f, 3);
    pRoleSprite->runAction(pJumpBy);
    
    DrawNode* pDrawNode = DrawNode::create();
    addChild(pDrawNode);
    float height = winSize.height*0.5f-pRoleSprite->getContentSize().height*0.5f;
    pDrawNode->drawLine(Vec2(0,height), Vec2(winSize.width,height), Color4F::RED);
    
    float height200 = height + 200.0f;
    pDrawNode->drawLine(Vec2(0,height200), Vec2(winSize.width,height200), Color4F::RED);
    
    float height100 = height + 100;
    pDrawNode->drawLine(Vec2(0,height100), Vec2(winSize.width,height100), Color4F::RED);
    
    return true;
}














