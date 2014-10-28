#include "ScoreScene.h"
#include "Config.h"
#include "TitleScene.h"

Score::Score()
{
}

Score::~Score()
{
}

Scene *Score::createScene()
{
    Scene *scene = Scene::create();
    Layer *layer = Score::create();
    scene->addChild(layer);
    
    return scene;
}

bool Score::init()
{
    if(!Layer::init())
    {
        return false;
    }
    setButton();
    
    showScore();
    
    return true;
}

void Score::showScore()
{
    UserDefault *userDef = UserDefault::getInstance();
    Label *rankingLabel = Label::createWithSystemFont("ランキング", "Arial", 50);
    rankingLabel->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height - 100));
    
    Label *rank1Label = Label::createWithSystemFont("", "Arial", 50);
    Label *rank2Label = Label::createWithSystemFont("", "Arial", 50);
    Label *rank3Label = Label::createWithSystemFont("", "Arial", 50);
    Label *rank4Label = Label::createWithSystemFont("", "Arial", 50);
    Label *rank5Label = Label::createWithSystemFont("", "Arial", 50);
    Label *rank6Label = Label::createWithSystemFont("", "Arial", 50);
    Label *rank7Label = Label::createWithSystemFont("", "Arial", 50);
    Label *rank8Label = Label::createWithSystemFont("", "Arial", 50);
    Label *rank9Label = Label::createWithSystemFont("", "Arial", 50);
    
    rank1Label->setPosition(Vec2(WINSIZE.width/2, rankingLabel->getPosition().y - 100));
    rank2Label->setPosition(Vec2(WINSIZE.width/2, rank1Label->getPosition().y - 100));
    rank3Label->setPosition(Vec2(WINSIZE.width/2, rank2Label->getPosition().y - 100));
    rank4Label->setPosition(Vec2(WINSIZE.width/2, rank3Label->getPosition().y - 100));
    rank5Label->setPosition(Vec2(WINSIZE.width/2, rank4Label->getPosition().y - 100));
    rank6Label->setPosition(Vec2(WINSIZE.width/2, rank5Label->getPosition().y - 100));
    rank7Label->setPosition(Vec2(WINSIZE.width/2, rank6Label->getPosition().y - 100));
    rank8Label->setPosition(Vec2(WINSIZE.width/2, rank7Label->getPosition().y - 100));
    rank9Label->setPosition(Vec2(WINSIZE.width/2, rank8Label->getPosition().y - 100));
    
    this->addChild(rankingLabel);
    this->addChild(rank1Label);
    this->addChild(rank2Label);
    this->addChild(rank3Label);
    this->addChild(rank4Label);
    this->addChild(rank5Label);
    this->addChild(rank6Label);
    this->addChild(rank7Label);
    this->addChild(rank8Label);
    this->addChild(rank9Label);
    
    rank1Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score1")));
    rank2Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score2")));
    rank3Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score3")));
    rank4Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score4")));
    rank5Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score5")));
    rank6Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score6")));
    rank7Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score7")));
    rank8Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score8")));
    rank9Label->setString(StringUtils::format("%d",userDef->getIntegerForKey("Score9")));
}

