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

