//
//  LayerShaderPractice10.h
//  SharpEffect
//
//  Created by ccf on 16/8/1.
//
//

#ifndef LayerShaderPractice10_h
#define LayerShaderPractice10_h

#include "cocos2d.h"

// 10 漩涡效果
class LayerShaderPractice10 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice10);
    virtual bool init() override;
private:
    void updateTextUVAnimation(float duration);
private:
    cocos2d::Sprite* m_pSprite = nullptr;
};

#endif /* LayerShaderPractice10_h */
