//
//  ActionShake.cpp
//  FengShader
//
//  Created by ccf on 16/3/4.
//
//

#include "ActionShake.h"

USING_NS_CC;
ActionShake* ActionShake::create(float duration, float strength)
{
    return create(duration, strength, strength);
}

// 产生震动效果的初始化函数,两个方向值不一样
ActionShake* ActionShake::create(float duration, float strengthX, float strengthY)
{
    ActionShake *pRet = new(std::nothrow) ActionShake();
    if (pRet && pRet->initWithDuration(duration, strengthX, strengthY))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool ActionShake::initWithDuration(float duration, float strengthX, float strengthY)
{
    if (ActionInterval::initWithDuration(duration))
    {
        m_strengthX = strengthX;
        m_strengthY = strengthY;
        
        return true;
    }
    
    return false;
}

//以下都是重写父类抽象类的函数(必须重写)
ActionShake* ActionShake::clone() const
{
    auto a = new ActionShake();
    a->initWithDuration(_duration, m_strengthX, m_strengthY);
    a->autorelease();
    return a;
}

ActionShake* ActionShake::reverse(void) const
{
    return ActionShake::create(_duration, -m_strengthX, -m_strengthY);
}

void ActionShake::startWithTarget(cocos2d::Node *target)
{
    ActionInterval::startWithTarget(target);
    
    // save the initial position
    m_initialX = target->getPosition().x;
    m_initialY = target->getPosition().y;
}

void ActionShake::update(float time)
{
    float randX = RandomHelper::random_real(-m_strengthX, m_strengthX);
    float randY = RandomHelper::random_real(-m_strengthY, m_strengthY);
    _target->setPosition(m_initialX + randX, m_initialY + randY);
}

void ActionShake::stop(void)
{
    // Action is done, reset clip position
    _target->setPosition(Vec2(m_initialX, m_initialY));
    
    ActionInterval::stop();
}



























