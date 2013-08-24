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
    void BGM_Mute();
    void SE_Mute();
    void BGM_On();
    void SE_On();
    void GoToTitle();
    void Exit();
    void setSetting(bool bgm,bool se);
    
    CREATE_FUNC(SettingView);
    
private:
    bool BGM,SE;
};


#endif
