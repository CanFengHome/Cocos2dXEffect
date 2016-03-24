//
//  LayerShaderStudy02.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderStudy02_h
#define LayerShaderStudy02_h

#include "cocos2d.h"

// 02 shader VAO/VBO
class LayerShaderStudy02 : public cocos2d::Layer
{
public:
    CREATE_FUNC(LayerShaderStudy02);
private:
    virtual bool init() override;
    
private:
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    void onCustomDraw(const cocos2d::Mat4& transform, uint32_t flags);
    
    void initData();
private:
    cocos2d::CustomCommand m_renderCommand;
    
    GLuint m_vao;
    GLuint m_vbo;
};

#endif /* LayerShaderStudy02_h */
