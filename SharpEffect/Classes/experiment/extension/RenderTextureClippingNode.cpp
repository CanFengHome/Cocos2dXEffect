//
//  RenderTextureClippingNode.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "RenderTextureClippingNode.h"

USING_NS_CC;

const static Size RenderContentSize = Size(150.0f, 148.0f);

RenderTextureClippingNode::~RenderTextureClippingNode()
{
    CC_SAFE_RELEASE(m_pTopSprite);
    CC_SAFE_RELEASE(m_pWater);
    CC_SAFE_RELEASE(m_pMaskSprite);
}

bool RenderTextureClippingNode::init()
{
    setContentSize(RenderContentSize);
    
    m_pTopSprite = Sprite::create("res/ui/water_bottle/bottle.png");
    m_pTopSprite->retain();
    
    m_pWater = Sprite::create("res/ui/water_bottle/water.png");
    m_pWater->retain();
    
    m_pMaskSprite = Sprite::create("res/ui/water_bottle/water_mask.png");
    m_pMaskSprite->retain();
    
    m_pTopSprite->setPosition(RenderContentSize*0.5f);
    m_pWater->setPosition(RenderContentSize*0.5f);
    m_pMaskSprite->setPosition(RenderContentSize*0.5f);
    
    Size s = Director::getInstance()->getWinSize();
    m_pTarget = RenderTexture::create(RenderContentSize.width, RenderContentSize.height);
    this->addChild(m_pTarget);
    
    BlendFunc maskBlend = {GL_ONE, GL_ZERO};
    BlendFunc waterBlend = {GL_DST_ALPHA, GL_ZERO};
    m_pMaskSprite->setBlendFunc(maskBlend);
    m_pWater->setBlendFunc(waterBlend);
    
    ActionInterval* pMoveAction = MoveBy::create(0.4f, Vec2(8.0f,0.0f));
    ActionInterval* pRepeatAction = Sequence::create(pMoveAction, pMoveAction->reverse(), NULL);
    m_pWater->runAction(RepeatForever::create(pRepeatAction));
    
    return true;
}

void RenderTextureClippingNode::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    m_pTarget->begin();
    
    m_pMaskSprite->visit();
    m_pWater->visit();
    m_pTopSprite->visit();
    
    m_pTarget->end();
}

void RenderTextureClippingNode::onEnter()
{
    Node::onEnter();
    
    m_pMaskSprite->resume();
    m_pWater->resume();
    
}

void RenderTextureClippingNode::onExit()
{
    Node::onExit();
    
    m_pMaskSprite->pause();
    m_pWater->pause();
}
