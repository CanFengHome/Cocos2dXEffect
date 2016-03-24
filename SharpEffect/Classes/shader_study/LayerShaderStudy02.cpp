
//
//  LayerShaderStudy02.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerShaderStudy02.h"

USING_NS_CC;
bool LayerShaderStudy02::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    initData();
    
    return true;
}

void LayerShaderStudy02::initData()
{
    setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_COLOR));
    
    // data define
    Size size = Director::getInstance()->getWinSize();
    // init data
    V2F_C4B_T2F vertexlist[] = {
        {Vec2(0,0),Color4B::GREEN,Tex2F(0,0)},
        {Vec2(size.width, 0),Color4B::RED,Tex2F(0,0)},
        {Vec2(size.width / 2, size.height),Color4B::BLUE,Tex2F(0,0)}
    };
    
    // 1.vao bind
    glGenVertexArrays(1, &m_vao);
    GL::bindVAO(m_vao);
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexlist), vertexlist, GL_STREAM_DRAW);
    
    // vertex
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C4B_T2F), (GLvoid *)offsetof(V2F_C4B_T2F, vertices));
    // color
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(V2F_C4B_T2F), (GLvoid *)offsetof(V2F_C4B_T2F, colors));
    
    GL::bindVAO(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    CHECK_GL_ERROR_DEBUG();
}

void LayerShaderStudy02::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
    m_renderCommand.init(_globalZOrder);
    m_renderCommand.func = CC_CALLBACK_0(LayerShaderStudy02::onCustomDraw, this, transform, flags);
    renderer->addCommand(&m_renderCommand);
}

void LayerShaderStudy02::onCustomDraw(const cocos2d::Mat4 &transform, uint32_t flags)
{
    assert(Configuration::getInstance()->supportsShareableVAO());
    
    auto glProgram = getGLProgram();
    glProgram->use();
    glProgram->setUniformsForBuiltins(transform);
    
    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    
    //通知cocos2d-x 的renderer，让它在合适的时候调用这些OpenGL命令
    // increment gl drawn batches and vertices
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
    //如果出错了，可以使用这个函数来获取出错信息
    CHECK_GL_ERROR_DEBUG();
}










