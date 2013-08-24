//
//  BoxView.h
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#ifndef NeverGiveUpTeam_BoxView_h
#define NeverGiveUpTeam_BoxView_h

#include "GV.h"
class BoxView : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void next();
    CREATE_FUNC(BoxView);
};


#endif
