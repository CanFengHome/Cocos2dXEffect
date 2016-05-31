//
//  LayerJellyStudy00.cpp
//  SharpEffect
//
//  Created by ccf on 16/5/30.
//
//

#include "LayerJellyStudy00.h"

USING_NS_CC;
bool LayerJellyStudy00::init()
{
    if (!LayerColor::initWithColor(Color4B::GRAY))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    m_pSimpleBtn = SimpleButton::createWithColorAndSize(ESimpleButtonColor::Blue, ESimpleButtonSize::Middle);
    addChild(m_pSimpleBtn);
    m_pSimpleBtn->setPosition(winSize*0.5f);
    m_pSimpleBtn->setLabel("click");
    m_pSimpleBtn->setClickCallback(CC_CALLBACK_0(LayerJellyStudy00::btnTestCallback, this));
    
    m_pSimpleBtnTarget= SimpleButton::createWithColorAndSize(ESimpleButtonColor::Green, ESimpleButtonSize::Middle);
    addChild(m_pSimpleBtnTarget);
    m_pSimpleBtnTarget->setPosition(winSize*0.5f+Size(0.0f, m_pSimpleBtn->getContentSize().height*1.5f));
    m_pSimpleBtnTarget->setLabel("Target");
    
    return true;
}

void LayerJellyStudy00::btnTestCallback()
{
    static int clickCount = 0;
    ++clickCount;
    m_pSimpleBtn->setLabel(__String::createWithFormat("click %d", clickCount)->getCString());
    
    if (clickCount % 5 == 0)
    {
        m_pSimpleBtnTarget->doVibrate(true);
    }
    else if (clickCount >= 100)
    {
        m_pSimpleBtnTarget->doVibrate(false);
    }
}















