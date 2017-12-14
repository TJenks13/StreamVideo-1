/*
  Account_t.cpp

  Test program for class Account
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "Account.hpp"
#include "Video.hpp"

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
	Video videoTest("Test Movie", Video::MOVIE, 1, 10, 0);

	Stream stream(videoTest,1);

	customer.addStream(stream);

	std::stringstream output;
	output << "Stream Report for Account: " << "Fred" << '\n';
	output << "Streams:" << '\n';
	output << '\t' << "Test Movie";

	output << '\t' << 1 << '\n';
	output << '\n';

	// total stream counts
	output << "Total Stream Events: " << 1 << '\n';

	// total non-original stream counts
	output << "Non-Original Stream Events: " << 1 << '\n';
	// total time
	output << "Total Time: " << 1 << ":" << 10 << '\n';

	REQUIRE(customer.report() == output.str());
}

TEST_CASE( "Report with TV show stream", "[Account]")
{
	Account customer("Fred");
	Video videoTest("Test", Video::TVSHOW, 1, 10, 1);

	Stream stream(videoTest,1);

	customer.addStream(stream);

	std::stringstream output;
	output << "Stream Report for Account: " << "Fred" << '\n';
	output << "Streams:" << '\n';
	output << '\t' << "Test";

	output << '\t' << 1 << '\n';
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

	int streamcount = 1;
	int originals = 1;
	int hours = 1;
	int minutes = 10;
	int episodes = 1;
	int occurrences = 1;

	Video videoTest("Test Original", Video::ORIGINAL, hours, minutes, episodes);

	Stream stream(videoTest,occurrences);

	customer.addStream(stream);

	std::stringstream output;
	output << "Stream Report for Account: " << "Fred" << '\n';
	output << "Streams:" << '\n';
	output << '\t' << "Test Original";

	output << '\t' << streamcount << '\n';
	output << '\n';

	// total stream counts
	output << "Total Stream Events: " << streamcount << '\n';

	// total non-original stream counts
	output << "Non-Original Stream Events: " << (streamcount - originals) << '\n';
	// total time
	output << "Total Time: " << hours << ":" << minutes << '\n';

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

	Stream stream(videoTest,occurrences);

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

	Stream stream(videoTest,occurrences);

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

	Stream stream(videoTest,occurrences);

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
