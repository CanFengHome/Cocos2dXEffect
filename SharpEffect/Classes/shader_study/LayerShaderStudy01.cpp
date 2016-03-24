//
//  LayerShaderStudy01.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerShaderStudy01.h"

USING_NS_CC;
bool LayerShaderStudy01::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    initData();
    
    return true;
}

void LayerShaderStudy01::initData()
{
    GLProgram* pProgram = new GLProgram;
    pProgram->initWithFilenames("res/shader_study/position.vert", "res/shader_study/position.frag");
    pProgram->link();
    pProgram->updateUniforms();
    CHECK_GL_ERROR_DEBUG();
    
    setGLProgram(pProgram);
    
    
    pProgram->release();
}

void LayerShaderStudy01::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
    m_renderCommand.init(_globalZOrder);
    m_renderCommand.func = CC_CALLBACK_0(LayerShaderStudy01::onCustomDraw, this, transform, flags);
    renderer->addCommand(&m_renderCommand);
}

void LayerShaderStudy01::onCustomDraw(const cocos2d::Mat4 &transform, uint32_t flags)
{
    Size winSize = Director::getInstance()->getWinSize();
    // data define
    GLfloat vertercies[] = {
        0.0f,0.0f,
        winSize.width,0.0f,
        winSize.width*0.5f,winSize.height};
    
    // gl programe use
    GLProgram* pGlPrograme = getGLProgram();
    pGlPrograme->use();
    
    // input params uniform-mvp
    pGlPrograme->setUniformsForBuiltins();
    
    GLuint attributePositionID = glGetAttribLocation(pGlPrograme->getProgram(), "vertexPosition");
    // input params attribute
    glVertexAttribPointer(attributePositionID, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*2, vertercies);
    
    // draw
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
    CHECK_GL_ERROR_DEBUG();
}








