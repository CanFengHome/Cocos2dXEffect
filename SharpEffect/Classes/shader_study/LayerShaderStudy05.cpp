//
//  LayerShaderStudy05.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerShaderStudy05.h"

USING_NS_CC;

bool LayerShaderStudy05::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    initData();
    
    return true;
}

void LayerShaderStudy05::initData()
{
    GLProgram* pProgram = GLProgram::createWithFilenames("res/shader_study/pos_col_uniform.vert", "res/shader_study/pos_col_uniform.frag");
    setGLProgram(pProgram);
    
    Size winSize = Director::getInstance()->getWinSize();
    GLfloat vertexlist[] = {
        0.0f,0.0f,
        winSize.width,0.0f,
        winSize.width*0.5f,winSize.height};
    
    // gen bind vao
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    // gen bind vbo
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexlist), vertexlist, GL_STREAM_DRAW);
    
    // input params
    GLuint attributePositionID = glGetAttribLocation(pProgram->getProgram(), "a_position");
    // vertex
    glEnableVertexAttribArray(attributePositionID);
    //    glVertexAttribPointer(attributePositionID, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C4B_T2F), (GLvoid *)offsetof(V2F_C4B_T2F, vertices));
    // 注意:stride参数是取了 2-GL_FLOAT 的内容后的偏移值，所以此处为0 可以理解为第一个参数和第二个参数之间的内存间隔，上面注释内容是从Demo3和Demo4中取得的代码，可以和此处进行对比，则理解更为透彻
    // 而最后一个参数，是在数组中需要访问数据的起始地址，是相对于数组的地址，而不是内存的地址
    glVertexAttribPointer(attributePositionID, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    
    // uniform
    GLuint uniformColorID = glGetUniformLocation(pProgram->getProgram(), "u_color");
    glUniform4f(uniformColorID, 0, 0, 1, 1);
    
    // clear
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    CHECK_GL_ERROR_DEBUG();
}

void LayerShaderStudy05::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    m_customCommand.init(_globalZOrder,transform,flags);
    m_customCommand.func = CC_CALLBACK_0(LayerShaderStudy05::onCustomDraw, this, transform, flags);
    renderer->addCommand(&m_customCommand);
}

void LayerShaderStudy05::onCustomDraw(const cocos2d::Mat4& transform, uint32_t flags)
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



















