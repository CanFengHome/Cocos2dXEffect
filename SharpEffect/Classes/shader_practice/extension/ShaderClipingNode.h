//
//  ShaderClipingNode.h
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#ifndef ShaderClipingNode_h
#define ShaderClipingNode_h

#include "cocos2d.h"

class ShaderClipingNode : public cocos2d::Node
{
public:
    CREATE_FUNC(ShaderClipingNode);
protected:
    virtual bool init() override;
        
private:
    cocos2d::Sprite* m_pTargetSprite = nullptr;

    // 水波动画
private:
    void moveUpdate(float dt);
    void clearStatus();
private:
    float m_intervalTime = 0.0f;
    float m_fMoveLen = 0.0f;
    int m_iForwardDir = 1;
};

#endif /* ShaderClipingNode_h */
