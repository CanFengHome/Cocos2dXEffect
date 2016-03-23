//
//  MacroDefine.h
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#ifndef MacroDefine_h
#define MacroDefine_h

#include "cocos2d.h"
#include "BaseBackLayer.h"
#include "FunctionBackLayer.h"

#define CREATE_BACK_LAYER_FUNC(__TYPE_LAYER__,__UI_LAYER__) \
class __TYPE_LAYER__ : public BaseBackLayer \
{ \
public: \
    CREATE_FUNC(__TYPE_LAYER__); \
protected: \
    virtual void gotoNextScene() override \
    { \
        cocos2d::Scene* pScene = cocos2d::Scene::create(); \
        pScene->addChild(__UI_LAYER__::create()); \
        pScene->addChild(FunctionBackLayer::create()); \
        cocos2d::Director::getInstance()->replaceScene(pScene); \
    } \
};

#define CREATE_TEST_LAYER_FUNC(__OUT_LAYER__,__LAYER_INDEX__) \
case __LAYER_INDEX__: \
__OUT_LAYER__ = LayerAnimationStudy##__LAYER_INDEX__::create(); \
break;









#endif /* MacroDefine_h */
