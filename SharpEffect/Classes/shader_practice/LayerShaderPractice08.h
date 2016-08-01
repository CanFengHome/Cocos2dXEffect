//
//  LayerShaderPractice08.h
//  SharpEffect
//
//  Created by ccf on 16/8/1.
//
//

#ifndef LayerShaderPractice08_h
#define LayerShaderPractice08_h

#include "cocos2d.h"

// 08 水池效果
class LayerShaderPractice08 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice08);
private:
    virtual bool init() override;
private:
    cocos2d::Sprite* m_pSprite = nullptr;
};


#endif /* LayerShaderPractice08_h */
