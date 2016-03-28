//
//  LayerShaderPractice01.h
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#ifndef LayerShaderPractice01_h
#define LayerShaderPractice01_h

#include "cocos2d.h"

// 01 冰冻效果 参考资料：http://caiwb1990.iteye.com/blog/2065278
class LayerShaderPractice01 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice01);
private:
    virtual bool init() override;
};


#endif /* LayerShaderPractice01_h */
