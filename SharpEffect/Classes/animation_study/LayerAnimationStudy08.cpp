//
//  LayerAnimationStudy08.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/23.
//
//

#include "LayerAnimationStudy08.h"

USING_NS_CC;
using namespace std;

bool LayerAnimationStudy08::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    string strFile = "res/animation/Hero.plist";
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(strFile);
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(0.1f);
    animation->setRestoreOriginalFrame(true);
    for (int i = 1; i < 5; i++)
    {
        const char *filename = __String::createWithFormat("hero%02d.png",i)->getCString();
        SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(filename);
        animation->addSpriteFrame(frame);
    }
    
    Sprite* pSprite = Sprite::createWithSpriteFrameName("hero00.png");
    pSprite->setPosition(winSize*0.5f);
    addChild(pSprite);
    
    ActionInterval* pActionInterval = RepeatForever::create(Animate::create(animation));
    pSprite->runAction(pActionInterval);
    
    return true;
}


void LayerAnimationStudy08::onEnter()
{
    LayerColor::onEnter();
    
    // 暂时没有发现用处
    _frameDisplayedListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [](EventCustom * event){
        auto userData = static_cast<AnimationFrame::DisplayedEventInfo*>(event->getUserData());
        
        log("target %p with data %s", userData->target, Value(userData->userInfo).getDescription().c_str());
    });
}

void LayerAnimationStudy08::onExit()
{
    LayerColor::onExit();
    
    _eventDispatcher->removeEventListener(_frameDisplayedListener);
}




