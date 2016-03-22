//
//  FunctionBackLayer.cpp
//  SharpEffect
//
//  Created by mfp on 16/3/22.
//
//

#include "FunctionBackLayer.h"

#include "SceneMain.h"
USING_NS_CC;
void FunctionBackLayer::gotoNextScene()
{
    Director::getInstance()->replaceScene(SceneMain::create());
}