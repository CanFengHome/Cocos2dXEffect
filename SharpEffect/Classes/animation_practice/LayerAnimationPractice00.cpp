//
//  LayerAnimationPractice00.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerAnimationPractice00.h"

USING_NS_CC;
bool LayerAnimationPractice00::init()
{
    if (!LayerColor::initWithColor(Color4B::GRAY))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pRoleSprite = Sprite::create("res/ui/bubble.png");
    pRoleSprite->setPosition(winSize.width*0.5f,winSize.height*0.5f);
    addChild(pRoleSprite);
    
    float dt = 0.5f;
    float contentScale = 1.0f;
    pRoleSprite->setScale(contentScale);
    // 对EaseSine曲线的描述 http://blog.sina.com.cn/s/blog_61e26bcb0101924u.html
    ActionInterval* pScaleAction = Sequence::create(
          EaseSineOut::create(ScaleTo::create(dt * 0.5f, 1.05f * contentScale, 0.95f * contentScale)),
          EaseSineInOut::create(ScaleTo::create(dt, 0.95f* contentScale, 1.05f * contentScale)),
          EaseSineIn::create(ScaleTo::create(dt * 0.5f, contentScale, contentScale)), nullptr);
    pRoleSprite->runAction(RepeatForever::create(pScaleAction));
    
    return true;
}