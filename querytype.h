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

const char* removeQuotes(const char *s_) {
	std::string t_(s_);
	return t_.substr(t_.find_first_of("\"") + 1, t_.find_last_of("\"") - 1).c_str();
}
