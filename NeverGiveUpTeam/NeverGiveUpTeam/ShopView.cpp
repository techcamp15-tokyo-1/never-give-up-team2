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
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    if(user->getBoolForKey("BGM_KEY",true)){
     
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("shop.mp3");
    }
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
    back->setPosition(ccp(size.width/2,size.height/2));
   // this->addChild(back);
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(ShopView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 25,size.height-25) );
        pCloseItem->setScale(2.0);
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
        
    
    
    
    CCParticleGalaxy* galaxy=CCParticleGalaxy::createWithTotalParticles(10);
    this->addChild(galaxy);
    
    
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
    power->setTag(5);
    stamina->setTag(6);
    money->setTag(7);
    this->addChild(power);
    this->addChild((stamina));
    this->addChild((money));
    //ここまで
    
    //ここから商品
    SetMarchandice();
    //ここまで

    
    return true;
}

void ShopView::next(){
    CCScene* next=StartView::scene();
    float duration=0.5f;
    CCScene* pScene=CCTransitionFade::create(duration,next);
    if(pScene){
        SimpleAudioEngine::sharedEngine()->sharedEngine()->stopBackgroundMusic();
        CCDirector::sharedDirector()->replaceScene(pScene);
    }
}
bool ShopView::Buy(CCMenuItemImage* image){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    int m=user->getIntegerForKey("money",-1);
    if(m==(-1)){
        return false;
    }else{
        int tag=image->getTag();
        int Price=0;
        string str="";
        switch(tag){
            case 1:
                Price=600;
                str="パワードリンク\nパワーが２０増えました！";
                if((m-Price)>=0){
                    //dialog show
                    CCMessageBox(str.c_str(), "購入！");
                    //所持金に価格を引いたものをセットする
                    int after=(m-Price);
                    user->setIntegerForKey("money",after);
                    user->flush();
                    
                    //power rewrite
                    CCLabelTTF* power=(CCLabelTTF *)this->getChildByTag(5);
                    //staに現在のスタミナを代入
                    int po=user->getIntegerForKey("power");
                    po+=20;
                    user->setIntegerForKey("power",po);
                    user->flush();
                    
                    //staをCCStringに変換する
                    CCString* str=CCString::createWithFormat("%d",po);
                    //書き換える
                    power->setString(str->getCString());
                    
                    //money rewrite
                    CCLabelTTF* money=(CCLabelTTF *)this->getChildByTag(7);
                    //moに所持金を代入
                    //int mo=user->getIntegerForKey("money",0);
                    //購入金額を引く
                    //                    mo-=m;
                    //書き換え
                    CCString* str2=CCString::createWithFormat("%d",after);
                    money->setString(str2->getCString());                }else{
                    CCMessageBox("", "ゼニーが足りません");
                }
                
                break;
                
            case 2:
                
                Price=500;
                str="スタミナドリンク\nスタミナが20回復しました!";
                //買えるなら
                if(m-Price>=0){
                    //dialog show
                    CCMessageBox(str.c_str(), "購入！");
                    //所持金に価格を引いたものをセットする
                    int after=(m-Price);
                    user->setIntegerForKey("money",after);
                    user->flush();
                   
                    //stamina rewrite
                    CCLabelTTF* stamina=(CCLabelTTF *)this->getChildByTag(6);
                    //staに現在のスタミナを代入
                    int sta=user->getIntegerForKey("stamina");
                    sta+=20;
                    user->setIntegerForKey("stamina",sta);
                    user->flush();

                    //staをCCStringに変換する
                    CCString* str=CCString::createWithFormat("%d",sta);
                    //書き換える
                    stamina->setString(str->getCString());

                    //money rewrite
                    CCLabelTTF* money=(CCLabelTTF *)this->getChildByTag(7);
                    //moに所持金を代入
                    //int mo=user->getIntegerForKey("money",0);
                    //購入金額を引く
//                    mo-=m;
                    //書き換え
                    CCString* str2=CCString::createWithFormat("%d",after);
                    money->setString(str2->getCString());
                    
                    
                }else{
                    CCMessageBox("", "ゼニーが足りません");
                }

                
                break;
                
            case 3:
                Price=3000;
                str="大地の肥料";
                if(m-Price>=0){
                    //dialog show
                    
                    //所持金に価格を引いたものをセットする
                    int after=(m-Price);
                    user->setIntegerForKey("money",after);
                    user->flush();
                    if(user->getBoolForKey("SE_KEY",true)){
                    
                        SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
                        SimpleAudioEngine::sharedEngine()->playEffect("growup.mp3");
                    }
                    
                    
                    int g=user->getIntegerForKey("GROW_RATE",0);
                    g+=10;
                    ostringstream ostring;//stream 宣言
                    ostring<<(g);//iをstreamに代入
                    
                    str+="\n成長率現在："+ostring.str()+"%";
                    
                    CCMessageBox(str.c_str(), "購入！");
                    user->setIntegerForKey("GROW_RATE", g);
                    user->flush();
                    
                    CCLabelTTF* money=(CCLabelTTF *)this->getChildByTag(7);
                    CCString* str2=CCString::createWithFormat("%d",after);
                    money->setString(str2->getCString());

                    
                }else{
                    CCMessageBox("", "ゼニーが足りません");
                }

                break;
                
            case 4:
                Price=5000;
                str="ハイパーハンマー\nパワーの上限が解放され、装備されました！";
                if(m-Price>=0){
                    //dialog show
                    CCMessageBox(str.c_str(), "購入！");
                    //所持金に価格を引いたものをセットする
                    int after=(m-Price);
                    user->setIntegerForKey("money",after);
                    user->flush();
                    user->setBoolForKey("hummer", true);
                    user->flush();
                    
                    CCLabelTTF* money=(CCLabelTTF *)this->getChildByTag(7);
                    CCString* str2=CCString::createWithFormat("%d",after);
                    money->setString(str2->getCString());

                    
                    
                    
                }else{
                    CCMessageBox("", "ゼニーが足りません");

                }

                
                break;
        }
        
           }
    return true;    
}

