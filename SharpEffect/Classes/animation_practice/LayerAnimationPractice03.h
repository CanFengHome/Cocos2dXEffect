//
//  LayerAnimationPractice03.h
//  SharpEffect
//
//  Created by ccf on 16/7/7.
//
//

#ifndef LayerAnimationPractice03_h
#define LayerAnimationPractice03_h

#include "cocos2d.h"

// 03 Bezier插值曲线动画
class LayerAnimationPractice03 : public cocos2d::LayerColor
{
public:
    LayerAnimationPractice03()=default;
    CC_DISALLOW_COPY_AND_ASSIGN(LayerAnimationPractice03);
    CREATE_FUNC(LayerAnimationPractice03);
    virtual bool init() override;
private:
    void calBeizerPoints();
    void createPointSprite(cocos2d::Vec2 position);
private:
    cocos2d::ccBezierConfig m_bezierConfig;
    cocos2d::Vec2 m_startPosition;
    
    cocos2d::Sprite* m_pItemSprite = nullptr;
    cocos2d::Sprite* m_pTargetSprite = nullptr;
};

#endif /* LayerAnimationPractice03_h */
