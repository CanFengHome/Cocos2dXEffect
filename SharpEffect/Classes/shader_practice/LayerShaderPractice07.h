//
//  LayerShaderPractice07.h
//  SharpEffect
//
//  Created by ccf on 16/4/15.
//
//

#ifndef LayerShaderPractice07_h
#define LayerShaderPractice07_h

#include "cocos2d.h"

// 07 使用shader模拟ClippingNode功能
class LayerShaderPractice07 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice07);
private:
    virtual bool init() override;
};

#endif /* LayerShaderPractice07_h */
