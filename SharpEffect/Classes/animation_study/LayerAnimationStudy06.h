//
//  LayerAnimationStudy06.h
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#ifndef LayerAnimationStudy06_h
#define LayerAnimationStudy06_h

#include "cocos2d.h"

// 06 Fade
class LayerAnimationStudy06 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationStudy06);
private:
    virtual bool init() override;
    
private:
    void createPointSprite(cocos2d::Vec2 position);
};

#endif /* LayerAnimationStudy06_h */
