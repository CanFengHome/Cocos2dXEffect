//
//  LayerAnimationPractice05.cpp
//  SharpEffect
//
//  Created by ccf on 16/7/21.
//
//

#include "LayerAnimationPractice05.h"

#include "ui/CocosGUI.h"

void LayerAnimationPractice05::constructPath()
{
    m_arrLevelPos.clear();
    m_arrInterpolationPath.clear();
    
    m_arrLevelPos.push_back(Vec2(298.0f, 187.0f));
    m_arrLevelPos.push_back(Vec2(502.0f, 372.0f));
    m_arrLevelPos.push_back(Vec2(376.0f, 473.0f));
    m_arrLevelPos.push_back(Vec2(220.0f, 595.0f));
    m_arrLevelPos.push_back(Vec2(397.0f, 800.0f));
    
    PointArray* pPtArray = PointArray::create(17);
    pPtArray->addControlPoint(m_arrLevelPos[0]);
    pPtArray->addControlPoint(Vec2(326.0f, 191.0f));
    pPtArray->addControlPoint(Vec2(345.0f, 199.0f));
    pPtArray->addControlPoint(Vec2(361.0f, 206.0f));
    pPtArray->addControlPoint(Vec2(378.0f, 214.0f));
    pPtArray->addControlPoint(Vec2(394.0f, 224.0f));
    pPtArray->addControlPoint(Vec2(409.0f, 232.0f));
    pPtArray->addControlPoint(Vec2(420.0f, 241.0f));
    pPtArray->addControlPoint(Vec2(433.0f, 251.0f));
    pPtArray->addControlPoint(Vec2(444.0f, 261.0f));
    pPtArray->addControlPoint(Vec2(455.0f, 272.0f));
    pPtArray->addControlPoint(Vec2(465.0f, 283.0f));
    pPtArray->addControlPoint(Vec2(474.0f, 296.0f));
    pPtArray->addControlPoint(Vec2(482.0f, 309.0f));
    pPtArray->addControlPoint(Vec2(488.0f, 322.0f));
    pPtArray->addControlPoint(Vec2(493.0f, 336.0f));
    pPtArray->addControlPoint(m_arrLevelPos[1]);
    m_arrInterpolationPath.pushBack(pPtArray);
    
    pPtArray = PointArray::create(8);
    pPtArray->addControlPoint(m_arrLevelPos[1]);
    pPtArray->addControlPoint(Vec2(483.0f, 409.0f));
    pPtArray->addControlPoint(Vec2(471.0f, 423.0f));
    pPtArray->addControlPoint(Vec2(458.0f, 433.0f));
    pPtArray->addControlPoint(Vec2(445.0f, 443.0f));
    pPtArray->addControlPoint(Vec2(430.0f, 450.0f));
    pPtArray->addControlPoint(Vec2(417.0f, 457.0f));
    pPtArray->addControlPoint(m_arrLevelPos[2]);
    m_arrInterpolationPath.pushBack(pPtArray);
    
    pPtArray = PointArray::create(13);
    pPtArray->addControlPoint(m_arrLevelPos[2]);
    pPtArray->addControlPoint(Vec2(350.0f, 487.0f));
    pPtArray->addControlPoint(Vec2(333.0f, 497.0f));
    pPtArray->addControlPoint(Vec2(323.0f, 503.0f));
    pPtArray->addControlPoint(Vec2(310.0f, 512.0f));
    pPtArray->addControlPoint(Vec2(300.0f, 520.0f));
    pPtArray->addControlPoint(Vec2(287.0f, 530.0f));
    pPtArray->addControlPoint(Vec2(275.0f, 540.0f));
    pPtArray->addControlPoint(Vec2(265.0f, 550.0f));
    pPtArray->addControlPoint(Vec2(255.0f, 559.0f));
    pPtArray->addControlPoint(Vec2(245.0f, 569.0f));
    pPtArray->addControlPoint(Vec2(236.0f, 578.0f));
    pPtArray->addControlPoint(m_arrLevelPos[3]);
    m_arrInterpolationPath.pushBack(pPtArray);
    
    pPtArray = PointArray::create(19);
    pPtArray->addControlPoint(m_arrLevelPos[3]);
    pPtArray->addControlPoint(Vec2(215.0f, 610.0f));
    pPtArray->addControlPoint(Vec2(207.0f, 636.0f));
    pPtArray->addControlPoint(Vec2(205.0f, 651.0f));
    pPtArray->addControlPoint(Vec2(209.0f, 667.0f));
    pPtArray->addControlPoint(Vec2(214.0f, 680.0f));
    pPtArray->addControlPoint(Vec2(222.0f, 695.0f));
    pPtArray->addControlPoint(Vec2(233.0f, 707.0f));
    pPtArray->addControlPoint(Vec2(245.0f, 719.0f));
    pPtArray->addControlPoint(Vec2(255.0f, 728.0f));
    pPtArray->addControlPoint(Vec2(267.0f, 737.0f));
    pPtArray->addControlPoint(Vec2(277.0f, 744.0f));
    pPtArray->addControlPoint(Vec2(290.0f, 751.0f));
    pPtArray->addControlPoint(Vec2(305.0f, 759.0f));
    pPtArray->addControlPoint(Vec2(322.0f, 767.0f));
    pPtArray->addControlPoint(Vec2(337.0f, 774.0f));
    pPtArray->addControlPoint(Vec2(356.0f, 782.0f));
    pPtArray->addControlPoint(Vec2(377.0f, 790.0f));
    pPtArray->addControlPoint(m_arrLevelPos[4]);
    m_arrInterpolationPath.pushBack(pPtArray);
    
}

