//
//  LayerAnimationPractice04.cpp
//  SharpEffect
//
//  Created by ccf on 16/7/21.
//
//

#include "LayerAnimationPractice04.h"

#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

const Size ITEM_SIZE(74.0f, 74.0f);
const float ITEM_DROP_STEP = ITEM_SIZE.height*0.1f;

#pragma mark NormalItem

bool NormalItem::init()
{
    m_pContentSprite = Sprite::create("res/jelly_study/item/item_3.png");
    addChild(m_pContentSprite);
    m_pContentSprite->setPosition(ITEM_SIZE*0.5f);
    m_pContentSprite->setScale(0.5f);
    
    setContentSize(ITEM_SIZE);
    
    return true;
}

void NormalItem::startDrop()
{
    if (m_bIsDropping)
    {
        return;
    }
    
    m_srcPosition = getPosition();
    m_targetPosition = getPosition() - Vec2(0.0f, ITEM_SIZE.height);
    schedule(schedule_selector(NormalItem::dropTimer), 0.1f);
}

void NormalItem::dropTimer(float dt)
{
    // 假设前提条件 m_targetPosition 在 m_srcPosition 正下方
    // 假设条件不判断
    
    if (getPositionY() <= m_targetPosition.y)
    {
        // 结束
        setPosition(m_targetPosition);
        resetStatus();
        unschedule(schedule_selector(NormalItem::dropTimer));
        return;
    }
    
    //
    m_bIsDropping = true;
    m_pContentSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    m_pContentSprite->setPositionY(0.0f);
    setPosition(getPosition()-Vec2(0.0f, ITEM_DROP_STEP));
    
    float moveDy = m_srcPosition.y - getPositionY();
    float textureScale = 1/m_pContentSprite->getScale();
    Rect textureRect(0.0f, (ITEM_SIZE.height-moveDy)*textureScale, ITEM_SIZE.width*textureScale, moveDy*textureScale);
    m_pContentSprite->setTextureRect(textureRect);
}

void NormalItem::resetStatus()
{
    m_bIsDropping = false;
    m_srcPosition = Vec2::ZERO;
    m_targetPosition = Vec2::ZERO;
    
    m_pContentSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    m_pContentSprite->setPositionY(ITEM_SIZE.height*0.5f);
}

#pragma mark LayerAnimationPractice04

bool LayerAnimationPractice04::init()
{
    if (!LayerColor::initWithColor(Color4B::GRAY))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    Button* pBtnTest = Button::create();
    pBtnTest->setTitleFontSize(40.0f);
    pBtnTest->setTitleColor(Color3B::BLACK);
    pBtnTest->setTitleText("Test");
    pBtnTest->setPosition(Vec2(winSize.width*0.5f, 40.0f));
    addChild(pBtnTest);
    pBtnTest->addClickEventListener(CC_CALLBACK_1(LayerAnimationPractice04::btnTestCallback, this));
    
    m_pNormalItem = NormalItem::create();
    m_pNormalItem->setPosition(winSize*0.5f+ITEM_SIZE);
    addChild(m_pNormalItem);
    
    for (int i=0; i<10; ++i)
    {
        DrawNode* pDrawNode = DrawNode::create();
        pDrawNode->drawRect(m_pNormalItem->getPosition()-Vec2(0.0f, i*ITEM_SIZE.height),
                            m_pNormalItem->getPosition()+ITEM_SIZE,
                            Color4F::RED);
        addChild(pDrawNode);
    }
    
    return true;
}

void LayerAnimationPractice04::btnTestCallback(Ref* pSender)
{
    if (!m_pNormalItem)
    {
        return;
    }
    
    m_pNormalItem->startDrop();
}































