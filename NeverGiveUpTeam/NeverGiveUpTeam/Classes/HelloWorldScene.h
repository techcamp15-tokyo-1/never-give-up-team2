#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "GV.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void callback();
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
