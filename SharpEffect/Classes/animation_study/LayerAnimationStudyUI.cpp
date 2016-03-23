//
//  LayerAnimationStudyUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#include "LayerAnimationStudyUI.h"
#include "animation_study.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerAnimationStudyUI

void LayerAnimationStudyUI::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 MoveTo3D");
    m_arrFunName.push_back("01 SkewTo");
    m_arrFunName.push_back("02 RotateTo");
    m_arrFunName.push_back("03 Jump");
    m_arrFunName.push_back("04 Bezier");
    
    
}

void LayerAnimationStudyUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, 00);
            CREATE_TEST_LAYER_FUNC(pLyrTest, 01);
            CREATE_TEST_LAYER_FUNC(pLyrTest, 02);
            CREATE_TEST_LAYER_FUNC(pLyrTest, 03);
            CREATE_TEST_LAYER_FUNC(pLyrTest, 04);
        default:
            break;
    }
    
    if (pLyrTest != nullptr)
    {
        pSceneFunction->addChild(pLyrTest);
    }
    pSceneFunction->addChild(AnimationStudyBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}

























