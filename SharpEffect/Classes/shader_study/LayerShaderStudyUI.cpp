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
    
    
}

void LayerShaderStudyUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerShaderStudy, 00);

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


























