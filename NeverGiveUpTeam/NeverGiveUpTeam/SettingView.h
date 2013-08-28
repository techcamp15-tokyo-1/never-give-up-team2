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
    void BGM_Off();
    void SE_Off();
    void VIBE_Off();
    void VIBE_On();
    void BGM_On();
    void NET_On();
    void NET_Off();
    void SE_On();
    void GoToTitle();
    void Exit();
    void switchCallBack(CCMenuItemImage* object);
    void News();
    
    CREATE_FUNC(SettingView);
    
private:
    bool BGM,SE;
};


#endif
