//
//  SettingView.cpp
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#include "SettingView.h"
#include "GV.h"

CCScene* SettingView::scene()
{
    CCScene *scene = CCScene::create();
    SettingView *layer = SettingView::create();
    scene->addChild(layer);
    return scene;
}

bool SettingView::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("Background.jpeg");
    back->setPosition(ccp(100.f,100.f));
    back->setTag(1);
    this->addChild(back);
    CCLog("Now is SecondScene");
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(SettingView::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    CCLabelTTF* label1=CCLabelTTF::create("Setting","arial",20);
    label1->setPosition(ccp(size.width/4,size.height/4*3));
    this->addChild(label1);

       
    
    
    return true;
}

void SettingView::next(){
    CCScene* next=TopView::scene();
    CCDirector::sharedDirector()->replaceScene(next);
}

void SettingView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
