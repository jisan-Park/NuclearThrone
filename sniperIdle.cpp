#include "stdafx.h"
#include "sniperIdle.h"

HRESULT sniperIdle::init(enemyinfo info)
{
	sniperhurtright = new animation;
	sniperhurtright->init("sniper_hurt");
	sniperhurtright->setPlayFrame(0, 2, false, false);
	sniperhurtright->setFPS(10);

	sniperhurtleft = new animation;
	sniperhurtleft->init("sniper_hurt");
	sniperhurtleft->setPlayFrame(5, 3, false, false);
	sniperhurtleft->setFPS(10);



	sniperidleright = new animation;
	sniperidleright->init("sniper_idle");
	sniperidleright->setPlayFrame(0, 3, false, true);
	sniperidleright->setFPS(10);

	sniperidleleft = new animation;
	sniperidleleft->init("sniper_idle");
	sniperidleleft->setPlayFrame(7, 4, false, true);
	sniperidleleft->setFPS(10);

	_img = IMAGEMANAGER->findImage("sniper_idle");
	if (info.direction == E_LEFT) _motion = sniperidleleft;
	if (info.direction == E_RIGHT) _motion = sniperidleright;
	_motion->start();
	_pt = info.pt;
	return S_OK;
}

void sniperIdle::update(enemyinfo & info)
{
	_pt = info.pt;
	_motion->frameUpdate(TIMEMANAGER->getElapsedTime() * 1.0f);
}
