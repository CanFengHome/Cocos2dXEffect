//
//  ShaderCircleNode.cpp
//  FengShader
//
//  Created by ccf on 16/3/4.
//
//

#include "ShaderCircleNode.h"

USING_NS_CC;
ShaderCircleNode* ShaderCircleNode::createWithContentSize(const cocos2d::Size& nodeSize)
{
    assert(nodeSize.width>0.0f && nodeSize.height>0.0f);
    
    ShaderCircleNode *pRet = new(std::nothrow) ShaderCircleNode;
    if (pRet && pRet->initWithContentSize(nodeSize))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

ShaderCircleNode::~ShaderCircleNode()
{
    clearData();
}

bool ShaderCircleNode::initWithContentSize(const cocos2d::Size& nodeSize)
{
    setContentSize(nodeSize);
    setAnchorPoint(Vec2(0.5f,0.5f));
    
    m_resolution = nodeSize;
    
#if CC_ENABLE_CACHE_TEXTURE_DATA
    auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event){
        this->setGLProgramState(nullptr);
        loadShaderPrograme();
        loadData();
    });
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif
    
    loadShaderPrograme();
    loadData();
    
    return true;
}

void ShaderCircleNode::setPosition(const Vec2 &newPosition)
{
    Node::setPosition(newPosition);
    auto position = getPosition();
    auto frameSize = Director::getInstance()->getOpenGLView()->getFrameSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto retinaFactor = Director::getInstance()->getOpenGLView()->getRetinaFactor();
    m_center = Vec2(position.x * frameSize.width / visibleSize.width * retinaFactor, position.y * frameSize.height / visibleSize.height * retinaFactor);
}

void ShaderCircleNode::loadShaderPrograme()
{
    GLProgram* pShaderProgram = GLProgram::createWithFilenames("res/shader_practice/case05.vert", "res/shader_practice/case05.frag");
    
    GLProgramState* pProgramState = GLProgramState::getOrCreateWithGLProgram(pShaderProgram);
    setGLProgramState(pProgramState);
}

void ShaderCircleNode::loadData()
{
    float w = getContentSize().width;
    float h = getContentSize().height;
    assert(w != 0 && h != 0);
    
    V2F_C4B_T2F vertexlist[] = {
        {Vec2(0.0f,0.0f),Color4B::RED,Tex2F(0.0f,0.0f)},
        {Vec2(w,0.0f),Color4B::GREEN,Tex2F(0.0f,0.0f)},
        {Vec2(w,h),Color4B::BLUE,Tex2F(0.0f,0.0f)},
        {Vec2(0.0f,h),Color4B::YELLOW,Tex2F(0.0f,0.0f)}
    };
    
    GLubyte indices[] = {
        0,1,2,
        0,2,3
    };
    
    assert (Configuration::getInstance()->supportsShareableVAO());
    
    // vao
    glGenVertexArrays(1, &m_vao);
    GL::bindVAO(m_vao);
    
    // vbo
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexlist), vertexlist, GL_STREAM_DRAW);
    // vbo input params
    // vertex
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C4B_T2F), (GLvoid *)offsetof(V2F_C4B_T2F, vertices));
    // color
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(V2F_C4B_T2F), (GLvoid *)offsetof(V2F_C4B_T2F, colors));
    // texcood
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_TEX_COORD);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C4B_T2F), (GLvoid *)offsetof(V2F_C4B_T2F, texCoords));
    
    // vbo index
    glGenBuffers(1, &m_indexVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) , indices, GL_STATIC_DRAW);
    
    // clear
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    CHECK_GL_ERROR_DEBUG();
}

void ShaderCircleNode::clearData()
{
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_indexVBO);
    GL::bindVAO(0);
    glDeleteVertexArrays(1, &m_vao);
    m_vao = m_vbo = m_indexVBO = 0;
}

void ShaderCircleNode::draw(Renderer* renderer, const Mat4& transform, uint32_t flags)
{
    m_customCommand.init(_globalZOrder, transform, flags);
    m_customCommand.func = CC_CALLBACK_0(ShaderCircleNode::onDraw, this, transform, flags);
    renderer->addCommand(&m_customCommand);
}

void ShaderCircleNode::onDraw(const cocos2d::Mat4& transform, uint32_t flags)
{
    // gl programe use
    GLProgram* pGlPrograme = getGLProgram();
    pGlPrograme->use();
    // 应用变换矩阵
    getGLProgramState()->apply(transform);
    
    getGLProgramState()->setUniformFloat("u_radius", 100.0f);
    getGLProgramState()->setUniformVec2("u_center", m_center);

    
    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE,(GLvoid*)0);
    glBindVertexArray(0);
    
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 6);
    CHECK_GL_ERROR_DEBUG();
}














