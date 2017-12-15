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

// create stream object depending on video type
Stream* createStream(const Video& video, const int occurrences);

void loadVideos(std::vector<Video>& videos);

int main() {

    // Load videos from data file
    std::vector<Video> videos;
    loadVideos(videos);

    // Account
    Account customer("Fred");

    // Some streams of these movies
    Stream* s1 = createStream(videos[0], 3);
    Stream* s2 = createStream(videos[1], 1);
    Stream* s3 = createStream(videos[2], 2);

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


// create stream object based on video type
Stream* createStream(const Video& video, const int occurrences)
{
	if(video.getType() == Video::MOVIE)
		return new MovieStream(video, occurrences);
	else if(video.getType() == Video::TVSHOW)
		return new TvStream(video, occurrences);
	else if(video.getType() == Video::ORIGINAL)
		return new OriginalStream(video, occurrences);
}

// load videos from file
void loadVideos(std::vector<Video>& videos)
{
	std::ifstream invideo("videos.csv");
	std::string line;
	while (getline(invideo, line)) {
	    std::istringstream sline(line);

	    // video type
	    std::string stype;
	    std::getline(sline, stype, ',');
	    int type;
	    if(stype == "MOVIE")
	    	type = Video::MOVIE;
	    else if(stype == "TVSHOW")
	    	type = Video::TVSHOW;
	    else if(stype == "ORIGINAL")
	    	type = Video::ORIGINAL;
	    else
	    	continue;

	    // video title
	    std::string title;
	    std::getline(sline, title, ',');

	    // video hours
	    std::string shours;
	    std::getline(sline, shours, ',');
	    std::stringstream strhours(shours);
	    int hours;
	    strhours >> hours;

	    // video minutes
	    std::string sminutes;
	    std::getline(sline, sminutes, ',');
	    std::stringstream strminutes(sminutes);
	    int minutes;
	    strminutes >> minutes;

	    // video episodes
	    std::string sepisodes;
	    std::getline(sline, sepisodes, ',');
	    std::stringstream strepisodes(sepisodes);
	    int episodes;
        strepisodes >> episodes;

        videos.push_back(Video(title, type, hours, minutes, episodes));
	}
	    invideo.close();
}
