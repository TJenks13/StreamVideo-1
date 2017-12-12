/*
  Video_t.cpp

  Test program for class Video
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Video.hpp"

TEST_CASE( "NOP", "[Video]" ) {
	Video video("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 0);

	REQUIRE(video.getTitle() == "The Lord of the Rings: The Fellowship of the Ring");
	REQUIRE(video.getType() == 0);
	REQUIRE(video.getHours() == 3);
	REQUIRE(video.getMinutes() == 18);
	REQUIRE(video.getEpisodes() == 0);
}
