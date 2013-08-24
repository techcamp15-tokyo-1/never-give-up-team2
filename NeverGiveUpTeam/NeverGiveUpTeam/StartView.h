//
//  StartView.h
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//
#ifndef NeverGiveUpTeam_StartView_h
#define NeverGiveUpTeam_StartView_h

#include "GV.h"
class StartView : public cocos2d::CCLayer
{
public:
    StartView();
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void next(const int s);
    void ccTouchesBegan(CCSet* touches,CCEvent* event);
    CREATE_FUNC(StartView);
};



#endif
