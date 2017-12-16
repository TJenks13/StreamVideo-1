/*
  StreamingActivity.cpp

  Basic operations of a streaming service
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Video.hpp"
#include "Stream.hpp"
#include "Account.hpp"

// reads file to load videos
void loadVideos(std::vector<Video>& videos);

int main() {

    // Load videos from data file
    std::vector<Video> videos;
    loadVideos(videos);

    // Account
    Account customer("Fred");

    // Some streams of these movies
    Stream* s1 = Stream::makeStream(videos[0], 3);
    Stream* s2 = Stream::makeStream(videos[1], 1);
    Stream* s3 = Stream::makeStream(videos[2], 2);

    customer.addStream(s1);
    customer.addStream(s2);
    customer.addStream(s3);

    // Output account streaming report
    std::cout << customer.report() << '\n';

    // Output account data report
    std::cout << customer.data() << '\n';

    // clean up
    delete s1;
    delete s2;
    delete s3;

    return 0;
}

// load videos from file
void loadVideos(std::vector<Video>& videos)
{
	std::ifstream invideo("videos.csv");
	std::string line;
	while (getline(invideo, line)) {
	    std::istringstream fileLine(line);

	    // video type
	    std::string vidType;
	    std::getline(fileLine, vidType, ',');
	    int type;
	    if(vidType == "MOVIE")
	    	type = Video::MOVIE;
	    else if(vidType == "TVSHOW")
	    	type = Video::TVSHOW;
	    else if(vidType == "ORIGINAL")
	    	type = Video::ORIGINAL;
	    else
	    	continue;

	    // video title
	    std::string videoTitle;
	    std::getline(fileLine, videoTitle, ',');

	    // video hours
	    std::string inHours;
	    std::getline(fileLine, inHours, ',');
	    std::stringstream videoHours(inHours);
	    int hours;
	    videoHours >> hours;

	    // video minutes
	    std::string inMinutes;
	    std::getline(fileLine, inMinutes, ',');
	    std::stringstream videoMinutes(inMinutes);
	    int minutes;
	    videoMinutes >> minutes;

	    // video episodes
	    std::string inEpisodes;
	    std::getline(fileLine, inEpisodes, ',');
	    std::stringstream videoEpisodes(inEpisodes);
	    int episodes;
        videoEpisodes >> episodes;

        videos.push_back(Video(videoTitle, type, hours, minutes, episodes));
	}
	    invideo.close();
}
