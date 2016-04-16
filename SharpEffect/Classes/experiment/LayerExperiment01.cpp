//
//  LayerExperiment01.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "LayerExperiment01.h"
#include "RenderTextureClippingNode.h"

USING_NS_CC;
bool LayerExperiment01::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
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
            
            RenderTextureClippingNode* pRenderTextureClippingNode = RenderTextureClippingNode::create();
            pRenderTextureClippingNode->setPosition(Vec2(currX,currY));
            addChild(pRenderTextureClippingNode);
        }
    }
    
    return true;
}