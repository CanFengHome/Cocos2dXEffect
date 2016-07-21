//
//  LayerAnimationPractice05.h
//  SharpEffect
//
//  Created by ccf on 16/7/21.
//
//

#ifndef LayerAnimationPractice05_h
#define LayerAnimationPractice05_h

#include <vector>
using namespace std;

#include "cocos2d.h"
USING_NS_CC;

// 05 路线进度动画
class LayerAnimationPractice05 : public cocos2d::LayerColor
{
public:
    LayerAnimationPractice05()=default;
    CC_DISALLOW_COPY_AND_ASSIGN(LayerAnimationPractice05);
    CREATE_FUNC(LayerAnimationPractice05);
    virtual bool init() override;
private:
    void btnTestCallback(cocos2d::Ref* pSender);
    void constructPath();
private:
    Sprite* m_pUserSprite = nullptr;
    Sprite* m_pAcitvityLineRed = nullptr;
    Sprite* m_pActivityLineGray = nullptr;
    Sprite* m_pBgSprite = nullptr;
    float m_fActivityLineRedImgWidth = 0.0f;
    float m_fActivityLineRedImgHeight = 0.0f;
    
    vector<Vec2> m_arrLevelPos;
    Vector<PointArray*> m_arrInterpolationPath;
};


struct LevelMoveInfo
{
    Vec2 m_endPosition;
    Sprite* m_pRouteSprite;
    Sprite* m_pDispareSprite;
    Size m_RouteSpriteSize;
};


class ActionLevelMoveCurve : public CatmullRomTo
{
CC_CONSTRUCTOR_ACCESS:
    ActionLevelMoveCurve() {}
    virtual ~ActionLevelMoveCurve() {}
public:
    static ActionLevelMoveCurve* create(float duration, PointArray* points, const LevelMoveInfo& moveInfo);
    bool initWithDuration(float duration, PointArray* points, const LevelMoveInfo& moveInfo);
    virtual void updatePosition(Vec2 &newPos) override;
    virtual void stop() override;
private:
    void updateRouteSpriteRect();
    CC_DISALLOW_COPY_AND_ASSIGN(ActionLevelMoveCurve);
protected:
    LevelMoveInfo m_moveInfo;
};


#endif /* LayerAnimationPractice05_h */
