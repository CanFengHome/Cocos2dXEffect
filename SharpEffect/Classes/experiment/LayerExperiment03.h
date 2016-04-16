//
//  LayerExperiment03.h
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#ifndef LayerExperiment03_h
#define LayerExperiment03_h

#include "cocos2d.h"

// 03 一个RenderTexture模拟ClippingNode Sprite批处理
class LayerExperiment03 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerExperiment03);
private:
    virtual bool init() override;
};


#endif /* LayerExperiment03_h */
