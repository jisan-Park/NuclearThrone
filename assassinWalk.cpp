#include "stdafx.h"
#include "assassinWalk.h"

HRESULT assassinWalk::init(enemyinfo info)
{
	assassinwalkleft = new animation;
	assassinwalkleft->init("assassin_walk");
	assassinwalkleft->setPlayFrame(0, 5, false, true);
	assassinwalkleft->setFPS(10);

	assassinwalkleft = new animation;					// �����ؾ���
	assassinwalkleft->init("assassin_walk");			// �����ؾ���
	assassinwalkleft->setPlayFrame(0, 5, false, true);	// �����ؾ���
	assassinwalkleft->setFPS(10);						// �����ؾ���

	assassinhurtright = new animation;
	assassinhurtright->init("assassin_hurt");
	assassinhurtright->setPlayFrame(0, 2, false, false);
	assassinhurtright->setFPS(10);

	assassinhurtleft = new animation;
	assassinhurtleft->init("assassin_hurt");
	assassinhurtleft->setPlayFrame(5, 3, false, false);
	assassinhurtleft->setFPS(10);
	_img = IMAGEMANAGER->findImage("assassin_walk");
	if (info.direction == E_LEFT) _motion = assassinwalkleft;
	if (info.direction == E_RIGHT) _motion = assassinwalkright;
	_motion->start();
	_pt = info.pt;
	return S_OK;
}

void assassinWalk::update(enemyinfo & info)
{
	_pt = info.pt;
	_motion->frameUpdate(TIMEMANAGER->getElapsedTime() * 1.0f);
}
