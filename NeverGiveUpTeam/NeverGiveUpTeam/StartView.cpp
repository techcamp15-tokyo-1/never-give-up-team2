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
                                                          menu_selector(StartView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    

    CCLabelTTF* label1=CCLabelTTF::create("森へ行く","arial",20);
    label1->setPosition(ccp(size.width/4,size.height/4*3));
    label1->setColor(ccc3(0,0,0));
    this->addChild(label1);
    CCLabelTTF* label2=CCLabelTTF::create("ショップへ行く","arial",20);
    label2->setPosition(ccp(size.width/4*3,size.height/4*3));
    label2->setColor(ccc3(0,0,0));
    this->addChild(label2);
    CCLabelTTF* label3=CCLabelTTF::create("倉庫","arial",20);
    label3->setPosition(ccp(size.width/4,size.height/3));
    label3->setColor(ccc3(0,0,0));
    this->addChild(label3);
    CCLabelTTF* label4=CCLabelTTF::create("図鑑","arial",20);
    label4->setPosition(ccp(size.width/4*3,size.height/3));
    label4->setColor(ccc3(0,0,0));
    this->addChild(label4);
    
    CCSize visibleSize=CCDirector::sharedDirector()->getVisibleSize();
    
    CCDrawNode *node=CCDrawNode::create();
    node->drawSegment(ccp(visibleSize.width/2,0),ccp(visibleSize.width/2,visibleSize.height),1,ccc4FFromccc3B(ccBLUE));
    addChild(node);
    
    CCDrawNode *node2=CCDrawNode::create();
    node2->drawSegment(ccp(0,visibleSize.height/2),ccp(visibleSize.width,visibleSize.height/2),1,ccc4FFromccc3B(ccBLUE));
    addChild(node2);
    
    
    
   CCSprite* m1=CCSprite::create("Forest.png");
    CCSprite* m2=CCSprite::create("Shop.png");
    CCSprite* m3=CCSprite::create("Box.png");
    CCSprite* m4=CCSprite::create("Zukan.png");
    
   
    
    
    
    m1->setPosition(ccp(size.width/4,size.height/4*3));
    m2->setPosition(ccp(size.width/4*3,size.height/4*3));
    m3->setPosition(ccp(size.width/4,size.height/4));
    m4->setPosition(ccp(size.width/4*3,size.height/4));
    m1->setScale(0.75f);
    m2->setScale(0.75f);
    m3->setScale(0.75f);
    m4->setScale(0.75f);
    this->addChild(m1);
    this->addChild(m2);
    this->addChild(m3);
    this->addChild(m4);
    
    
    CCDrawNode *ste=CCDrawNode::create();
    ste->drawSegment(ccp(0,visibleSize.height/10*9),ccp(visibleSize.width,visibleSize.height/10*9),1,ccc4FFromccc3B(ccBLUE));
    addChild(ste);
    
    
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
    //ここまで

    
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
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
