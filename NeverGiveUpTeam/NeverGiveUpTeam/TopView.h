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
    void hit(CCMenuItemImage* image,CCSet* set);
    void ccTouchesBegan(CCSet* touches,CCEvent* event);
    void ccTouchesMoved(CCSet* touches,CCEvent* event);
    void Dec_Stamina(const int consume);
    void fall();
    string getNameNum(const int num);
    int k[24][1];
    CREATE_FUNC(TopView);

};



#endif
