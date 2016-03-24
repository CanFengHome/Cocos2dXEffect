//
//  LayerShaderStudy04.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderStudy04_h
#define LayerShaderStudy04_h

// 04 define shader 颜色Byte类型
class LayerShaderStudy04 : public cocos2d::Layer
{
public:
    CREATE_FUNC(LayerShaderStudy04);
private:
    virtual bool init() override;
    
private:
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
    void onCustomDraw(const cocos2d::Mat4& transform, uint32_t flags);
private:
    cocos2d::CustomCommand m_renderCommand;
    
    GLuint m_vao;
    GLuint m_vbo;
};

#endif /* LayerShaderStudy04_h */
