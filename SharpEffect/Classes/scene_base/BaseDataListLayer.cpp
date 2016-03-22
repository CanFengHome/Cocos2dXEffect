//
//  BaseDataListLayer.cpp
//  SharpEffect
//
//  Created by ccf on 16/3/22.
//
//

#include "BaseDataListLayer.h"

using namespace std;
USING_NS_CC;
using namespace ui;

bool BaseDataListLayer::init()
{
    if (!LayerColor::initWithColor(Color4B::WHITE)) {
        return false;
    }
    return true;
}

void BaseDataListLayer::onEnter()
{
    LayerColor::onEnter();
    
    this->initFunNames();
    this->initListView();
}

void BaseDataListLayer::initListView()
{
    Size winSize = Director::getInstance()->getWinSize();
    float contentWidth = winSize.width-20.0f;
    if (m_pListView == nullptr)
    {
        m_pListView = ListView::create();
        m_pListView->setDirection(ui::ScrollView::Direction::VERTICAL);
        m_pListView->setBounceEnabled(true);
        m_pListView->setBackGroundImage("res/ui/green_edit.png");
        m_pListView->setBackGroundImageScale9Enabled(true);
        m_pListView->setContentSize(Size(contentWidth, winSize.height-100.0f));
        
        auto callBack = [this](Ref *pSender, cocos2d::ui::ListView::EventType type){
            switch (type)
            {
                case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START:
                {
                    // ListView* listView = static_cast<ListView*>(pSender);
                    // CC_UNUSED_PARAM(listView);
                    // CCLOG("select child start index = %ld", listView->getCurSelectedIndex());
                    break;
                }
                case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END:
                {
                    ListView* listView = static_cast<ListView*>(pSender);
                    // CC_UNUSED_PARAM(listView);
                    // CCLOG("select child end index = %ld", listView->getCurSelectedIndex());
                    
                    // this->handlerFunction(listView->getCurSelectedIndex());
                    this->clickFunIndex(m_arrFunName.size()-1-listView->getCurSelectedIndex());
                    break;
                }
                default:
                    break;
            }
        };
        
        m_pListView->addEventListener((ListView::ccListViewCallback)callBack);
        m_pListView->setScrollBarPositionFromCorner(Vec2(7, 7));
        addChild(m_pListView);
        m_pListView->setPosition(Vec2(winSize*0.5f-m_pListView->getContentSize()*0.5f));
        
        // create model
        Button* default_button = Button::create();
        default_button->setName("btnClickMe");
        default_button->setTitleFontSize(28.0f);
        default_button->setTitleColor(Color3B::BLACK);
        
        Layout* default_item = Layout::create();
        default_item->setTouchEnabled(true);
        default_item->setContentSize(Size(contentWidth, 40.0f));
        default_button->setPosition(Vec2(default_item->getContentSize().width / 2.0f,
                                         default_item->getContentSize().height / 2.0f));
        default_item->addChild(default_button);
        default_item->setLayoutType(cocos2d::ui::Layout::Type::HORIZONTAL);
        
        // set model
        m_pListView->setItemModel(default_item);
    }
    
    m_pListView->removeAllChildren();
    // add default item
    ssize_t count = m_arrFunName.size();
    for (int i = 0; i < count; ++i)
    {
        m_pListView->pushBackDefaultItem();
    }
    
    int index = 0;
    for (vector<std::string>::reverse_iterator pItem = m_arrFunName.rbegin(); pItem != m_arrFunName.rend(); ++pItem)
    {
        Widget* pLayout = m_pListView->getItem(index);
        Button* button = static_cast<Button*>(pLayout->getChildByName("btnClickMe"));
        button->setTitleText(*pItem);
        
        ++index;
    }
}

#pragma mark LayerMain





















