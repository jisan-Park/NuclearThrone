#pragma once
#include "weapon.h"
class grenadeLauncher :
	public weapon
{
public:
	virtual HRESULT init(POINT pt);
	virtual void update();
};

