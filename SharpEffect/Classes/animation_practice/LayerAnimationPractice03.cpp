//
//  LayerAnimationPractice03.cpp
//  SharpEffect
//
//  Created by ccf on 16/7/7.
//
//

#include "LayerAnimationPractice03.h"

#include <vector>
using namespace std;

USING_NS_CC;

bool LayerAnimationPractice03::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    m_pTargetSprite = Sprite::create("res/ui/jar.png");
    addChild(m_pTargetSprite);
    m_pTargetSprite->setRotation(-90.0f);
    m_pTargetSprite->setPosition(winSize.width-m_pTargetSprite->getContentSize().width*0.5f-50,
                                 winSize.height-m_pTargetSprite->getContentSize().height*0.5f-50);
    
    m_pItemSprite = Sprite::create("res/ui/coin.png");
    m_pItemSprite->setPosition(300.0f,300.0f);
    addChild(m_pItemSprite);
    
//    float itemWidth = pItemSprite->getContentSize().width;
//    float itemHeight = pItemSprite->getContentSize().height;
//    float randomX = RandomHelper::random_real(itemWidth,winSize.width-itemWidth);
//    float randomY = RandomHelper::random_real(300.0f, 300.0f+itemHeight*0.5f*9);
//    pItemSprite->setPosition(randomX,randomY);
    
    // create collect bezier
    Vec2 bottleneck = Vec2(m_pTargetSprite->getPositionX()-m_pTargetSprite->getContentSize().width*0.5f,m_pTargetSprite->getPositionY());
    m_bezierConfig.endPosition = bottleneck;
    m_bezierConfig.controlPoint_1 = m_pItemSprite->getPosition()+Vec2(-200.0f,0.0f);
    m_bezierConfig.controlPoint_2 = bottleneck+Vec2(-50.0f,-50.0f);
//    BezierTo* pBezier = BezierTo::create(3.0f, m_bezierConfig);
    
    m_startPosition = m_pItemSprite->getPosition();
//    m_pItemSprite->runAction(Sequence::create(pBezier, MoveTo::create(0.3f, m_pTargetSprite->getPosition()), nullptr));
    
    DrawNode* pDrawNode = DrawNode::create();
    addChild(pDrawNode);
    pDrawNode->drawCubicBezier(m_pItemSprite->getPosition(), m_bezierConfig.controlPoint_1, m_bezierConfig.controlPoint_2, bottleneck, 100, Color4F::BLUE);
    
//    createPointSprite(m_bezierConfig.endPosition);
//    createPointSprite(m_bezierConfig.controlPoint_1);
//    createPointSprite(m_bezierConfig.controlPoint_2);
//    createPointSprite(pItemSprite->getPosition());
    
    calBeizerPoints();
    
    return true;
}

void LayerAnimationPractice03::createPointSprite(cocos2d::Vec2 position)
{
    Sprite* pSprite = Sprite::create();
    pSprite->setTextureRect(Rect(0,0,10,10));
    pSprite->setPosition(position);
    pSprite->setColor(Color3B::RED);
    addChild(pSprite);
}

static inline float g_bezierat(float a, float b, float c, float d, float t)
{
    return (powf(1-t,3) * a +
            3*t*(powf(1-t,2))*b +
            3*powf(t,2)*(1-t)*c +
            powf(t,3)*d );
}

static const int splite_count = 5;

void LayerAnimationPractice03::calBeizerPoints()
{
    ccBezierConfig bezierConfig = m_bezierConfig;
    bezierConfig.controlPoint_1 = bezierConfig.controlPoint_1 - m_startPosition;
    bezierConfig.controlPoint_2 = bezierConfig.controlPoint_2 - m_startPosition;
    bezierConfig.endPosition = bezierConfig.endPosition - m_startPosition;
    
    float xa = 0;
    float xb = bezierConfig.controlPoint_1.x;
    float xc = bezierConfig.controlPoint_2.x;
    float xd = bezierConfig.endPosition.x;
    
    float ya = 0;
    float yb = bezierConfig.controlPoint_1.y;
    float yc = bezierConfig.controlPoint_2.y;
    float yd = bezierConfig.endPosition.y;
    
    float timeStep = 1.0f/splite_count;
    float currTime = timeStep;
    vector<Vec2> arrSplitePt;
    arrSplitePt.push_back(m_startPosition);
    for (int i=0; i<splite_count; ++i)
    {
        float x = g_bezierat(xa, xb, xc, xd, currTime);
        float y = g_bezierat(ya, yb, yc, yd, currTime);
        
        arrSplitePt.push_back(m_startPosition + Vec2(x, y));
        currTime += timeStep;
    }
    
    // debug display
    for (const Vec2& item : arrSplitePt)
    {
        createPointSprite(item);
    }

    const float minOffsetDis = 15.0f;
    const float maxOffsetDis = 50.0f;
    float offsetStep = (maxOffsetDis-minOffsetDis)/(splite_count+1);
    float curOffsetDis = maxOffsetDis;
    
    PointArray* pPtArray = PointArray::create(arrSplitePt.size()+1);
    pPtArray->addControlPoint(m_startPosition);

    bool isLeft = true;
    for (int i=0; i<arrSplitePt.size()-1; ++i)
    {
        Vec2 currPt = arrSplitePt[i];
        Vec2 nextPt = arrSplitePt[i+1];
        
        Vec3 pathDir(nextPt.x-currPt.x, nextPt.y-currPt.y, 0.0f);
        Vec3 auxiliaryDir = isLeft?Vec3(0.0f, 0.0f, 1.0f) : Vec3(0.0f, 0.0f, -1.0f);
        auxiliaryDir.cross(pathDir);
        
        Vec2 offsetDir(auxiliaryDir.x, auxiliaryDir.y);
        offsetDir.normalize();
        offsetDir.scale(curOffsetDis);
        
        pPtArray->addControlPoint(arrSplitePt[i+1] + offsetDir);
        createPointSprite(arrSplitePt[i+1] + offsetDir);
        
        isLeft = !isLeft;
        curOffsetDis -= offsetStep;
        curOffsetDis = MAX(curOffsetDis, minOffsetDis);
    }
    
    DrawNode* pDrawNode = DrawNode::create();
    addChild(pDrawNode);
    pDrawNode->drawCatmullRom(pPtArray, 100, Color4F::GREEN);
//    pDrawNode->setVisible(false);
    
    m_pItemSprite->runAction(Sequence::create(CatmullRomTo::create(5.0f, pPtArray), MoveTo::create(0.3f, m_pTargetSprite->getPosition()), nullptr));
    
}





















