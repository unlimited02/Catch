#include "ItemSprite.h"
#include "Config.h"

ItemSprite::ItemSprite(GomiType gomitype)
: _gomiType(gomitype)
{
}

ItemSprite *ItemSprite::create(GomiType gomitype)
{
    auto gomi = new ItemSprite(gomitype);
    gomi->init();
    gomi->autorelease();
    
    return gomi;
}

bool ItemSprite::init()
{
    if(!Sprite::init())
    {
        return false;
    }
    
    std::string filename;
    switch (_gomiType)
    {
        case Type1:
            filename = "gomiItem1.png";
            break;
        case Type2:
            filename = "gomiItem2.png";
            break;
        default:
            filename = "gomiItem3.png";
            break;
    }
    
    if (!Sprite::initWithFile(filename))
    {
        return false;
    }
    
    Vec2 pos = Vec2(DUST_DEFAULT_X, DUST_DEFAULT_Y);
    Action *gomiAction = getAction1();
    
    setPosition(pos);
    runAction(gomiAction);
    
    return true;
}

Action *ItemSprite::getAction1()
{
    ActionInterval *move1;
    
    std::random_device rd;
    std::mt19937 rand = std::mt19937(rd());
    int random = std::uniform_int_distribution<int>(0,4)(rand);

    switch (random) {
        case 0: move1 = MoveTo::create(random + 5, Vec2(DUST_OUT_X, DUST1_Y)); break;
        case 1: move1 = MoveTo::create(random + 5, Vec2(DUST_OUT_X, DUST2_Y)); break;
        case 2: move1 = MoveTo::create(random + 5, Vec2(DUST_OUT_X, DUST3_Y)); break;
        case 3: move1 = MoveTo::create(random + 5, Vec2(DUST_OUT_X, DUST4_Y)); break;
        default: move1 = MoveTo::create(random + 5, Vec2(DUST_OUT_X, DUST5_Y)); break;
    }
    return move1;
}
