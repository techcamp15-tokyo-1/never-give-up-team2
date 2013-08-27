//
//  TapSprite.h
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/25.
//
//

#ifndef NeverGiveUpTeam_TapSprite_h
#define NeverGiveUpTeam_TapSprite_h

#include "GV.h"

class TapSprite:public CCSprite,public CCTargetedTouchDelegate{
public:
    static TapSprite* create(const char *filename);
    virtual void Enter();
    virtual void Exit();
    virtual bool ccTouchBegan(CCTouch *touch,CCEvent *event);
    virtual void ccTouchMoved(CCTouch *touch,CCEvent *event);
    virtual void ccTouchEnded(CCTouch *touch,CCEvent *event);
    virtual void ccTouchCancelled(CCTouch *touch,CCEvent *event);
};



#endif
