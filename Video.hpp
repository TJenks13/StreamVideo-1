/*
  Video.hpp

  Include file for Video class

  Include file for RunTime class
*/

#ifndef VIDEO_H
#define VIDEO_H


#include <string>


class Video {
public:

    static const int MOVIE      = 0;
    static const int TVSHOW     = 1;
    static const int ORIGINAL   = 2;


    // constructor
    Video(const std::string& title, int type, int hours, int minutes, int episodes);

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


private:
    std::string title;
    int type;
    int hours;
    int minutes;
    int episodes;


};




#endif
