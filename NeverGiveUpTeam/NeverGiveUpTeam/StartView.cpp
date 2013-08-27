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
     SimpleAudioEngine::sharedEngine()->playBackgroundMusic("top.mp3",true);
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("colk.png");
    back->setPosition(ccp(100.f,100.f));
    back->setTag(1);
    this->addChild(back);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(StartView::menuCloseCallback));
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    CCSprite* state=CCSprite::create("state.png");//ステータスバー
    state->setScaleX(size.width/state->getContentSize().width);
    state->setScaleY(state->getContentSize().height/size.height/10*8);//0.35f
    state->setPosition(ccp(size.width/2,size.height-(state->getContentSize().height/6)));
    this->addChild(state);
    
    //ステータスに表示
    CCLabelTTF* power=CCLabelTTF::create(HelloWorld::getPower().c_str(),"Thonburi",20);
    CCLabelTTF* stamina=CCLabelTTF::create(HelloWorld::getStamina().c_str(),"Thonburi",20);
    CCLabelTTF* money=CCLabelTTF::create(HelloWorld::getMoney().c_str(),"Thonburi",20);
    power->setPosition(ccp(size.width/5*4,size.height/40*39));
    stamina->setPosition(ccp(size.width/5*4,size.height/40*37.5));
    money->setPosition(ccp(size.width/5*4,size.height/40*36));
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
  /*
    CCSprite* plevel1=CCSprite::create("B.png");
    CCSprite* plevel2=CCSprite::create("Y.png");
    CCSprite* plevel3=CCSprite::create("R.png");
    CCSprite* slevel1=CCSprite::create("B.png");
    CCSprite* slevel2=CCSprite::create("Y.png");
    CCSprite* slevel3=CCSprite::create("R.png");
    plevel1->setScale(0.35f);
    plevel2->setScale(0.35f);
    
    plevel1->setPosition(ccp(size.width/2,size.height/40*37.5));
    this->addChild(plevel1);
    plevel2->setPosition(ccp(size.width/2+plevel1->getContentSize().width/2,size.height/40*37.5));
    this->addChild(plevel2);
//    plevel1->setPosition(ccp(size.width/2,size.height/40*37.5));
  //  this->addChild(plevel1);

    //ここまで
   */

    
    
    
    CCSprite* m1=CCSprite::create("Forest.png");
    CCSprite* m2=CCSprite::create("Shop.png");
    CCSprite* m3=CCSprite::create("Box.png");
    CCSprite* m4=CCSprite::create("Zukan.png");
    
    float max=size.height-(state->getContentSize().height);
    float max2=m1->getPositionX()-m1->getContentSize().height/2;
    
    m1->setPosition(ccp(size.width/4,max+state->getContentSize().height/7));
    m2->setPosition(ccp(size.width/4*3,max+state->getContentSize().height/7));
    m3->setPosition(ccp(size.width/4,max2+m1->getContentSize().height));
    m4->setPosition(ccp(size.width/4*3,max2+m1->getContentSize().height));
    m1->setScaleX(0.75f);
    m2->setScaleX(0.75f);
    m3->setScaleX(0.75f);
    m4->setScaleX(0.75f);
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
    ste2->drawSegment(ccp(size.width/2,state->getPositionY()-25),ccp(size.width/2,0),1,ccc4FFromccc3B(ccBLUE));
    this->addChild(ste2);
 
    
    CCDrawNode *sta=CCDrawNode::create();
    sta->drawSegment(ccp(90,size.height/40*37.5),ccp(size.width/3*2,size.height/40*37.5),10,ccc4FFromccc3B(ccYELLOW));
    //this->addChild(sta);
    
    
    
    
    
    
    return true;
}

void StartView::next(const int s){
     float duration=0.5f;
    if(s==1){
        duration =1.0;
            CCScene* next=BoxView::scene();
            CCScene* pScene=CCTransitionPageTurn::create(duration,next,true);
            if(pScene){
                CCDirector::sharedDirector()->replaceScene(pScene);
            }
    }else if(s==2){
            CCScene* next2=TopView::scene();
            CCScene* pScene2=CCTransitionFade::create(duration,next2);
            if(pScene2){
                CCDirector::sharedDirector()->replaceScene(pScene2);
            }
    }else if(s==3){
            CCScene* next3=CollectView::scene();
            CCScene* pScene3=CCTransitionFade::create(duration,next3);
            if(pScene3){
                CCDirector::sharedDirector()->replaceScene(pScene3);
            }
    }else if(s==4){
            CCScene* next4=ShopView::scene();
            CCScene* pScene4=CCTransitionFade::create(duration,next4);
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
        next(2);
        CCLog("next2");//Mori
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
