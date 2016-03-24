//
//  LayerAnimationPractice00.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerAnimationPractice00_h
#define LayerAnimationPractice00_h

#include "cocos2d.h"

// 00 气泡抖动
class LayerAnimationPractice00 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationPractice00);
private:
    virtual bool init() override;
};

#endif /* LayerAnimationPractice00_h */
