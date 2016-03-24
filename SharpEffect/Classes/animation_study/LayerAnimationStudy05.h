//
//  LayerAnimationStudy05.h
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#ifndef LayerAnimationStudy05_h
#define LayerAnimationStudy05_h

#include "cocos2d.h"

// 05 Blink
class LayerAnimationStudy05 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationStudy05);
private:
    virtual bool init() override;
    
private:
    void createPointSprite(cocos2d::Vec2 position);
};

#endif /* LayerAnimationStudy05_h */
