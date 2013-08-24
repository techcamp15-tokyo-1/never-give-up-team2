//
//  ShopView.cpp
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#include "ShopView.h"
#include "GV.h"

ShopView::ShopView(){
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("shop.mp3");
}
CCScene* ShopView::scene()
{
    CCScene *scene = CCScene::create();
    ShopView *layer = ShopView::create();
    scene->addChild(layer);
    return scene;
}

bool ShopView::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("top.mp3",true);

    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("Background.jpeg");
    back->setPosition(ccp(100.f,100.f));
    back->setTag(1);
    this->addChild(back);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(ShopView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
        
    
    
    CCLabelTTF* label1=CCLabelTTF::create("Shop","arial",20);
    label1->setPosition(ccp(size.width/4,size.height/4*3));
    this->addChild(label1);
    
                                                           
    return true;
}

void ShopView::next(){
    CCScene* next=SettingView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}

void ShopView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
