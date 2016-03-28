//
//  LayerShaderPractice06.h
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#ifndef LayerShaderPractice06_h
#define LayerShaderPractice06_h

#include "cocos2d.h"

// 06 心形跳动 算法详细解释 http://blog.csdn.net/stalendp/article/details/22221597
class LayerShaderPractice06 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice06);
private:
    virtual bool init() override;
};

#endif /* LayerShaderPractice06_h */
