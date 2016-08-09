//
//  LayerCommonCodeUI.h
//  SharpEffect
//
//  Created by ccf on 16/8/9.
//
//

#ifndef LayerCommonCodeUI_h
#define LayerCommonCodeUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerCommonCodeUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerCommonCodeUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(CommonCodeBackLayer, LayerCommonCodeUI);

#endif /* LayerCommonCodeUI_h */
