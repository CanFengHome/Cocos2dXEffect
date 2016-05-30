//
//  LayerJellyStudyUI.h
//  SharpEffect
//
//  Created by ccf on 16/5/30.
//
//

#ifndef LayerJellyStudyUI_h
#define LayerJellyStudyUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerJellyStudyUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerJellyStudyUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(JellyStudyBackLayer,LayerJellyStudyUI);

#endif /* LayerJellyStudyUI_h */
