#include "GhostClock.h"

#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

static time_point<system_clock, microseconds> initialTimePoint;

GhostError_t GhostClockInit(void)
{
	initialTimePoint = time_point_cast<chrono::microseconds>(system_clock::now());
	return GhostOK;
}

GhostError_t GhostGetCurrentYear(int* Year)
{
	auto tt = system_clock::to_time_t(system_clock::now());
	struct tm* ptm = localtime(&tt);
	*Year = ptm->tm_year;
	return GhostOK;
}

GhostError_t GhostGetCurrentMonth(int* Month)
{
	auto tt = system_clock::to_time_t(system_clock::now());
	struct tm* ptm = localtime(&tt);
	*Month = ptm->tm_mon;
	return GhostOK;
}

GhostError_t GhostGetCurrentDay(int* Day)
{
	auto tt = system_clock::to_time_t(system_clock::now());
	struct tm* ptm = localtime(&tt);
	*Day = ptm->tm_mday;
	return GhostOK;
}

GhostError_t GhostGetCurrentDate(int* Year, int* Month, int* Day)
{
	auto tt = system_clock::to_time_t(system_clock::now());
	struct tm* ptm = localtime(&tt);
	*Year = ptm->tm_year;
	*Month = ptm->tm_mon;
	*Day = ptm->tm_mday;
	return GhostOK;
}

GhostError_t GhostGetCurrentHour(int* Hour)
{
	auto tt = system_clock::to_time_t(system_clock::now());
	struct tm* ptm = localtime(&tt);
	*Hour = ptm->tm_hour;
	return GhostOK;
}

GhostError_t GhostGetCurrentMinute(int* Minute)
{
	auto tt = system_clock::to_time_t(system_clock::now());
	struct tm* ptm = localtime(&tt);
	*Minute = ptm->tm_min;
	return GhostOK;
}

GhostError_t GhostGetCurrentSecond(int* Second)
{
	auto tt = system_clock::to_time_t(system_clock::now());
	struct tm* ptm = localtime(&tt);
	*Second = ptm->tm_sec;
	return GhostOK;
}

GhostError_t GhostGetCurrentTime(int* Hour, int* Minute, int* Second)
{
	auto tt = system_clock::to_time_t(system_clock::now());
	struct tm* ptm = localtime(&tt);
	*Hour = ptm->tm_hour;
	*Minute = ptm->tm_min;
	*Second = ptm->tm_sec;
	return GhostOK;
}


/// <summary>
/// Get the time from startup to now.
/// </summary>
/// <returns></returns>
GhostError_t GhostGetCurrentMilliseconds(double* Milliseconds)
{
	duration<double, std::milli> timeGap = time_point_cast<chrono::microseconds>(system_clock::now()) - initialTimePoint;
	*Milliseconds = timeGap.count();
	return GhostOK;
}

GhostError_t GhostGetCurrentMicroseconds(double* Microseconds)
{
	duration<double, std::micro> timeGap = time_point_cast<chrono::microseconds>(system_clock::now()) - initialTimePoint;
	*Microseconds = timeGap.count();
	return GhostOK;
}


/// <summary>
/// Sleep functions.
/// </summary>
/// <returns></returns>
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
