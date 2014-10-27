#ifndef __Catch__ItemSprite__
#define __Catch__ItemSprite__

#include "cocos2d.h"

USING_NS_CC;

class ItemSprite : public cocos2d::Sprite
{
private:
    enum GomiType
    {
        Type1 = 1,
        Type2,
        Type3,
    };
    
public:
    virtual bool init();
    void setSprite();
    
    GomiType _gomiType;
    ItemSprite(GomiType gomitype);
    static ItemSprite* create(GomiType gomitype);
    
    Action *getAction1();
};

#endif /* defined(__Catch__ItemSprite__) */
