//
//  LayerShaderPractice03.h
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#ifndef LayerShaderPractice03_h
#define LayerShaderPractice03_h

#include "cocos2d.h"

// 03 闪电效果 http://cocos2d.9tech.cn/news/2014/0210/39791.html
class LayerShaderPractice03 : public cocos2d::Layer
{
public:
    CREATE_FUNC(LayerShaderPractice03);
private:
    virtual bool init() override;
    
private:
    // 闪电路线的递归函数，起始终止点和偏移量
    void drawLighting(float x1,float y1,float x2,float y2,float displace);
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    
private:
    cocos2d::Vec2 m_posSrc;
    cocos2d::Vec2 m_posTarget;
    float m_curDetail = 5;
    cocos2d::DrawNode* m_pDrawNode = nullptr;
};


#endif /* LayerShaderPractice03_h */
