#include "structure.h"

// int SetBGATimer(Timer * T, double newTime);
// int SetAbleClockCount(char val);
// int SetClockFlag(Timer * T, char flag);
// int NONE_004b6770(void);
// int BGATimer(Timer * T);
// int ResetTimeLapse(int timerID, Timer * T);
// double GetTime(void);
// double GetTimeWrap(void);
// int InitTimer(Timer * T);
// int CalcFPS(Timer * t);
// double GetTimeLapse(uint timerID, Timer * T);
// int SetTimeLapse(int timerID, Timer * T);

//recording timer
int SetClockFlag(Timer * T, char flag);
int SetBGATimer(Timer * T, double newTime);
int BGATimer(Timer * T);

int NONE_004b6770(void);

//config and init timer
int SetAbleClockCount(char val);
int InitTimer(Timer * T);

double GetTime(void);
double GetTimeWrap(void);

int CalcFPS(Timer * t);

int SetTimeLapse(int timerID, Timer * T);
int ResetTimeLapse(int timerID, Timer * T);
double GetTimeLapse(uint timerID, Timer * T);