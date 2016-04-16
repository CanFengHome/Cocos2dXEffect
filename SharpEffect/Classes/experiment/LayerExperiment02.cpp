//
//  LayerExperiment02.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "LayerExperiment02.h"

#include "AllRenderTextureClippingNode.h"

USING_NS_CC;
bool LayerExperiment02::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    AllRenderTextureClippingNode* pAllRenderTextureClippingNode = AllRenderTextureClippingNode::create();
    pAllRenderTextureClippingNode->setPosition(winSize*0.5f);
    addChild(pAllRenderTextureClippingNode);
    
    return true;
}






