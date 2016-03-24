//
//  LayerAnimationStudy10.h
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#ifndef LayerAnimationStudy10_h
#define LayerAnimationStudy10_h

#include "cocos2d.h"

// 10 CatmullRomTo
class LayerAnimationStudy10 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationStudy10);
private:
    virtual bool init() override;
    
private:
    void createControlPoint(cocos2d::Vec2& pt);
};

#endif /* LayerAnimationStudy10_h */
