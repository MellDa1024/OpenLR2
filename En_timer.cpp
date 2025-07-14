#include "En_timer.h"
#include <Windows.h>
#include "dxlib/DxLib.h" // for error log

double ClockTime;
bool ableClockFlag;
bool ableClockCount;

//4b6710
int SetBGATimer(Timer *T, double newTime){
	ClockTime = newTime;
	T->bga = newTime;
	return 1;
}

//4b6730
int SetAbleClockCount(char val){
	ableClockCount = val;
	return 1;
}

//4b6740
int SetClockFlag(Timer *T, char flag){
	T->flag = flag;
	ClockTime = 0.0;
	ableClockFlag = flag;
	return 1;
}

//4b6770
int NONE_004b6770(void){
	return 1;
}

//4b6780
int BGATimer(Timer *T){
	if (T->bgaFramerate <= 0.0) {
		T->bga = T->bga + 33.33333333333334;
	}
	else {
		T->bga = 1000.0 / T->bgaFramerate + T->bga;
	}
	ClockTime = T->bga;
	return 1;
}

//4b67d0
int ResetTimeLapse(int timerID, Timer *T){
	T->clock[timerID] = -1.0;
	if (timerID == 140) {
		T->Rhythm = -1.0;
		return 1;
	}
	return 1;
}

//4b6800 //not reliable
double GetTime(void){
	long long lVar1;
	DWORD time;
	BOOL BVar2;
	LARGE_INTEGER pfc_time;
	LARGE_INTEGER pfc_freq;
	double ret;

	if (ableClockCount == '\0') {
		time = timeGetTime();
		ret = (double)(time & 0x7fffffff);
	}
	else {
		BVar2 = QueryPerformanceFrequency(&pfc_freq);
		if (BVar2 == 0) {
			time = timeGetTime();
			ret = (double)(time & 0x7fffffff);
		}
		else {
			QueryPerformanceCounter(&pfc_time);
			ret = (double)pfc_time.QuadPart*1000 / (double)pfc_freq.QuadPart;
		}
	}
	return ret;
}

//4b6890
double GetTimeWrap(void) {
	double dVar1;

	if (ableClockFlag != '\0') {
		return ClockTime;
	}
	timeBeginPeriod(1);
	dVar1 = GetTime();
	timeEndPeriod(1);
	return dVar1;
}
/*
bool ableClockCount;
bool ableClockFlag;
double ClockTime;

//4b6800
double GetTime(){
	LARGE_INTEGER timer, t1;
	long long lVar1;
	DWORD time;
	BOOL BVar2;
	undefined4 local_10;
	undefined4 uStack12;
	long long local_8;
	double ret;

	if (ableClockCount == '\0') {
		time = timeGetTime();
		ret = (double)(time & 0x7fffffff);
	}
	else {
		BVar2 = QueryPerformanceFrequency(&timer);
		if (BVar2 == 0) {
			time = timeGetTime();
			ret = (double)(time & 0x7fffffff);
		}
		else {
			QueryPerformanceCounter(&t1);
			ret = t1.QuadPart / timer.QuadPart;
		}
	}
	return ret;
}

//4b6890
double GetTimeWrap() {
	double ret;
	if (ableClockFlag) {
		return ClockTime;
	}
	timeBeginPeriod(1);
	ret = GetTime();
	timeEndPeriod(1);
	return ret;
}
*/

//4b68d0
int InitTimer(Timer *T) {
	double dVar4;

	T->clock[0] = -1.0;
	for (int i = 0; i < 499; i++) {
		T->clock[i + 1] = T->clock[i];
	}

	dVar4 = ClockTime;
	if (ableClockFlag == '\0') {
		timeBeginPeriod(1);
		dVar4 = GetTime();
		timeEndPeriod(1);
	}
	T->scratch = dVar4;
	dVar4 = ClockTime;
	if (ableClockFlag == '\0') {
		timeBeginPeriod(1);
		dVar4 = GetTime();
		timeEndPeriod(1);
	}
	T->rhythmTick = dVar4;
	dVar4 = ClockTime;
	if (ableClockFlag == '\0') {
		timeBeginPeriod(1);
		dVar4 = GetTime();
		timeEndPeriod(1);
	}
	T->gameTick = dVar4;
	T->tickTime = 0.0;
	T->Rhythm = -1.0;
	dVar4 = ClockTime;
	if (ableClockFlag == '\0') {
		timeBeginPeriod(1);
		dVar4 = GetTime();
		timeEndPeriod(1);
	}
	T->vSyncTick = dVar4;
	dVar4 = ClockTime;
	if (ableClockFlag == '\0') {
		timeBeginPeriod(1);
		dVar4 = GetTime();
		timeEndPeriod(1);
	}
	T->FPSclock = dVar4;
	T->FPScount = 0.0;
	ErrorLogFmtAdd("タイマーを初期化しました\n");
	return 1;
}

//4b6a10
int CalcFPS(Timer *t){
	double dVar1;

	t->FPScount = t->FPScount + 1.0;
	dVar1 = ClockTime;
	if (ableClockFlag == '\0') {
		timeBeginPeriod(1);
		dVar1 = GetTime();
		timeEndPeriod(1);
	}
	dVar1 = dVar1 - t->FPSclock;
	if ( dVar1 > 1000.0) {
		dVar1 = ClockTime;
		if (ableClockFlag == '\0') {
			timeBeginPeriod(1);
			dVar1 = GetTime();
			timeEndPeriod(1);
		}
		t->FPS = (t->FPScount * 1000.0 + 499.0) / (dVar1 - t->FPSclock);
		t->FPScount = 0.0;
		if (ableClockFlag != '\0') {
			t->FPSclock = ClockTime;
			return 1;
		}
		timeBeginPeriod(1);
		dVar1 = GetTime();
		timeEndPeriod(1);
		t->FPSclock = dVar1;
	}
	return 1;
}

//4b6b10
double GetTimeLapse(uint timerID, Timer *T) {
	double ret;

	if (500 < timerID) return -1.0;
	if (timerID == 140) return T->Rhythm;

	ret = -1.0;
	if (ret != T->clock[timerID]) {
		if ((T->flag == '\0') || (T->bgaFramerate <= 0.0)) {
			return GetTimeWrap() - T->clock[timerID];
		}
		ret = T->bga - T->clock[timerID];
	}
	return ret;
}

//4b6b80
int SetTimeLapse(int timerID, Timer *T){
	double dVar1;

	if ((*(char *)&T->flag != '\0') && (0.0 < T->bgaFramerate)) {
		T->clock[timerID] = T->bga;
	}
	if (ableClockFlag != '\0') {
		T->clock[timerID] = ClockTime;
		return 1;
	}
	timeBeginPeriod(1);
	dVar1 = GetTime();
	timeEndPeriod(1);
	T->clock[timerID] = dVar1;
	return 1;
}