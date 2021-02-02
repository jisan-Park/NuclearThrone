#pragma once
#include "singletonBase.h"
#include <vector>
enum whoshot
{
	PLAYER,
	ENEMY
};
struct tagBullet
{
	image* img;				//�Ѿ��� �̹���
	RECT rc;
	POINT pt;				//���� ��ǥ
	POINT firept;			//�߻��� �� ��ǥ
	whoshot who;
	float angle;			//����
	float radius;			//������
	float speed;			//���ǵ�
	bool isFire;			//�߻��ߴ�?
	int count;				//������ �̹��� ī��Ʈ��
};
class bullet : singletonBase<bullet>
{
private:
	vector <tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	float _range;			//��Ÿ�
public:
	bullet() {};
	~bullet() {};
	
	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	virtual void fire(POINT pt, float speed, float angle, whoshot who);
	virtual void fire(POINT pt, float speed, float angle, float turnangle, whoshot who);
	virtual void move();
};

