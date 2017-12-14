/*
  Stream.hpp

  Include file for Stream class
*/

#ifndef RENTAL_H
#define RENTAL_H

#include "Video.hpp"

class Stream {
public:

    // constructor
    Stream(const Video& video, int occurrences);

    // destructor
    ~Stream() {}
    // number of times watched
    int getOccurrences() const;

    // video rented
    const Video& getVideo() const;

    virtual int getStreamCount() const { return 0; };

private:
    Video video;
    int occurrences;
};

class TvStream : public Stream
{
public:

	// constructor
	TvStream(const Video& video, int occurrences);

	// for TV shows, the stream count is just the number of streams
	int getStreamCount() const override;
};

class MovieStream : public Stream
{
public:

	// constructor
	MovieStream(const Video& video, int occurrences);

	// For movies, stream count is the number of hours, with a minimum of 1
	int getStreamCount() const override;
};

class OriginalStream : public Stream
{
public:

	// constructor
	OriginalStream(const Video& video, int occurrences);

	// for TV shows, the stream count is just the number of streams
	int getStreamCount() const override;
};

#endif
