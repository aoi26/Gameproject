#include <vector>
#include <iostream>
#include "Camera.h"
#include "Object.h"
#include "Geometry.h"

using namespace std;

Object::Object()
{
}


Object::~Object()
{
}

//呼び出した物の矩形を返す
Rect& Object::GetRect() 
{
	return _rect;
}

void Object::Updata() 
{

}

//それぞれのposを返す
Position2& Object::GetPos()
{
	return _pos;
}
//ﾌﾟﾚｲﾔｰの状態を返す
CHAR_ST Object::GetcharState() 
{
	return _state;
}
