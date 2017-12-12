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
void Account::addStream(const Stream& stream) {

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
    for(Stream& stream : loopStart) 
    {

        // title of stream
        output << '\t' << stream.getVideo().getTitle();

        // current total hours and minutes
        totalHours += stream.getVideo().getHours() * stream.getOccurrences();
        totalMinutes += stream.getVideo().getMinutes() * stream.getOccurrences();

        // stream counts and originals
        int streamCount = 0;
        int originals = 0;
        switch (stream.getVideo().getType()) {

            // for movies, the stream count is the number of hours, with a minimum of 1
            case Video::MOVIE:
                streamCount += stream.getOccurrences() * (stream.getVideo().getHours() ? stream.getVideo().getHours() : 1);
                break;

            // for TV shows, the stream count is just the number of streams
            case Video::TVSHOW:
                streamCount += stream.getOccurrences();
                break;

            // for TV shows, the stream count is just the number of streams
            case Video::ORIGINAL:
                originals += stream.getOccurrences();
                streamCount += stream.getOccurrences();
                break;
        }

        // stream counts for this video
        std::ostringstream out_str_stream;
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
    for(Stream& stream : loopStart) 
    {

        // customer name
        output << name << ',';

        // stream type
        switch (stream.getVideo().getType()) {

            // for movies, the stream count is the number of hours, with a minimum of 1
            case Video::MOVIE:
                output << "MOVIE";
                break;

            // for TV shows, the stream count is just the number of streams
            case Video::TVSHOW:
                output << "TVSHOW";
                break;

            // for TV shows, the stream count is just the number of streams
            case Video::ORIGINAL:
                output << "ORIGINAL";
                break;
        }       

        // stream title
        output << ',' << stream.getVideo().getTitle();

        // stream hours and minutes
        output << ',' << (stream.getVideo().getHours() * stream.getOccurrences());
        output << ',' << (stream.getVideo().getMinutes() * stream.getOccurrences());

        // stream counts
        output << ',';
        switch (stream.getVideo().getType()) {

            // for movies, the stream count is the number of hours, with a minimum of 1
            case Video::MOVIE:
                output << (stream.getOccurrences() * (stream.getVideo().getHours() ? stream.getVideo().getHours() : 1));
                break;

            // all others are just the number of occurrences
            default:
                output << stream.getOccurrences();
                break;
        }

        output << '\n';
    }

    return output.str();
}