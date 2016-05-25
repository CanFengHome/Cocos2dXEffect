//
//  LetterActionNode.cpp
//  Practice
//
//  Created by mfp on 16/5/12.
//
//

#include "LetterActionNode.h"

using namespace std;
USING_NS_CC;

static const int LETTER_SPRITE_ZORDER = 10;
static const int LETTER_MASK_BOTTOM_SPRITE_ZORDER = 5;
static const float LETTER_SPACE_INTERVAL_DISTANCE = 10.0f;
static const char* const PLIST_FONT_ANIMATION = "res/animation/bingo_font_animation.plist";


LetterActionNode* LetterActionNode::createWithString(const std::string& strLetters)
{
    LetterActionNode *pRet = new(std::nothrow) LetterActionNode();
    if (pRet && pRet->initWithString(strLetters))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool LetterActionNode::initWithString(const std::string& strLetters)
{
    if (strLetters.empty() ||
        // 首尾不能有空字符
        strLetters.front() == ' ' ||
        strLetters.back() == ' ')
    {
        return false;
    }
    
    // 预加载plist文件
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(PLIST_FONT_ANIMATION);
    
    // 可以按照屏幕宽度尺寸处理
    if (strLetters.size() < 6)
    {
        m_fLetterTargetScale = 0.6f;
    }
    else
    {
        m_fLetterTargetScale = 0.46f;
    }
    
    m_fMaxContetHeight = 0.0f;
    m_fContentWidth = 0.0f;
    m_strLetters = strLetters;
    
    for (int i=0; i<strLetters.size(); ++i)
    {
        char letter = strLetters[i];
        if (letter == ' ')
        {
            m_arrLetterSprites.push_back(nullptr);
            m_arrLetterBottomMaskSprites.push_back(nullptr);
            
            continue;
        }
        
        Sprite* pLetterSprite = Sprite::createWithSpriteFrameName(__String::createWithFormat("bingo_font_animation_%c.png", letter)->getCString());
        assert(pLetterSprite!=nullptr);
        pLetterSprite->setScale(m_fLetterTargetScale);
        addChild(pLetterSprite, LETTER_SPRITE_ZORDER);
        m_arrLetterSprites.push_back(pLetterSprite);
        
        m_fContentWidth += pLetterSprite->getContentSize().width*m_fLetterTargetScale;
        m_fMaxContetHeight = MAX(m_fMaxContetHeight, pLetterSprite->getContentSize().height*m_fLetterTargetScale);
        
        Sprite* pLetterMaskSprite = Sprite::createWithSpriteFrameName(__String::createWithFormat("bingo_font_animation_%c1.png", letter)->getCString());
        assert(pLetterMaskSprite!=nullptr);
        pLetterMaskSprite->setScale(m_fLetterTargetScale);
        addChild(pLetterMaskSprite, LETTER_MASK_BOTTOM_SPRITE_ZORDER);
        m_arrLetterBottomMaskSprites.push_back(pLetterMaskSprite);
        
        pLetterSprite->setVisible(false);
        pLetterSprite->setScale(0.5f*m_fLetterTargetScale);
        pLetterSprite->setOpacity(128.0f);
        
        pLetterMaskSprite->setScale(0.0f);
    }
    
#if _DEBUG
    Size winSize = Director::getInstance()->getWinSize();
    assert(strLetters.size() == m_arrLetterSprites.size());
    assert(contentWidth < winSize.width);
#endif
    
    assert(m_arrLetterSprites[0] != nullptr);
    float startY = -m_fMaxContetHeight;
    float startX = -m_fContentWidth*0.5f + m_arrLetterSprites[0]->getContentSize().width*m_fLetterTargetScale*0.5f;
    
    m_arrLetterSprites[0]->setPosition(startX, startY);
    float firstSpriteEndY = 0.0f;
    float spriteEndBottomHeight = firstSpriteEndY-m_arrLetterSprites[0]->getContentSize().height*m_fLetterTargetScale*0.5f;
    
    m_arrLetterBottomMaskSprites[0]->setPosition(startX, firstSpriteEndY);
    float prevSpriteRightX = startX + m_arrLetterSprites[0]->getContentSize().width*m_fLetterTargetScale*0.5f;
    
    for (int i = 1; i < m_arrLetterSprites.size(); ++i)
    {
        if (m_arrLetterSprites[i] == nullptr) // 空格字符需要添加空格的距离
        {
            prevSpriteRightX += LETTER_SPACE_INTERVAL_DISTANCE;
            continue;
        }
        
        Sprite* pLetterSprite = m_arrLetterSprites[i];
        assert(pLetterSprite != nullptr);
        float currX = prevSpriteRightX+pLetterSprite->getContentSize().width*m_fLetterTargetScale*0.5f;
        pLetterSprite->setPosition(currX, startY);
        
        float endY = spriteEndBottomHeight + pLetterSprite->getContentSize().height*m_fLetterTargetScale*0.5f;
        m_arrLetterBottomMaskSprites[i]->setPosition(currX, endY);
        
        prevSpriteRightX += pLetterSprite->getContentSize().width*m_fLetterTargetScale;
    }
    
    return true;
}

static const float timeFromBottomToTop = 0.13f*2.0f; // 1.3
static const float timeScale1 = 0.08f; // 0.8
static const float timeScale2 = 0.13f; // 1.3

void LetterActionNode::startLetterAction()
{
    float targetScale = 1.0f * m_fLetterTargetScale;
    for (int i=0; i<m_arrLetterSprites.size(); ++i)
    {
        if (m_arrLetterSprites[i] == nullptr)
        {
            // 空格不处理动画
            continue;
        }
        
        Sprite* pLetterSprite = m_arrLetterSprites[i];
        Sprite* pLetterMaskSprite = m_arrLetterBottomMaskSprites[i];
        assert(pLetterSprite != nullptr && pLetterMaskSprite != nullptr);
        Vec2 targetPosition = Vec2(pLetterSprite->getPositionX(), pLetterMaskSprite->getPositionY());
        
        Vector<FiniteTimeAction*> actionList;
        actionList.pushBack(DelayTime::create(timeFromBottomToTop*0.2f*i));
        actionList.pushBack(Show::create());
        actionList.pushBack(Spawn::create(EaseOut::create(MoveTo::create(timeFromBottomToTop, targetPosition), 5.0f),
                                          EaseOut::create(ScaleTo::create(timeFromBottomToTop, targetScale), 5.0f),
                                          EaseIn::create(FadeIn::create(timeFromBottomToTop), 10.0f),
                                          nullptr));
        ActionInterval* pScaleAction1 = Sequence::create(ScaleTo::create(timeScale1, targetScale*2.0f, targetScale*0.5f),
                                                         ScaleTo::create(timeScale2, targetScale), nullptr);
        ActionInterval* pScaleAction2 = Sequence::create(ScaleTo::create(timeScale1, targetScale*1.5f, targetScale*0.8f),
                                                         ScaleTo::create(timeScale2, targetScale), nullptr);
        ActionInterval* pScaleAction3 = Sequence::create(ScaleTo::create(timeScale1, targetScale*1.2f, targetScale*0.9f),
                                                         ScaleTo::create(timeScale2, targetScale), nullptr);
        actionList.pushBack(pScaleAction1);
        actionList.pushBack(pScaleAction2);
        actionList.pushBack(pScaleAction3);
        
        if (i == m_arrLetterSprites.size()-1)
        {
            actionList.pushBack(CallFunc::create(CC_CALLBACK_0(LetterActionNode::bottomToTopActionFinish, this)));
        }
                            
        pLetterSprite->runAction(Sequence::create(actionList));
        
        pLetterMaskSprite->runAction(Sequence::create(DelayTime::create(timeFromBottomToTop*0.2f*i),
                                                      ScaleTo::create(timeFromBottomToTop*0.3f, targetScale*1.2f),
                                                      ScaleTo::create(timeScale2, targetScale),
                                                      ScaleTo::create(timeScale1, targetScale*1.1f),
                                                      ScaleTo::create(timeScale2, targetScale),
                                                      nullptr));
    }
}

void LetterActionNode::bottomToTopActionFinish()
{
    float moveByHeight = MIN(m_fMaxContetHeight*0.5f, 30.0f);
    float unitActionTime = 0.15f; // 1.0f
    float scaleMoveTime = 0.2f;// 0.5f;
    MoveBy* pMoveAction2 = MoveBy::create(scaleMoveTime, Vec2(0.0f, moveByHeight));

    auto allSpritesDisppear = [this, scaleMoveTime]()
    {
        for (int i = 0; i < m_arrLetterSprites.size(); ++i)
        {
            Sprite* pLetterSprite = m_arrLetterSprites[i];
            Sprite* pLetterMaskSprite = m_arrLetterBottomMaskSprites[i];
            
            if (pLetterSprite != nullptr && pLetterMaskSprite != nullptr) // 字符和字符mask必须配对出现
            {
                ActionInterval* pLetterDisappearAction = EaseIn::create(FadeOut::create(scaleMoveTime), 0.5f);
                pLetterSprite->runAction(pLetterDisappearAction);
                pLetterMaskSprite->runAction(pLetterDisappearAction->clone());
            } // else continue. 如果是空格，则获取值 == nullptr
        }
    };
    
    Size winSize = Director::getInstance()->getWinSize();
    float disappearScaleTo = winSize.width*1.2f/m_fContentWidth;
    ActionInterval* pDisappearAction = Spawn::create(pMoveAction2,
                                                     ScaleTo::create(scaleMoveTime, disappearScaleTo),
                                                     CallFunc::create(allSpritesDisppear),
                                                     nullptr);
    // 可以在最后增加 RemoveSelf::create(), 因为该Node的Action时间和单个Sprite的Action时间一致
    this->runAction(Sequence::create(DelayTime::create(unitActionTime*1.0f),
                                     pDisappearAction,
                                     nullptr));
}





















