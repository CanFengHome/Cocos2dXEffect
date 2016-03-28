//
//  LayerShaderPractice02.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#include "LayerShaderPractice02.h"

USING_NS_CC;
bool LayerShaderPractice02::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    // 作为参考
    Sprite* pBg1 = Sprite::create("res/ui/shader_case2/02background.png");
    pBg1->setPosition(winSize.width*0.5f, winSize.height-pBg1->getContentSize().height*0.5f);
    addChild(pBg1);
    
    Sprite* pMask1 = Sprite::create("res/ui/shader_case2/02mask.png");
    pMask1->setAnchorPoint(Vec2(0.0f,1.0f));
    pMask1->setPosition(0,pBg1->getContentSize().height);
    pBg1->addChild(pMask1);
    // 默认 {GL_ONE, GL_ONE_MINUS_SRC_ALPHA}
    
    // 使用Blend
    Sprite* pBg2 = Sprite::create("res/ui/shader_case2/02background.png");
    pBg2->setPosition(winSize.width*0.5f, pBg2->getContentSize().height*0.5f);
    addChild(pBg2);
    
    Sprite* pMask2 = Sprite::create("res/ui/shader_case2/02mask.png");
    pMask2->setAnchorPoint(Vec2(0.0f,1.0f));
    pMask2->setPosition(0,pBg2->getContentSize().height);
    pBg2->addChild(pMask2);
    
    BlendFunc blendFunc = BlendFunc::ADDITIVE;//{GL_SRC_ALPHA, GL_ONE}
    pMask2->setOpacity(120);
    //    BlendFunc blendFunc = {GL_ZERO, GL_SRC_COLOR};
    pMask2->setBlendFunc(blendFunc);
    
    return true;
}
