//
//  LayerAnimationStudy11.h
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#ifndef LayerAnimationStudy11_h
#define LayerAnimationStudy11_h

#include "cocos2d.h"

// 11 CardinalSpline 可变张力曲线
class LayerAnimationStudy11 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationStudy11);
private:
    virtual bool init() override;
    
private:
    void createControlPoint(cocos2d::Vec2& pt);
};

#endif /* LayerAnimationStudy11_h */
