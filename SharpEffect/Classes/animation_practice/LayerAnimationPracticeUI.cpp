//
//  LayerAnimationPracticeUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerAnimationPracticeUI.h"
#include "animation_practice.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerAnimationStudyUI

void LayerAnimationPracticeUI::initFunNames()
{
    m_arrFunName.clear();
    
    m_arrFunName.push_back("00 气泡抖动");
    m_arrFunName.push_back("01 抖动动画");
    m_arrFunName.push_back("02 字幕动画");
    m_arrFunName.push_back("03 Bezier插值曲线动画");
}

void LayerAnimationPracticeUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationPractice, 00);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationPractice, 01);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationPractice, 02);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationPractice, 03);
            
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
    pSceneFunction->addChild(AnimationPracticeBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}
















