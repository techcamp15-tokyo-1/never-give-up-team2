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
    //乱数初期シード
    srand((unsigned)time(NULL));
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);
    //画面サイズ取得
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* back=CCSprite::create("MainBackGroundSpring.png");
    back->setPosition(ccp(size.width/2,size.height/2));
    back->setScale(2.0f);
    this->addChild(back);
  
    //Menu ここから
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(TopView::next) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 25, size.height-25) );
    pCloseItem->setScale(2.0);
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
   //スタミナ切れるまででれない
    // this->addChild(pMenu, 1);
    //ここまで
    
      
    //ステータスバー
    CCSprite* state=CCSprite::create("state.png");
    
       
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
    
       
    CCSprite* tree =CCSprite::create("kunugi1.png");//Picture of Tree
    
    //叩く画像
    CCSprite* foot;
    //もしハンマーを買った事があれば
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    if(user->getBoolForKey("hummer")){
        foot=CCSprite::create("Hummer.png");
        foot->setScale(0.5f);
        foot->setPosition(ccp(size.width,size.height/3));
        foot->setTag(1);
    }else{
    foot=CCSprite::create("FootStart.png");
    foot->setScale(0.25f);
    foot->setPosition(ccp(size.width,size.height/3));
    foot->setTag(1);
    }
        
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
    int s=user->getIntegerForKey("stamina");
/*    if(s<=0){
        CCMessageBox("スタミナは時間経過、または回復アイテムで回復することができます","スタミナ切れ！");
        CCScene* next=StartView::scene();
        float duration=0.5f;
        CCScene* pScene=CCTransitionFade::create(duration,next);
        if(pScene){
            
            SimpleAudioEngine::sharedEngine()->sharedEngine()->stopBackgroundMusic();
            CCDirector::sharedDirector()->replaceScene(pScene);
        }

    }
 */
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
string TopView::getNameNum(const int num){
    switch(num){
        case 1:return "トノサマバッタ"; break;
        case 2:return "バッタ";break;
        case 3:return "ノコギリクワガタ";break;
        case 4:return "りんご";break;
        case 5:return "ヘラクレスオオカブト";break;
        case 6:return "ヒラタクワガタ";break;
        case 7:return "カマキリ";break;
        case 8:return "松ぼっくり";break;
        case 9:return "セミ";break;
        case 10:return "セミの抜け殻";break;
        case 11:return "パイナップル";break;
        case 12:return "モモ";break;
        case 13:return "メロン";break;
        case 14:return "なまけもの";break;
        case 15:return "ギラファオオクワガタ";break;
        case 16:return "スイカ";break;
        case 17:return "たわし";break;
        case 18:return "りんご";break;
        case 19:return "バナナ";break;
        case 20:return "コーカサスオオカブト";break;
        case 21:return "眼鏡";break;
        case 22:return "コアラ";break;
        case 23:return "トカゲ";break;
         }
}

void TopView::ccTouchesMoved(CCSet* touches,CCEvent* event){
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    //スタミナ取得
    int s=user->getIntegerForKey("stamina");
    
    string str="";
    string forstring;
    ostringstream oss;
       int setnum=0;
    
    //もしスタミナがきれたら
    if(s<=0){
        //各種保持データの保存
        for(int i=0;i<23;i++){
            string s="";
            ostringstream ostring;//stream 宣言
            ostring<<(i);//i+1をstreamに代入
            s=ostring.str();
            user->setIntegerForKey(s.c_str(),k[i][0]);
            CCLog("s=%s,k[%d]=%d",s.c_str(),i,k[i][0]);
            user->flush();
        }
        
       string numstr="";
        for(int i=0;i<23;i++){
            
            string s="";
            ostringstream ostring;//stream 宣言
            ostring<<(i);//i+1をstreamに代入
            s=ostring.str();
            setnum=user->getIntegerForKey(s.c_str());
            CCLog("setnum=%d",setnum);

         //   numstr="";
            if(setnum>0){
                
                str+=getNameNum(i);
                str+=" ×";
                oss<<setnum;
                numstr=oss.str();
                str+=numstr;
                str+="\n";
                oss.str("");
                CCLog("str=%s",str.c_str());
            }
        }
        

        
        CCMessageBox("スタミナは時間経過、または回復アイテムで回復することができます","スタミナ切れ！");
        CCMessageBox(str.c_str(),"獲得！");
        CCScene* next=StartView::scene();
        float duration=1.0f;
        CCScene* pScene=CCTransitionFade::create(duration,next);
        if(pScene){
            SimpleAudioEngine::sharedEngine()->sharedEngine()->stopBackgroundMusic();
            CCDirector::sharedDirector()->replaceScene(pScene);
        }
    }
    if(0<=user->getIntegerForKey("stamina")){
    CCSprite* player=(CCSprite*)this->getChildByTag(1);
    CCSprite* tree=(CCSprite *)this->getChildByTag(2);

    CCTouch* touch=(CCTouch*)touches->anyObject();
    CCPoint location=touch->getLocationInView();
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    location.y=size.height-location.y;
    
    //player->getPositionX() //GodMode
    if(player->getPositionX()<=(tree->getPositionX()+tree->getContentSize().width/2)*0.35f){
        
        CCLog("tree hit");
        //ものを降らせる
        fall();
        //効果音を再生する
        SimpleAudioEngine::sharedEngine()->playEffect("keri.mp3");
        float duration=1.0;
        
        CCMoveTo* move=CCMoveTo::create(duration,ccp(size.width/3*2,player->getPositionY()));
        player->runAction(move);
        
        int stamina=atoi(HelloWorld::getStamina().c_str());
        if(stamina>0){
            stamina-=1;
        }
        user->setIntegerForKey("stamina",stamina);
        user->flush();
  //スタミナ現象を更新する
        CCLabelTTF* staminaImage=(CCLabelTTF *)this->getChildByTag(5);
        CCString* str=CCString::createWithFormat("%d",stamina);
        staminaImage->setString(str->getCString());
              
    }else{
         player->setPosition(location);
    }
    }
}

