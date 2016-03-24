//
//  LayerShaderStudy00.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerShaderStudy00.h"

USING_NS_CC;
bool LayerShaderStudy00::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_COLOR));
    
    return true;
}

void LayerShaderStudy00::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
    m_renderCommand.init(_globalZOrder);
    m_renderCommand.func = CC_CALLBACK_0(LayerShaderStudy00::onCustomDraw, this, transform, flags);
    renderer->addCommand(&m_renderCommand);
}

void LayerShaderStudy00::onCustomDraw(const cocos2d::Mat4 &transform, uint32_t flags)
{
    Size winSize = Director::getInstance()->getWinSize();
    // data define
    GLfloat vertercies[] = {
        0.0f,0.0f,
        winSize.width,0.0f,
        winSize.width*0.5f,winSize.height};
    GLfloat color[] = {
        1.0f,0.0f,0.0f,1.0f,
        0.0f,1.0f,0.0f,1.0f,
        0.0f,0.0f,1.0f,1.0f
    };
    
    // gl programe use
    GLProgram* pGlPrograme = getGLProgram();
    pGlPrograme->use();
    
    // input params uniform-mvp
    pGlPrograme->setUniformsForBuiltins();
    
    // input params attribute
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*2, vertercies);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*4, color);
    
    // draw
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
    CHECK_GL_ERROR_DEBUG();
}














