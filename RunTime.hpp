/*
 * RunTime.hpp
 *
 */

#ifndef RUNTIME_H
#define RUNTIME_H

class RunTime {
public:
	RunTime(int hours, int minutes);
	int getHours() const;
	int getMinutes() const;

private:
	int _hours;
	int _minutes;
};

#endif
