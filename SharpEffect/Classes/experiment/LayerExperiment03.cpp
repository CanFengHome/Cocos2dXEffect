//
//  LayerExperiment03.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "LayerExperiment03.h"

#include "AllRenderTextureBatchClippingNode.h"

USING_NS_CC;
bool LayerExperiment03::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    AllRenderTextureBatchClippingNode* pAllRenderTextureBatchClippingNode = AllRenderTextureBatchClippingNode::create();
    pAllRenderTextureBatchClippingNode->setPosition(winSize*0.5f);
    addChild(pAllRenderTextureBatchClippingNode);
    
    return true;
}



















