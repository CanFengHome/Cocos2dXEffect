//
//  AllRenderTextureClippingNode.h
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#ifndef AllRenderTextureClippingNode_h
#define AllRenderTextureClippingNode_h

#include "cocos2d.h"

class AllRenderTextureClippingNode : public cocos2d::Node
{
public:
    CREATE_FUNC(AllRenderTextureClippingNode);
protected:
    virtual bool init() override;
private: // render
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    virtual void onEnter() override;
    virtual void onExit() override;
    
private:
    cocos2d::Vector<cocos2d::Sprite*> m_arrTopSprites;
    cocos2d::Vector<cocos2d::Sprite*> m_arrWaters;
    cocos2d::Vector<cocos2d::Sprite*> m_arrMaskSprites;
    
    cocos2d::RenderTexture* m_pTarget = nullptr;
};

#endif /* AllRenderTextureClippingNode_h */
