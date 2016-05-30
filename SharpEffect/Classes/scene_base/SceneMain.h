//
//  MainScene.h
//  Hello
//
//  Created by ccf on 16/2/19.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"

class LayerMainDataList : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerMainDataList);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

class SceneMain : public cocos2d::Scene
{
public:
    CREATE_FUNC(SceneMain);
private:
    virtual bool init() override;
};

class CloseBackLayer : public BaseBackLayer
{
public:
    CREATE_FUNC(CloseBackLayer);
    
protected:
    virtual void gotoNextScene() override;
};


#endif /* MainScene_h */
