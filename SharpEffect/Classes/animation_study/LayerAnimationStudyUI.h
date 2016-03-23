//
//  LayerAnimationStudyUI.h
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#ifndef LayerAnimationStudyUI_h
#define LayerAnimationStudyUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerAnimationStudyUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerAnimationStudyUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(AnimationStudyBackLayer,LayerAnimationStudyUI);

#endif /* LayerAnimationStudyUI_h */
