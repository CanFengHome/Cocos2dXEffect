//
//  AllRenderTextureBatchClippingNode.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "AllRenderTextureBatchClippingNode.h"


USING_NS_CC;

const static Size RenderContentSize = Size(150.0f, 148.0f);

AllRenderTextureBatchClippingNode::~AllRenderTextureBatchClippingNode()
{
    CC_SAFE_RELEASE(m_pTopBatchNode);
    CC_SAFE_RELEASE(m_pMaskBatchNode);
    CC_SAFE_RELEASE(m_pWaterBatchNode);
}

bool AllRenderTextureBatchClippingNode::init()
{
    Size winSize = Director::getInstance()->getWinSize();
    m_pTarget = RenderTexture::create(winSize.width, winSize.height);
    this->addChild(m_pTarget);
    
    m_pTopBatchNode = SpriteBatchNode::create("res/ui/water_bottle/bottle.png");
    m_pTopBatchNode->retain();
    
    m_pMaskBatchNode = SpriteBatchNode::create("res/ui/water_bottle/water_mask.png");
    m_pMaskBatchNode->retain();
    
    m_pWaterBatchNode = SpriteBatchNode::create("res/ui/water_bottle/water.png");
    m_pWaterBatchNode->retain();
    
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
            m_pTopBatchNode->addChild(pTopSprite);
            
            Sprite* pWater = Sprite::create("res/ui/water_bottle/water.png");
            m_arrWaters.pushBack(pWater);
            m_pWaterBatchNode->addChild(pWater);
            
            Sprite* pMaskSprite = Sprite::create("res/ui/water_bottle/water_mask.png");
            m_arrMaskSprites.pushBack(pMaskSprite);
            m_pMaskBatchNode->addChild(pMaskSprite);
            
            pTopSprite->setPosition(currX, currY);
            pWater->setPosition(currX, currY);
            pMaskSprite->setPosition(currX, currY);
            
            ActionInterval* pMoveAction = MoveBy::create(0.4f, Vec2(8.0f,0.0f));
            ActionInterval* pRepeatAction = Sequence::create(pMoveAction, pMoveAction->reverse(), NULL);
            pWater->runAction(RepeatForever::create(pRepeatAction));
        }
    }
    
    BlendFunc maskBlend = {GL_ONE, GL_ZERO};
    m_pMaskBatchNode->setBlendFunc(maskBlend);
    
    BlendFunc waterBlend = {GL_DST_ALPHA, GL_ZERO};
    m_pWaterBatchNode->setBlendFunc(waterBlend);
    
    return true;
}

void AllRenderTextureBatchClippingNode::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    m_pTarget->begin();
    
    m_pMaskBatchNode->cocos2d::Node::visit();
    m_pWaterBatchNode->cocos2d::Node::visit();
    m_pTopBatchNode->cocos2d::Node::visit();
    
    m_pTarget->end();
}

void AllRenderTextureBatchClippingNode::onEnter()
{
    Node::onEnter();
    
    for (Sprite* pWater : m_arrWaters)
    {
        pWater->resume();
    }
}

void AllRenderTextureBatchClippingNode::onExit()
{
    Node::onExit();
    for (Sprite* pWater : m_arrWaters)
    {
        pWater->pause();
    }
}

























