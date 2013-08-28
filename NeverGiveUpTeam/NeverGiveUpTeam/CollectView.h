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
    void setImage();
    void CollectScene(CCMenuItemImage* image);
    CREATE_FUNC(CollectView);
    bool set,set2;
};



#endif
