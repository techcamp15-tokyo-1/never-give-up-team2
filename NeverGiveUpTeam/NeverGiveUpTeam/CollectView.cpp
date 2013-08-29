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
    pCloseItem->setPosition( ccp(size.width - 25, size.height-25) );
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
    setHatenaK();
    
    
    
    return true;
}

void CollectView::setImage(){
    CCSprite* collect[MAX_COLLECT];
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* zukan=CCSprite::create("z.png");
        zukan->setPosition(ccp(size.width/2,size.height/2-40));
        zukan->setScaleX(1.2);
        zukan->setScaleY(1.8);
        zukan->setTag(4);
        
    CCSprite* y=CCSprite::create("zm.png");
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
    item2->setPosition(ccp(size.width/2,30));
    item2->setScaleX(2);
    item2->setScaleY(2.2);
    item2->setTag(2);
    CCMenuItemImage *item3 = CCMenuItemImage::create(
                                                     "OButton.png",
                                                     "OButton.png",
                                                     this,
                                                     menu_selector(CollectView::CollectScene) );
    item3->setPosition(ccp(size.width/4*3+50,30));
    item3->setScaleX(2);
    item3->setScaleY(2.2);
    item3->setTag(3);
    
    
        //ここまで
    CCMenu* Menu = CCMenu::create(item1,item2,item3, NULL);
    Menu->setPosition( CCPointZero );
    this->addChild(Menu, 1);


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
        setHatenaK();
        this->getChildByTag(4)->setVisible(CollectView::set);
        CollectView::set=!(CollectView::set);
        this->getChildByTag(5)->setVisible(CollectView::set2);
                CollectView::set2=!(CollectView::set2);

    }else if(tag==2){
        SetHatenaM();
        this->getChildByTag(5)->setVisible(CollectView::set2);
        CollectView::set2=!(CollectView::set2);
        this->getChildByTag(4)->setVisible(CollectView::set);
        CollectView::set=!(CollectView::set);
    }else if(tag==3){
        CCLog("others");
    }
}

void CollectView::setHatenaK(){
    CCSize size= CCDirector::sharedDirector()->getWinSize();
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    for(int i=0;i<8;i++){
        if(i%2==1){
            string str="i";
            ostringstream ostring;//stream 宣言
            ostring<<(i);//iをstreamに代入
            str+=ostring.str();
        if(user->getBoolForKey(str.c_str(),false)){
    CCSprite* hatena1=CCSprite::create("hatena.png");
    hatena1->setPosition(ccp(size.width/8*i,690));
    hatena1->setScaleX(1.1);
    hatena1->setScaleY(1.5);
    this->addChild(hatena1);
            }
        }
    }

    for(int i=0;i<8;i++){
        if(i%2==1){
            string str="i";
            ostringstream ostring;//stream 宣言
            ostring<<(i+4);//iをstreamに代入
            str+=ostring.str();
            if(user->getBoolForKey(str.c_str(),false)){
    CCSprite* hatena2=CCSprite::create("hatena.png");
    hatena2->setPosition(ccp(size.width/8*i,455));
    hatena2->setScaleX(1.1);
    hatena2->setScaleY(1.5);
    this->addChild(hatena2);
            }
    }
    }
    for(int i=0;i<8;i++){
        if(i%2==1){
            string str="i";
            ostringstream ostring;//stream 宣言
            ostring<<(i+8);//iをstreamに代入
            str+=ostring.str();
            if(user->getBoolForKey(str.c_str(),false)){
    CCSprite* hatena3=CCSprite::create("hatena.png");
    hatena3->setPosition(ccp(size.width/8*i,220));
    hatena3->setScaleX(1.1);
    hatena3->setScaleY(1.5);
    this->addChild(hatena3);
            }
    }
    }
    
}
void CollectView::SetHatenaM(){
    CCSize size= CCDirector::sharedDirector()->getWinSize();
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    for(int i=0;i<8;i++){
        if(i%2==1){
            string str="m";
            ostringstream ostring;//stream 宣言
            ostring<<(i);//iをstreamに代入
            str+=ostring.str();
            if(user->getBoolForKey(str.c_str(),false)){
                CCSprite* hatena1=CCSprite::create("hatena.png");
                hatena1->setPosition(ccp(size.width/8*i,690));
                hatena1->setScaleX(1.1);
                hatena1->setScaleY(1.5);
                this->addChild(hatena1);
            }
        }
    }
    
    for(int i=0;i<8;i++){
        if(i%2==1){
            string str="m";
            ostringstream ostring;//stream 宣言
            ostring<<(i+4);//iをstreamに代入
            str+=ostring.str();
            if(user->getBoolForKey(str.c_str(),false)){
                CCSprite* hatena2=CCSprite::create("hatena.png");
                hatena2->setPosition(ccp(size.width/8*i,455));
                hatena2->setScaleX(1.1);
                hatena2->setScaleY(1.5);
                this->addChild(hatena2);
            }
        }
    }
    for(int i=0;i<8;i++){
        if(i%2==1){
            string str="m";
            ostringstream ostring;//stream 宣言
            ostring<<(i+8);//iをstreamに代入
            str+=ostring.str();
            if(user->getBoolForKey(str.c_str(),false)){
                CCSprite* hatena3=CCSprite::create("hatena.png");
                hatena3->setPosition(ccp(size.width/8*i,220));
                hatena3->setScaleX(1.1);
                hatena3->setScaleY(1.5);
                this->addChild(hatena3);
            }
        }
    }
    

}
void CollectView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
