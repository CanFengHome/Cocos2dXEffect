//
//  LayerPhysicsStudyUI.cpp
//  SharpEffect
//
//  Created by ccf on 16/6/2.
//
//

#include "LayerPhysicsStudyUI.h"

#include "physics_study.h"

using namespace std;
USING_NS_CC;
using namespace ui;

#pragma mark LayerParticleStudyUI

void LayerPhysicsStudyUI::initFunNames()
{
    m_arrFunName.clear();
    m_arrFunName.push_back("00 物理碰撞检测");
    
}

void LayerPhysicsStudyUI::clickFunIndex(ssize_t selIndex)
{
    Scene* pSceneFunction = Scene::createWithPhysics();
    PhysicsWorld* pPhysicsWorld = pSceneFunction->getPhysicsWorld();
    pPhysicsWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    pPhysicsWorld->setGravity(Vec2::ZERO);
    pPhysicsWorld->setSubsteps(3);
    
    Layer* pLyrTest = nullptr;
    
    switch (selIndex)
    {
            CREATE_TEST_LAYER_FUNC(pLyrTest, LayerPhysicsStudy, 00);
            
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
    pSceneFunction->addChild(PhysicsStudyBackLayer::create());
    Director::getInstance()->replaceScene(pSceneFunction);
}



