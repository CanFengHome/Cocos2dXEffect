//
//  LayerExperimentUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/4/16.
//
//

#include "LayerExperimentUI.h"

#include "experiment.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerParticleStudyUI

void LayerExperimentUI::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 ClippingNode");
    m_arrFunName.push_back("01 多个RenderTexture模拟ClippingNode");
    m_arrFunName.push_back("02 一个RenderTexture模拟ClippingNode");
    m_arrFunName.push_back("03 一个RenderTexture Sprite批处理");
    
    
    
    
    
}

void LayerExperimentUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerExperiment, 00);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerExperiment, 01);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerExperiment, 02);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerExperiment, 03);
            
            
            
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
    pSceneFunction->addChild(ExperimentBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}
