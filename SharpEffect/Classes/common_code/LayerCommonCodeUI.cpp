//
//  LayerCommonCodeUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/8/9.
//
//

#include "LayerCommonCodeUI.h"

#include "common_code.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerCommonCodeUI

void LayerCommonCodeUI::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 Des加解密");

    
}

void LayerCommonCodeUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerCommonCode, 00);
            
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
    pSceneFunction->addChild(CommonCodeBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}





