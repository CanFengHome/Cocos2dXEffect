//
//  LayerShaderPractice01.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#include "LayerShaderPractice01.h"

USING_NS_CC;
bool LayerShaderPractice01::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    std::string roleRes = "res/role/role1.png";
    Size winSize = Director::getInstance()->getWinSize();
    // src sprite
    Sprite* pSrcSprite = Sprite::create(roleRes);
    pSrcSprite->setPosition(winSize.width*0.5f,pSrcSprite->getContentSize().height);
    addChild(pSrcSprite);
    
    Sprite* pRoleSprite = Sprite::create(roleRes);
    pRoleSprite->setPosition(winSize*0.5f);
    addChild(pRoleSprite);
    
    GLProgram* pShaderProgram = GLProgram::createWithFilenames("res/shader_practice/case01.vert", "res/shader_practice/case01.frag");
    pRoleSprite->setGLProgram(pShaderProgram);
    
    return true;
}


