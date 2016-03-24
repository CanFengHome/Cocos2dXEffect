//
//  MainScene.cpp
//  Hello
//
//  Created by ccf on 16/2/19.
//
//

#include "SceneMain.h"
#include "FunctionBackLayer.h"
#include "LayerAnimationStudyUI.h"
#include "LayerShaderStudyUI.h"
#include "LayerParticleStudyUI.h"
#include "LayerAnimationPracticeUI.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerMain

void LayerMainDataList::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 Action学习");
    m_arrFunName.push_back("01 Action实践");
    m_arrFunName.push_back("02 Shader学习");
    m_arrFunName.push_back("03 Shader实践");
    m_arrFunName.push_back("04 粒子学习");
    m_arrFunName.push_back("05 粒子实践");
}

void LayerMainDataList::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
        case 0:
            pLyrTest = LayerAnimationStudyUI::create();
            break;
        case 1:
            pLyrTest = LayerAnimationPracticeUI::create();
            break;
        case 2:
            pLyrTest = LayerShaderStudyUI::create();
            break;
        case 4:
            pLyrTest = LayerParticleStudyUI::create();
            break;
        default:
            break;
    }
    
    if (pLyrTest != nullptr)
    {
        pSceneFunction->addChild(pLyrTest);
    }
    pSceneFunction->addChild(FunctionBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}


#pragma mark SceneMain

bool SceneMain::init()
{
    LayerMainDataList* pLyrMain = LayerMainDataList::create();
    addChild(pLyrMain);
    
    return true;
}










