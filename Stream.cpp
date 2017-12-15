/*
  Stream.cpp

  Definition file for Stream class
*/

#include "Stream.hpp"


// constructor
Stream::Stream(const Video& video, int timesWatched)
    : video(video), timesWatched(timesWatched)
{ }

// create stream object based on video type
Stream* Stream::makeStream(const Video& video, const int timesWatched)
{
	if(video.getType() == Video::MOVIE)
		return new MovieStream(video, timesWatched);
	else if(video.getType() == Video::TVSHOW)
		return new TvStream(video, timesWatched);
	else if(video.getType() == Video::ORIGINAL)
		return new OriginalStream(video, timesWatched);
}


// number of times watched
int Stream::getTimesWatched() const {

    return timesWatched;
}

// video rented
const Video& Stream::getVideo() const {

    return video;
}

int Stream::getHours() const {
	return video.getHours() * timesWatched;
}

int Stream::getMinutes() const {
	return video.getMinutes() * timesWatched;
}

// movie stream constructor
MovieStream::MovieStream(const Video& video, int timesWatched)
	: Stream(video, timesWatched)
{ }

// For movies, stream count is the number of hours, with a minimum of 1
int MovieStream::getStreamCount() const
{
	return getTimesWatched() * (getVideo().getHours() ? getVideo().getHours() : 1);
}

// type of movie stream
std::string MovieStream::getType() const
{
	return "MOVIE";
}

// TV stream constructor
TvStream::TvStream(const Video& video, int timesWatched)
	: Stream(video, timesWatched)
{ }

// for TV shows, the stream count is just the number of streams
int TvStream::getStreamCount() const
{
	return getTimesWatched();
}

// type of tv stream
std::string TvStream::getType() const
{
	return "TVSHOW";
}

// original stream constructor
OriginalStream::OriginalStream(const Video& video, int timesWatched)
	: Stream(video, timesWatched)
{ }

// for TV shows, the stream count is just the number of streams
int OriginalStream::getStreamCount() const
{
	return getTimesWatched();
}

// type of original stream
std::string OriginalStream::getType() const
{
	return "ORIGINAL";
}
