#ifndef __Catch__MainScene__
#define __Catch__MainScene__

#include "cocos2d.h"
#include "ItemSprite.h"

USING_NS_CC;

class Main : public cocos2d::Layer
{
private:
    std::deque<bool> deleteList;
    
    float time;
    float _time;
    float saveTime;
    
    int tagNumber = 0;
    int deleteTag = 0;
    int useTag;
    int score = 0;
    int dustCount = 0;
    
    enum Tag
    {
        T_Dust  = 1001,
        T_Item1,
        T_Label1
    };
    
    enum ZOrder
    {
        Z_Dust  = 0,
        Z_Item1,
        Z_GetItem,
        Z_Label,
    };
    
    struct GomiConfig
    {
        int gomiType;
        float appearanceTime;
    };
    
public:
    std::vector<GomiConfig> _gomiConfigs;
    std::vector<int> types;
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    static Action* action1();
    static Action* action2();

    void showDust();
    void setSprite();
    void setSpriteJudge();
    void gomiConfig();
    void scoreCaric();
    void scoreLabel();
    
    virtual void update(float dt);
    virtual void restart();
    virtual void gameEnd(cocos2d::Ref *pSender);
    
    CREATE_FUNC(Main);
};

#endif /* defined(__Catch__MainScene__) */
