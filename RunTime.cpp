/*
 * RunTime.cpp
 *
 */

#include "RunTime.hpp"


RunTime::RunTime(int hours, int minutes)
	: _hours(hours), _minutes(minutes)
	{ };

int RunTime::getHours() const
{
	return _hours;
}

int RunTime::getMinutes() const
{
	return _minutes;
}



