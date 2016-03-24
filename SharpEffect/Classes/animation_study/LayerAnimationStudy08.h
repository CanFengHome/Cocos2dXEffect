//
//  LayerAnimationStudy08.h
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#ifndef LayerAnimationStudy08_h
#define LayerAnimationStudy08_h

#include "cocos2d.h"

// 08 Plist Animation
class LayerAnimationStudy08 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationStudy08);
private:
    virtual bool init() override;
    
    virtual void onEnter() override;
    virtual void onExit() override;
    
private:
    cocos2d::EventListenerCustom* _frameDisplayedListener = nullptr;
};

#endif /* LayerAnimationStudy08_h */
