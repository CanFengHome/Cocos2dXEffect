//
//  LayerAnimationPractice04.h
//  SharpEffect
//
//  Created by ccf on 16/7/21.
//
//

#ifndef LayerAnimationPractice04_h
#define LayerAnimationPractice04_h

#include "cocos2d.h"

class NormalItem : public cocos2d::Node
{
public:
    NormalItem()=default;
    DISALLOW_COPY_AND_ASSIGN(NormalItem);
    CREATE_FUNC(NormalItem);
    virtual bool init() override;
public:
    void startDrop();
    
private:
    void dropTimer(float dt);
    void resetStatus();
protected:
    cocos2d::Sprite* m_pContentSprite = nullptr;
    bool m_bIsDropping = false;
    
    // 起点pos
    cocos2d::Vec2 m_srcPosition;
    // 掉落点pos
    cocos2d::Vec2 m_targetPosition;
};

// 04 棋子掉落动画
class LayerAnimationPractice04 : public cocos2d::LayerColor
{
public:
    LayerAnimationPractice04()=default;
    CC_DISALLOW_COPY_AND_ASSIGN(LayerAnimationPractice04);
    CREATE_FUNC(LayerAnimationPractice04);
    virtual bool init() override;
private:
    void btnTestCallback(cocos2d::Ref* pSender);
private:
    NormalItem* m_pNormalItem = nullptr;
};


#endif /* LayerAnimationPractice04_h */
