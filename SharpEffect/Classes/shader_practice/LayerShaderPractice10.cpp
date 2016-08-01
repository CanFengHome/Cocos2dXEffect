//
//  LayerShaderPractice10.cpp
//  SharpEffect
//
//  Created by ccf on 16/8/1.
//
//

#include "LayerShaderPractice10.h"

USING_NS_CC;

bool LayerShaderPractice10::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    m_pSprite = Sprite::create("res/ui/water.png");
    m_pSprite->setPosition(winSize*0.5f);
    addChild(m_pSprite);
    
    GLProgram* pProgram = GLProgram::createWithFilenames("res/shader_practice/case10.vert", "res/shader_practice/case10.frag");
    m_pSprite->setGLProgram(pProgram);
    
    return true;
}




























