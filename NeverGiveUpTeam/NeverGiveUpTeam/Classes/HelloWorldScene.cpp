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
    
    CCScene* start=StartView::scene();
    //CCDirector::sharedDirector()->pushScene(start);
    CCDirector::sharedDirector()->runWithScene(start);
    CCLog("Now is First");
    
    CCLabelTTF* label=CCLabelTTF::create("First","arial",48);
    label->setPosition(ccp(100.f,100.f));
    this->addChild(label);
    
    
    
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
