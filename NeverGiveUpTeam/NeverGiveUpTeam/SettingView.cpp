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
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("SBG.png");
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
    
    CCParticleSnow* snow=CCParticleSnow::createWithTotalParticles(5000);
    snow->setSkewY(5.0f);
    this->addChild(snow);
    
        
    TapSprite* setting1=TapSprite::create("setting1.png");
    TapSprite* setting2=TapSprite::create("setting2.png");
    TapSprite* setting3=TapSprite::create("setting3.png");
    setting1->setPosition(ccp(size.width/2,size.height/3*2));
    setting2->setPosition(ccp(size.width/2,size.height/3.5));
    setting3->setPosition(ccp(size.width/2,size.height/8));
    
    setting1->setScale(0.5f);
    setting2->setScale(0.5f);
    setting3->setScale(0.5f);
    this->addChild(setting1);
    this->addChild(setting2);
    this->addChild(setting3);
    
    //OptionContentSize
    CCSize s_size=setting1->getContentSize();
    //GBM Switch
    CCMenuItemImage* item1 = CCMenuItemImage::create(
                                                         "On.png",
                                                         "On.png",
                                                         this,
                                                     menu_selector(SettingView::switchCallBack));
    item1->setPosition(ccp(size.width/4*3+10,size.height-s_size.height/8));
    item1->setScale(0.75f);
    item1->setTag(1);
    
    //SE switch
    CCMenuItemImage* item2 = CCMenuItemImage::create(
                                                     "On.png",
                                                     "On.png",
                                                     this,
                                                     menu_selector(SettingView::switchCallBack));
    item2->setPosition(ccp(size.width/4*3+10,size.height-s_size.height/8*2));
    item2->setScale(0.75f);
        item2->setTag(2);

    //VIBE Switch
    CCMenuItemImage* item3 = CCMenuItemImage::create(
                                                     "On.png",
                                                     "On.png",
                                                     this,
                                                     menu_selector(SettingView::switchCallBack));
    item3->setPosition(ccp(size.width/4*3+10,size.height-s_size.height/8*3));
    item3->setScale(0.75f);
        item3->setTag(3);

    //NETWORK Switch
    CCMenuItemImage* item4 = CCMenuItemImage::create(
                                                     "On.png",
                                                     "On.png",
                                                     this,
                                                     menu_selector(SettingView::switchCallBack));
    
    item4->setPosition(ccp(size.width/4*3+10,size.height-s_size.height/8*4));
    item4->setScale(0.75f);
        item4->setTag(4);
    
    CCMenu* menu=CCMenu::create(item1,item2,item3,item4,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu,1);
    
    
    
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

void SettingView::BGM_Off(){
    SettingView::BGM=false;
}
void SettingView::SE_Off(){
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
    user->setBoolForKey("SE_KEY",se);
    user->flush();
}

bool SettingView::getBGM(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    bool b=user->getBoolForKey("BGM_KEY",true);
    return b;
}

bool SettingView::getSE(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    bool s=user->getBoolForKey("SE_KEY",true);
    return s;
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

void SettingView::switchCallBack(CCObject* object){
    CCMenuItem* item=(CCMenuItem *)(object);
    int tag=item->getTag();//getTag
    CCSize size=CCDirector::sharedDirector()->getWinSize();//getWindowSize
    
    CCNode* node = (CCMenuItem*)getChildByTag(tag);
    //float s=node->getPositionY();
    //float p=item->getChildByTag(1)->getPositionY();
        CCLog("item_y=%f",node->getPositionY());
    
    //Off Switch
     CCSprite* off=CCSprite::create("Off.png");
     //off->setScale(0.75f);
     CCSize s_size;
     off->setScale(0.75f);

    switch(tag){
        case 1:
            s_size=item->getContentSize();
            off->setPosition(ccp(size.width/4*3+10,416.5));//size.height-node->getPositionY()));
            this->addChild(off);
            break;
    }
    
}





