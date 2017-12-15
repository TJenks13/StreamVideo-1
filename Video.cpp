/*
  Video.cpp

  Definition file for Video class
*/

#include "Video.hpp"

// constructor
Video::Video(const std::string& title, int type, int hours, int minutes, int episodes)
    : title(title), type(type), hours(hours), minutes(minutes), episodes(episodes)
{ }

Video::Video(const DataRecord& datum)
{
	title = datum.getTitle();

	// get video type
	if(datum.getType() == "MOVIE")
		type = Video::MOVIE;
	else if(datum.getType() == "TVSHOW")
		type = Video::TVSHOW;
	else if(datum.getType() == "ORIGINAL")
		type = Video::ORIGINAL;

	hours = datum.getHours();
	minutes = datum.getMinutes();
	episodes = datum.getEpisodes();

}


// video title
const std::string& Video::getTitle() const {

    return title;
}

// video type
int Video::getType() const {

    return type;
}

// video length in hours
int Video::getHours() const {

    return hours;
}

// video length in minutes
int Video::getMinutes() const {

    return minutes;
}

// number of episodes
int Video::getEpisodes() const {

    // special case as movies do not have episodes
    if (type == Video::MOVIE)
        return 0;

    return episodes;
}

// set video length
void Video::setLength(int hours, int minutes) {

    this->hours = hours;
    this->minutes = minutes;
}
