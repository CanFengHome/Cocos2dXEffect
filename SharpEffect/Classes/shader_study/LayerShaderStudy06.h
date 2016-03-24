//
//  LayerShaderStudy06.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderStudy06_h
#define LayerShaderStudy06_h

#include "cocos2d.h"

// 06 shader quad
class LayerShaderStudy06 : public cocos2d::Layer
{
public:
    CREATE_FUNC(LayerShaderStudy06);
private:
    virtual bool init() override;
    
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    
    void onCustomDraw(const cocos2d::Mat4& transform, uint32_t flags);
private:
    void initData();
    
private:
    cocos2d::CustomCommand m_customCommand;
    GLuint m_vao;
    GLuint m_vbo;
};

#endif /* LayerShaderStudy06_h */
