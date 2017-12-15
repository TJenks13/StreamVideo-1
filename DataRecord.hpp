/*
  DataRecord.hpp

  Include file for DataRecord class
*/


#ifndef DATARECORD_H
#define DATARECORD_H

#include <string>

// object for deserialized data from video.csv
class DataRecord
{
public:

	// sets type of video
	void setType(std::string type);

	// sets title of video
	void setTitle(std::string title);

	// sets hours of video
	void setHours(int hours);

	// sets minutes of video
	void setMinutes(int minutes);

	// sets episodes of video
	void setEpisodes(int episodes);

	// gets type of video
	const std::string getType() const;

	// gets title of video
	const std::string getTitle() const;

	// gets hours of video
	const int getHours() const;

	// gets minutes of video
	const int getMinutes() const;

	// gets episodes of video
	const int getEpisodes() const;

private:
	std::string _type;
	std::string _title;
	int _hours;
	int _minutes;
	int _episodes;

};

#endif
