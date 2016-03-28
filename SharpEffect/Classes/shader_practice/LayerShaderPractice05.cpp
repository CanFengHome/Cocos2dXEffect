//
//  LayerShaderPractice05.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#include "LayerShaderPractice05.h"

#include "ShaderCircleNode.h"

USING_NS_CC;
bool LayerShaderPractice05::init()
{
    if (!LayerColor::initWithColor(Color4B::GRAY))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    ShaderCircleNode* pCircleNode = ShaderCircleNode::createWithContentSize(Size(300.0f,300.0f));
    pCircleNode->setPosition(winSize*0.5f);
    addChild(pCircleNode);
    
    return true;
}