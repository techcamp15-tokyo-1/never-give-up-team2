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
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
    SimpleAudioEngine::sharedEngine()->preloadEffect("keri.mp3");
    return scene;
}

bool TopView::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //    CCSize backSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("MainBackgroundFall.png");
    back->setPosition(ccp(100.f,100.f));
    back->setTag(1);
    this->addChild(back);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(TopView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    CCLabelTTF* label=CCLabelTTF::create("Top","arial",48);
    label->setPosition(ccp(100.f,100.f));
    this->addChild(label);
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
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
    
    //power=255,100,100
    //stamina=
    //money=
    
    CCSprite* tree =CCSprite::create("kunugi1.png");//Picture of Tree
    CCSprite* foot=CCSprite::create("FootStart.png");//Picture of foot
    tree->setScale(0.4f);
    foot->setScale(0.125f);
    tree->setPosition(ccp(size.width/2,size.height/2));
    foot->setPosition(ccp(size.width,size.height/3));
    this->addChild(tree);
    this->addChild(foot);
    
    //Action
    CCActionInterval* action1=CCMoveTo::create(0.7,ccp(size.width/3,size.height/3));
    CCActionInterval* action2=CCRepeatForever::create(action1);
    foot->runAction(action2);
    
    CCActionInterval* action3=CCJumpBy::create(0.7,ccp(0,0),10,1);
    CCActionInterval* action4=CCRepeatForever::create(action3);
    tree->runAction(action4);
    
    SimpleAudioEngine::sharedEngine()->playEffect("keri.mp3");
    SimpleAudioEngine::sharedEngine()->playEffect("keri.mp3");
        SimpleAudioEngine::sharedEngine()->playEffect("keri.mp3");
        SimpleAudioEngine::sharedEngine()->playEffect("keri.mp3");
        SimpleAudioEngine::sharedEngine()->playEffect("keri.mp3");
        SimpleAudioEngine::sharedEngine()->playEffect("keri.mp3");
    
    
    CCLabelTTF* test=CCLabelTTF::create("完全にテストです","arial",38);
    test->setPosition(ccp(size.width/2,size.height/3*2));
    this->addChild(test);
    
    
    
    return true;
}

void TopView::next(){
    CCScene* next=StartView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }

}

void TopView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
