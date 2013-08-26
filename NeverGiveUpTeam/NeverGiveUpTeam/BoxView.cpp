//
//  BoxView.cpp
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#include "BoxView.h"
#include "GV.h"
#include "XTLayer.h"

CCScene* BoxView::scene()
{
    CCScene *scene = CCScene::create();
    BoxView *layer = BoxView::create();
    scene->addChild(layer);
    return scene;
}

bool BoxView::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
     this->setTouchMode(kCCTouchesAllAtOnce);
     this->setTouchEnabled(true);
    
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("Background.jpeg");
    back->setPosition(ccp(100.f,100.f));
    back->setTag(1);
    this->addChild(back);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(BoxView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
       
    
    CCLabelTTF* label1=CCLabelTTF::create("Box","arial",20);
    label1->setPosition(ccp(size.width/4,size.height/4*3));
    this->addChild(label1);
    
    sell(1500);
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

/*
void BoxView::xtSwipeGesture(XTTouchDirection direction, float distance, float speed)
{
    string directionStr = "";
    switch (direction) {
        case XTLayer::UP:    directionStr = "UP";    break;
        case XTLayer::DOWN:  directionStr = "DOWN";  break;
        case XTLayer::LEFT:  directionStr = "LEFT";  break;
        case XTLayer::RIGHT: directionStr = "RIGHT"; break;
        default:break;
    }
    
    CCLog("フリック");
}
*/

void BoxView::next(){
    CCScene* next=ShopView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
        CCDirector::sharedDirector()->replaceScene(pScene);
    }

}

void BoxView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void BoxView::sell(const int Price){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    int money=user->getIntegerForKey("money",0);
    CCLog("sell now money %d",money);
    money+=Price;
    user->setIntegerForKey("money", money);
    user->flush();
    CCLog("after sell %d",money);
}


/*
void BoxView::xtTouchesBegan(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesBegan");
}

void BoxView::xtTouchesMoved(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesMoved");
}

void BoxView::xtTouchesEnded(cocos2d::CCSet* _touches, cocos2d::CCEvent* event)
{
    CCLog("xtTouchesEnded");
}

void BoxView::xtTouchesBegan(CCPoint position)
{
    CCLog("xtTouchesBegan x: %f, y: %f", position.x, position.y);
}

void BoxView::xtTouchesMoved(CCPoint position)
{
    CCLog("xtTouchesMoved x: %f, y: %f", position.x, position.y);
}

void BoxView::xtTouchesEnded(CCPoint position)
{
    CCLog("xtTouchesEnded x: %f, y: %f", position.x, position.y);
}

void BoxView::xtTapGesture(CCPoint position)
{
    CCLog("xtTapGesture x: %f, y: %f", position.x, position.y);
}

void BoxView::xtDoubleTapGesture(CCPoint position)
{
    CCLog("xtDoubleTapGesture x: %f, y: %f", position.x, position.y);
}

void BoxView::xtLongTapGesture(CCPoint position)
{
    CCLog("xtLongTapGesture x: %f, y: %f", position.x, position.y);
}
*/
