//
//  LayerShaderPracticeUI.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderPracticeUI_h
#define LayerShaderPracticeUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerShaderPracticeUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerShaderPracticeUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(ShaderPracticeBackLayer,LayerShaderPracticeUI);


#endif /* LayerShaderPracticeUI_h */
