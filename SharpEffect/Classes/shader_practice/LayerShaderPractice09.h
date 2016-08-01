//
//  LayerShaderPractice09.h
//  SharpEffect
//
//  Created by ccf on 16/8/1.
//
//

#ifndef LayerShaderPractice09_h
#define LayerShaderPractice09_h

#include "cocos2d.h"

// 09 UV动画
class LayerShaderPractice09 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerShaderPractice09);
    virtual bool init() override;
private:
    void updateTextUVAnimation(float duration);
private:
    cocos2d::Sprite* m_pSprite = nullptr;
    cocos2d::Vec2 m_textUV;
};

#endif /* LayerShaderPractice09_h */
