//
//  LayerShaderStudy05.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderStudy05_h
#define LayerShaderStudy05_h

#include "cocos2d.h"

// 05 shader uniform
class LayerShaderStudy05 : public cocos2d::Layer
{
public:
    CREATE_FUNC(LayerShaderStudy05);
private:
    virtual bool init() override;
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    
    void initData();
    void onCustomDraw(const cocos2d::Mat4& transform, uint32_t flags);
private:
    cocos2d::CustomCommand m_customCommand;
    
    GLuint m_vao;
    GLuint m_vbo;
};

#endif /* LayerShaderStudy05_h */
