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
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
    

}

void SettingView::BGM_Mute(){
    SettingView::BGM=false;
}
void SettingView::SE_Mute(){
    SettingView::SE=false;
}

void SettingView::BGM_On(){
    SettingView::BGM=true;
}
void SettingView::SE_On(){
    SettingView::SE=true;
}

void SettingView::setSetting(bool bgm, bool se){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("BGM_KEY",bgm);
    user->setBoolForKey("SE_KEY",bgm);
    user->flush();
    
}

void SettingView::Exit(){
    CCDirector::sharedDirector()->end();
}

void SettingView::GoToTitle(){
    CCScene* next=HelloWorld::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionCrossFade::create(duration,next);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}


void SettingView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
