//
//  ShaderClipingNode.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "ShaderClipingNode.h"

USING_NS_CC;

bool ShaderClipingNode::init()
{
    m_pTargetSprite = Sprite::create("res/ui/water_bottle/water.png");
    addChild(m_pTargetSprite, 30);
    
    GLProgram* pProgram = GLProgram::createWithFilenames("res/shader_practice/case07.vert", "res/shader_practice/case07.frag");
    m_pTargetSprite->setGLProgram(pProgram);
    
    Texture2D* pNewTexture = Director::getInstance()->getTextureCache()->addImage("res/ui/water_bottle/water_mask.png");
    m_pTargetSprite->getGLProgramState()->setUniformTexture("u_Texture", pNewTexture);
    
    Sprite* pTopSprite = Sprite::create("res/ui/water_bottle/bottle.png");
    addChild(pTopSprite, 40);
    pTopSprite->setPosition(m_pTargetSprite->getPosition());
    
    clearStatus();
    schedule(schedule_selector(ShaderClipingNode::moveUpdate), 0.1f);
    
    return true;
}

void ShaderClipingNode::moveUpdate(float dt)
{
    assert(m_pTargetSprite != nullptr);
    
    m_intervalTime += dt;
    float dtLen = dt * 10 * m_iForwardDir;
    m_fMoveLen += dtLen;
    m_fMoveLen = MAX(0, MIN(10, m_fMoveLen));
    
    if (m_fMoveLen <= 0.0000001f || m_fMoveLen >= 10.0f)
    {
        m_iForwardDir *= -1;
        m_intervalTime = 0.0f;
    }
    
    m_pTargetSprite->getGLProgramState()->setUniformFloat("u_MoveLen", m_fMoveLen/m_pTargetSprite->getContentSize().width);
}

void ShaderClipingNode::clearStatus()
{
    m_intervalTime = 0.0f;
    m_fMoveLen = 0.0f;
    m_iForwardDir = 1;
}









