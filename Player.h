#pragma once
#include "singletonBase.h"
#include "assultRifle.h"
#include "grenadeLauncher.h"
#include "machineGun.h"
#include "pistol.h"
#include "razerRifle.h"
#include "shotGun.h"
#include "shovel.h"
#include "sword.h"
#include "triplemachinegun.h"

enum MOVEDIRCTION
{
	NOMOVE,
	RIGHTMOVE,
	LEFTMOVE,
	UPMOVE,
	DOWNMOVE
};

enum DIRECTION
{
	RIGHT,
	LEFT
};

enum PLAYERSTATE
{
	IDLE,
	WALK,
	HURT,
	DEAD,
	SKILL
};

class Player
{
protected:
	POINT _pt;				//xy ��ǥ�Դϴ�
	float _width, _height;	//�ʺ� �����Դϴ�
	RECT _rc;				//�浹������ ��Ʈ�Դϴ�
	int _speed;				//�����̴� �ӵ��Դϴ�
	int _damage;			//�������Դϴ�
	int _firecnt;			//�߻� ���Դϴ�
	float _aimAngle;		//���ذ��Դϴ�
	float _moveAngle;		//�̵����Դϴ�
	image* _img;			//�̹��� �Դϴ�
	animation* _motion;		//�ִϸ��̼� ���
	bool _ishit;			//�Ȱ�Ȯ��
	int _maxhp;				//��HP
	int _hp;				//HP
	bool _isdead;

	bool _isdash;
	float _pushp;

	PLAYERSTATE _playerstate;
	DIRECTION _direction;
	MOVEDIRCTION _movedirctionx;
	MOVEDIRCTION _movedirctiony;

	weapon* _currentWeapon;
	weapon* _readyWeapon;
public:
	Player();
	~Player();

	virtual HRESULT init(float x, float y);
	virtual void update();
	virtual void release();

	virtual void render(HDC hdc);

	virtual void attack();
	virtual void move();
	virtual void setAnimation();
	//�ݹ��� ���� ����,����
	//=========================================
	DIRECTION getDirection() { return _direction; }
	void setDirection(DIRECTION direction) { _direction = direction; }

	PLAYERSTATE getState() { return _playerstate; }
	void setState(PLAYERSTATE state) { _playerstate = state; }

	image* getImage() { return _img; }
	void setImage(image* img) { _img = img; }

	animation* getMotion() { return _motion; }
	void setteMotion(animation* ani) { _motion = ani; }

	void setIshit(bool ishit) { _ishit = ishit; }

	void setIsdead(bool isdead) { _isdead = isdead; }
	//=========================================
	POINT getPt() { return _pt; }
	void setPT(POINT pt) { _pt = pt; }

};

