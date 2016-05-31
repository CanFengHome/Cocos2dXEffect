//
//  EaseElasticOutWithCoefficient.cpp
//  Hello
//
//  Created by ccf on 16/5/31.
//
//

#include "EaseElasticOutWithCoefficient.h"

USING_NS_CC;

EaseElasticOutWithCoefficient* EaseElasticOutWithCoefficient::create(ActionInterval *action)
{
    return EaseElasticOutWithCoefficient::create(action, 0.3f, 10.0f);
}

EaseElasticOutWithCoefficient* EaseElasticOutWithCoefficient::create(ActionInterval *action, float period, float reductionCoefficient)
{
    EaseElasticOutWithCoefficient *ret = new (std::nothrow) EaseElasticOutWithCoefficient();
    if (ret)
    {
        if (ret->initWithActionAndCoefficient(action, period, reductionCoefficient))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }
    
    return ret;
}

bool EaseElasticOutWithCoefficient::initWithActionAndCoefficient(cocos2d::ActionInterval *action, float period, float reductionCoefficient)
{
    if (EaseElastic::initWithAction(action, period))
    {
        m_fReductionCoefficient = reductionCoefficient;
        return true;
    }
    return false;
}

EaseElasticOutWithCoefficient* EaseElasticOutWithCoefficient::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) EaseElasticOutWithCoefficient();
    a->initWithActionAndCoefficient(_inner->clone(), _period, m_fReductionCoefficient);
    a->autorelease();
    return a;
}

void EaseElasticOutWithCoefficient::update(float time)
{
//    _inner->update(tweenfunc::elasticEaseOut(time, _period));
    float newT = 0;
    if (time == 0 || time == 1)
    {
        newT = time;
    }
    else
    {
        float s = _period / 4;
        newT = powf(2, -m_fReductionCoefficient * time) * sinf((time - s) * (float)M_PI * 2.0f / _period) + 1;
    }
    _inner->update(newT);
}

EaseElasticOutWithCoefficient* EaseElasticOutWithCoefficient::reverse() const
{
    return EaseElasticOutWithCoefficient::create(_inner->reverse(), _period, m_fReductionCoefficient);
}











