//
//  LayerShaderPractice06.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#include "LayerShaderPractice06.h"
#include "ShaderHeartNode.h"

USING_NS_CC;
bool LayerShaderPractice06::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    ShaderHeartNode* pHeartNode = ShaderHeartNode::createWithContentSize(Size(300.0f,300.0f));
    pHeartNode->setPosition(winSize*0.5f);
    addChild(pHeartNode);
    
    return true;
}
