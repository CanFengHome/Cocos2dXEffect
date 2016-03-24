//
//  LayerShaderStudy00.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderStudy00_h
#define LayerShaderStudy00_h

#include "cocos2d.h"

// 00 shader first triangle
class LayerShaderStudy00 : public cocos2d::Layer
{
public:
    CREATE_FUNC(LayerShaderStudy00);
private:
    virtual bool init() override;
    
private:
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    void onCustomDraw(const cocos2d::Mat4& transform, uint32_t flags);
private:
    cocos2d::CustomCommand m_renderCommand;
};

#endif /* LayerShaderStudy00_h */
