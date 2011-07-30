/*
 * tokens.h
 *
 *  Created on: Jul 5, 2011
 *      Author: admin
 */

#include <vector>
#include <string>

class Data {

public:
	std::vector<std::string> likes;
	std::vector<std::string> hates;
	std::vector<std::string> from;
	std::vector<std::string> moods;
	std::vector<std::string> info;
	std::vector<std::string> vals;

	static Data* getInstance() {
		if (hasInstance_ == false) {
			inst_ = new Data();
			hasInstance_ = true;
			return inst_;
		}

		return inst_;
	}

	~Data() {
		hasInstance_ = false;
	}

	void free() {
		likes.clear();
		moods.clear();
		from.clear();
		hates.clear();
		info.clear();
		vals.clear();
	}
private:
	static Data *inst_;
	static bool hasInstance_;
	Data() {}; // Private constructor
	Data(const Data&); // Prevent copy-construction
	Data& operator=(const Data&); // Prevent assignment
};

bool Data::hasInstance_ = false;
Data* Data::inst_ = NULL;
