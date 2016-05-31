//
//  SimpleButton.h
//  Hello
//
//  Created by ccf on 16/5/31.
//
//

#ifndef SimpleButton_h
#define SimpleButton_h

#include <functional>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

enum class ESimpleButtonColor
{
    Red,
    Green,
    Blue,
    Yellow,
    Grey
};

enum class ESimpleButtonSize
{
    Big,
    Middle,
    Small,
    Long
};

class SimpleButton : public cocos2d::Node
{
public:
    static SimpleButton* createWithColorAndSize(const ESimpleButtonColor& colorType, const cocos2d::Size& contentSize);
    static SimpleButton* createWithColorAndSize(const ESimpleButtonColor& colorType, const ESimpleButtonSize& contentSizeType);
    
    void setLabel(const std::string& strContent);
    void setLabel(const std::string& strContent, float fontSize);
    void setClickCallback(std::function<void()> funcCallback);
    void setEnabled(bool isEnabled);
    // 振动
    void doVibrate(bool isVibrate);
    // 摆动
    void doSwing(bool isSwing);
    
    virtual void setScaleX(float scaleX) override;
    virtual void setScaleY(float scaleY) override;
    virtual void setScale(float scale) override;
    virtual void setScale(float scaleX, float scaleY) override;
private:
    bool initWithColorAndSize(const ESimpleButtonColor& colorType, const cocos2d::Size& contentSize);
    
    static cocos2d::ui::Scale9Sprite* createButtonSprite(const ESimpleButtonColor& colorType);
    static std::string getButtonSpriteRes(const ESimpleButtonColor& colorType);
    static cocos2d::Size getSizeBySizeType(const ESimpleButtonSize& contentSizeType);
    
    bool onTouchBeganCallback(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    void onTouchMovedCallback(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    void onTouchEndedCallback(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    // 判断输入的touch点是否位于按钮的点击区域内
    bool touchInsideButton(cocos2d::Touch* pTouch);
    
    void stopActionState();
    void doPressedAction();
    void doNormalAction();
private:
    std::function<void()> m_funcClickCallback;
    cocos2d::Node* m_pContainer;
    ESimpleButtonColor m_eButtonColorType;
    
    float m_fStartScaleX = 1.0f;
    float m_fStartScaleY = 1.0f;
    
    CC_SYNTHESIZE_READONLY(cocos2d::ui::Scale9Sprite*, m_pBtnScale9Sprite, BtnSprite);
    // 按钮中的文字
    CC_SYNTHESIZE_READONLY(cocos2d::Label*, m_pContentLabel, ContentLabel);
    
    // 是否enable
    CC_SYNTHESIZE_READONLY(bool, m_bEnabled, Enabled);
};

#endif /* SimpleButton_h */
