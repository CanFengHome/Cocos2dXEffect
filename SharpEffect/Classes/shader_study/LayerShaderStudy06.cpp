//
//  LayerShaderStudy06.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerShaderStudy06.h"

USING_NS_CC;

bool LayerShaderStudy06::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    initData();
    
    return true;
}

void LayerShaderStudy06::initData()
{
    Size winSize = Director::getInstance()->getWinSize();
    
    float left = 100.0f;
    float right = winSize.width - left;
    float bottom = 100.0f;
    float top = winSize.height-bottom;
    
    GLfloat vertexs[] = {
        left,bottom,
        right,bottom,
        left,top,
        left,top,
        right,bottom,
        right,top
    };
    
    GLProgram* pProgram = GLProgram::createWithFilenames("res/shader_study/position.vert", "res/shader_study/position.frag");
    setGLProgram(pProgram);
    
    GLuint attributePositionID = glGetAttribLocation(pProgram->getProgram(), "vertexPosition");
    
    // vao
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    // vbo -> gpu
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs), vertexs, GL_STREAM_DRAW);
    // input vertex params
    glEnableVertexAttribArray(attributePositionID);
    glVertexAttribPointer(attributePositionID, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    
    // clear
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    CHECK_GL_ERROR_DEBUG();
}

void LayerShaderStudy06::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    m_customCommand.init(_globalZOrder,transform,flags);
    m_customCommand.func = CC_CALLBACK_0(LayerShaderStudy06::onCustomDraw, this,transform,flags);
    renderer->addCommand(&m_customCommand);
}

void LayerShaderStudy06::onCustomDraw(const cocos2d::Mat4& transform, uint32_t flags)
{
    // gl programe use
    GLProgram* pGlPrograme = getGLProgram();
    pGlPrograme->use();
    // input params uniform-mvp
    pGlPrograme->setUniformsForBuiltins();
    
    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 6);
    CHECK_GL_ERROR_DEBUG();
}








