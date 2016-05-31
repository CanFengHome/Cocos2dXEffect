//
//  LayerJellyStudyUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/5/30.
//
//

#include "LayerJellyStudyUI.h"

#include "jelly_study.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerParticleStudyUI

void LayerJellyStudyUI::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 SimpleButton");
    m_arrFunName.push_back("01 Swing");
    
    
}

void LayerJellyStudyUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerJellyStudy, 00);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerJellyStudy, 01);
            
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
    pSceneFunction->addChild(JellyStudyBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}




























