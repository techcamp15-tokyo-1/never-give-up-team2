//
//  SettingView.h
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#ifndef NeverGiveUpTeam_SettingView_h
#define NeverGiveUpTeam_SettingView_h

#include "GV.h"
class SettingView : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void next();
    CREATE_FUNC(SettingView);
};


#endif
