#pragma once
#include "singletonBase.h"

//�� Ÿ�� ������ 64
#define TILESIZE 64

//Ÿ�� ����
#define TILEX 30
#define TILEY 30

//�����ִ� Ÿ�� ����
#define SHOW_TILEX 10
#define SHOW_TILEY 10

// 640 x 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

// Ÿ�ϼ� (����Ÿ��) ����
#define SAMPLETILEX 6
#define SAMPLETILEY 7

enum TERRAIN
{
	TR_C, TR_C2, TR2_C, TR2_C1, TR2_C2, TR3_1, TR3_2, TR3_3, TR3_4, TR_BREAK

	, T2R_C, T2R_C2, T2R_C3, T2R_C4, T2R_C5, T2R_P, T2R_P2, T2R_P3, T2R_H, T2R_H2
	, T2R_BREAK, T2R_PP

	, T3R_C, T3R_C2, T3R_C2B, T3R_C2R, T3R_C2L, T3R_C2T
};

enum WALL
{
	W_B, W_L, W_LB, W_LT, W_R, W_RT, W_RB, W_ROOF, W_T										   ,W_3B, W_3T, W_3R,W_3L, W_4			,W_2BT, W_2RL

	, W2_B, W2_B1, W2_B2, W2_R, W2_R2, W2_R3

	, W3_B, W3_L, W3_LB, W3_LT, W3_R, W3_RB, W3_RT, W3_C, W3_C1, W3_C2, W3_T,					W3_3B, W3_3T, W3_3R, W3_3L , W3_4 , W3_2BT, W3_2RL

	, WALL_NONE
};


enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK2, OBJ_BLOCK3, OBJ_BLOCK4, OBJ_BLOCK5, OBJ_BLOCK6, OBJ_BLOCK7, OBJ_BLOCK8, OBJ_BLOCK9, OBJ_BLOCK10, OBJ_BLOCK11, OBJ_BLOCK12,

	OBJ2_BLOCK1, OBJ2_BLOCK2, OBJ2_BLOCK3, OBJ2_BLOCK4, OBJ2_BLOCK5, OBJ2_BLOCK6

	, OBJ3_BLOCK1, OBJ3_BLOCK2, OBJ3_BLOCK3

	, OBJ1_SHD, OBJ2_SHD, OBJ3_SHD

	, OBJ_NONE
};


enum selectBtn
{
	DrawTerrain,
	DrawWall,
	DrawObj,
	DrawEnemy,
	DrawBoss,
	DrawPlayer,
	Eraser
};

struct tagTile
{
	bool isSelected;
	TERRAIN terrain;		//����
	OBJECT obj;				//������Ʈ
	WALL   wall;

	RECT rc;				//��Ʈ

	int terrainFrameX;		//Ÿ�� ��ȣ(�ִϸ��̼� ������ ��ȣ �����ϸ��)
	int terrainFrameY;
	int objFrameX;			//������Ʈ ��ȣ (���� ����)
	int objFrameY;
	int wallFrameX;
	int wallFrameY;
};


//���� Ÿ�� ����ü(�ȷ�Ʈ Ÿ��)
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//���� Ŭ���� ���� Ÿ���� ���� ������ ����ü
struct tagCurrentTile
{
	image* img;
	int x;
	int y;
};

struct showTile {
	//�浹ó����
	RECT rc;
	//index
	POINT pt;
};


class mapManager : public singletonBase<mapManager>
{
private:
	//////////////////////////[��ġ���� �� set]///////////////////////
	POINT player_pt;
	int player_type;

	//////////////////////////[�����ֱ� �� set]///////////////////////

	//�巡�� �� point
	POINT _min;
	POINT _max;
	//left, top tile index
	POINT _pt;
	//����, ���� ����
	int width_count;
	int height_count;
	//ũ��
	int size;
	showTile _showTile[TILEX][TILEY];
	//////////////////////////[�����ϱ� �� set]///////////////////////

	//������ ��ư = ������ ��ư�� ���� �����ϴ� �ൿ�� �޶���
	selectBtn _Select;
	//���� ���õ� Ÿ��
	tagCurrentTile	_currentTile;
	//Ÿ�� ��
	tagSampleTile	_sampleTile[SAMPLETILEX][SAMPLETILEY];
	//�׷��� Ÿ�� �迭
	tagTile _tiles[TILEX][TILEY];

	//random map 
	int _rnd;
	int _xtemp;
	int _ytemp;

	int _x2temp;
	int _y2temp;

	int _objtemp;
	int _tiletemp;
	int _walltemp;

public:
	HRESULT init();
	void update();
	void release();

	void render(HDC hdc);
	void RectRender(HDC hdc);
	void stretchMapRender(HDC hdc);
	void strectchSceneRender(HDC hdc);
	void mapRender(HDC hdc);
	void mapToolRender(HDC hdc);
	void minimapRender(HDC hdc);

	void save();
	void load();
	void load(LPCSTR strKey);
	void eraser();

	//random map
	void emptymap();
	void random();

	//init
	void setImage();
	void setTiles();
	void setSampleTile();
	
	//update
	void setMap();
	void moveIndex();			//�̵�
	void updateTileIndex();
	void autoTile();
	void setTileRect();

	//setter
	void setPlayerType(int i) { player_type = i; };
	void setPlayerPoint(POINT pt) { player_pt = pt; };
	void setSize(int i) { size = i; };
	void setWidthCount(int i);
	void setHeightCount(int i);
	//void setShowTileMemory();	//width,height_count �� set �� ��, ���
	void setSelectBtn(selectBtn b) { _Select = b; };
	void setPoint(int left, int top) { _pt.x = left; _pt.y = top; };
	//random
	void setRandomStage(int num) { _rnd = num; };
	//getter
	tagCurrentTile getEnemyTileset(int type);
	int getEnemyType(int x, int y);
	int getPlayerType() { return player_type; };
	POINT getPlayerPoint() { return player_pt; };
	int getSize() { return size; };
	int getWidthCount() { return width_count; };
	int getHeightCount() { return height_count; };
	selectBtn getSelectBtn() { return _Select; };
	POINT getPoint() { return _pt; };

	//findSelect Tile
	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);
	WALL wallSelect(int frameX, int frameY);
};

