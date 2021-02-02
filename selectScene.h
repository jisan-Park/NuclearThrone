#pragma once
#include "gameNode.h"
class selectScene : public gameNode
{
private:

public:
	HRESULT init();
	void update();
	void release();
	void render();
};

