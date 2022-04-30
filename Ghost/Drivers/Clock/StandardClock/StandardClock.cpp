#include "GhostClock.h"

#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

static auto initialTimePoint = time_point_cast<chrono::microseconds>(system_clock::now());

GhostError_t GhostClockInit(void)
{
	return GhostOK;
}

GhostError_t GhostGetCurrentYear(int* Year)
{
	return GhostOK;
}

GhostError_t GhostGetCurrentMonth(int* Month)
{
	return GhostOK;
}

GhostError_t GhostGetCurrentDay(int* Day)
{
	return GhostOK;
}

GhostError_t GhostGetCurrentDate(int* Year, int* Month, int* Day)
{
	return GhostOK;
}

GhostError_t GhostSleepMillisecond(int Milliseconds)
{
	this_thread::sleep_for(milliseconds(Milliseconds));
	return GhostOK;
}

GhostError_t GhostSleepMicrosecond(int Microseconds)
{
	this_thread::sleep_for(microseconds(Microseconds));
	return GhostOK;
}

