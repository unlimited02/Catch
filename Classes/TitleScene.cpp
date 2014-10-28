#include "TitleScene.h"
#include "Config.h"
#include "MainScene.h"
#include "ScoreScene.h"

Scene *Title::createScene()
{
    Scene *scene = Scene::create();
    Layer *layer = Title::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool Title::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    setButton();
    
    return true;
}

// ボタンの配置
void Title::setButton()
{
    MenuItem *startItem = MenuItemImage::create("startbtn_result.png", "startbtn_push.png", CC_CALLBACK_0(Title::gameStart, this));
    startItem->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/3));
    
    Menu *start = Menu::create(startItem, nullptr);
    start->setPosition(Vec2::ZERO);
    this->addChild(start, Z_Button);
    
    MenuItem *endItem = MenuItemImage::create("endbtn_result.png", "endbtn_push.png", CC_CALLBACK_1(Title::gameEnd, this));
    endItem->setPosition(Vec2(WINSIZE.width/2, startItem->getPosition().y - WINSIZE.height/10));
    
    Menu *end = Menu::create(endItem, nullptr);
    end->setPosition(Vec2::ZERO);
    this->addChild(end, Z_Button);
    
    MenuItem *scoreItem = MenuItemImage::create("endbtn_result.png", "endbtn_push.png", CC_CALLBACK_0(Title::gameScore, this));
    scoreItem->setPosition(Vec2(WINSIZE.width/2, endItem->getPosition().y - WINSIZE.height/10));
    
    Menu *score = Menu::create(scoreItem, nullptr);
    score->setPosition(Vec2::ZERO);
    this->addChild(score, Z_Button);
    
    Label *startLabel = Label::createWithSystemFont("スタート", "Arial", 30);
    startLabel->setPosition(startItem->getPosition());
    this->addChild(startLabel, Z_Label);
    
    Label *endLabel = Label::createWithSystemFont("終了", "Arial", 30);
    endLabel->setPosition(endItem->getPosition());
    this->addChild(endLabel, Z_Label);
    
    Label *scoreLabel = Label::createWithSystemFont("ランキング", "Arial", 30);
    scoreLabel->setPosition(scoreItem->getPosition());
    this->addChild(scoreLabel, Z_Label);
}

void Title::gameStart()
{
    Scene *scene = Main::createScene();
    TransitionScene *effect = TransitionPageTurn::create(0.5, scene, 0);
    Director::getInstance()->replaceScene(effect);
}

void Title::gameScore()
{
    Scene *scene = Score::createScene();
    TransitionScene *effect = TransitionPageTurn::create(0.5, scene, 0);
    Director::getInstance()->replaceScene(effect);
}

void Title::gameEnd(cocos2d::Ref *pSender)
{
    Director::getInstance()->end();
    exit(0);
}
