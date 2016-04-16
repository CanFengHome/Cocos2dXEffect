//
//  LayerExperiment02.h
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#ifndef LayerExperiment02_h
#define LayerExperiment02_h

#include "cocos2d.h"

// 02 一个RenderTexture模拟ClippingNode
class LayerExperiment02 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerExperiment02);
private:
    virtual bool init() override;
};

#endif /* LayerExperiment02_h */
