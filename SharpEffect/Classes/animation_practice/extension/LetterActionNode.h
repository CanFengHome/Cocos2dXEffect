//
//  LetterActionNode.h
//  Practice
//
//  Created by mfp on 16/5/12.
//
//

#ifndef LetterActionNode_h
#define LetterActionNode_h

#include <string>
#include <vector>
#include "cocos2d.h"

class LetterActionNode : public cocos2d::Node
{
public:
    static LetterActionNode* createWithString(const std::string& strLetters);
    bool initWithString(const std::string& strLetters);
    
    void startLetterAction();
    
private:
    void bottomToTopActionFinish();
    
private:
    std::vector<cocos2d::Sprite*> m_arrLetterSprites;
    std::vector<cocos2d::Sprite*> m_arrLetterBottomMaskSprites;
    std::string m_strLetters;
    
    float m_fLetterTargetScale = 1.0f;
    float m_fMaxContetHeight = 0.0f;
    float m_fContentWidth = 0.0f;
};

#endif /* LetterActionNode_h */