bool LayerAnimationPractice05::init()
{
    if (!LayerColor::init())
    {
        return false;
    }
    
    constructPath();
    
    Size winSize = Director::getInstance()->getWinSize();
    
    m_pBgSprite = Sprite::create("res/ui/route/summer_activity_play_bg.png");
    addChild(m_pBgSprite);
    m_pBgSprite->setPosition(winSize*0.5f);
    
    m_pActivityLineGray = Sprite::create("res/ui/route/summer_activity_play_line_gray.png");
    m_pBgSprite->addChild(m_pActivityLineGray);
    m_pActivityLineGray->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    m_pActivityLineGray->setPosition(0.0f, m_pActivityLineGray->getContentSize().height);
    
    m_pAcitvityLineRed = Sprite::create("res/ui/route/summer_activity_play_line_red.png");
    m_pBgSprite->addChild(m_pAcitvityLineRed);
    m_pAcitvityLineRed->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    // 测试使用
    m_pAcitvityLineRed->setPositionX(50.0f);
    m_fActivityLineRedImgWidth = m_pAcitvityLineRed->getContentSize().width;
    m_fActivityLineRedImgHeight = m_pAcitvityLineRed->getContentSize().height;
    m_pAcitvityLineRed->setTextureRect(Rect::ZERO);
    //    m_pAcitvityLineRed->setVisible(false);
    
    for (const Vec2& pos : m_arrLevelPos)
    {
        Sprite* pLevelSprite = Sprite::create("res/ui/route/base_girl.png");
        pLevelSprite->setPosition(pos);
        pLevelSprite->setScale(0.85f);
        m_pBgSprite->addChild(pLevelSprite);
    }
    
    m_pUserSprite = Sprite::create("res/ui/route/user_own_board.png");
    m_pUserSprite->setPosition(m_arrLevelPos[0]);
    m_pUserSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    m_pBgSprite->addChild(m_pUserSprite);
    
    ui::Button* pBtnTest = ui::Button::create();
    pBtnTest->setTitleFontSize(40);
    pBtnTest->setTitleColor(Color3B::WHITE);
    pBtnTest->setTitleText("Test");
    pBtnTest->addClickEventListener(CC_CALLBACK_1(LayerAnimationPractice05::btnTestCallback, this));
    m_pBgSprite->addChild(pBtnTest);
    pBtnTest->setPosition(Vec2(winSize.width-pBtnTest->getContentSize().width,
                               pBtnTest->getContentSize().height));
    pBtnTest->setPressedActionEnabled(true);
    
    return true;
}

void LayerAnimationPractice05::btnTestCallback(Ref* pSender)
{
    static int curIndex = 0;
    
    m_pUserSprite->setPosition(m_arrLevelPos[curIndex]);
    m_pAcitvityLineRed->setTextureRect(Rect::ZERO);
    
    PointArray* pPtArray = m_arrInterpolationPath.at(curIndex);
    
    //    DrawNode* pDrawNode = DrawNode::create();
    //    m_pBgSprite->addChild(pDrawNode);
    //    pDrawNode->drawCatmullRom(pPtArray, 100, Color4F::GREEN);
    
    ActionLevelMoveCurve* pActionLeveMove = ActionLevelMoveCurve::create(1.0f, pPtArray,
                                                                         {   .m_endPosition=Vec2(m_arrLevelPos[curIndex+1]),
                                                                             .m_pRouteSprite = m_pAcitvityLineRed,
                                                                             .m_pDispareSprite = m_pActivityLineGray,
                                                                             .m_RouteSpriteSize = Size(m_fActivityLineRedImgWidth, m_fActivityLineRedImgHeight)});
    m_pUserSprite->runAction(pActionLeveMove);
    
    curIndex = (curIndex+1)%(int)(m_arrLevelPos.size()-1);
}


ActionLevelMoveCurve* ActionLevelMoveCurve::create(float duration, PointArray* points, const LevelMoveInfo& moveInfo)
{
    ActionLevelMoveCurve* pRet = new(std::nothrow) ActionLevelMoveCurve();
    if (pRet && pRet->initWithDuration(duration, points, moveInfo))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool ActionLevelMoveCurve::initWithDuration(float duration, PointArray* points, const LevelMoveInfo& moveInfo)
{
    bool ret = false;
    
    if (CatmullRomTo::initWithDuration(duration, points))
    {
        m_moveInfo = moveInfo;
        ret = true;
    }
    
    return ret;
}

void ActionLevelMoveCurve::updatePosition(Vec2 &newPos)
{
    CatmullRomTo::updatePosition(newPos);
    
    updateRouteSpriteRect();
}

void ActionLevelMoveCurve::stop()
{
    CatmullRomTo::stop();
    
    if (_target)
    {
        _target->setPosition(m_moveInfo.m_endPosition);
        updateRouteSpriteRect();
    }
}

void ActionLevelMoveCurve::updateRouteSpriteRect()
{
    if (_target)
    {
        if (m_moveInfo.m_pRouteSprite)
        {
            Size textureSize = m_moveInfo.m_RouteSpriteSize;
            m_moveInfo.m_pRouteSprite->setTextureRect(Rect(0.0f,
                                                           textureSize.height - _target->getPositionY(),
                                                           textureSize.width,
                                                           _target->getPositionY()));
            m_moveInfo.m_pDispareSprite->setTextureRect(Rect(0.0f, 0.0f, textureSize.width, textureSize.height - _target->getPositionY()));
        }
    }
}




































