//
//  LayerShaderPractice03.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/28.
//
//

#include "LayerShaderPractice03.h"

USING_NS_CC;
bool LayerShaderPractice03::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    m_posSrc = Vec2(winSize.width*0.5f,100.0f);
    m_posTarget = Vec2(winSize.width*0.5f,winSize.height-200.0f);
    
    m_pDrawNode = DrawNode::create();
    addChild(m_pDrawNode);
    
    return true;
}

// 闪电路线的递归函数，起始终止点和偏移量
void LayerShaderPractice03::drawLighting(float x1,float y1,float x2,float y2,float displace)
{
    if (displace < m_curDetail)
    {
        assert(m_pDrawNode != nullptr);
        m_pDrawNode->drawLine(Vec2(x1,y1), Vec2(x2,y2), Color4F::RED);
    }
    else
    {
        float midX = (x1+x2)*0.5f;
        float midY = (y1+y2)*0.5f;
        midX += CCRANDOM_MINUS1_1()*displace;
        midY += CCRANDOM_MINUS1_1()*displace;
        drawLighting(x1, y1, midX, midY, displace*0.5f);
        drawLighting(midX, midY, x2, y2, displace*0.5f);
    }
}

void LayerShaderPractice03::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    assert(m_pDrawNode != nullptr);
    m_pDrawNode->clear();
    drawLighting(m_posSrc.x, m_posSrc.y, m_posTarget.x, m_posTarget.y, 200);
}




