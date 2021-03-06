#include <DxLib.h>
#include <ctime>
#include <iostream>
#include "Geometry.h"
#include "GameMain.h"
#include "TimeManager.h"



TimeManager::TimeManager()
{
	timerFlag = false;
	timerCnt = 0;
	flameCnt = 0;
}


TimeManager::~TimeManager()
{
}

void TimeManager::Updata()
{
	if (timerFlag == true) {
		flameCnt++;
		if (flameCnt % 60 == 0) {
			timerCnt++;
		}
	}
	if (timerCnt > 999) {
		timerCnt = 999;
	}
#ifdef _DEBUG
	DrawFormatString(100, 20, 0xff4444, "%d", timerCnt);
#endif
}
void TimeManager::StartTimer()
{
	timerFlag = true;
}
void TimeManager::StopTimer()
{
	timerFlag = false;
}

int TimeManager::ShowTimer()
{
	if (timerFlag == false) {
		return timerCnt;
	}
	return 0;
}