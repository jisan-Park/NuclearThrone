#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);  

	SCENEMANAGER->addScene("���۾�", new StartScene);
	SCENEMANAGER->addScene("���θ޴���", new mainmenuScene);

	SCENEMANAGER->addScene("���Ӿ�", new gameScene);
	SCENEMANAGER->addScene("Ŀ���Ҿ�", new customScene);
	SCENEMANAGER->addScene("������", new maptoolScene);
	SCENEMANAGER->addScene("���þ�", new settingScene);


	SCENEMANAGER->changeScene("���۾�");

	return S_OK;
}


void playGround::release()
{
	gameNode::release();
}

void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ ���� �ǵ��� ���� ==============================

	SCENEMANAGER->render();

	if (KEYMANAGER->isToggleKey(VK_TAB)) {
		TIMEMANAGER->render(getMemDC());
	}
	//================= �Ʒ��� �ǵ��� ���� ==============================
	_backBuffer->render(getHDC());
}