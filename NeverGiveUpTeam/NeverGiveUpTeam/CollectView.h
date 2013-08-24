//
//  CollectView.h
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#ifndef NeverGiveUpTeam_CollectView_h
#define NeverGiveUpTeam_CollectView_h
#include "GV.h"
class CollectView : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void next();
    CREATE_FUNC(CollectView);
};



#endif
