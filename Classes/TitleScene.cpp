#include "TitleScene.h"
#include "Config.h"
#include "MainScene.h"

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
    
    Menu *start = Menu::create(startItem, NULL);
    start->setPosition(Vec2::ZERO);
    this->addChild(start, Z_Button);
    
    MenuItem *endItem = MenuItemImage::create("endbtn_result.png", "endbtn_push.png", CC_CALLBACK_1(Title::gameEnd, this));
    endItem->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/3 - WINSIZE.height/6));
    
    Menu *end = Menu::create(endItem, NULL);
    end->setPosition(Vec2::ZERO);
    this->addChild(end, Z_Button);
}

void Title::gameStart()
{
    Scene *scene = Main::createScene();
    TransitionScene *effect = TransitionPageTurn::create(0.5, scene, 0);
    Director::getInstance()->replaceScene(effect);
}

void Title::gameEnd(cocos2d::Ref *pSender)
{
    Director::getInstance()->end();
    exit(0);
}
