/*
  Stream.hpp

  Include file for Stream class
*/

#ifndef RENTAL_H
#define RENTAL_H

#include "Video.hpp"

#include <string>

class Stream {
public:

    // constructor
    Stream(const Video& video, int timesWatched);

    // create stream object based on video type
    static Stream* makeStream(const Video& video, const int timesWatched);

    // destructor
    virtual ~Stream() = default;

    // number of times watched
    int getTimesWatched() const;

    // video rented
    const Video& getVideo() const;

    virtual int getStreamCount() const = 0;

    virtual std::string getType() const = 0;

    int getHours() const;
    int getMinutes() const;

private:
    Video video;
    int timesWatched;
};


class MovieStream : public Stream
{
public:

	// constructor
	MovieStream(const Video& video, int timesWatched);

	// For movies, stream count is the number of hours, with a minimum of 1
	int getStreamCount() const override;

	// type of stream as string
	std::string getType() const override;
};

class TvStream : public Stream
{
public:

	// constructor
	TvStream(const Video& video, int timesWatched);

	// for TV shows, the stream count is just the number of streams
	int getStreamCount() const override;

	// type of stream as string
	std::string getType() const override;
};


class OriginalStream : public Stream
{
public:

	// constructor
	OriginalStream(const Video& video, int timesWatched);

	// for TV shows, the stream count is just the number of streams
	int getStreamCount() const override;

	// type of stream as string
	std::string getType() const override;
};

#endif
