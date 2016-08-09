//
//  LayerCommonCode00.cpp
//  SharpEffect
//
//  Created by ccf on 16/8/9.
//
//

#include "LayerCommonCode00.h"

#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;

#include "EncryptionHandler.h"

USING_NS_CC;
bool LayerCommonCode00::init()
{
    if (!LayerColor::initWithColor(Color4B::GRAY))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    string strMsg1 = "中文gold:1000 life:100";
    string strMsg1Encry = EncryptionHandler::encrypt(strMsg1);
    string strMsg1Decrypt = EncryptionHandler::decrypt(strMsg1Encry);
    
    string strResult;
    strResult.append("原字符串：");
    strResult.append(strMsg1);
    CCLOG("加密：%s", strMsg1Encry.c_str());
//    strResult.append("\n加密：");
//    strResult.append(strMsg1Encry);
    strResult.append("\n解密：");
    strResult.append(strMsg1Decrypt);

    Label* pLblDisplayInfo = Label::create();
    addChild(pLblDisplayInfo);
    pLblDisplayInfo->setPosition(winSize*0.5f);
    pLblDisplayInfo->setString(strResult);
    pLblDisplayInfo->setSystemFontSize(24.0f);
    pLblDisplayInfo->setColor(Color3B::BLACK);
    
    return true;
}



























