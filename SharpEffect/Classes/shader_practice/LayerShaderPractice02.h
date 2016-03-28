//
//  LayerShaderPractice02.h
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#ifndef LayerShaderPractice02_h
#define LayerShaderPractice02_h

#include "cocos2d.h"

// 02 灯光光晕效果 Blend使用 参考资料：http://blog.csdn.net/yang3wei/article/details/7795764
class LayerShaderPractice02 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice02);
private:
    virtual bool init() override;
};

#endif /* LayerShaderPractice02_h */
