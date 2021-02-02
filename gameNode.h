#pragma once
#include "image.h"

//����۶�� �� ��Ʈ�� �̹����� �ϳ� �����صд�
static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", 1920, 1920);
//����۶�� �� ��Ʈ�� �̹����� �ϳ� �����صд�
static image* _mapBuffer = IMAGEMANAGER->addImage("mapBuffer", 1920, 1920);


class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;		//�Ŵ��� �ʱ�ȭ �Ҳ��� ����

public:
	gameNode();
	virtual ~gameNode();


	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ����
	virtual void render();			//�׸��� ����

	//map�׸��� ��
	HDC getMapDC() { return _mapBuffer->getMemDC(); };

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

