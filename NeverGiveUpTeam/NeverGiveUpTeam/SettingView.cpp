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
    //タッチ許可とタッチモードの設定
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);
    //画面サイズの取得
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    //バックグラウンド画像の設定
    CCSprite* back=CCSprite::create("SBG.png");
    back->setPosition(ccp(size.width/2,size.height/2));
    back->setTag(1);
    this->addChild(back);
    
    //メニューアイテムの設定
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(SettingView::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 25, 25) );
    pCloseItem->setScale(2.0);
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    //雪のパーティクル処理
    CCParticleSnow* snow=CCParticleSnow::createWithTotalParticles(3000);
    snow->setSkewY(5.0f);
    this->addChild(snow);
    
    //セッティング画面上部の設定
    TapSprite* setting1=TapSprite::create("setting1.png");
    setting1->setPosition(ccp(size.width/2,size.height/3*2));
    this->addChild(setting1);
    //おしらせの設定
    CCMenuItemImage* news = CCMenuItemImage::create(
                                    "setting2.png",
                                    "setting2.png",
                                    this,
                                    menu_selector(SettingView::News));
    news->setPosition(ccp(size.width/2,size.height/8));
    news->setTag(9);
    
        //タイトルに戻る　の設定
    CCMenuItemImage* title = CCMenuItemImage::create(
                                                    "setting3.png",
                                                    "setting3.png",
                                                    this,
                                                     menu_selector(SettingView::GoToTitle));
    title->setPosition(ccp(size.width/2,size.height/3.5));
    title->setTag(10);

    
    //OptionContentSize
    CCSize s_size=setting1->getContentSize();
    //GBM Switch
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    
    CCMenuItemImage *item1,*item2,*item3,*item4;
    
    if(user->getBoolForKey("BGM_KEY")){
     item1 = CCMenuItemImage::create(
                                                         "On.png",
                                                         "On.png",
                                                         this,
                                                     menu_selector(SettingView::switchCallBack));
    item1->setPosition(ccp(size.width/4*3+10,size.height/8*7-20));
       item1->setTag(1);
    }else{
         item1 = CCMenuItemImage::create(
                                                         "Off.png",
                                                         "Off.png",
                                                         this,
                                                         menu_selector(SettingView::switchCallBack));
        item1->setPosition(ccp(size.width/4*3+10,size.height/8*7-20));
        item1->setTag(5);

    }
    
    
    
    //SE switch
    if(user->getBoolForKey("SE_KEY")){
        item2=CCMenuItemImage::create(
                                                     "On.png",
                                                     "On.png",
                                                     this,
                                                     menu_selector(SettingView::switchCallBack));
    item2->setPosition(ccp(size.width/4*3+10,size.height/8*6-20));
        item2->setTag(2);
        
    }else{
         item2 = CCMenuItemImage::create(
                                                         "Off.png",
                                                         "Off.png",
                                                         this,
                                                         menu_selector(SettingView::switchCallBack));
        item2->setPosition(ccp(size.width/4*3+10,size.height/8*6-20));
        item2->setTag(6);
     
    }

    //VIBE Switch
    if(user->getBoolForKey("VIBE_KEY")){
     item3 = CCMenuItemImage::create(
                                                     "On.png",
                                                     "On.png",
                                                     this,
                                                     menu_selector(SettingView::switchCallBack));
    item3->setPosition(ccp(size.width/4*3+10,size.height/8*5-20));
        item3->setTag(3);
    }else{
        item3 = CCMenuItemImage::create(
                                                         "Off.png",
                                                         "Off.png",
                                                         this,
                                                         menu_selector(SettingView::switchCallBack));
        item3->setPosition(ccp(size.width/4*3+10,size.height/8*5-20));
        item3->setTag(7);
    }

    //NETWORK Switch
    if(user->getBoolForKey("NET_KEY")){
     item4 = CCMenuItemImage::create(
                                                     "On.png",
                                                     "On.png",
                                                     this,
                                                     menu_selector(SettingView::switchCallBack));
    
    item4->setPosition(ccp(size.width/4*3+10,size.height/8*4-20));
        item4->setTag(4);
    }else{
         item4 = CCMenuItemImage::create(
                                                         "Off.png",
                                                         "Off.png",
                                                         this,
                                                         menu_selector(SettingView::switchCallBack));
        item4->setPosition(ccp(size.width/4*3+10,size.height/8*4-20));
        item4->setTag(8);
    }
    
    CCMenu* menu=CCMenu::create(item1,item2,item3,item4,NULL);
    menu->setPosition(CCPointZero);
    
    CCMenu* menu2=CCMenu::create(news,title,NULL);
    menu2->setPosition(CCPointZero);
    this->addChild(menu,1);
    this->addChild(menu2,1);
    
    
    
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
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("BGM_KEY",false);
    user->flush();

}
void SettingView::SE_Off(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("SE_KEY",false);
    user->flush();
}

