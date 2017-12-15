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

TEST_CASE("Test Case for TV Show", "[Video]"){
	Video show("Breaking Bad", 1, 8, 12, 11);

	REQUIRE(show.getTitle() == "Breaking Bad");
	REQUIRE(show.getType() == 1);
	REQUIRE(show.getHours() == 8);
	REQUIRE(show.getMinutes() == 12);
	REQUIRE(show.getEpisodes() == 11);
}

TEST_CASE("Test Case for Original", "[Video]"){
	Video original("Red vs Blue", 2, 3, 15, 20);

	REQUIRE(original.getTitle() == "Red vs Blue");
	REQUIRE(original.getType() == 2);
	REQUIRE(original.getHours() == 3);
	REQUIRE(original.getMinutes() == 15);
	REQUIRE(original.getEpisodes() == 20);
}




 
