/*
  Video_t.cpp

  Test program for class Video
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Video.hpp"
#include "DataRecord.hpp"

TEST_CASE( "NOP", "[Video]" ) {
	Video video("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 0);

	REQUIRE(video.getTitle() == "The Lord of the Rings: The Fellowship of the Ring");
	REQUIRE(video.getType() == 0);
	REQUIRE(video.getHours() == 3);
	REQUIRE(video.getMinutes() == 18);
	REQUIRE(video.getEpisodes() == 0);
}

TEST_CASE( "Construct video with DataRecord", "[Video]")
{
	DataRecord dr;
	dr.setTitle("Balto");
	dr.setType("MOVIE");
	dr.setHours(3);
	dr.setMinutes(18);
	dr.setEpisodes(0);

	REQUIRE(dr.getType() == "MOVIE");

	Video v(dr);
	REQUIRE(v.getTitle() == "Balto");
	REQUIRE(v.getType() == 0);
	REQUIRE(v.getHours() == 3);
	REQUIRE(v.getMinutes() == 18);
	REQUIRE(v.getEpisodes() == 0);
}
