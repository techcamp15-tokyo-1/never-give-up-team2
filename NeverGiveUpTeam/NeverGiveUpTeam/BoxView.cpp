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
    scroll=CCScrollView::create(ccp(size.width,size.height));
    scroll->setDirection(kCCScrollViewDirectionVertical);
    this->addChild(scroll);
    CCSprite* back=CCSprite::create("Background.jpeg");
    back->setPosition(ccp(size.width/2,size.height/2));
    back->setTag(1);
//    this->addChild(back);
//    scroll->setContainer(back);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(BoxView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 25, size.height-25) );
        pCloseItem->setScale(2.0);
  
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    //scroll->setContainer(pMenu);
    
    CCSprite* state=CCSprite::create("state.png");//ステータスバー
    state->setScaleY(0.7);
    state->setScaleX(0.9);
    state->setPosition(ccp(size.width/2,size.height-(state->getContentSize().height/3)));
    this->addChild(state);
    CCLog("Box");

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
    
    setImage();

    
    
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
    CCScene* next=StartView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
        SimpleAudioEngine::sharedEngine()->sharedEngine()->stopBackgroundMusic();
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

void BoxView::setImage(){
    CCSprite* collect[MAX_COLLECT];
    CCUserDefault* user =CCUserDefault::sharedUserDefault();
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    float x=size.width/8,y=size.height-size.height/5;
    for(int i=0;i<MAX_COLLECT;i++){
        ostringstream oss;
        string str="";
        oss<<(i+1);
        str+=oss.str();
        str+=".png";
        collect[i]=CCSprite::create(str.c_str());
        
        collect[i]->setPosition(ccp(x,y));
        collect[i]->setScale(0.5f);

        //  scroll->setContainer(collect[i]);
        this->addChild(collect[i]);
        string str2="";
        ostringstream ostring;//stream 宣言
        ostring<<(i+1);
        str2+=ostring.str();
        ostring<<(user->getIntegerForKey(str2.c_str(),0));//iをstreamに代入
        string num=ostring.str();//int to string
        str+=num;//連結
        
        CCLabelTTF* label=CCLabelTTF::create(num.c_str(),"arial",20);
        label->setPosition(ccp(x,y-35));
        this->addChild(label);
        

        if(++x>size.width){
            x=(size.width/8);
            y-=(size.height/4);
        }
        else{
            x+=(size.width/4);
            
        }
    }
}


