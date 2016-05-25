//
//  LayerAnimationPractice02.h
//  SharpEffect
//
//  Created by mfp on 16/5/25.
//
//

#ifndef LayerAnimationPractice02_h
#define LayerAnimationPractice02_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "LetterActionNode.h"

// 02 字幕动画
class LayerAnimationPractice02 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerAnimationPractice02);
private:
    virtual bool init() override;
    void btnDoneCallback(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType pTouchEventType);
private:
    LetterActionNode* m_pLetterNode = nullptr;
};

#endif /* LayerAnimationPractice02_h */
