//
//  RenderTextureClippingNode.h
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#ifndef RenderTextureClippingNode_h
#define RenderTextureClippingNode_h

#include "cocos2d.h"

class RenderTextureClippingNode : public cocos2d::Node
{
public:
    CREATE_FUNC(RenderTextureClippingNode);
    ~RenderTextureClippingNode();
private:
    virtual bool init() override;
private: // render
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    virtual void onEnter() override;
    virtual void onExit() override;
    
private:
    cocos2d::Sprite* m_pTopSprite = nullptr;
    cocos2d::Sprite* m_pWater = nullptr;
    cocos2d::Sprite* m_pMaskSprite = nullptr;
    
    cocos2d::RenderTexture* m_pTarget = nullptr;
};

#endif /* RenderTextureClippingNode_h */
