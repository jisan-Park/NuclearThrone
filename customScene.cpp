#include "stdafx.h"
#include "customScene.h"

HRESULT customScene::init()
{
	//maptool set
	MAPMANAGER->load("saveMap1.bmp");
	mouse = RectMake(0,0,64,64);
	return S_OK;
}

void customScene::update()
{
	for (enemy* e : ENEMYMANAGER->getEnemys("custom")) {
		//�� ���ʹ��� update
		e->update();
	}
		

	if (KEYMANAGER->isOnceKeyDown(VK_BACK)) {
		SCENEMANAGER->changeScene("���θ޴���");
	}
	PLAYERMANAGER->update();

	//player �������� camera set
	CAMERAMANAGER->setCameraPoint(
		PLAYERMANAGER->getPlayer()->getPt().x,
		PLAYERMANAGER->getPlayer()->getPt().y);
	

	CAMERAMANAGER->update();

}

void customScene::release()
{
}

void customScene::render()
{
	//Ÿ��
	/*MAPMANAGER->strectchSceneRender(getMemDC());
	PLAYERMANAGER->render(getMemDC());
	Rectangle(getMemDC(), mouse);*/

	MAPMANAGER->strectchSceneRender(getMapDC());
	PLAYERMANAGER->render(getMapDC());

	for (enemy* e : ENEMYMANAGER->getEnemys("custom")) {
		//�� ���ʹ��� update
		e->render(getMapDC());
	}

	Rectangle(getMapDC(), mouse);
	//MAPMANAGER->RectRender(getMapDC());

	_mapBuffer->stretchRender(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, CAMERAMANAGER->getCameraPoint().x, CAMERAMANAGER->getCameraPoint().y, CAMERAMANAGER->getSizeX(), CAMERAMANAGER->getSizeY());
}