void ShopView::Save(const int money){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    user->setIntegerForKey("money",money);
    user->flush();
}
void ShopView::SetMarchandice(){
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCMenuItemImage* item1= CCMenuItemImage::create(
                                                          "s1.png",
                                                          "s1.png",
                                                          this,
                                                          menu_selector(ShopView::Buy) );
    item1->setPosition( ccp(35,size.height/5*4-80));
    item1->setScale(1);
    item1->setTag(1);
    CCMenuItemImage* item2= CCMenuItemImage::create(
                                                    "s2.png",
                                                    "s2.png",
                                                    this,
                                                    menu_selector(ShopView::Buy) );
    item2->setPosition( ccp(35,size.height/5*3-100) );
    item2->setScale(1);
        item2->setTag(2);
    CCMenuItemImage* item3= CCMenuItemImage::create(
                                                    "s3.png",
                                                    "s3.png",
                                                    this,
                                                    menu_selector(ShopView::Buy) );
    item3->setPosition( ccp(50,size.height/5*2-100) );
    item3->setScale(1);
        item3->setTag(3);
    CCMenuItemImage* item4= CCMenuItemImage::create(
                                                    "Hummer.png",
                                                    "Hummer.png",
                                                    this,
                                                    menu_selector(ShopView::Buy) );
    item4->setPosition( ccp(50,size.height/5-110) );
    item4->setScale(0.25f);
    item4->setTag(4);
    
        CCLabelTTF* l1=CCLabelTTF::create("パワードリンク","arial",40);
        CCLabelTTF* l2=CCLabelTTF::create("スタミナドリンク","arial",40);
        CCLabelTTF* l3=CCLabelTTF::create("大地の肥料","arial",40);
        CCLabelTTF* l4=CCLabelTTF::create("ハイパーハンマー","arial",40);
    
    l1->setPosition(ccp(size.width/2,size.height/5*4-100));
    l2->setPosition(ccp(size.width/2,size.height/5*3-100));
    l3->setPosition(ccp(size.width/2,size.height/5*2-100));
    l4->setPosition(ccp(size.width/2,size.height/5-100));
    
    this->addChild(l1);
    this->addChild(l2);
    this->addChild(l3);
    this->addChild(l4);
    
    CCLabelTTF* p1=CCLabelTTF::create("¥600","arial",40);
    CCLabelTTF* p2=CCLabelTTF::create("¥500","arial",40);
    CCLabelTTF* p3=CCLabelTTF::create("¥3000","arial",40);
    CCLabelTTF* p4=CCLabelTTF::create("¥5000","arial",40);
    
    p1->setPosition(ccp(size.width-50,size.height/5*4-100));
    p2->setPosition(ccp(size.width-50,size.height/5*3-100));
    p3->setPosition(ccp(size.width-60,size.height/5*2-100));
    p4->setPosition(ccp(size.width-60,size.height/5-100));
    
    this->addChild(p1);
    this->addChild(p2);
    this->addChild(p3);
    this->addChild(p4);
    

    CCMenu* pMenu = CCMenu::create(item1,item2,item3,item4, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
}
void ShopView::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
