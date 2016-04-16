//
//  LayerExperimentUI.h
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#ifndef LayerExperimentUI_h
#define LayerExperimentUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerExperimentUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerExperimentUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(ExperimentBackLayer,LayerExperimentUI);

#endif /* LayerExperimentUI_h */
