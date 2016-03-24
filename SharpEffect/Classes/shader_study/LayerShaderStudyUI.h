//
//  LayerShaderStudyUI.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderStudyUI_h
#define LayerShaderStudyUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerShaderStudyUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerShaderStudyUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(ShaderStudyBackLayer,LayerShaderStudyUI);

#endif /* LayerShaderStudyUI_h */
