//
//  LayerPhysicsStudyUI.h
//  SharpEffect
//
//  Created by ccf on 16/6/2.
//
//

#ifndef LayerPhysicsStudyUI_h
#define LayerPhysicsStudyUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerPhysicsStudyUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerPhysicsStudyUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(PhysicsStudyBackLayer, LayerPhysicsStudyUI);

#endif /* LayerPhysicsStudyUI_h */
