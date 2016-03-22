//
//  FunctionBackLayer.h
//  SharpEffect
//
//  Created by mfp on 16/3/22.
//
//

#ifndef FunctionBackLayer_h
#define FunctionBackLayer_h

#include "BaseBackLayer.h"

class FunctionBackLayer : public BaseBackLayer
{
public:
    CREATE_FUNC(FunctionBackLayer);
    
protected:
    virtual void gotoNextScene() override;
};

#endif /* FunctionBackLayer_h */
