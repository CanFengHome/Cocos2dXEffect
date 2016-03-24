//
//  LayerShaderStudy04.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerShaderStudy04.h"

USING_NS_CC;
bool LayerShaderStudy04::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    // data define
    V2F_C4B_T2F vertexlist[] = {
        {Vec2(0,0),Color4B::GREEN,Tex2F(0,0)},
        {Vec2(winSize.width, 0),Color4B::RED,Tex2F(0,0)},
        {Vec2(winSize.width / 2, winSize.height),Color4B::BLUE,Tex2F(0,0)}
    };
    
//    V2F_C4F_T2F vertexlist[] = {
//        {Vec2(0,0),Color4F::GREEN,Tex2F(0,0)},
//        {Vec2(winSize.width, 0),Color4F::RED,Tex2F(0,0)},
//        {Vec2(winSize.width / 2, winSize.height),Color4F::BLUE,Tex2F(0,0)}
//    };
    
    GLProgram* pProgram = GLProgram::createWithFilenames("res/shader_study/position_color.vert", "res/shader_study/position_color.frag");
    setGLProgram(pProgram);
    
    // 1.vao bind
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    
    // 2.vao的vbo
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexlist), vertexlist, GL_STREAM_DRAW);
    
    GLuint attributePositionID = glGetAttribLocation(pProgram->getProgram(), "a_position");
    GLuint attributeColorID = glGetAttribLocation(pProgram->getProgram(), "a_color");
    
    // vertex
    glEnableVertexAttribArray(attributePositionID);
    glVertexAttribPointer(attributePositionID, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C4B_T2F), (GLvoid *)offsetof(V2F_C4B_T2F, vertices));
//    glVertexAttribPointer(attributePositionID, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C4F_T2F), (GLvoid*)(offsetof(V2F_C4F_T2F, vertices)));
    
    // color
    glEnableVertexAttribArray(attributeColorID);
    glVertexAttribPointer(attributeColorID, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(V2F_C4B_T2F), (GLvoid *)offsetof(V2F_C4B_T2F, colors));
//    glVertexAttribPointer(attributeColorID, 4, GL_FLOAT, GL_FALSE, sizeof(V2F_C4F_T2F), (GLvoid*)(offsetof(V2F_C4F_T2F, colors)));
    
    // 特别注意上面两种颜色的处理方式
    // 如果是color 4b，取值范围[0,255]，则传入的数值类型是 gl_unsigned_byte
    // 而如果是color 4f，取值范围[0,1]，则传入的数值类型是gl_float
    // 另外还要特别注意，如果是color 4b，则指定类型为byte之外，还要告知GPU，要对传入的参数进行归一化处理，保证最终取值范围在[0,1]，所以此处指定为GL_TRUE
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    CHECK_GL_ERROR_DEBUG();
    
    return true;
}

void LayerShaderStudy04::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
{
    m_renderCommand.init(_globalZOrder);
    m_renderCommand.func = CC_CALLBACK_0(LayerShaderStudy04::onCustomDraw, this, transform, flags);
    renderer->addCommand(&m_renderCommand);
}

void LayerShaderStudy04::onCustomDraw(const cocos2d::Mat4 &transform, uint32_t flags)
{
    // gl programe use
    GLProgram* pGlPrograme = getGLProgram();
    pGlPrograme->use();
    // input params uniform-mvp
    pGlPrograme->setUniformsForBuiltins();
    
    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
    CHECK_GL_ERROR_DEBUG();
}




















