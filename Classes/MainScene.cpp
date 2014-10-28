#include "MainScene.h"
#include "ItemSprite.h"
#include "Config.h"
#include "ScoreScene.h"

Scene *Main::createScene()
{
    Scene *scene = Scene::create();
    Layer *layer = Main::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool Main::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    gomiConfig();
    
    setSprite();
    
    setSpriteJudge();
    
    setButton();
    
    showDust();

    scheduleUpdate();
    
    setButton();
    
    // タッチイベント
    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(Main::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Main::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Main::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

// ゴミの生成
void Main::showDust()
{
    auto type = static_cast<ItemSprite::GomiType>(_gomiConfigs[0].gomiType);
    auto gomi = ItemSprite::create(type);
    this->addChild(gomi, Z_Dust, tagNumber);
    log("ごみTAG%d",tagNumber);
    tagNumber += 1;
    _gomiConfigs.erase(_gomiConfigs.begin());
}

// ごみをつかむ
bool Main::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    for (int tag = 0 ; tag < tagNumber ; tag++)
    {
        if (deleteList[tag])
        {
            auto item = (Sprite*)getChildByTag(tag);
            if (item->getBoundingBox().containsPoint(touch->getLocation()))
            {
                log("つかむ！TAG%d",tag);
                item->setLocalZOrder(Z_GetItem);
                item->stopAllActions();
                useTag = tag;
                return true;
            }
        }
    }
    return false;
}

// ごみを移動させる
void Main::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    getChildByTag(useTag)->Node::setPosition(getChildByTag(useTag)->getPosition() + touch->getDelta());
}

// 離すとゴミが消える,ゴミ箱に落とすと加点
void Main::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    auto box1 = getChildByTag(DUSTBOX_TAG_1)->boundingBox();
    auto box2 = getChildByTag(DUSTBOX_TAG_2)->boundingBox();
    auto box3 = getChildByTag(DUSTBOX_TAG_3)->boundingBox();
    auto gomi = getChildByTag(useTag)->getPosition();
    
    if (box1.containsPoint(gomi) && types[useTag] == 1)
    {
        getChildByTag(DUSTBOX_TAG_1)->runAction(action2());
        scoreCaric();
    }
    else if (box2.containsPoint(gomi) && types[useTag] == 2)
    {
        getChildByTag(DUSTBOX_TAG_2)->runAction(action2());
        scoreCaric();
    }
    else if (box3.containsPoint(gomi) && types[useTag] == 3)
    {
        getChildByTag(DUSTBOX_TAG_3)->runAction(action2());
        scoreCaric();
    }
    else
    {
        dustCount = 0;
    }
    
    getChildByTag(useTag)->runAction(action1());
}

void Main::setSprite()
{
    Sprite *gomiBoxItem1 = Sprite::create("gomiBox1.png");
    gomiBoxItem1->setPosition(Vec2(WINSIZE.width/2, WINSIZE.height/2 + WINSIZE.height/3));
    this->addChild(gomiBoxItem1, Z_Dust, DUSTBOX_TAG_1);
    
    Sprite *gomiBoxItem2 = Sprite::create("gomiBox2.png");
    gomiBoxItem2->setPosition(Vec2(WINSIZE.width/2 + WINSIZE.width/3, WINSIZE.height/2 + WINSIZE.height/4));
    this->addChild(gomiBoxItem2, Z_Dust, DUSTBOX_TAG_2);
    
    Sprite *gomiBoxItem3 = Sprite::create("gomiBox3.png");
    gomiBoxItem3->setPosition(Vec2(WINSIZE.width/2 - WINSIZE.width/3, WINSIZE.height/2 + WINSIZE.height/4));
    this->addChild(gomiBoxItem3, Z_Dust, DUSTBOX_TAG_3);
}

// 画像の取得判定用
void Main::setSpriteJudge()
{
    for (int tagJudge = tagNumber ; tagJudge < SPRITEMOUNT + 1 ; tagJudge++)
    {
        deleteList.push_back(true);
    }
}
// ボタンの配置
void Main::setButton()
{
    // 終了ボタン
    MenuItem *endItem = MenuItemImage::create("endbtn_result.png", "endbtn_push.png", CC_CALLBACK_1(Main::gameEnd, this));
    endItem->setPosition(Vec2(WINSIZE.width/2 + WINSIZE.width/4, WINSIZE.height/2 - WINSIZE.height/2.5 -50));
    Menu *menu1 = Menu::create(endItem, nullptr);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, Z_Button);
    
    // リスタートボタン
    MenuItem *restartItem = MenuItemImage::create("startbtn_result.png", "startbtn_push.png", CC_CALLBACK_0(Main::restart, this));
    restartItem->setPosition(Vec2(WINSIZE.width/2 + WINSIZE.width/4, WINSIZE.height/2 - WINSIZE.height/2.5));
    Menu *menu2 = Menu::create(restartItem, nullptr);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2, Z_Button);
    
    // スコアボタン
    MenuItem *scoreItem = MenuItemImage::create("startbtn_result.png", "startbtn_push.png", CC_CALLBACK_0(Main::showScore, this));
    scoreItem->setPosition(Vec2(WINSIZE.width/2 + WINSIZE.width/4, WINSIZE.height/2 - WINSIZE.height/2.5 - 100));
    Menu *menu3 = Menu::create(scoreItem, nullptr);
    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, Z_Button);
    
    Label *endLabel = Label::createWithSystemFont("終了", "Arial", 30);
    endLabel->setPosition(endItem->getPosition());
    this->addChild(endLabel, Z_Label);
    
    Label *restartLabel = Label::createWithSystemFont("リスタート", "Arial", 30);
    restartLabel->setPosition(restartItem->getPosition());
    this->addChild(restartLabel, Z_Label);
    
    Label *scoreLabel = Label::createWithSystemFont("ランキング", "Arial", 30);
    scoreLabel->setPosition(scoreItem->getPosition());
    this->addChild(scoreLabel, Z_Label);
}