void Score::changeScore()
{
    UserDefault *userDef = UserDefault::getInstance();
    int score = userDef->getIntegerForKey("Score");
    int rank1 = userDef->getIntegerForKey("Score1");
    int rank2 = userDef->getIntegerForKey("Score2");
    int rank3 = userDef->getIntegerForKey("Score3");
    int rank4 = userDef->getIntegerForKey("Score4");
    int rank5 = userDef->getIntegerForKey("Score5");
    int rank6 = userDef->getIntegerForKey("Score6");
    int rank7 = userDef->getIntegerForKey("Score7");
    int rank8 = userDef->getIntegerForKey("Score8");
    int rank9 = userDef->getIntegerForKey("Score9");
    
    
    if (rank1 < score)
    {
        userDef->setIntegerForKey("Score1", score);
        userDef->setIntegerForKey("Score2", rank1);
        userDef->setIntegerForKey("Score3", rank2);
        userDef->setIntegerForKey("Score4", rank3);
        userDef->setIntegerForKey("Score5", rank4);
        userDef->setIntegerForKey("Score6", rank5);
        userDef->setIntegerForKey("Score7", rank6);
        userDef->setIntegerForKey("Score8", rank7);
        userDef->setIntegerForKey("Score9", rank8);
    }
    else if (rank2 < score)
    {
        userDef->setIntegerForKey("Score2", score);
        userDef->setIntegerForKey("Score3", rank2);
        userDef->setIntegerForKey("Score4", rank3);
        userDef->setIntegerForKey("Score5", rank4);
        userDef->setIntegerForKey("Score6", rank5);
        userDef->setIntegerForKey("Score7", rank6);
        userDef->setIntegerForKey("Score8", rank7);
        userDef->setIntegerForKey("Score9", rank8);
    }
    else if (rank3 < score)
    {
        userDef->setIntegerForKey("Score3", score);
        userDef->setIntegerForKey("Score4", rank3);
        userDef->setIntegerForKey("Score5", rank4);
        userDef->setIntegerForKey("Score6", rank5);
        userDef->setIntegerForKey("Score7", rank6);
        userDef->setIntegerForKey("Score8", rank7);
        userDef->setIntegerForKey("Score9", rank8);
    }
    else if (rank4 < score)
    {
        userDef->setIntegerForKey("Score4", score);
        userDef->setIntegerForKey("Score5", rank4);
        userDef->setIntegerForKey("Score6", rank5);
        userDef->setIntegerForKey("Score7", rank6);
        userDef->setIntegerForKey("Score8", rank7);
        userDef->setIntegerForKey("Score9", rank8);
    }
    else if (rank5 < score)
    {
        userDef->setIntegerForKey("Score5", score);
        userDef->setIntegerForKey("Score6", rank5);
        userDef->setIntegerForKey("Score7", rank6);
        userDef->setIntegerForKey("Score8", rank7);
        userDef->setIntegerForKey("Score9", rank8);
    }
    else if (rank6 < score)
    {
        userDef->setIntegerForKey("Score6", score);
        userDef->setIntegerForKey("Score7", rank6);
        userDef->setIntegerForKey("Score8", rank7);
        userDef->setIntegerForKey("Score9", rank8);
    }
    else if (rank7 < score)
    {
        userDef->setIntegerForKey("Score7", score);
        userDef->setIntegerForKey("Score8", rank7);
        userDef->setIntegerForKey("Score9", rank8);
    }
    else if (rank8 < score)
    {
        userDef->setIntegerForKey("Score8", score);
        userDef->setIntegerForKey("Score9", rank8);
    }
    else if (rank9 < score)
    {
        userDef->setIntegerForKey("Score9", score);
    }
    else
    {
    }
    
}

void Score::resetScore()
{
    UserDefault *userDef = UserDefault::getInstance();

    userDef->setIntegerForKey("Score", 0);
    userDef->setIntegerForKey("Score1", 0);
    userDef->setIntegerForKey("Score2", 0);
    userDef->setIntegerForKey("Score3", 0);
    userDef->setIntegerForKey("Score4", 0);
    userDef->setIntegerForKey("Score5", 0);
    userDef->setIntegerForKey("Score6", 0);
    userDef->setIntegerForKey("Score7", 0);
    userDef->setIntegerForKey("Score8", 0);
    userDef->setIntegerForKey("Score9", 0);
    
}

void Score::setButton()
{
    MenuItem *returnItem = MenuItemImage::create("endbtn_result.png", "endbtn_push.png", CC_CALLBACK_0(Score::resetScore, this));
    returnItem->setPosition(Vec2(WINSIZE.width - 100 ,WINSIZE.height - WINSIZE.height + 50));
    
    Menu *menu1 = Menu::create(returnItem, nullptr);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, Z_Button);
    
    MenuItem *resetItem = MenuItemImage::create("endbtn_result.png", "endbtn_push.png", CC_CALLBACK_0(Score::returnScene, this));
    resetItem->setPosition(Vec2(WINSIZE.width - WINSIZE.width + 100 ,WINSIZE.height - WINSIZE.height + 50));
    
    Menu *menu2 = Menu::create(resetItem, nullptr);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2 ,Z_Button);
    
    Label *returnLabel = Label::createWithSystemFont("リセット", "Arial", 30);
    returnLabel->setPosition(returnItem->getPosition());
    this->addChild(returnLabel, Z_Label);
    
    Label *resetLabel = Label::createWithSystemFont("タイトルへ", "Arial", 30);
    resetLabel->setPosition(resetItem->getPosition());
    this->addChild(resetLabel, Z_Label);
}

void Score::returnScene()
{
    Scene *scene = Title::createScene();
    TransitionScene *effect = TransitionPageTurn::create(0.5, scene, 0);
    Director::getInstance()->replaceScene(effect);
}
