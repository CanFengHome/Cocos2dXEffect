//
//  BaseBackLayer.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#include "BaseBackLayer.h"
USING_NS_CC;
using namespace ui;

#pragma mark BaseBackLayer

bool BaseBackLayer::init()
{
    if (!Layer::create())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    Button* pBtnBack = Button::create();
    pBtnBack->setPressedActionEnabled(true);
    pBtnBack->addClickEventListener(CC_CALLBACK_1(BaseBackLayer::btnBackCallback, this));
    pBtnBack->setTitleText("Back");
    addChild(pBtnBack);
    pBtnBack->setTitleFontSize(40.0f);
    pBtnBack->setTitleColor(Color3B::BLUE);
    pBtnBack->setPosition(Vec2(winSize.width-pBtnBack->getContentSize().width*0.5f,
                               pBtnBack->getContentSize().height*0.5f));
    
    return true;
}

void BaseBackLayer::btnBackCallback(Ref* pSender)
{
    gotoNextScene();
}











