//
//  LayerShaderPractice04.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#include "LayerShaderPractice04.h"
#include "ShaderDemoNode.h"

USING_NS_CC;
bool LayerShaderPractice04::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    ShaderDemoNode* pDemoNode = ShaderDemoNode::createWithContentSize(Size(100.0f,100.0f));
    pDemoNode->setPosition(winSize*0.5f);
    addChild(pDemoNode);
    
    return true;
}
