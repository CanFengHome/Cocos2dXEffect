//
//  MainScene.h
//  Hello
//
//  Created by mfp on 16/2/19.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "BaseDataListLayer.h"

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

#endif /* MainScene_h */
