//
//  LayerAnimationStudy00.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#include "LayerAnimationStudy00.h"

USING_NS_CC;
bool LayerAnimationStudy00::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pRoleSprite = Sprite::create("res/role/role1.png");
    pRoleSprite->setPosition3D(Vec3(winSize.width*0.5f,winSize.height*0.5f,0.0f));
    pRoleSprite->runAction(MoveTo::create(2.0f, Vec3(winSize.width*0.5f, winSize.height*0.5f, -500.0f)));
    addChild(pRoleSprite);
    
    //    this->runAction(Sequence::create(RotateTo::create(2.0f, 120.0f), RotateTo::create(2.0f, 0.0f), nullptr));
    
    return true;
}