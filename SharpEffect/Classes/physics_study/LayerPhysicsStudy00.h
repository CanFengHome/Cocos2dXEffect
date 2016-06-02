//
//  LayerPhysicsStudy00.h
//  SharpEffect
//
//  Created by ccf on 16/6/2.
//
//

#ifndef LayerPhysicsStudy00_h
#define LayerPhysicsStudy00_h

#include "cocos2d.h"

// 00 物理碰撞检测
class LayerPhysicsStudy00 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerPhysicsStudy00);
    virtual bool init() override;
private:
    void initPhysicsBox();
    void initBallSprite();
private:
    bool contactCallback(cocos2d::PhysicsContact& contact);
};


#endif /* LayerPhysicsStudy00_h */
