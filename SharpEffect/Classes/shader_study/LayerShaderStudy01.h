//
//  LayerShaderStudy01.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderStudy01_h
#define LayerShaderStudy01_h

#include "cocos2d.h"

// 01 shader define
class LayerShaderStudy01 : public cocos2d::Layer
{
public:
    CREATE_FUNC(LayerShaderStudy01);
private:
    virtual bool init() override;
    
private:
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    void onCustomDraw(const cocos2d::Mat4& transform, uint32_t flags);
    
    void initData();
private:
    cocos2d::CustomCommand m_renderCommand;
};


#endif /* LayerShaderStudy01_h */