void TopView::fall(){
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();

    float duration=1.0f;
    float x=0,y=0;
    CCSprite* falls;
    int num=(rand()%20+1);
    
    CCUserDefault* user=CCUserDefault::sharedUserDefault();
    if(num==1){
        k[num][0]++;
        user->setBoolForKey("i1",true);
        user->flush();
        falls=CCSprite::create("1.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==2){
                k[num][0]++;
        user->setBoolForKey("i2",true);
        user->flush();

             falls=CCSprite::create("2.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==3){
                k[num][0]++;
        user->setBoolForKey("i5",true);
        user->flush();

            falls=CCSprite::create("3.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==4){
                k[num][0]++;
        user->setBoolForKey("m7",true);
        user->flush();
            falls=CCSprite::create("4.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==5){
                k[num][0]++;
        user->setBoolForKey("i9",true);
        user->flush();

        falls=CCSprite::create("5.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==6){
                k[num][0]++;
        user->setBoolForKey("i3",true);
        user->flush();

        falls=CCSprite::create("6.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==7){
                k[num][0]++;
        user->setBoolForKey("i12",true);
        user->flush();

        falls=CCSprite::create("7.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==8){
                k[num][0]++;
        falls=CCSprite::create("8.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==9){
                k[num][0]++;
        user->setBoolForKey("i11",true);
        user->flush();

        falls=CCSprite::create("9.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==10){
                k[num][0]++;
        user->setBoolForKey("i10",true);
        user->flush();

        falls=CCSprite::create("10.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==11){
                k[num][0]++;
        user->setBoolForKey("m8",true);
        user->flush();
        falls=CCSprite::create("11.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==12){
                k[num][0]++;
        falls=CCSprite::create("12.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==13){
                k[num][0]++;
        user->setBoolForKey("m4",true);
        user->flush();
        falls=CCSprite::create("13.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==14){
                k[num][0]++;
        falls=CCSprite::create("14.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==15){
                k[num][0]++;
        user->setBoolForKey("i6",true);
        user->flush();

        falls=CCSprite::create("15.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==16){
                k[num][0]++;
        user->setBoolForKey("m3",true);
        user->flush();
        falls=CCSprite::create("16.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==17){
                k[num][0]++;
        falls=CCSprite::create("17.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==18){
                k[num][0]++;
        falls=CCSprite::create("18.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==19){
                k[num][0]++;
        user->setBoolForKey("m1",true);
        //user->flush();
        falls=CCSprite::create("19.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==20){
                k[num][0]++;
        user->setBoolForKey("i8",true);
        user->flush();

        falls=CCSprite::create("20.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }
    else if(num==21){
                k[num][0]++;
        falls=CCSprite::create("21.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==22){
                k[num][0]++;
        falls=CCSprite::create("22.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }else if(num==23){
            k[num][0]++;
        falls=CCSprite::create("23.png");
        x=rand()%320;
        y=rand()%100+size.height;
        //      falls->setScale(0.75f);
        falls->setPosition(ccp((float)x,(float)y));
        CCActionInterval* action=CCMoveTo::create(duration,ccp(x,20));
        CCActionInterval* ease=CCEaseInOut::create(action,1.25f);
        falls->runAction(ease);
        this->addChild(falls);
    }
    
        
}

void TopView::menuCloseCallback(CCObject* pSender){
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
