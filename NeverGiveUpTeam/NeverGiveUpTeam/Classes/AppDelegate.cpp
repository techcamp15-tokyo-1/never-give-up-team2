//
//  NeverGiveUpTeamAppDelegate.cpp
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#include "GV.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
    
    
   // if(getBGM())
        SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0);
   // }else{
      //  SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0);
   // }
   // if(this->getSE()){
        SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
    //}else{
    //    SimpleAudioEngine::sharedEngine()->setEffectsVolume(0);
    //}
    
    //音楽データをプリロード
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("top.mp3");
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("start.mp3");
     CCLog("First Ok");

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::getBGM(){
    //set Setting Data From SharedPriference
   // CCUserDefault* user=CCUserDefault::sharedUserDefault();
   // bool BGM=user->getBoolForKey("BGM_KEY",true);
    return true;
}
bool AppDelegate::getSE(){
   // CCUserDefault* user1=CCUserDefault::sharedUserDefault();
   // bool SE=user1->getBoolForKey("SE_KEY",true);
    return true;
    
}
bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
   
    // create a scene. it's an autorelease object
    CCLog("AppDelegate Ok");
    CCScene *pScene = HelloWorld::scene();
    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
