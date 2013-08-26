//
//  TapSprite.cpp
//  NeverGiveUpTeam
//
//  Created by AKIE SAMU on 2013/08/25.
//
//


#include "GV.h"

TapSprite* TapSprite::create(const char* filename){
    TapSprite *sprite=new TapSprite();
    if(sprite && sprite->initWithFile(filename)){
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}

void TapSprite::Enter(){
    CCSprite::onEnter();
    CCTouchDispatcher* disp=CCDirector::sharedDirector()->getTouchDispatcher();
    disp->addTargetedDelegate(this,0,true);
}
void TapSprite::Exit(){
    CCSprite::onExit();
    CCTouchDispatcher* disp=CCDirector::sharedDirector()->getTouchDispatcher();
    disp->addTargetedDelegate(this,0,true);
}
bool TapSprite::ccTouchBegan(CCTouch *touch,CCEvent *event){
    CCPoint point=touch->getLocation();
    CCSize size=this->getTexture()->getContentSize();
    CCRect rect=CCRectMake(this->getPositionX()-size.width/2, this->getPositionY()-size.height/2,size.width, size.height);
    return rect.containsPoint(point);
}
void TapSprite::ccTouchMoved(CCTouch *touch,CCEvent *event){
    CCPoint point =touch->getLocation();
    this->setPosition(point);
}
void TapSprite::ccTouchEnded(CCTouch *touch,CCEvent *event){
    //End of Touch
}
void TapSprite::ccTouchCancelled(CCTouch *touch,CCEvent *event){
    //Cancel of touch
}