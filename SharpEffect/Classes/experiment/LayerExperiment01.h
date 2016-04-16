//
//  LayerExperiment01.h
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#ifndef LayerExperiment01_h
#define LayerExperiment01_h

#include "cocos2d.h"

// 01 多个RenderTexture模拟ClippingNode
class LayerExperiment01 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerExperiment01);
private:
    virtual bool init() override;
};


#endif /* LayerExperiment01_h */