void SettingView::BGM_On(){
    SettingView::BGM=true;
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("BGM_KEY",true);
    user->flush();
}
void SettingView::SE_On(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("SE_KEY",true);
    user->flush();

}


void SettingView::VIBE_On(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("VIBE_KEY",true);
    user->flush();

}
void SettingView::VIBE_Off(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("VIBE_KEY",false);
    user->flush();
}
void SettingView::NET_On(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("NET_KEY",true);
    user->flush();
    
}
void SettingView::NET_Off(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setBoolForKey("NET_KEY",false);
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
void SettingView::News(){
    CCMessageBox("Version1.0 リリースしました","バージョン" );
    CCLog("Version1.0 リリースしました");
}

void SettingView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void SettingView::switchCallBack(CCMenuItemImage* object){
    int tag=object->getTag();
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    //Off Switch
    CCMenuItemImage* off = CCMenuItemImage::create(
                                                     "Off.png",
                                                     "Off.png",
                                                     this,
                                                     menu_selector(SettingView::switchCallBack));
   
    //On Switch
    CCMenuItemImage* on = CCMenuItemImage::create(
                                                   "On.png",
                                                   "On.png",
                                                   this,
                                                   menu_selector(SettingView::switchCallBack));
 

     switch(tag){
        case 1:
            CCLog("tag(1)Ok");

             off->setPosition(ccp(size.width/4*3+10,object->getPositionY()));
             off->setTag(5);
             BGM_Off();
             
            break;
         case 2:
             CCLog("tag(2)Ok");
             off->setPosition(ccp(size.width/4*3+10,object->getPositionY()));
                          off->setTag(2);
             SE_Off();

             
             break;
         case 3:
             CCLog("tag(3)Ok");
             off->setPosition(ccp(size.width/4*3+10,object->getPositionY()));
                          off->setTag(3);
             VIBE_Off();

             
             break;
         case 4:
             CCLog("tag(4)Ok");
             off->setPosition(ccp(size.width/4*3+10,object->getPositionY()));
                          off->setTag(4);
             NET_Off();

             
             break;
         case 5:
             CCLog("tag(5)Ok");
             on->setPosition(ccp(size.width/4*3+10,object->getPositionY()));
             on->setTag(1);
             BGM_On();

             
             break;
         case 6:
             CCLog("tag(6)Ok");
             on->setPosition(ccp(size.width/4*3+10,object->getPositionY()));
             on->setTag(6);
             SE_On();

             
             break;
         case 7:
             CCLog("tag(7)Ok");
             on->setPosition(ccp(size.width/4*3+10,object->getPositionY()));
             on->setTag(7);
             VIBE_On();

             
             break;
         case 8:
             CCLog("tag(8)Ok");
             on->setPosition(ccp(size.width/4*3+10,object->getPositionY()));
             on->setTag(8);
             NET_On();

             
             break;
         default:
             CCLog("CallBack No Target");
             break;
             
    }
    
    object->setVisible(false);
    object->setTag(1);
    
    if(tag<=4){
         this->addChild(off);
    }else{
         this->addChild(on);
    }
}





