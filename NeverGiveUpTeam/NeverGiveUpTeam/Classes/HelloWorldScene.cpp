#include "GV.h"
using namespace CocosDenshion;
using namespace cocos2d;

HelloWorld::HelloWorld(){
r=0;b=0;gc=0;
}
CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

void HelloWorld::setStatus(){
#ifndef _FIRST_SET_ //first call first set
#define _FIRST_SET_

    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    int power=user->getIntegerForKey("power",-1);
    int stamina=user->getIntegerForKey("stamina",-1);
    int money=user->getIntegerForKey("money",-1);
    
    if(power==(-1)){
        user->setIntegerForKey("power",10);
    }
    if(stamina==(-1)){
        user->setIntegerForKey("stamina",MAX_STAMINA);
    }
    if(money==(-1)){
        user->setIntegerForKey("money",0);
    }
    
    CCLog("p=%d,s=%d,m=%d",power,stamina,money);
    
    user->flush();

    
#endif
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    for(int i=0;i<10;i++){
    setStatus();
    }
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("start.mp3",true);
   
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::callback));
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    
    CCSprite* back=CCSprite::create("StartBackground.jpeg");
    back->setPosition(ccp(0.f,0.f));
    this->addChild(back);
    
    
    
    
    
    CCSprite* title=CCSprite::create("title_logo.png");
    title->setScaleX(0.75f);
    title->setPosition(ccp(size.width/2,size.height/5*3));
    this->addChild(title);
    
    TapSprite* startl=(TapSprite*)TapSprite::create("Start.png");
    startl->setPosition(ccp(size.width/2,size.height/3));
    startl->setScale(0.25f);
    startl->setTag(1);
    this->addChild(startl);
    
    
    
    CCLabelTTF* copyright=CCLabelTTF::create("©2013 TechnologyCamp","arial",20);
    //NGU=Never Give Up Team
    CCLabelTTF* dev=CCLabelTTF::create("CoDeveloped by NGUT","arial",20);
    copyright->setPosition(ccp(size.width/2,size.height/5));
    dev->setPosition(ccp(size.width/2,size.height/7));
    
    this->addChild(copyright);
    this->addChild(dev);
    
    CCActionInterval* action1=CCJumpBy::create(0.7,ccp(0,0),5,1);
    CCActionInterval* action2=CCRepeatForever::create(action1);
    startl->runAction(action2);
 
    CCParticleSun* par=CCParticleSun::createWithTotalParticles(2000);
    ccColor4F color=par->getStartColor();
    color.r=1.0f;
    color.g=0.5f;
    color.b=0.5f;
    color.a=0.5f;
    par->setStartColor(color);
    par->setPosition(ccp(size.width/10*9,size.height/10*9));
    this->addChild(par);
    
    CCParticleGalaxy* g=CCParticleGalaxy::createWithTotalParticles(1000);
    ccColor4F gcolor=g->getStartColor();
    gcolor.r=0;
    gcolor.g=1.0f;
    gcolor.b=0.2f;
    gcolor.a=0;
    g->setStartColor(gcolor);
    this->addChild(g);

    return true;
}

void HelloWorld::ccTouchesBegan(CCSet* touches,CCEvent* event){
    CCTouch* touch=(CCTouch*)touches->anyObject();
    CCPoint point=touch->getLocationInView();
    CCSprite *start=(CCSprite *)this->getChildByTag(1);
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    if(point.y<=size.height-start->getPositionY()+40 &&point.y>=size.height-start->getPositionY()-40){
        callback();
    }
}

void HelloWorld::callback(){
    CCScene* next=StartView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionProgressInOut::create(duration,next);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
    //    float x=0,y=0,z=0;
    //  CCCamera* camera=this->getCamera();
    //  camera->getEyeXYZ(&x, &y, &z);
    // camera->setEyeXYZ(x, y, 200); zoomout
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

string HelloWorld::getPower(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    int power=user->getIntegerForKey("power",0);
    string str="";
    ostringstream ostring;//stream 宣言
    ostring<<(power);//iをstreamに代入
    string num=ostring.str();//int to string
    str+=num;//連結
    return str;
}

string HelloWorld::getStamina(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    int stamina=user->getIntegerForKey("stamina",0);
    string str="";
    ostringstream ostring;//stream 宣言
    ostring<<(stamina);//iをstreamに代入
    string num=ostring.str();//int to string
    str+=num;//連結
    str+="/100";
    return str;
}

string HelloWorld::getMoney(){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    int money=user->getIntegerForKey("money",0);
    string str="";
    ostringstream ostring;//stream 宣言
    ostring<<(money);//iをstreamに代入
    string num=ostring.str();//int to string
    str+=num;//連結
     return str;
}
