//
//  LayerAnimationStudy09.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#include "LayerAnimationStudy09.h"

USING_NS_CC;
bool LayerAnimationStudy09::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pRoleSprite = Sprite::create("res/role/role1.png");
    pRoleSprite->setPosition3D(Vec3(winSize.width*0.5f,winSize.height*0.5f,0.0f));
    addChild(pRoleSprite);
    
    ActionInterval* pRotateAction1 = RotateBy::create(2.0f, 120.0f);
    ActionInterval* pRotateAction2 = pRotateAction1->reverse();
    ActionInterval* pAction = Sequence::create(pRotateAction1,pRotateAction2, nullptr);
    
    TargetedAction* pTargetAction = TargetedAction::create(pRoleSprite, pAction);
    
    this->runAction(Sequence::create(DelayTime::create(1.0f), pTargetAction, nullptr));
    
    return true;
}

