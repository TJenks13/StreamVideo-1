/*
  Video.hpp

  Include file for Video class
*/

#ifndef VIDEO_H
#define VIDEO_H

#include "DataRecord.hpp"

#include <string>

class Video {
public:

    static const int MOVIE      = 0;
    static const int TVSHOW     = 1;
    static const int ORIGINAL   = 2;

    // constructor
    Video(const std::string& title, int type, int hours, int minutes, int episodes);

    // constructor with data record
    Video(const DataRecord& datum);

    // video title
    const std::string& getTitle() const;

    // video type
    int getType() const;

    // length in hours
    int getHours() const;

    // length in minutes
    int getMinutes() const;

    // number of episodes
    int getEpisodes() const;

    // set video length
    void setLength(int hours, int minutes);

private:
    std::string title;
    int type;
    int hours;
    int minutes;
    int episodes;
};

#endif
