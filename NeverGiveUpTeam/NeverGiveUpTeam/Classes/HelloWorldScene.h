#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "GV.h"

class HelloWorld :public cocos2d::CCLayer
{
public:
    HelloWorld();
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void callback();
    void ccTouchesBegan(CCSet* touches,CCEvent* event);
    void setStatus();
    static string getPower();
    static string getStamina();
    static string getMoney();
    float r,gc,b;
    
    CREATE_FUNC(HelloWorld);
  
};

#endif // __HELLOWORLD_SCENE_H__
