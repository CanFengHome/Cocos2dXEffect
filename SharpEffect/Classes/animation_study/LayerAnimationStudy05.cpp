//
//  LayerAnimationStudy05.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#include "LayerAnimationStudy05.h"

USING_NS_CC;
bool LayerAnimationStudy05::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pRoleSprite = Sprite::create("res/role/role1.png");
    pRoleSprite->setPosition3D(Vec3(winSize.width*0.5f,winSize.height*0.5f,0.0f));
    addChild(pRoleSprite);
    
    pRoleSprite->runAction(Blink::create(2.0f, 5));
    
    return true;
}

























