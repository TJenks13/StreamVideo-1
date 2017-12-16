/*
 * RunTime.cpp
 *
 */
 #include "RunTime.hpp"

RunTime::RunTime(int hours, int minutes)
{
   _hours = hours;
   _minutes = minutes;
}

RunTime::getHours() const
{
    return _hours;
}

RunTime::getMinutes() const
{
    return _minutes;
}
