/*
  Video.cpp

  Definition file for Video class
*/

#include "Video.hpp"

// constructor
Video::Video(const std::string& title, int type, int hours, int minutes, int episodes)
    : title(title), type(type), hours(hours), minutes(minutes), episodes(episodes)
{ }

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




