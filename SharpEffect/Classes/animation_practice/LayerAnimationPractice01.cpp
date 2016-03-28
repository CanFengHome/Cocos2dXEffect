//
//  LayerAnimationPractice01.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#include "LayerAnimationPractice01.h"

#include "ActionShake.h"

USING_NS_CC;
bool LayerAnimationPractice01::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pRoleSprite = Sprite::create("res/role/role1.png");
    pRoleSprite->setPosition(winSize*0.5f);
    addChild(pRoleSprite);
    
    ActionInterval* pShakeAction = ActionShake::create(5.0f, 10);
    ActionInterval* pTaretAction = TargetedAction::create(pRoleSprite, pShakeAction);
    
    this->runAction(Sequence::create(DelayTime::create(0.3f), pTaretAction, nullptr));
    
    return true;
}