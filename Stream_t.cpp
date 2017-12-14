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
    Stream vidInfo(vid,1);


    //Test if function return proper value '1'
    REQUIRE(vidInfo.getOccurrences() == 1);

}

TEST_CASE("Test getVideo() method")
{
    //Create video object. Title is Star Wars
    Video vid("Star Wars",1,1,1,1);

    //Create Stream Object
    Stream vidInfo(vid,1);

    //Create copy of vid object
    Video vid2 = vidInfo.getVideo();

    //Test if getVideo() returns "Star Wars" from vid2
    REQUIRE(vid2.getTitle() == "Star Wars");

}

TEST_CASE("Ensure getVideo() also returned correct data about vid")
{
        //Create video object. Title is Star Wars
    Video vid("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 0);

    //Create Stream Object
    Stream vidInfo(vid,1);

    //Test if getVideo() returns all correct data from vid
    REQUIRE(vidInfo.getVideo().getTitle() == "The Lord of the Rings: The Fellowship of the Ring");
    REQUIRE(vidInfo.getVideo().getType() == 0);
    REQUIRE(vidInfo.getVideo().getHours() == 3);
    REQUIRE(vidInfo.getVideo().getMinutes() == 18);
    REQUIRE(vidInfo.getVideo().getEpisodes() == 0);

}

