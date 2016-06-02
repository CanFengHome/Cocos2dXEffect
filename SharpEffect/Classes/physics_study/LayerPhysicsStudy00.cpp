//
//  LayerPhysicsStudy00.cpp
//  SharpEffect
//
//  Created by ccf on 16/6/2.
//
//

#include "LayerPhysicsStudy00.h"

USING_NS_CC;
bool LayerPhysicsStudy00::init()
{
    if (!LayerColor::initWithColor(Color4B::GRAY))
    {
        return false;
    }
    
    initPhysicsBox();
    initBallSprite();
    
    EventListenerPhysicsContact* pContactListener = EventListenerPhysicsContact::create();
    pContactListener->onContactBegin = CC_CALLBACK_1(LayerPhysicsStudy00::contactCallback, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(pContactListener, this);
    
    Size winSize = Director::getInstance()->getWinSize();
    
    return true;
}

bool LayerPhysicsStudy00::contactCallback(PhysicsContact& contact)
{
    Sprite* pSpriteA = dynamic_cast<Sprite*>(contact.getShapeA()->getBody()->getNode());
    Sprite* pSpriteB = dynamic_cast<Sprite*>(contact.getShapeB()->getBody()->getNode());
    
    if ((pSpriteA->getTag() == 100 && pSpriteB->getTag()==101) ||
        (pSpriteA->getTag() == 101 && pSpriteB->getTag()==100))
    {
        pSpriteA->removeFromParent();
        pSpriteB->removeFromParent();
    }
    
    return true;
}

void LayerPhysicsStudy00::initPhysicsBox()
{
    Size winSize = Director::getInstance()->getWinSize();
    
    PhysicsBody* pBoxBody = PhysicsBody::createEdgeBox(winSize, PhysicsMaterial(0.0f, 1.0f, 0.0f), 3);
    Node* pNode = Node::create();
    pNode->setPhysicsBody(pBoxBody);
    pNode->setContentSize(winSize);
    pNode->setPosition(winSize*0.5f);
    addChild(pNode);
}

void LayerPhysicsStudy00::initBallSprite()
{
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* pSprite1 = Sprite::create("res/physics_study/ball.png");
    addChild(pSprite1);
    PhysicsBody* pSprite1Body = PhysicsBody::createCircle(pSprite1->getContentSize().width*0.5f,
                                                          PhysicsMaterial(0.1f, 1.0f, 0.0f));
    pSprite1->setPhysicsBody(pSprite1Body);
    pSprite1->setPosition(winSize.width*0.5f - 200.0f, winSize.height*0.8f);
    pSprite1->setTag(100);
    
    Sprite* pSprite2 = Sprite::create("res/physics_study/ball.png");
    addChild(pSprite2);
    PhysicsBody* pSprite2Body = PhysicsBody::createCircle(pSprite2->getContentSize().width*0.5f,
                                                          PhysicsMaterial(0.1f, 1.0f, 0.0f));
    pSprite2->setPhysicsBody(pSprite2Body);
    pSprite2->setPosition(winSize.width*0.5f + 200.0f, winSize.height*0.8f);
    pSprite2->setTag(101);
    
    //    pSprite1Body->applyImpulse(Vec2(5000.0f, 5000.0f));
    //    pSprite2Body->applyImpulse(Vec2(-5000.0f, -5000.0f));
    
    pSprite1Body->applyImpulse(Vec2(5000.0f, 0.0f));
    pSprite2Body->applyImpulse(Vec2(-5000.0f, 0.0f));
    
    //    // 碰撞但是不会触发碰撞事件
    //    pSprite1Body->setCategoryBitmask(0x1); // 0001
    //    pSprite1Body->setCollisionBitmask(0x1);// 0001
    //    pSprite1Body->setContactTestBitmask(0x1);// 0001
    //
    //    pSprite2Body->setCategoryBitmask(0x3);// 0011
    //    pSprite2Body->setCollisionBitmask(0x3);// 0011
    //    pSprite2Body->setContactTestBitmask(0x2);// 0010
    
    // 碰撞但是 会触发碰撞事件
    pSprite1Body->setCategoryBitmask(0x1); // 0001
    pSprite1Body->setCollisionBitmask(0x1);// 0001
    pSprite1Body->setContactTestBitmask(0x1);// 0001
    
    pSprite2Body->setCategoryBitmask(0x3);// 0011
    pSprite2Body->setCollisionBitmask(0x3);// 0011
    pSprite2Body->setContactTestBitmask(0x3);// 0011
    
    //    // 不会发生碰撞 所以也不会触发碰撞事件
    //    pSprite1Body->setCategoryBitmask(0x1); // 0001
    //    pSprite1Body->setCollisionBitmask(0x1);// 0001
    //    pSprite1Body->setContactTestBitmask(0x1);// 0001
    //
    //    pSprite2Body->setCategoryBitmask(0x2);// 0010
    //    pSprite2Body->setCollisionBitmask(0x2);// 0010
    //    pSprite2Body->setContactTestBitmask(0x2);// 0010
}



















