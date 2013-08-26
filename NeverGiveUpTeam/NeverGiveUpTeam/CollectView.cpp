//
//  CollectView.cpp
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#include "CollectView.h"
#include "GV.h"
#include <iostream>
#include <sstream>
#include <string>

CCScene* CollectView::scene()
{
    CCScene *scene = CCScene::create();
    CollectView *layer = CollectView::create();
    scene->addChild(layer);
    return scene;
}

bool CollectView::init()
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
                                                          menu_selector(CollectView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    
    CCLabelTTF* label1=CCLabelTTF::create("ステータスバー","arial",50);
    label1->setPosition(ccp(size.width/2,size.height/10*9));
    this->addChild(label1);
    
    setImage();
    
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

void CollectView::setImage(){
    CCSprite* collect[MAX_COLLECT];
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    float x=size.width/8,y=size.height-size.height/5;
    for(int i=0;i<MAX_COLLECT;i++){
        collect[i]=CCSprite::create("Melon.png");
      
        collect[i]->setPosition(ccp(x,y));
        collect[i]->setScale(0.25f);
        this->addChild(collect[i]);
        
        string str="No.";
        ostringstream ostring;//stream 宣言
        ostring<<(i+1);//iをstreamに代入
        string num=ostring.str();//int to string
        str+=num;//連結
        
        CCLabelTTF* label=CCLabelTTF::create(str.c_str(),"arial",20);
        label->setPosition(ccp(x,y-size.height/10));
        this->addChild(label);
        
        if(++x>size.width){
            x=(size.width/8);
            y-=(size.height/4);
        }
        else{
            x+=(size.width/4);
            
        }
        

    }
}

void CollectView::next(){
    CCScene* next=BoxView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }

}

void CollectView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
