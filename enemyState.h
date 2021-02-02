#pragma once
enum ENEMYDIRECTION
{
	E_RIGHT,
	E_LEFT
};

enum ENEMYSTATE
{
	E_IDLE,
	E_WALK,
	E_FIRE,
	E_HURT,
	E_DEAD,
	E_ATTACK,
	E_IMMUNE
};
enum ENEMYNOTICESTATE
{
	UNNOTICED,
	NOTICED
};

enum ENEMYMOVETYPE
{
	ALWAYSFOLLOW,
	BALANCE,
	ALWAYSRUN
};

struct enemyinfo
{
	POINT pt;				//xy ��ǥ�Դϴ�
	float width, height;	//�ʺ� �����Դϴ�
	RECT rc;				//�浹������ ��Ʈ�Դϴ�
	int hp;				//hp�Դϴ�.
	int speed;				//�����̴� �ӵ��Դϴ�
	int damage;			//�������Դϴ�
	int firecnt;			//�߻� ���Դϴ�
	float aimAngle;		//���ذ��Դϴ�
	float moveAngle;		//�̵����Դϴ�
	bool isHurt;		//���ƴ��� ���°̴ϴ�


	ENEMYSTATE state;
	ENEMYSTATE nextState;
	
	ENEMYMOVETYPE movetype;
	ENEMYDIRECTION direction;
	ENEMYNOTICESTATE nstate;
};

class enemyState
{
protected:
	//�̹���
	image* _img;
	//���� �ִϸ��̼� ������ �󸶵��� �߰��ǵ� �������
	animation* _motion;
	POINT _pt;

	bool isHurt;
public:
	enemyState();
	~enemyState();

	virtual HRESULT init(enemyinfo info);
	virtual void update(enemyinfo &info);
	virtual void release();
	virtual void render(HDC hdc);
	void init(image* img, animation* ani, int x, int y);

	void setImage(image* temp) { _img = temp; };
	void setAnimation(animation* ani) { _motion = ani; };
	void setPoint(int x, int y) { _pt.x = x; _pt.y = y; };
	void setHurt(bool what) { isHurt = what; };
	static void hurtFinish(void* obj);
	virtual void setRect();
};

