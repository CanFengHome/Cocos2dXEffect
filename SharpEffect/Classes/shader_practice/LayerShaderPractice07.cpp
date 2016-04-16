//
//  LayerShaderPractice07.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/15.
//
//

#include "LayerShaderPractice07.h"

#include "ShaderClipingNode.h"

USING_NS_CC;
bool LayerShaderPractice07::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pBgSprite = Sprite::create("res/ui/bg1.png");
    addChild(pBgSprite);
    pBgSprite->setPosition(winSize*0.5f);
    
    float fixWidth = 74.0f*2;
    float fixHeight = 74.0f*2;
    float initX = 74.0f;
    float initY = 74.0f;
    
    for (int row=0; row<7; ++row)
    {
        for (int col=0; col<4; ++col)
        {
            float currX = initX + fixWidth * col;
            float currY = initY + fixHeight * row;
            
            ShaderClipingNode* pShaderClipingNode = ShaderClipingNode::create();
            addChild(pShaderClipingNode);
            pShaderClipingNode->setPosition(Vec2(currX,currY));
        }
    }
    
    return true;
}
