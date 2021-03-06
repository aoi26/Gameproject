#pragma once
#include "Geometry.h"

class Camera;

class Object
{
private:
public:
	Object();
	~Object();
	Rect _rect;
	Position2 _pos;
	CHAR_ST _state;
	virtual Rect& GetRect();		//それぞれの矩形を返す
	virtual Position2& GetPos();	//場所を返す
	CHAR_ST GetcharState();		//状態を返す

	virtual void Updata();
};

