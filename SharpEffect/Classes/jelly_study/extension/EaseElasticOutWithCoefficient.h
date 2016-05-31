//
//  EaseElasticOutWithCoefficient.h
//  Hello
//
//  Created by ccf on 16/5/31.
//
//

#ifndef EaseElasticOutWithCoefficient_h
#define EaseElasticOutWithCoefficient_h

#include "cocos2d.h"

class CC_DLL EaseElasticOutWithCoefficient : public cocos2d::EaseElastic
{
public:
    static EaseElasticOutWithCoefficient* create(cocos2d::ActionInterval *action, float period, float reductionCoefficient);
    static EaseElasticOutWithCoefficient* create(cocos2d::ActionInterval *action);
    
    // Overrides
    virtual void update(float time) override;
    virtual EaseElasticOutWithCoefficient* clone() const override;
    virtual EaseElasticOutWithCoefficient* reverse() const override;
    
protected:
    bool initWithActionAndCoefficient(ActionInterval *action, float period, float reductionCoefficient);
    
protected:
    float m_fReductionCoefficient=1.0f;
    
CC_CONSTRUCTOR_ACCESS:
    EaseElasticOutWithCoefficient() {}
    virtual ~EaseElasticOutWithCoefficient() {}
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseElasticOutWithCoefficient);
};

#endif /* EaseElasticOutWithCoefficient_h */
