//
//  StartView.cpp
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#include "GV.h"


CCScene* StartView::scene()
{
    CCScene *scene = CCScene::create();
    StartView *layer = StartView::create();
    scene->addChild(layer);
    return scene;
}

bool StartView::init()
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
                                                          menu_selector(StartView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    

    CCLabelTTF* label1=CCLabelTTF::create("森へ行く","arial",20);
    label1->setPosition(ccp(size.width/4,size.height/4*3));
    this->addChild(label1);
    CCLabelTTF* label2=CCLabelTTF::create("ショップへ行く","arial",20);
    label2->setPosition(ccp(size.width/4*3,size.height/4*3));
    this->addChild(label2);
    CCLabelTTF* label3=CCLabelTTF::create("倉庫","arial",20);
    label3->setPosition(ccp(size.width/4,size.height/3));
    this->addChild(label3);
    CCLabelTTF* label4=CCLabelTTF::create("図鑑","arial",20);
    label4->setPosition(ccp(size.width/4*3,size.height/3));
    this->addChild(label4);


    
    
    return true;
}

void StartView::next(){
    CCScene* next=TopView::scene();
    CCDirector::sharedDirector()->replaceScene(next);
}

void StartView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
