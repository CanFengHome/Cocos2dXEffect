//
//  MainScene.cpp
//  Hello
//
//  Created by ccf on 16/2/19.
//
//

#include "SceneMain.h"
#include "FunctionBackLayer.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerMain

void LayerMainDataList::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 Action学习");
    m_arrFunName.push_back("00 Action模仿");
    m_arrFunName.push_back("01 Shader学习");
    m_arrFunName.push_back("01 Shader模仿");
    m_arrFunName.push_back("02 粒子学习");
    m_arrFunName.push_back("02 粒子模仿");
}

void LayerMainDataList::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
        case 0:
            
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










