//
//  StartView.cpp
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#include "GV.h"

StartView::StartView(){
}
CCScene* StartView::scene()
{
    CCScene *scene = CCScene::create();
    StartView *layer = StartView::create();
    scene->addChild(layer);
    return scene;
}

bool StartView::init()
{
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    if(user->getBoolForKey("BGM_KEY",true)){
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("top.mp3",true);
        bool first=user->getBoolForKey("FIRST",false);
        if(first){
            
        }else{
            CCMessageBox("画面遷移は右下または、右上のonマークで切り替わります", "-ガイド-");
            user->setBoolForKey("FIRST",true);
            user->flush();

        }
    
    
    }
        if ( !CCLayer::init() )
    {
        return false;
    }
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("colk.png");
    back->setPosition(ccp(size.width/2,size.height/2));
    back->setScale(2.0);
    back->setTag(1);
    this->addChild(back);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(StartView::menuCloseCallback));
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 25, 25) );
        pCloseItem->setScale(2.0);
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    CCSprite* state=CCSprite::create("state.png");//ステータスバー
    state->setScaleY(0.7);
    state->setScaleX(0.9);
    state->setPosition(ccp(size.width/2,size.height-(state->getContentSize().height/3)));
    this->addChild(state);

    
    //ステータスに表示
    CCLabelTTF* power=CCLabelTTF::create(HelloWorld::getPower().c_str(),"Thonburi",40);
    CCLabelTTF* stamina=CCLabelTTF::create(HelloWorld::getStamina().c_str(),"Thonburi",40);
    CCLabelTTF* money=CCLabelTTF::create(HelloWorld::getMoney().c_str(),"Thonburi",40);
    power->setPosition(ccp(size.width/5*4,size.height/40*39));
    stamina->setPosition(ccp(size.width/5*4,size.height/40*37.5));
    money->setPosition(ccp(size.width/5*4,size.height/40*36-5));
    ccColor3B sc=power->getColor();
    sc.r=0;
    sc.g=0;
    sc.b=0;
    power->setColor(sc);
    stamina->setColor(sc);
    money->setColor(sc);
    this->addChild(power);
    this->addChild((stamina));
    this->addChild((money));
    
    
    CCSprite* m1=CCSprite::create("Forest.png");
    CCSprite* m2=CCSprite::create("Shop.png");
    CCSprite* m3=CCSprite::create("Box.png");
    CCSprite* m4=CCSprite::create("Zukan.png");
    
    m1->setScaleX(1.5);
        m1->setScaleY(1.7);
    m2->setScale(1.5);
        m2->setScaleY(1.7);
    m3->setScale(1.5);
        m3->setScaleY(2.1);
    m4->setScale(1.5);
        m4->setScaleY(2.1);
    
    float max=size.height-(state->getContentSize().height);
    //float max2=m1->getPositionX()-m1->getContentSize().height/2;
    
    m1->setPosition(ccp(size.width/4,max-state->getContentSize().height/2-22));
    m2->setPosition(ccp(size.width/4*3,max-state->getContentSize().height/2-22));
    m3->setPosition(ccp(size.width/4,size.height/2-m3->getContentSize().height-30));
    m4->setPosition(ccp(size.width/4*3,size.height/2-m4->getContentSize().height-30));
 //   m1->setScaleX(0.75f);
 //   m2->setScaleX(0.75f);
 //   m3->setScaleX(0.75f);
 //   m4->setScaleX(0.75f);
    this->addChild(m1);
    this->addChild(m2);
    this->addChild(m3);
    this->addChild(m4);
    
    CCDrawNode *ste=CCDrawNode::create();
    CCPoint rec[4]={
        ccp(90,size.height/40*38),
        ccp(size.width/3*2,size.height/40*38),
        ccp(90,size.height/40*37),        
        ccp(size.width/3*2,size.height/40*37)
    };
    
    ste->drawPolygon(rec,4,ccc4FFromccc3B(ccYELLOW),1,ccc4FFromccc3B(ccYELLOW));
    // this->addChild(ste);
    
    //Status Bar
    CCDrawNode *ste2=CCDrawNode::create();
    ste2->drawSegment(ccp(size.width/2,state->getPositionY()-state->getContentSize().height/2+30),ccp(size.width/2,0),1,ccc4FFromccc3B(ccWHITE));
    this->addChild(ste2);
 
    
    CCDrawNode *sta=CCDrawNode::create();
    sta->drawSegment(ccp(0,size.height/2-20),ccp(size.width,size.height/2-20),1,ccc4FFromccc3B(ccWHITE));
    this->addChild(sta);
    
    
    
    
    
    
    return true;
}

void StartView::next(const int s){
     float duration=0.5f;
        SimpleAudioEngine::sharedEngine()->sharedEngine()->stopBackgroundMusic();
    if(s==1){
        duration =1.0;
            CCScene* next=BoxView::scene();
            CCScene* pScene=CCTransitionTurnOffTiles::create(duration,next);
            if(pScene){
                CCDirector::sharedDirector()->replaceScene(pScene);
            }
    }else if(s==2){
            CCScene* next2=TopView::scene();
            CCScene* pScene2=CCTransitionZoomFlipAngular::create(duration,next2);
            if(pScene2){
                CCDirector::sharedDirector()->replaceScene(pScene2);
            }
    }else if(s==3){
            CCScene* next3=CollectView::scene();
            CCScene* pScene3=CCTransitionPageTurn::create(duration,next3,true);
            if(pScene3){
                CCDirector::sharedDirector()->replaceScene(pScene3);
            }
    }else if(s==4){
            CCScene* next4=ShopView::scene();
            CCScene* pScene4=CCTransitionCrossFade::create(duration,next4);
            if(pScene4){
                CCDirector::sharedDirector()->replaceScene(pScene4);
            }
        }
}

void StartView::ccTouchesBegan(CCSet* touches,CCEvent* enevet){
    CCTouch* touch=(CCTouch*)touches->anyObject();
    CCPoint location=touch->getLocationInView();
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    if(location.x<=size.width/2 && location.y>=size.height/2){
        next(1);
        CCLog("next1");//Box
    }else if(location.x<=size.width/2 && location.y<=size.height/2){
        CCUserDefault* user=CCUserDefault::sharedUserDefault();
        int s=user->getIntegerForKey("stamina");
        if(s>0){
        next(2);
        CCLog("next2");//Mori
        }else{
            CCMessageBox("","スタミナがありません！");
        }
    }else if(location.x>=size.width/2 && location.y>=size.height/2){
        next(3);
        CCLog("next3");//Collect
    }else if(location.x>=size.width/2 && location.y<=size.height/2){
        next(4);
        CCLog("next4");//Shop
    }
}
void StartView::menuCloseCallback(CCObject* pSender)
{
    //CCDirector::sharedDirector()->end();
        float duration =1.0;
        CCScene* next=SettingView::scene();
        CCScene* pScene=CCTransitionJumpZoom::create(duration,next);
        if(pScene){
            CCDirector::sharedDirector()->replaceScene(pScene);
        }

    
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  //  exit(0);
//#endif
}
