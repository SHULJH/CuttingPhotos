#include "HelloWorldScene.h"
#include <CuttingPhotos.h>
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	CuttingPhotos *photo = CuttingPhotos::create("2.jpeg", 3, 3);
	photo->setAnchorPoint(Vec2(0, 0));

	auto size = photo->getContentSize();
	photo->setPosition(visibleSize.width/2 - size.width/2, visibleSize.height/2 - size.height/2);

	addChild(photo);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
