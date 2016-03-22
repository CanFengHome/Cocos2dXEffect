//
//  BaseBackLayer.h
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#ifndef BaseBackLayer_h
#define BaseBackLayer_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class BaseBackLayer : public cocos2d::Layer
{
protected:
    virtual bool init() override;
    void btnBackCallback(cocos2d::Ref* pSender);
protected:
    virtual void gotoNextScene()=0;
};

#endif /* BaseBackLayer_h */
