//
//  LayerParticleStudyUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerParticleStudyUI.h"

#include "particle_study.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerParticleStudyUI

void LayerParticleStudyUI::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 Paticle plist load");
    
    
}

void LayerParticleStudyUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerParticleStudy, 00);
            
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
    pSceneFunction->addChild(ParticleStudyBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}

