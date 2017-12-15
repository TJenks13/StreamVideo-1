/*
  Account.cpp

  Definition file for Account class
*/

#include "Account.hpp"
#include "Video.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Account::Account(const std::string& name)
    : name(name)
{ }

// account name
std::string Account::getName() const {

    return name;
}

// add a stream to this account
void Account::addStream(const Stream* stream) {

    streams.push_back(stream);
}

// account streaming report
std::string Account::report() const {

    // stringstream to convert data
    std::ostringstream output;

    // customer name
    output << "Stream Report for Account: " << getName() << '\n';

    // list of streams
    output << "Streams:" << '\n';
    int totalStreams = 0;
    int totalOriginals = 0;
    int totalHours = 0;
    int totalMinutes = 0;

    auto loopStart = streams;
    for(const Stream* s : loopStart)
    {

        // title of stream
        output << '\t' << s->getVideo().getTitle();

        // current total hours and minutes
        totalHours += s->getHours();
        totalMinutes += s->getMinutes();

        // stream counts and originals
        int streamCount = 0;
        int originals = 0;

        streamCount += s->getStreamCount();

        if(s->getType() == "ORIGINAL")
        	originals += s->getTimesWatched();

        // stream counts for this video
        output << '\t' << streamCount << '\n';

        totalStreams += streamCount;
        totalOriginals += originals;
    }
    output << '\n';

    // total stream counts
    output << "Total Stream Events: " << totalStreams << '\n';

    // total non-original stream counts
    output << "Non-Original Stream Events: " << (totalStreams - totalOriginals) << '\n';

    // total time
    int minutes = totalMinutes % 60;
    int hours = totalHours + totalMinutes / 60;
    output << "Total Time: " << hours << ":" << minutes << '\n';

    return output.str();
}

// account data in CSV
std::string Account::data() const {

    // stringstream to convert data
    std::ostringstream output;

    // customer name
    std::string name = getName();

    // list of streams
    auto loopStart = streams;
    for(const Stream* s : loopStart)
    {

        // customer name
        output << name << ',';

        // stream type
        output << s->getType();

        // stream title
        output << ',' << s->getVideo().getTitle();

        // stream hours and minutes
        output << ',' << s->getHours();
        output << ',' << s->getMinutes();

        // stream counts
        output << ',';

        // stream counts
        output << s->getStreamCount();

        output << '\n';
    }

    return output.str();
}
