//
//  WaterBottleClipingNode.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "WaterBottleClipingNode.h"

USING_NS_CC;
bool WaterBottleClipingNode::init()
{
    Sprite* pTopSprite = Sprite::create("res/ui/water_bottle/bottle.png");
    addChild(pTopSprite, 10);
    
    Sprite* pWater1 = Sprite::create("res/ui/water_bottle/water.png");
    Sprite* pMaskSprite = Sprite::create("res/ui/water_bottle/water_mask.png");
    
    ClippingNode* pClippingNode = ClippingNode::create();
    addChild(pClippingNode);
    
    // 属性设置
    pClippingNode->setInverted(false);
    pClippingNode->setAlphaThreshold(0.5f);
    // 模板
    pClippingNode->setStencil(pMaskSprite);
    // 底图
    pClippingNode->addChild(pWater1);
    
    ActionInterval* pMoveAction = MoveBy::create(0.4f, Vec2(8.0f,0.0f));
    ActionInterval* pRepeatAction = Sequence::create(pMoveAction, pMoveAction->reverse(), NULL);
    pWater1->runAction(RepeatForever::create(pRepeatAction));
    
    setContentSize(Size(150.0f,148.0f));
    
    return true;
}




