#pragma once
#include "Enemy.h"

class MapCtl;
class HitClass;
class Player;
class Rope;
class EnemyServer;
class ModelMgr;

class EmAround :
	public Enemy
{
private:
	HitClass& _hit;
	Player& _pl;
	Rope& _rope;
	EnemyServer& _server;
	Position2 _pos;
	Position2 _initPos;
	Rect _emRect;
	Circle _emEye;
	ENEMY_STATE _state;
	ENEMY_DATA _emData;
	MapCtl* _map;
	DIR _dir;
	EnemyServerData _individualData;		//ｴﾈﾐｰ本部に送るﾃﾞｰﾀ
	ModelMgr* _modelmgr;

	//重力について
	float vx;
	float vy;
	float speed;			
	bool moveFlag;			//向きを切り替えるためのフラグ
	int dis;				//どれくらい動いたら反対を向くのか定義する
	float interCnt;			//反対側を向くまでのカウント

	int loseSightCnt;		//PLが認識範囲から外れて見失うまでのカウント
	int fearCnt;			//ひるんでいる秒数

	int modelhandle;//かり

	void Move();			//敵の動きについての管理を行う

	void BasicMove();		//未発見状態の基本動作
	void InterMove();		//未発見状態の途中動作
	void FoundMove();		//ﾌﾟﾚｲﾔｰ発見時の動作
	void CheckMove();		//マップとのあたり判定について
	void Visibility();		//敵の視界に関して
	void moveFear();		//怯み状態に関して
	void LoseSight();		//ﾌﾟﾚｲﾔｰを見失ったとき
	void Gravity();			//重力判定
	void SetRange();		//視界の広さをレベル別に判定します

public:
	EmAround(Position2 pos,Player& pl,Rope& rope,EnemyServer& server,HitClass& hit);
	~EmAround();

	void Updata();	
	Rect& GetRect();
	ENEMY_STATE & GetState();
	void EnemyFalter();		//怯み状態になる条件
	void GetClass(HitClass* hit,Player& pl);		//クラス受け取り用
	void SetInitPos();

	void Draw(Position2 offset);
};

