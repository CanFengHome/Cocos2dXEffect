//
//  LayerAnimationPractice01.h
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#ifndef LayerAnimationPractice01_h
#define LayerAnimationPractice01_h

#include "cocos2d.h"

// 01 抖动动画 参考资料：http://blog.csdn.net/wonengxing/article/details/42076407
class LayerAnimationPractice01 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationPractice01);
private:
    virtual bool init() override;
};

#endif /* LayerAnimationPractice01_h */
