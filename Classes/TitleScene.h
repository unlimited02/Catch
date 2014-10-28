#ifndef __Catch__TitleScene__
#define __Catch__TitleScene__

#include "cocos2d.h"

USING_NS_CC;

class Title : public cocos2d::Layer
{
private:
    enum Tag
    {
        
    };
    enum ZOder
    {
        Z_Bg = 0,
        Z_Button,
        Z_Label,
    };
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void setButton();
    
    virtual void gameStart();
    virtual void gameScore();
    virtual void gameEnd(cocos2d::Ref *pSender);
    
    
    CREATE_FUNC(Title);
};

#endif /* defined(__Catch__TitleScene__) */
