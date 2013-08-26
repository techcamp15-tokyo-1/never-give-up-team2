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
    
    CCParticleGalaxy* galaxy=CCParticleGalaxy::createWithTotalParticles(1000);
    this->addChild(galaxy);
    
    Buy(700);
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

void ShopView::next(){
    CCScene* next=SettingView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}
bool ShopView::Buy(const int Price){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    int m=user->getIntegerForKey("money",-1);
    CCLog("buy now load money %d",m);
    if(m==(-1)){
        return false;
    }
    if((m-Price)<0){
        return false;
    }else{
        m-=Price;
        user->setIntegerForKey("money",m);
        user->flush();
        CCLog("buy after money %d",m);
    }
    return true;    
}

void ShopView::Save(const int money){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setIntegerForKey("money",money);
    user->flush();
}

void ShopView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
