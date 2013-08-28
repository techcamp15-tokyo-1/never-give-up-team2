//
//

//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#include "GV.h"



CCScene* TopView::scene()
{
    CCScene *scene = CCScene::create();
    TopView *layer = TopView::create();
    scene->addChild(layer);
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    if(user->getBoolForKey("SE_KEY",true)){
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
    SimpleAudioEngine::sharedEngine()->preloadEffect("keri.mp3");
    }
    return scene;
}

bool TopView::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("Background.jpeg");
    back->setPosition(ccp(size.width/2,size.height/2));
    this->addChild(back);
  
    //ここから
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(TopView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 25, 25) );
        pCloseItem->setScale(2.0);
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    //ここまで
    
      
    
    CCSprite* state=CCSprite::create("state.png");//ステータスバー
    
       
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
    stamina->setTag(5);
    money->setColor(sc);
   
   //ここまで
    
    //power=255,100,100
    //stamina=
    //money=
    
    CCSprite* tree =CCSprite::create("kunugi1.png");//Picture of Tree
    
    CCSprite* foot=CCSprite::create("FootStart.png");
    foot->setScale(0.25f);
    foot->setPosition(ccp(size.width,size.height/3));

    foot->setTag(1);
    
    
    /*
    CCMenuItemImage* foot=CCMenuItemImage::create("FootStart.png","FootStart.png",this,menu_selector(TopView::hit));
    foot->setScale(0.125);
    foot->setPosition(ccp(size.width,size.height/3));
    CCMenu* f=CCMenu::create(foot,NULL);
    f->setPosition(CCPointZero);
    this->addChild(f,1);
     */
    
    tree->setScaleX(0.6f);
    tree->setScaleY(1.0f);
    tree->setTag(2);
    tree->setPosition(ccp(size.width/3,size.height/2));
    this->addChild(tree);
    
    //Action
    CCActionInterval* action1=CCMoveTo::create(0.7,ccp(size.width/3,size.height/3));
    CCActionInterval* action2=CCRepeatForever::create(action1);
//    foot->runAction(action2);
    
    CCActionInterval* action3=CCJumpBy::create(0.7,ccp(0,0),10,1);
    CCActionInterval* action4=CCRepeatForever::create(action3);
  //  tree->runAction(action4);
    
   
    this->addChild(foot);
    state->setScaleY(0.7);
    state->setScaleX(0.9);
    state->setPosition(ccp(size.width/2,size.height-(state->getContentSize().height/3)));
    this->addChild(state);
    this->addChild(power);
    this->addChild((stamina));
    this->addChild((money));

   
    return true;
}

void TopView::hit(CCMenuItemImage* image,CCSet* set){
    CCTouch* touch=(CCTouch*)set->anyObject();
    CCPoint location=touch->getLocationInView();
    image->setPosition(location);
}

void TopView::next(){
    CCScene* next=StartView::scene();
   
    float duration=0.5f;

   
  
        CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){

        SimpleAudioEngine::sharedEngine()->sharedEngine()->stopBackgroundMusic();
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
    
}

void TopView::ccTouchesBegan(CCSet* touches,CCEvent* event){
    
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    if(0<=user->getIntegerForKey("stamina")){
    CCLog("ccTouchesBegan");
    CCTouch* touch=(CCTouch*)touches->anyObject();
    CCPoint location=touch->getLocationInView();
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    location.y=size.height-location.y;
     CCSprite* tree=(CCSprite *)this->getChildByTag(2);
    
    CCSprite* player=(CCSprite*)this->getChildByTag(1);
    if(location.x<=(tree->getPositionX())){
        location.x=tree->getPositionX();
    }
    player->setPosition(location);
    }
}

void TopView::ccTouchesMoved(CCSet* touches,CCEvent* event){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    CCLog("s=%d",user->getIntegerForKey("stamina"));
    if(0<=user->getIntegerForKey("stamina")){
    CCLog("s=%d",user->getIntegerForKey("stamina"));
    CCSprite* player=(CCSprite*)this->getChildByTag(1);
    CCSprite* tree=(CCSprite *)this->getChildByTag(2);

    CCTouch* touch=(CCTouch*)touches->anyObject();
    CCPoint location=touch->getLocationInView();
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    location.y=size.height-location.y;
    
        //player->getPositionX() //GodMode
    if(player->getPositionX()<=(tree->getPositionX()+tree->getContentSize().width/2)*0.35f){
        
               

        CCLog("tree hit");
        SimpleAudioEngine::sharedEngine()->playEffect("keri.mp3");
        float duration=1;
        CCMoveTo* move=CCMoveTo::create(duration,ccp(size.width/3*2,player->getPositionY()));
        player->runAction(move);
        
        int stamina=atoi(HelloWorld::getStamina().c_str());
        if(stamina>0){
            stamina-=1;
        }

        user->setIntegerForKey("stamina",stamina);
        user->flush();
        
        CCLabelTTF* staminaImage=(CCLabelTTF *)this->getChildByTag(5);
        CCString* str=CCString::createWithFormat("%d",stamina);//user->getIntegerForKey("stamina"));
        staminaImage->setString(str->getCString());
//        staminaImage->setString(stamina);
        CCLog("%d",stamina);
    }else{
         player->setPosition(location);
    }
    
    }
   
}

void TopView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
