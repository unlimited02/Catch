#ifndef __Catch__ScoreScene__
#define __Catch__ScoreScene__

#include "cocos2d.h"

USING_NS_CC;

class Score : public cocos2d::Layer
{
private:
    std::vector<int> scores;
    
    enum ZOrder
    {
        Z_Bg = 0,
        Z_Button,
        Z_Label,
    };
    
public:
    Score();
    virtual ~Score();
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void showScore();
    void resetScore();
    static void changeScore();
    void setButton();
    
    virtual void returnScene();
    
    CREATE_FUNC(Score);
};

#endif /* defined(__Catch__ScoreScene__) */
