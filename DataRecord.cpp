/*
  DataRecord.cpp

  Definition file for Video class
*/

#include "DataRecord.hpp"

// sets type of video
void DataRecord::setType(std::string type)
{
	_type = type;
}

// sets title of video
void DataRecord::setTitle(std::string title)
{
	_title = title;
}

// sets hours of video
void DataRecord::setHours(int hours)
{
	_hours = hours;
}

// sets minutes of video
void DataRecord::setMinutes(int minutes)
{
	_minutes = minutes;
}

// sets episodes of video
void DataRecord::setEpisodes(int episodes)
{
	_episodes = episodes;
}


// gets title of video
const std::string DataRecord::getTitle() const
{
	return _title;
}

// gets type of video
const std::string DataRecord::getType() const
{
	return _type;
}

// gets hours of video
const int DataRecord::getHours() const
{
	return _hours;
}

// gets minutes of video
const int DataRecord::getMinutes() const
{
	return _minutes;
}

// gets episodes of video
const int DataRecord::getEpisodes() const
{
	return _episodes;
}
