//
//  LayerShaderPracticeUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerShaderPracticeUI.h"
#include "shader_practice.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerShaderPracticeUI

void LayerShaderPracticeUI::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 角色中毒");
    m_arrFunName.push_back("01 冰冻效果");
    m_arrFunName.push_back("02 灯光光晕效果 Blend使用");
    m_arrFunName.push_back("03 闪电效果");
    m_arrFunName.push_back("04 标准Shader Node中自定义渲染shade");
    
    
}

void LayerShaderPracticeUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderPractice, 00);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderPractice, 01);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderPractice, 02);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderPractice, 03);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderPractice, 04);
            

            
        case 8:
            break;
        case 9:
            break;
            
            
        default:
            break;
    }
    
    if (pLyrTest != nullptr)
    {
        pSceneFunction->addChild(pLyrTest);
    }
    pSceneFunction->addChild(ShaderPracticeBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}


























