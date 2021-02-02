#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>
#include "enemy.h"
#include "bandit.h"
#include "bigBandit.h"
#include "bigMaggot.h"
#include "greenMaggot.h"
#include "maggot.h"
#include "maggotNest.h"
#include "scolpion.h"
#include "bigRat.h"
#include "frog.h"
#include "gator.h"
#include "greenFrog.h"
#include "greenRat.h"
#include "rat.h"
#include "assassin.h"
#include "bigDog.h"
#include "raven.h"
#include "salamander.h"
#include "sniper.h"

enum ENEMYTYPE
{
	//STAGE1 0-7
	BIGBANDIT,
	BANDIT,
	BIGMAGGOT,
	MAGGOT,
	GREENMAGGOT,
	SCOLPION,
	MAGGOTNEST,

	//STAGE2 8-12
	BIGRAT,
	RAT,
	GREENRAT,
	FROG,
	GREENFROG,
	GATOR,

	//STAGE3 13-17
	BIGDOG,
	ASSASSIN,
	RAVEN,
	SALAMADER,
	SNIPER
};

class enemyManager : public singletonBase<enemyManager>
{
private:
	//���ʹ� ����
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

	typedef map<string, vEnemy> mvEnemy;
	typedef map<string, vEnemy>::iterator mviEnemy;

private:
	//�̸��� ���ʹ� ���� �����
	mvEnemy _mvEnemy;
	//�����ֱ�� ���ʹ� ����
	vEnemy _showEnemy;
public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void setimage();
	void addEnemys(string strKey, ENEMYTYPE enemyType, int x, int y);
	void deleteEnemys(string strKey, int x, int y);
	vector<enemy*> getEnemys(string strKey);
};

