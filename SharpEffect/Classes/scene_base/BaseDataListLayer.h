//
//  BaseDataListLayer.h
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#ifndef BaseDataListLayer_h
#define BaseDataListLayer_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class BaseDataListLayer : public cocos2d::LayerColor
{
protected:
    virtual bool init() override;
    virtual void onEnter() override;
    void initListView();
protected:
    virtual void initFunNames() = 0;
    virtual void clickFunIndex(ssize_t selIndex) = 0;
protected:
    std::vector<std::string> m_arrFunName;
    cocos2d::ui::ListView* m_pListView = nullptr;
};

#endif /* BaseDataListLayer_h */
