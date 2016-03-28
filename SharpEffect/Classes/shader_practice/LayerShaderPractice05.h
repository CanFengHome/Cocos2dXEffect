//
//  LayerShaderPractice05.h
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#ifndef LayerShaderPractice05_h
#define LayerShaderPractice05_h

#include "cocos2d.h"

// 05 shader darw circle
class LayerShaderPractice05 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice05);
private:
    virtual bool init() override;
};

#endif /* LayerShaderPractice05_h */
