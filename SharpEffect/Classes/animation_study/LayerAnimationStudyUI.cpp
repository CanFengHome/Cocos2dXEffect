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
    m_arrFunName.push_back("05 Blink");
    m_arrFunName.push_back("06 Fade");
    m_arrFunName.push_back("07 Tint");
    m_arrFunName.push_back("08 Plist Animation");
    m_arrFunName.push_back("09 TargetAction");
    m_arrFunName.push_back("10 CatmullRomTo 固定张力曲线");
    m_arrFunName.push_back("11 CardinalSpline 可变张力曲线");
    
    
}

void LayerAnimationStudyUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::create();
    Layer* pLyrTest = nullptr;
    
    switch (selIndex) {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 00);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 01);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 02);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 03);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 04);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 05);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 06);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 07);
        case 8:
            pLyrTest = LayerAnimationStudy08::create();
            break;
        case 9:
            pLyrTest = LayerAnimationStudy09::create();
            break;
            
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 10);
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerAnimationStudy, 11);
            
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

























