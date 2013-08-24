//
//

//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#include "GV.h"



CCScene* TopView::scene()
{
    CCScene *scene = CCScene::create();
    TopView *layer = TopView::create();
    scene->addChild(layer);
    return scene;
}

bool TopView::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //    CCSize backSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("Background.jpeg");
    back->setPosition(ccp(100.f,100.f));
    back->setTag(1);
    this->addChild(back);
    CCLog("Now is TopScene");
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(TopView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    CCLabelTTF* label=CCLabelTTF::create("Top","arial",48);
    label->setPosition(ccp(100.f,100.f));
    this->addChild(label);
    
    
    
    return true;
}

void TopView::next(){
    CCScene* next=CollectView::scene();
    CCDirector::sharedDirector()->replaceScene(next);
}

void TopView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
