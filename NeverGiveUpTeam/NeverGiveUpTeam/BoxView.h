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
#include "XTLayer.h"

class BoxView : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void next();
    void sell(const int Price);
/*
    virtual void xtTouchesBegan(cocos2d::CCSet* _touches, cocos2d::CCEvent* event);
    virtual void xtTouchesMoved(cocos2d::CCSet* _touches, cocos2d::CCEvent* event);
    virtual void xtTouchesEnded(cocos2d::CCSet* _touches, cocos2d::CCEvent* event);
    virtual void xtTouchesBegan(CCPoint position);
    virtual void xtTouchesMoved(CCPoint position);
    virtual void xtTouchesEnded(CCPoint position);
    virtual void xtTapGesture(CCPoint position);
    virtual void xtDoubleTapGesture(CCPoint position);
    virtual void xtLongTapGesture(CCPoint position);
 */
    
    //void xtSwipeGesture(XTTouchDirection direction, float distance, float speed);
    
    CREATE_FUNC(BoxView);
};


#endif
