//
//  LayerShaderStudyUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerShaderStudyUI.h"
#include "shader_study.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerAnimationStudyUI

void LayerShaderStudyUI::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 shader first triangle");
    m_arrFunName.push_back("01 shader define");
    m_arrFunName.push_back("02 shader VAO/VBO");
    m_arrFunName.push_back("03 define shader 颜色float类型");
    m_arrFunName.push_back("04 define shader 颜色Byte类型");
    m_arrFunName.push_back("05 shader uniform");
    m_arrFunName.push_back("06 shader quad");
    m_arrFunName.push_back("07 shader quad vbo index");

    
}

void LayerShaderStudyUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 00);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 01);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 02);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 03);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 04);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 05);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 06);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 07);
            


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
    pSceneFunction->addChild(ShaderStudyBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}


























