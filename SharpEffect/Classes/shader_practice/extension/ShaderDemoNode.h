//
//  ShaderDemoNode.h
//  FengShader
//
//  Created by ccf on 16/3/4.
//
//

#ifndef ShaderDemoNode_h
#define ShaderDemoNode_h

#include "cocos2d.h"

class ShaderDemoNode : public cocos2d::Node
{
public:
    static ShaderDemoNode* createWithContentSize(const cocos2d::Size& nodeSize);
    ~ShaderDemoNode();
private:
    bool initWithContentSize(const cocos2d::Size& nodeSize);
    virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    
private:
    void loadShaderPrograme();
    void loadData();
    void clearData();
    
    void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
    
private:
    cocos2d::CustomCommand m_customCommand;
    float m_time = 0.0f;
    
    GLuint m_vao=0;
    GLuint m_vbo=0;
    GLuint m_indexVBO=0;
};

#endif /* ShaderDemoNode_h */
