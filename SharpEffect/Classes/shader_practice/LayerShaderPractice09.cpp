//
//  LayerShaderPractice09.cpp
//  SharpEffect
//
//  Created by ccf on 16/8/1.
//
//

#include "LayerShaderPractice09.h"


USING_NS_CC;

bool LayerShaderPractice09::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    // 纹理长宽必须都是2的整数倍
    m_pSprite = Sprite::create("res/ui/repeat.png");
    m_pSprite->setPosition(winSize*0.5f);
    addChild(m_pSprite);
    
    // texture params
    Texture2D::TexParams textureParams;
    textureParams.magFilter = GL_NEAREST;
    textureParams.minFilter = GL_NEAREST;
    textureParams.wrapS = GL_REPEAT;
    textureParams.wrapT = GL_REPEAT;
    m_pSprite->getTexture()->setTexParameters(textureParams);
    
    GLProgram* pProgram = GLProgram::createWithFilenames("res/shader_practice/case09.vert", "res/shader_practice/case09.frag");
    m_pSprite->setGLProgram(pProgram);
    
    m_textUV = Vec2::ZERO;
    schedule(schedule_selector(LayerShaderPractice09::updateTextUVAnimation), 0.1f);
    
    return true;
}

void LayerShaderPractice09::updateTextUVAnimation(float duration)
{
    m_textUV.x += duration*0.5f;
    m_pSprite->getGLProgramState()->setUniformVec2("u_TexUV", m_textUV);
}




























