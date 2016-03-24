//
//  LayerAnimationPracticeUI.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerAnimationPracticeUI_h
#define LayerAnimationPracticeUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerAnimationPracticeUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerAnimationPracticeUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(AnimationPracticeBackLayer,LayerAnimationPracticeUI);

#endif /* LayerAnimationPracticeUI_h */
