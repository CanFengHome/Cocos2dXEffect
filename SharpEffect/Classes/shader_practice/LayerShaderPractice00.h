//
//  LayerShaderPractice00.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderPractice00_h
#define LayerShaderPractice00_h

#include "cocos2d.h"

// 参考资料：http://caiwb1990.iteye.com/blog/2065278
// 00 角色中毒
class LayerShaderPractice00 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice00);
private:
    virtual bool init() override;
};

#endif /* LayerShaderPractice00_h */
