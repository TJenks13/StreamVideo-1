/*
  Account_t.cpp

  Test program for class Account
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Account.hpp"
#include "Video.hpp"

#include <sstream>

TEST_CASE( "No streaming", "[Account]" ) {

    Account customer("Fred");

    REQUIRE(customer.getName() == "Fred");
    REQUIRE(customer.data() == "");
}

TEST_CASE( "Report without streams", "[Account]") {
	Account customer("Fred");

	std::stringstream output;

	output << "Stream Report for Account: " << "Fred" << '\n';
	output << "Streams:" << '\n';
	output << '\n';
	output << "Total Stream Events: " << 0 << '\n';
	output << "Non-Original Stream Events: " << 0 << '\n';
	output << "Total Time: " << 0 << ':' << 0 << '\n';
	REQUIRE(customer.report() == output.str());
}


TEST_CASE( "Report with movie stream", "[Account]")
{
	Account customer("Fred");

	int hours = 2;
	int minutes = 10;
	int episodes = 1;
	int occurrences = 2;

	Video videoTest("Test Movie", Video::MOVIE, hours, minutes, episodes);

	MovieStream movieStream(videoTest,occurrences);
	const Stream* stream = &movieStream;

	customer.addStream(stream);

	std::stringstream output;
	output << "Stream Report for Account: " << "Fred" << '\n';
	output << "Streams:" << '\n';
	output << '\t' << "Test Movie";

	output << '\t' << (occurrences * hours) << '\n';
	output << '\n';

	// total stream counts
	output << "Total Stream Events: " << (occurrences * hours) << '\n';

	// total non-original stream counts
	output << "Non-Original Stream Events: " << (occurrences * hours) << '\n';
	// total time
	output << "Total Time: " << (hours * occurrences) << ":" << (occurrences * minutes) << '\n';

	REQUIRE(customer.report() == output.str());
}

TEST_CASE( "Report with TV show stream", "[Account]")
{
	Account customer("Fred");

	int hours = 1;
	int minutes = 10;
	int episodes = 1;
	int occurrences = 1;


	Video videoTest("Test Show", Video::TVSHOW, hours, minutes, episodes);

	TvStream tvStream(videoTest, occurrences);
	const Stream* stream = &tvStream;

	customer.addStream(stream);

	std::stringstream output;
	output << "Stream Report for Account: " << "Fred" << '\n';
	output << "Streams:" << '\n';
	output << '\t' << "Test Show";

	output << '\t' << occurrences << '\n';
	output << '\n';

	// total stream counts
	output << "Total Stream Events: " << 1 << '\n';

	// total non-original stream counts
	output << "Non-Original Stream Events: " << 1 << '\n';
	// total time
	output << "Total Time: " << 1 << ":" << 10 << '\n';

	REQUIRE(customer.report() == output.str());
}

TEST_CASE( "Report with Original stream", "[Account]") {
	Account customer("Fred");

	int hours = 1;
	int minutes = 10;
	int episodes = 1;
	int occurrences = 2;

	Video videoTest("Test Original", Video::ORIGINAL, hours, minutes, episodes);

	OriginalStream originalStream(videoTest, occurrences);
	const Stream* stream = &originalStream;

	customer.addStream(stream);

	std::stringstream output;
	output << "Stream Report for Account: " << "Fred" << '\n';
	output << "Streams:" << '\n';
	output << '\t' << "Test Original";

	output << '\t' << occurrences << '\n';
	output << '\n';

	// total stream counts
	output << "Total Stream Events: " << occurrences << '\n';

	// total non-original stream counts
	output << "Non-Original Stream Events: " << (occurrences - occurrences) << '\n';
	// total time
	output << "Total Time: " << (occurrences * hours) << ":" << (occurrences * minutes) << '\n';

	REQUIRE(customer.report() == output.str());
}

TEST_CASE("Data without stream" "[Account]") {
	Account customer("Fred");

	REQUIRE(customer.data() == "");
}

TEST_CASE("Data with MOVIE stream", "[Account]") {
	Account customer("Fred");

	int streamcount = 1;
	int originals = 0;
	int hours = 1;
	int minutes = 10;
	int episodes = 0;
	int occurrences = 1;

	Video videoTest("Balto", Video::MOVIE, hours, minutes, episodes);

	MovieStream movieStream(videoTest,occurrences);
	const Stream* stream = &movieStream;

	customer.addStream(stream);

	std::stringstream output;
	output << customer.getName() << ',';
	output << "MOVIE";
	output << ',' << "Balto";

	output << ',' << hours;
	output << ',' << minutes;
	output << ',';
	output << (occurrences * hours);
	output << '\n';

	REQUIRE(customer.data() == output.str());

}

TEST_CASE("Data with TVSHOW stream", "[Account]") {
	Account customer("Fred");

	int streamcount = 1;
	int originals = 0;
	int hours = 1;
	int minutes = 10;
	int episodes = 1;
	int occurrences = 1;

	Video videoTest("Test Show", Video::TVSHOW, hours, minutes, episodes);

	TvStream tvStream(videoTest,occurrences);
	const Stream* stream = &tvStream;

	customer.addStream(stream);

	std::stringstream output;
	output << customer.getName() << ',';
	output << "TVSHOW";
	output << ',' << "Test Show";

	output << ',' << hours;
	output << ',' << minutes;
	output << ',';
	output << (occurrences * hours);
	output << '\n';

	REQUIRE(customer.data() == output.str());

}

TEST_CASE("Data with ORIGINAL stream", "[Account]") {
	Account customer("Fred");

	int streamcount = 1;
	int originals = 0;
	int hours = 1;
	int minutes = 10;
	int episodes = 1;
	int occurrences = 1;

	Video videoTest("Test Original", Video::ORIGINAL, hours, minutes, episodes);

	OriginalStream originalStream(videoTest,occurrences);
	const Stream* stream = &originalStream;

	customer.addStream(stream);

	std::stringstream output;
	output << customer.getName() << ',';
	output << "ORIGINAL";
	output << ',' << "Test Original";

	output << ',' << hours;
	output << ',' << minutes;
	output << ',';
	output << (occurrences * hours);
	output << '\n';

	REQUIRE(customer.data() == output.str());

}
