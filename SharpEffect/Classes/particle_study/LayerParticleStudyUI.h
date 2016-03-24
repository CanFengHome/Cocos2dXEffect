//
//  LayerParticleStudyUI.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerParticleStudyUI_h
#define LayerParticleStudyUI_h

#include "BaseDataListLayer.h"
#include "BaseBackLayer.h"
#include "MacroDefine.h"

class LayerParticleStudyUI : public BaseDataListLayer
{
public:
    CREATE_FUNC(LayerParticleStudyUI);
protected:
    virtual void initFunNames() override;
    virtual void clickFunIndex(ssize_t selIndex) override;
};

CREATE_BACK_LAYER_FUNC(ParticleStudyBackLayer,LayerParticleStudyUI);

#endif /* LayerParticleStudyUI_h */
