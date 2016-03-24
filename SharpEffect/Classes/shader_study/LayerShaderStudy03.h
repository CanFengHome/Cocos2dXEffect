//
//  LayerShaderStudy03.h
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#ifndef LayerShaderStudy03_h
#define LayerShaderStudy03_h

// 03 define shader 颜色float类型
class LayerShaderStudy03 : public cocos2d::Layer
{
public:
    CREATE_FUNC(LayerShaderStudy03);
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

#endif /* LayerShaderStudy03_h */
