//
//  LayerJellyStudy00.h
//  SharpEffect
//
//  Created by ccf on 16/5/30.
//
//

#ifndef LayerJellyStudy00_h
#define LayerJellyStudy00_h

#include "cocos2d.h"

#include "SimpleButton.h"

// 00 SimpleButton
class LayerJellyStudy00 : public cocos2d::LayerColor
{
public:
    CREATE_FUNC(LayerJellyStudy00);
private:
    virtual bool init() override;
private:
    void btnTestCallback();
    SimpleButton* m_pSimpleBtn = nullptr;
    SimpleButton* m_pSimpleBtnTarget = nullptr;
};


#endif /* LayerJellyStudy00_h */
