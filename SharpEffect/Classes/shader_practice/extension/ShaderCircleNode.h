//
//  ShaderCircleNode.h
//  FengShader
//
//  Created by ccf on 16/3/4.
//
//

#ifndef ShaderCircleNode_h
#define ShaderCircleNode_h

#include "cocos2d.h"

class ShaderCircleNode : public cocos2d::Node
{
public:
    static ShaderCircleNode* createWithContentSize(const cocos2d::Size& nodeSize);
    ~ShaderCircleNode();
    virtual void setPosition(const cocos2d::Vec2 &newPosition) override;
    
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
    cocos2d::Vec2 m_center;
    cocos2d::Vec2 m_resolution;
    
    float m_time = 0.0f;
    
    GLuint m_vao=0;
    GLuint m_vbo=0;
    GLuint m_indexVBO=0;
};

#endif /* ShaderCircleNode_h */
