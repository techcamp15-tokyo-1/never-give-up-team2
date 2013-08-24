//
//  TopView.h
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#ifndef NeverGiveUpTeam_TopView_h
#define NeverGiveUpTeam_TopView_h
#include "GV.h"
class TopView : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void next();
    CREATE_FUNC(TopView);
};



#endif
