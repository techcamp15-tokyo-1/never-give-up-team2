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
    CollectView::set=false;
    CollectView::set2=true;
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("ZBG.png");
    back->setPosition(ccp(size.width/2,size.height/2));
    this->addChild(back);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(CollectView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 25, 25) );
        pCloseItem->setScale(2.0);
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    
    setImage();
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
    //ここまで

    
    
    return true;
}

void CollectView::setImage(){
    CCSprite* collect[MAX_COLLECT];
    CCSize size=CCDirector::sharedDirector()->getWinSize();
   /* float x=size.width/8,y=size.height-size.height/5;
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
            
        }*/
        
        CCSprite* zukan=CCSprite::create("z.png");
        zukan->setPosition(ccp(size.width/2,size.height/2-40));
        zukan->setScaleX(1.2);
        zukan->setScaleY(1.8);
    zukan->setTag(4);
        
    CCSprite* y=CCSprite::create("mi.png");
    y->setPosition(ccp(size.width/2,size.height/2-40));
    y->setScaleX(1.2);
    y->setScaleY(1.8);
    y->setTag(5);
    this->addChild(y);
    this->addChild(zukan);

    CCMenuItemImage *item1 = CCMenuItemImage::create(
                                                     "KButton.png",
                                                     "KButton.png",
                                                     this,
                                                     menu_selector(CollectView::CollectScene) );
    item1->setPosition(ccp(size.width/6,30));
    item1->setScaleX(2);
    item1->setScaleY(2.2);
    item1->setTag(1);
    CCMenuItemImage *item2 = CCMenuItemImage::create(
                                                     "MButton.png",
                                                     "MButton.png",
                                                     this,
                                                     menu_selector(CollectView::CollectScene) );
    item2->setPosition(ccp(size.width/5*2+25,30));
    item2->setScaleX(2);
    item2->setScaleY(2.2);
    item2->setTag(2);
    CCMenuItemImage *item3 = CCMenuItemImage::create(
                                                     "OButton.png",
                                                     "OButton.png",
                                                     this,
                                                     menu_selector(CollectView::CollectScene) );
    item3->setPosition(ccp(size.width/4*3,30));
    item3->setScaleX(2);
    item3->setScaleY(2.2);
    item3->setTag(3);
    
    
        //ここまで
    CCMenu* Menu = CCMenu::create(item1,item2,item3, NULL);
    Menu->setPosition( CCPointZero );
    this->addChild(Menu, 1);



        
        CCSprite* hatena=CCSprite::create("hatena.png");
        hatena->setPosition(ccp(size.width/8-10,size.height/2-30));
        hatena->setScaleX(1.1);
        hatena->setScaleY(1.5);
        this->addChild(hatena);

    
}

void CollectView::next(){
    CCScene* next=StartView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
                SimpleAudioEngine::sharedEngine()->sharedEngine()->stopBackgroundMusic();
        CCDirector::sharedDirector()->replaceScene(pScene);
    }

}
void CollectView::CollectScene(CCMenuItemImage* image){
    int tag=image->getTag();
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    if(tag==1){
        this->getChildByTag(4)->setVisible(CollectView::set);
        CollectView::set=!(CollectView::set);
        this->getChildByTag(5)->setVisible(CollectView::set2);
                CollectView::set2=!(CollectView::set2);
    }else if(tag==2){
        this->getChildByTag(5)->setVisible(CollectView::set2);
        CollectView::set2=!(CollectView::set2);
        this->getChildByTag(4)->setVisible(CollectView::set);
        CollectView::set=!(CollectView::set);
        
    }
}

void CollectView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
