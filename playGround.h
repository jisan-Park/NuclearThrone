#pragma once
#include "gameNode.h"
#include "StartScene.h"
#include "mainmenuScene.h"
#include "settingScene.h"
#include "maptoolScene.h"
#include "gameScene.h"
#include "customScene.h"
class playGround : public gameNode
{
private:

public:
	playGround();
	~playGround();

	virtual HRESULT init();	//�ʱ�ȭ ���� �Լ�
	virtual void release();	//�޸� ���� �Լ�
	virtual void update();	//���� ����
	virtual void render();	//�׸��� ����
};