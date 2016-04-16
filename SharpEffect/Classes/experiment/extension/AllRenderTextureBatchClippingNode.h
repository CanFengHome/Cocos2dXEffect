//
//  AllRenderTextureBatchClippingNode.h
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#ifndef AllRenderTextureBatchClippingNode_h
#define AllRenderTextureBatchClippingNode_h

#include "cocos2d.h"

class AllRenderTextureBatchClippingNode : public cocos2d::Node
{
public:
    CREATE_FUNC(AllRenderTextureBatchClippingNode);
    ~AllRenderTextureBatchClippingNode();
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
    
    cocos2d::SpriteBatchNode* m_pTopBatchNode = nullptr;
    cocos2d::SpriteBatchNode* m_pMaskBatchNode = nullptr;
    cocos2d::SpriteBatchNode* m_pWaterBatchNode = nullptr;
    
    cocos2d::RenderTexture* m_pTarget = nullptr;
};

#endif /* AllRenderTextureBatchClippingNode_h */
