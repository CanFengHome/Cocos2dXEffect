//
//  LayerShaderPractice04.h
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#ifndef LayerShaderPractice04_h
#define LayerShaderPractice04_h

#include "cocos2d.h"

// 04 标准Shader 演示在Node中自定义渲染shade
class LayerShaderPractice04 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice04);
private:
    virtual bool init() override;
};

#endif /* LayerShaderPractice04_h */
