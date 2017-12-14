/*
  Stream.cpp

  Definition file for Stream class
*/

#include "Stream.hpp"


// constructor
Stream::Stream(const Video& video, int occurrences)
    : video(video), occurrences(occurrences)
{ }

// number of times watched
int Stream::getOccurrences() const {

    return occurrences;
}

// video rented
const Video& Stream::getVideo() const {

    return video;
}

// movie stream constructor
MovieStream::MovieStream(const Video& video, int occurrences)
	: Stream(video, occurrences)
{ }

// For movies, stream count is the number of hours, with a minimum of 1
int MovieStream::getStreamCount() const
{
	return getOccurrences() * (getVideo().getHours() ? getVideo().getHours() : 1);
}

// type of movie stream
std::string MovieStream::getType() const
{
	return "MOVIE";
}

// TV stream constructor
TvStream::TvStream(const Video& video, int occurrences)
	: Stream(video, occurrences)
{ }

// for TV shows, the stream count is just the number of streams
int TvStream::getStreamCount() const
{
	return getOccurrences();
}

// type of tv stream
std::string TvStream::getType() const
{
	return "TVSHOW";
}

// original stream constructor
OriginalStream::OriginalStream(const Video& video, int occurrences)
	: Stream(video, occurrences)
{ }

// for TV shows, the stream count is just the number of streams
int OriginalStream::getStreamCount() const
{
	return getOccurrences();
}

// type of original stream
std::string OriginalStream::getType() const
{
	return "ORIGINAL";
}
