#include "GV.h"
using namespace CocosDenshion;
using namespace cocos2d;

HelloWorld::HelloWorld(){

}
CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    CCLog("HelloOk");
    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
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
    
    CCScene* start=TopView::scene();
    //CCDirector::sharedDirector()->pushScene(start);
    CCDirector::sharedDirector()->runWithScene(start);
    
    CCSprite* back=CCSprite::create("StartBackground.jpeg");
    back->setPosition(ccp(0.f,0.f));
    this->addChild(back);
    
    
    CCLabelTTF* label=CCLabelTTF::create("世界樹の不思議","arial",44);
    label->setPosition(ccp(size.width/2,size.height/1.5));
    this->addChild(label);
    CCLabelTTF* startl=CCLabelTTF::create("START","arial",48);
    startl->setPosition(ccp(size.width/2,size.height/3));
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
    return true;
}


void HelloWorld::callback(){
    CCScene* next=StartView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
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
