//
//  LayerParticleStudy00.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/24.
//
//

#include "LayerParticleStudy00.h"

USING_NS_CC;
bool LayerParticleStudy00::init()
{
    if (!LayerColor::initWithColor(Color4B::BLACK))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    std::string resFile = "res/particle/flower.plist";
    auto emitter1 = ParticleSystemQuad::create(resFile);
    //    emitter1->setStartColor(Color4F(1,0,0,1));
    emitter1->setPosition(Vec2( winSize.width*0.5f, winSize.height*0.5f));
    addChild(emitter1);
    
    return true;
}
