#pragma once
#include <cocos2d.h>

USING_NS_CC;

class CuttingPhotos :public Layer {
	CuttingPhotos();
	virtual ~CuttingPhotos();
public:
	static CuttingPhotos *create(const char *photo, unsigned int rows = 3, unsigned int columns = 3);

protected:
	unsigned int _rows;
	unsigned int _columns;
	unsigned int _sliceWidth;
	unsigned int _sliceHeight;

	std::vector<std::vector<Sprite*>> _slices;

	virtual bool initWithPhoto(const char *photo, unsigned int rows = 3, unsigned int columns = 3);

	bool initSlices(const char *photo);

	void initTouchEventListener();

	void move(int x, int y);

public:
	void restart();
};