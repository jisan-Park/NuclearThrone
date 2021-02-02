#pragma once
#include "salamanderState.h"
class salamanderFire :
	public salamanderState
{
private:
	animation* salamanderfireright;
	animation* salamanderfireleft;
	animation* salamanderhurtright;
	animation* salamanderhurtleft;


public:
	virtual HRESULT init(enemyinfo info);
	virtual void update(enemyinfo &info);
};

