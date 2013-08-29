//
//  ShopView.h
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/23.
//
//

#ifndef NeverGiveUpTeam_ShopView_h
#define NeverGiveUpTeam_ShopView_h

#include "GV.h"
class ShopView : public cocos2d::CCLayer
{
public:
    ShopView();
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void next();
    bool Buy(CCMenuItemImage* image);
    bool Buy_Cancel();
    void Save(const int money);
    void SetMarchandice();
    
    
    CREATE_FUNC(ShopView);
};


#endif
