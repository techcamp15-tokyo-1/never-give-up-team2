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
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(StartView);
};



#endif
