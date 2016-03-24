//
//  LayerAnimationStudy06.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#include "LayerAnimationStudy06.h"

USING_NS_CC;
bool LayerAnimationStudy06::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pRoleSprite1 = Sprite::create("res/role/role1.png");
    pRoleSprite1->setPosition3D(Vec3(winSize.width*0.5f,winSize.height*0.5f,0.0f));
    addChild(pRoleSprite1);
    
    Sprite* pRole2 = Sprite::create("res/role/role1.png");
    pRole2->setPosition(100.0f,100.0f);
    addChild(pRole2);
    
    pRoleSprite1->setOpacity(122);
    pRoleSprite1->runAction(FadeIn::create(2.0f));
    pRole2->runAction(FadeOut::create(2.0f));
    
    
    return true;
}
