//
//  SimpleButton.cpp
//  Hello
//
//  Created by ccf on 16/5/31.
//
//

#include "SimpleButton.h"

#include "MacrosAssert.h"
#include "EaseElasticOutWithCoefficient.h"

USING_NS_CC;
using namespace cocos2d::ui;

static const Size BIG_BUTTON = Size(274,93);
static const Size MIDDLE_BUTTON = Size(244,83);
static const Size SMALL_BUTTON = Size(145,50);
static const Size LONG_BUTTON = Size(335,83);

SimpleButton* SimpleButton::createWithColorAndSize(const ESimpleButtonColor& colorType, const Size& contentSize)
{
    SimpleButton *pRet = new(std::nothrow) SimpleButton();
    if (pRet && pRet->initWithColorAndSize(colorType, contentSize))
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

SimpleButton* SimpleButton::createWithColorAndSize(const ESimpleButtonColor& colorType, const ESimpleButtonSize& contentSizeType)
{
    Size contentSize = getSizeBySizeType(contentSizeType);
    return createWithColorAndSize(colorType, contentSize);
}

cocos2d::Size SimpleButton::getSizeBySizeType(const ESimpleButtonSize& contentSizeType)
{
    switch (contentSizeType)
    {
        case ESimpleButtonSize::Big:
            return BIG_BUTTON;
        case ESimpleButtonSize::Middle:
            return MIDDLE_BUTTON;
        case ESimpleButtonSize::Small:
            return SMALL_BUTTON;
        case ESimpleButtonSize::Long:
            return LONG_BUTTON;
        default:
            return MIDDLE_BUTTON;
    }
}

std::string SimpleButton::getButtonSpriteRes(const ESimpleButtonColor& colorType)
{
    std::string strRes("res/jelly_study/simple_button/");
    switch (colorType)
    {
        case ESimpleButtonColor::Red:
            strRes.append("button_red.png");
            break;
        case ESimpleButtonColor::Green:
            strRes.append("button_green.png");
            break;
        case ESimpleButtonColor::Blue:
            strRes.append("button_blue.png");
            break;
        case ESimpleButtonColor::Yellow:
            strRes.append("button_yellow.png");
            break;
        case ESimpleButtonColor::Grey:
            strRes.append("button_grey.png");
            break;
        default:
            return "";
    }
    return strRes;
}

Scale9Sprite* SimpleButton::createButtonSprite(const ESimpleButtonColor& colorType)
{
    std::string strRes = getButtonSpriteRes(colorType);
    const Rect fullRect(0.0f, 0.0f, 105.0f, 97.0f);
    const Rect capInsetsRect(52.0f, 14.0f, 1.0f, 74.0f);
    return Scale9Sprite::create(strRes, fullRect, capInsetsRect);
}

bool SimpleButton::initWithColorAndSize(const ESimpleButtonColor& colorType, const Size& contentSize)
{
    m_funcClickCallback = nullptr;
    m_bEnabled = true;
    m_eButtonColorType = colorType;
    
    m_pContainer = Node::create();
    CC_RETURN_VALUE_IF_ASSERT_FAIL(m_pContainer != nullptr, false);
    addChild(m_pContainer);
    
    m_pBtnScale9Sprite = createButtonSprite(colorType);
    m_pBtnScale9Sprite->setContentSize(contentSize);
    m_pContainer->addChild(m_pBtnScale9Sprite);
    
    m_pContentLabel = Label::create();
    m_pContainer->addChild(m_pContentLabel);
    m_pContentLabel->setSystemFontSize(contentSize.height*0.5f);
    
    EventListenerTouchOneByOne* pTouchListener = EventListenerTouchOneByOne::create();
    pTouchListener->setSwallowTouches(true);
    pTouchListener->onTouchBegan = CC_CALLBACK_2(SimpleButton::onTouchBeganCallback, this);
    pTouchListener->onTouchMoved = CC_CALLBACK_2(SimpleButton::onTouchMovedCallback, this);
    pTouchListener->onTouchEnded = CC_CALLBACK_2(SimpleButton::onTouchEndedCallback, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(pTouchListener, this);
    
    m_pContainer->setContentSize(contentSize);
    this->setContentSize(contentSize);
    
    return true;
}

bool SimpleButton::onTouchBeganCallback(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
    if (isVisible() == false || m_bEnabled == false)
    {
        return false;
    }
    
    if (!touchInsideButton(pTouch))
    {
        return false;
    }

    doPressedAction();
    
    return true;
}

void SimpleButton::onTouchMovedCallback(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
}

void SimpleButton::onTouchEndedCallback(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
    if (touchInsideButton(pTouch))
    {
        if (m_funcClickCallback)
        {
            m_funcClickCallback();
        }
    }
    
    doNormalAction();
}

bool SimpleButton::touchInsideButton(Touch* pTouch)
{
    //convertTouchToNodeSpace中会考虑scale
    Size touchableSize = this->getContentSize();
    Rect rect = Rect(-touchableSize.width*0.5f, -touchableSize.height*0.5f, touchableSize.width, touchableSize.height);
    
    Point touchPos = m_pContainer->convertTouchToNodeSpace(pTouch);
    return rect.containsPoint(touchPos);
}

void SimpleButton::setLabel(const std::string& strContent)
{
    CC_RETURN_IF_ASSERT_FAIL(m_pContentLabel != nullptr);
    m_pContentLabel->setString(strContent);
}

void SimpleButton::setLabel(const std::string& strContent, float fontSize)
{
    CC_RETURN_IF_ASSERT_FAIL(m_pContentLabel != nullptr);
    m_pContentLabel->setString(strContent);
    m_pContentLabel->setSystemFontSize(fontSize);
}

void SimpleButton::setClickCallback(std::function<void()> funcCallback)
{
    m_funcClickCallback = funcCallback;
}

void SimpleButton::stopActionState()
{
    m_pContainer->stopAllActions();
    m_pContainer->setScale(m_fStartScaleX, m_fStartScaleY);
}

void SimpleButton::doPressedAction()
{
    if (m_pContainer)
    {
        float duration = 0.5f;
        stopActionState();
        m_pContainer->runAction(EaseElasticOutWithCoefficient::create(ScaleTo::create(duration, m_fStartScaleX * 0.8f, m_fStartScaleY * 0.8f), 0.3f, 5.0f));
    }
}

void SimpleButton::doNormalAction()
{
    if (m_pContainer)
    {
        float duration = 0.5f;
        stopActionState();
        m_pContainer->runAction(EaseElasticOutWithCoefficient::create(ScaleTo::create(duration, m_pContainer->getScale()*1.0f), 0.3f, 5.0f));
    }
}

void SimpleButton::setEnabled(bool isEnabled)
{
    CC_RETURN_IF_ASSERT_FAIL(m_pBtnScale9Sprite != nullptr);
    m_bEnabled = isEnabled;
    
    ESimpleButtonColor colorType = m_bEnabled ? m_eButtonColorType : ESimpleButtonColor::Grey;
    std::string strRes = getButtonSpriteRes(colorType);
    m_pBtnScale9Sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(strRes));
}

void SimpleButton::doVibrate(bool isVibrate)
{
    CC_RETURN_IF_ASSERT_FAIL(m_pContainer != nullptr);
    
    stopActionState();
    
    if (isVibrate)
    {
        FiniteTimeAction* pAction = RepeatForever::create(Sequence::create(DelayTime::create(1.5f),
                          ScaleTo::create(0.0f, m_fStartScaleX * 0.8f, m_fStartScaleY * 1.2f),     //0.8 1.1
                          EaseElasticOutWithCoefficient::create(ScaleTo::create(0.8f, m_fStartScaleX, m_fStartScaleY), 0.25f, 2.5f),
                                                                           nullptr));
        m_pContainer->runAction(pAction);
    }
}

void SimpleButton::setScaleX(float scaleX)
{
    Node::setScaleX(scaleX);
    m_fStartScaleX = scaleX;
}

void SimpleButton::setScaleY(float scaleY)
{
    Node::setScaleY(scaleY);
    m_fStartScaleY = scaleY;
}

void SimpleButton::setScale(float scale)
{
    Node::setScale(scale);
    m_fStartScaleX = m_fStartScaleY = scale;
}

void SimpleButton::setScale(float scaleX, float scaleY)
{
    Node::setScale(scaleX, scaleY);
    m_fStartScaleX = scaleX;
    m_fStartScaleY = scaleY;
}














