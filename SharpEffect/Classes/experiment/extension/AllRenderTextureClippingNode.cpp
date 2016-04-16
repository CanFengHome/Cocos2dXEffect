//
//  AllRenderTextureClippingNode.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "AllRenderTextureClippingNode.h"

USING_NS_CC;

bool AllRenderTextureClippingNode::init()
{
    Size winSize = Director::getInstance()->getWinSize();
    m_pTarget = RenderTexture::create(winSize.width, winSize.height);
    this->addChild(m_pTarget);
    
    float fixWidth = 74.0f*2;
    float fixHeight = 74.0f*2;
    float initX = 74.0f;
    float initY = 74.0f;
    
    for (int row=0; row<7; ++row)
    {
        for (int col=0; col<4; ++col)
        {
            float currX = initX + fixWidth * col;
            float currY = initY + fixHeight * row;
            
            Sprite* pTopSprite = Sprite::create("res/ui/water_bottle/bottle.png");
            m_arrTopSprites.pushBack(pTopSprite);
            
            Sprite* pWater = Sprite::create("res/ui/water_bottle/water.png");
            m_arrWaters.pushBack(pWater);
            
            Sprite* pMaskSprite = Sprite::create("res/ui/water_bottle/water_mask.png");
            m_arrMaskSprites.pushBack(pMaskSprite);
            
            pTopSprite->setPosition(currX, currY);
            pWater->setPosition(currX, currY);
            pMaskSprite->setPosition(currX, currY);
            
            BlendFunc maskBlend = {GL_ONE, GL_ZERO};
            BlendFunc waterBlend = {GL_DST_ALPHA, GL_ZERO};
            pMaskSprite->setBlendFunc(maskBlend);
            pWater->setBlendFunc(waterBlend);
            
            ActionInterval* pMoveAction = MoveBy::create(0.4f, Vec2(8.0f,0.0f));
            ActionInterval* pRepeatAction = Sequence::create(pMoveAction, pMoveAction->reverse(), NULL);
            pWater->runAction(RepeatForever::create(pRepeatAction));
        }
    }
    
    return true;
}

void AllRenderTextureClippingNode::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    m_pTarget->begin();
    
    for (Sprite* pMaskSprite : m_arrMaskSprites)
    {
        pMaskSprite->visit();
    }
    
    
    for (Sprite* pWater : m_arrWaters)
    {
        pWater->visit();
    }
    
    
    for (Sprite* pTopSprite : m_arrTopSprites)
    {
        pTopSprite->visit();
    }
    
    m_pTarget->end();
}

void AllRenderTextureClippingNode::onEnter()
{
    Node::onEnter();
    
    for (Sprite* pWater : m_arrWaters)
    {
        pWater->resume();
    }
}

void AllRenderTextureClippingNode::onExit()
{
    Node::onExit();
    for (Sprite* pWater : m_arrWaters)
    {
        pWater->pause();
    }
}

























