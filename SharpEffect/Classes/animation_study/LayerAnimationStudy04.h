//
//  LayerAnimationStudy04.h
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#ifndef LayerAnimationStudy04_h
#define LayerAnimationStudy04_h

#include "cocos2d.h"

// 04 Bezier
class LayerAnimationStudy04 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationStudy04);
private:
    virtual bool init() override;
    
private:
    void createPointSprite(cocos2d::Vec2 position);
};

#endif /* LayerAnimationStudy04_h */
