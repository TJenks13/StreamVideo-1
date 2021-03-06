/*
  Stream_t.cpp

  Test program for class Stream
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stream.hpp"

#include <iostream>

TEST_CASE( "Test Occurrence Method", "[Stream]" ) {

    //Create video object. Title is Star Wars
    Video vid("Star Wars",1,1,1,1);

    //Set occurrence of vid to 1
    TvStream tvStream(vid,1);
    Stream* vidInfo = &tvStream;


    //Test if function return proper value '1'
    REQUIRE(vidInfo->getTimesWatched() == 1);

}

TEST_CASE("Test getVideo() method")
{
    //Create video object. Title is Star Wars
    Video vid("Star Wars",1,1,1,1);

    //Create Stream Object
    MovieStream movieStream(vid,1);
    Stream* vidInfo = &movieStream;

    //Create copy of vid object
    Video vid2 = vidInfo->getVideo();

    //Test if getVideo() returns "Star Wars" from vid2
    REQUIRE(vid2.getTitle() == "Star Wars");

}

TEST_CASE("Ensure getVideo() also returned correct data about vid")
{
        //Create video object. Title is Star Wars
    Video vid("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 0);

    //Create Stream Object
    MovieStream stream(vid,1);
    Stream* vidInfo = &stream;

    //Test if getVideo() returns "Star Wars" from vid2
    REQUIRE(vidInfo->getVideo().getTitle() == "The Lord of the Rings: The Fellowship of the Ring");
    REQUIRE(vidInfo->getVideo().getType() == 0);
    REQUIRE(vidInfo->getVideo().getHours() == 3);
    REQUIRE(vidInfo->getVideo().getMinutes() == 18);
    REQUIRE(vidInfo->getVideo().getEpisodes() == 0);

}

TEST_CASE("Make Movie Stream", "[Stream]")
{
	const int type = Video::MOVIE;
	const int hours = 1;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;
	Video video("Test Movie Stream", type, hours, minutes, episodes);

	Stream* s = Stream::makeStream(video, timesWatched);

	REQUIRE(s->getType() == "MOVIE");
}

TEST_CASE("Make TV Stream", "[Stream]")
{
	const int type = Video::TVSHOW;
	const int hours = 1;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;
	Video video("Test TV Show Stream", type, hours, minutes, episodes);

	Stream* s = Stream::makeStream(video, timesWatched);

	REQUIRE(s->getType() == "TVSHOW");
}

TEST_CASE("Make Original Stream", "[Stream]")
{
	const int type = Video::ORIGINAL;
	const int hours = 1;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;
	Video video("Test Original Stream", type, hours, minutes, episodes);

	Stream* s = Stream::makeStream(video, timesWatched);

	REQUIRE(s->getType() == "ORIGINAL");
}

TEST_CASE("TV Show Stream", "[Stream]")
{
	const int type = Video::TVSHOW;
	const int hours = 1;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;
	Video video("Test TV Show Stream", type, hours, minutes, episodes);

	TvStream tvStream(video, timesWatched);

	REQUIRE(tvStream.getVideo().getTitle() == "Test TV Show Stream");
	REQUIRE(tvStream.getVideo().getType() == type);
	REQUIRE(tvStream.getVideo().getHours() == hours);
	REQUIRE(tvStream.getVideo().getMinutes() == minutes);
	REQUIRE(tvStream.getVideo().getEpisodes() == episodes);
	REQUIRE(tvStream.getTimesWatched() == timesWatched);
}

TEST_CASE("Movie Stream", "[Stream]")
{
	const int type = Video::MOVIE;
	const int hours = 1;
	const int minutes = 2;
	const int episodes = 0;
	const int timesWatched = 3;

	Video video("Test Movie Stream", type, hours, minutes, episodes);

	MovieStream movieStream(video,timesWatched);

	REQUIRE(movieStream.getVideo().getTitle() == "Test Movie Stream");
	REQUIRE(movieStream.getVideo().getType() == type);
	REQUIRE(movieStream.getVideo().getHours() == hours);
	REQUIRE(movieStream.getVideo().getMinutes() == minutes);
	REQUIRE(movieStream.getVideo().getEpisodes() == episodes);
	REQUIRE(movieStream.getTimesWatched() == timesWatched);
}

TEST_CASE("Original Stream", "[Stream]")
{
	const int type = Video::ORIGINAL;
	const int hours = 1;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;

	Video video("Test Original Stream", type, hours, minutes, episodes);

	MovieStream movieStream(video,timesWatched);

	REQUIRE(movieStream.getVideo().getTitle() == "Test Original Stream");
	REQUIRE(movieStream.getVideo().getType() == type);
	REQUIRE(movieStream.getVideo().getHours() == hours);
	REQUIRE(movieStream.getVideo().getMinutes() == minutes);
	REQUIRE(movieStream.getVideo().getEpisodes() == episodes);
	REQUIRE(movieStream.getTimesWatched() == timesWatched);
}

TEST_CASE("Stream Count TV Show", "[Stream]")
{
	const int type = Video::TVSHOW;
	const int hours = 5;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;

	Video video("Test TV Show Stream", type, hours, minutes, episodes);

	TvStream tvStream(video, timesWatched);
	Stream* stream = &tvStream;

	const int expectedResult = timesWatched;

	// for TV shows, the stream count is just the number of streams
	REQUIRE(tvStream.getStreamCount() == expectedResult);

	// Test that override is working
	REQUIRE(stream->getStreamCount() == expectedResult);

}

TEST_CASE("Stream Count Movie", "[Stream]")
{
	const int type = Video::MOVIE;
	const int hours = 5;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;

	Video video("Test Movie Stream count", type, hours, minutes, episodes);

	MovieStream movieStream(video, timesWatched);
	Stream* stream = &movieStream;

	const int expectedResult = timesWatched * hours;

	// For movies, stream count is the number of hours, with a minimum of 1
	REQUIRE(movieStream.getStreamCount() == expectedResult);

	// Test that override is working
	REQUIRE(stream->getStreamCount() == expectedResult);

}

TEST_CASE("Stream Count Movie with 0 hours", "[Stream]")
{
	const int type = Video::MOVIE;
	const int hours = 0;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;

	Video video("Test Movie Stream count", type, hours, minutes, episodes);

	MovieStream movieStream(video, timesWatched);
	Stream* stream = &movieStream;

	// we are here expecting the number of hours to be replaced with 1
	const int expectedResult = timesWatched * 1;

	// For movies, stream count is the number of hours, with a minimum of 1
	REQUIRE(movieStream.getStreamCount() == expectedResult);

	// Test that override is working
	REQUIRE(stream->getStreamCount() == expectedResult);
}

TEST_CASE("Stream Count Original", "[Stream]")
{
	const int type = Video::ORIGINAL;
	const int hours = 5;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;

	Video video("Test Original Stream Count", type, hours, minutes, episodes);

	OriginalStream originalStream(video, timesWatched);

	const int expectedResult = timesWatched;

	// for TV shows, the stream count is just the number of streams
	REQUIRE(originalStream.getStreamCount() == expectedResult);

}

TEST_CASE("Get Hours", "[Stream]")
{
	const int type = Video::ORIGINAL;
	const int hours = 5;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;

	Video video("Test Original Stream Count", type, hours, minutes, episodes);

	OriginalStream originalStream(video, timesWatched);

	REQUIRE(originalStream.getHours() == 20);

}

TEST_CASE("Get Minutes", "[Stream]")
{
	const int type = Video::ORIGINAL;
	const int hours = 5;
	const int minutes = 2;
	const int episodes = 3;
	const int timesWatched = 4;

	Video video("Test Original Stream Count", type, hours, minutes, episodes);

	OriginalStream originalStream(video, timesWatched);

	REQUIRE(originalStream.getMinutes() == 8);

}
