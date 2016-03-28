//
//  ActionShake.h
//  FengShader
//
//  Created by ccf on 16/3/4.
//
//

#ifndef ActionShake_h
#define ActionShake_h

#include "cocos2d.h"

// 抖动动画
// 原理：target对象的位置pos
// [-strengthX,-strengthY]和[strengthX,strengthY]组成的矩形Rect
// 每帧在Rect中随机设置位置。
// so，对象的锚点最好是中心，抖动的强度最好不要太大-可按照contentSize的比例来设置
class ActionShake : public cocos2d::ActionInterval
{
public:
    // 产生震动效果的初始化函数参数,两个方向相同
    // @param duration 震动持续的时间
    // @param strength 震动的幅度
    static ActionShake* create(float duration, float strength);
    
    // 产生震动效果的初始化函数,两个方向值不一样
    static ActionShake* create(float duration, float strengthX, float strengthY);
private:
    bool initWithDuration(float duration, float strengthX, float strengthY);
    
private:
    //以下都是重写父类抽象类的函数(必须重写)
    virtual ActionShake* clone() const override;
    virtual ActionShake* reverse(void) const override;
    virtual void startWithTarget(cocos2d::Node *target) override;
    virtual void update(float time) override;
    virtual void stop(void) override;
private:
    // 精灵的位置
    float m_initialX=0;
    float m_initialY=0;
    // 抖动的幅度
    float m_strengthX=0;
    float m_strengthY=0;
};

#endif /* ActionShake_h */
