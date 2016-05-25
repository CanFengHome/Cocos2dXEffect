//
//  LayerAnimationPractice02.cpp
//  SharpEffect
//
//  Created by mfp on 16/5/25.
//
//

#include "LayerAnimationPractice02.h"

USING_NS_CC;
using namespace cocos2d::ui;

bool LayerAnimationPractice02::init()
{
    if (!LayerColor::initWithColor(Color4B::GRAY))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Button* pBtnDone = Button::create();
    pBtnDone->setPressedActionEnabled(true);
    pBtnDone->addTouchEventListener(CC_CALLBACK_2(LayerAnimationPractice02::btnDoneCallback, this));
    pBtnDone->setTitleText("Done");
    pBtnDone->setTitleColor(Color3B::BLACK);
    addChild(pBtnDone);
    pBtnDone->setTitleFontSize(25.0f);
    pBtnDone->setPosition(Vec2(winSize.width*0.5f, pBtnDone->getContentSize().height));
    pBtnDone->setName("BtnDone");
    
    return true;
}

void LayerAnimationPractice02::btnDoneCallback(Ref *pSender, Widget::TouchEventType pTouchEventType)
{
    if (pTouchEventType == Widget::TouchEventType::ENDED)
    {
        if (m_pLetterNode != nullptr && m_pLetterNode->getParent() != nullptr)
        {
            m_pLetterNode->removeFromParent();
        }
        
        Size winSize = Director::getInstance()->getWinSize();
        m_pLetterNode = LetterActionNode::createWithString("bingo bingo");
        addChild(m_pLetterNode);
        m_pLetterNode->setPosition(winSize*0.5f);
        
        m_pLetterNode->startLetterAction();
    }
}




























