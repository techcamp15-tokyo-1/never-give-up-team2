#include "GV.h"
using namespace CocosDenshion;
using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
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
    CCLog("Now is First");
    
    CCSprite* back=CCSprite::create("StartBackground.jpeg");
    back->setPosition(ccp(0.f,0.f));
    this->addChild(back);
    
    
    CCLabelTTF* label=CCLabelTTF::create("タイトル","arial",48);
    label->setPosition(ccp(size.width/2,size.height/1.5));
    this->addChild(label);
    CCLabelTTF* startl=CCLabelTTF::create("START","arial",48);
    startl->setPosition(ccp(size.width/2,size.height/4));
    this->addChild(startl);
    
    
    
    return true;
}

void HelloWorld::callback(){
    CCScene* next=StartView::scene();
    CCDirector::sharedDirector()->replaceScene(next);

}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