// 更新
void Main::update(float dt)
{
    time += dt;

    removeChildByTag(T_Label1);
    scoreLabel();
    
    // ゴミの表示判定
    if (_gomiConfigs.size() > 0 &&
        _gomiConfigs[0].appearanceTime <= time)
    {
        showDust();
    }

    // 真理値の変更
    if (deleteTag <= SPRITEMOUNT && getChildByTag(deleteTag)->getScale() == 0)
    {
        removeChildByTag(deleteTag);
        deleteList[deleteTag] = false;
        deleteTag += 1;
    }
    
    // 真理値、カウント初期化
    if (deleteTag <= SPRITEMOUNT && getChildByTag(deleteTag)->getPosition().x <= -50)
    {
        removeChildByTag(deleteTag);
        deleteList[deleteTag] = false;
        dustCount = 0;
        deleteTag += 1;
    }
    
    if (deleteTag == SPRITEMOUNT)
    {
        UserDefault *userDef = UserDefault::getInstance();
        userDef->setIntegerForKey("Score", score);
        userDef->flush();
    }
    
}

// ゴミのタイプ、出現時間の設定
void Main::gomiConfig()
{
    GomiConfig gomi;
    for (int count = 0; count < SPRITEMOUNT + 1; count++)
    {
        std::random_device rd;
        std::mt19937 rand = std::mt19937(rd());
        int random = std::uniform_int_distribution<int>(1,3)(rand);
        
        gomi.gomiType = random;
        gomi.appearanceTime = count + 0.5;
        _gomiConfigs.push_back(gomi);
        types.push_back(random);
    }
}

// スコアの加点
void Main::scoreCaric()
{
    dustCount += 1;
    if (dustCount < 10)
    {
        score += 10;
    }
    else if (dustCount < 20)
    {
        score += 50;
    }
    else if (dustCount < 30)
    {
        score += 100;
    }
    else if (dustCount < 40)
    {
        score += 200;
    }
    else if (dustCount < 50)
    {
        score += 500;
    }
    else if (dustCount < 60)
    {
        score += 1000;
    }
    else if (dustCount < 65)
    {
        score += 3000;
    }
    else
    {
        score *= 1.25;
    }
    log("スコア:%d",score);
}

// スコア表示
void Main::scoreLabel()
{
    Label *label = Label::createWithSystemFont("", "Arial", 50);
    label->setPosition(Vec2(WINSIZE.width/2 + WINSIZE.width/4, WINSIZE.height/2 - WINSIZE.height/3));
    this->addChild(label, Z_Label, T_Label1);
    
    label->setString(StringUtils::format("スコア:%d点",score));
}

Action *Main::action1()
{
    ActionInterval *scale = ScaleTo::create(0.2f, 0);
    return scale;
}

Action *Main::action2()
{
    ActionInterval *rotate1 = RotateTo::create(0.05f, 1);
    ActionInterval *ease1   = EaseInOut::create(rotate1, 0.05);
    ActionInterval *rotate2 = RotateTo::create(0.05f, -1);
    ActionInterval *ease2   = EaseInOut::create(rotate2, 0.05);
    ActionInterval *rotate3 = RotateTo::create(0.05f, 0);
    ActionInterval *ease3   = EaseInOut::create(rotate3, 0.05);
    ActionInterval *seq1    = Sequence::create(ease1, ease2, ease3, nullptr);
    ActionInterval *rep1    = Repeat::create(seq1, 1);
    
    return Repeat::create(rep1, 2);
}

void Main::restart()
{
    Score::changeScore();
    Scene *scene = Main::createScene();
    TransitionScene *effect = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(effect);
    log("リスタート");
}

void Main::showScore()
{
    Score::changeScore();
    Scene *scene = Score::createScene();
    TransitionScene *effect = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(effect);
    log("リスタート");
}

void Main::gameEnd(cocos2d::Ref *pSender)
{
    unscheduleUpdate();
    log("Update終了");
    Score::changeScore();
    Director::getInstance()->end();
    exit(0);
}
