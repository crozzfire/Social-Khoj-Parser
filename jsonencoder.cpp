/*
 * jsonencoder.cpp
 *
 *  Created on: Jul 11, 2011
 *      Author: crozzfire
 */

#include <string>
#include <iostream>
#include "data.cpp"

class JSONEncoder {

private:
	//states
	std::string STRING_BEGIN;
	std::string STRING_END;
	std::string ARRAY_BEGIN;
	std::string ARRAY_END;
	std::string OBJECT_BEGIN;
	std::string OBJECT_END;
	std::string NVP_SEPARATOR;
	std::string NVP_INIT;
	std::string t_;

public:

	char* encodeParsed() {

		Data *data = Data::getInstance();

		STRING_BEGIN = "\"";
		STRING_END = "\"";
		ARRAY_BEGIN = "[";
		ARRAY_END = "]";
		OBJECT_BEGIN = "{";
		OBJECT_END = "}";
		NVP_SEPARATOR = ",";
		NVP_INIT = ":";
		t_ = "";
		t_ += OBJECT_BEGIN;

		t_ += STRING_BEGIN + "likes" + STRING_END;
		t_ += NVP_INIT;
		t_ += ARRAY_BEGIN;
		for (std::vector<std::string>::iterator it = data->likes.begin(); it
				!= data->likes.end(); ++it) {
			std::string i_ = *it;
			int pos = 0;
			std::string replace = "\\\"";
			while (true) {
				pos = i_.find("\"", pos);
				if (pos == std::string::npos)
					break;

				i_.replace(pos, replace.size() - 1, replace);
				pos += replace.size();
			}

			t_ += STRING_BEGIN + i_ + STRING_END;

			if (it != data->likes.end() - 1)
				t_ += NVP_SEPARATOR;
		}
		t_ += ARRAY_END;
		t_ += NVP_SEPARATOR;

		t_ += STRING_BEGIN + "hates" + STRING_END;
		t_ += NVP_INIT;
		t_ += ARRAY_BEGIN;
		for (std::vector<std::string>::iterator it = data->hates.begin(); it
				!= data->hates.end(); ++it) {
			std::string i_ = *it;
			int pos = 0;
			std::string replace = "\\\"";
			while (true) {
				pos = i_.find("\"", pos);
				if (pos == std::string::npos)
					break;

				i_.replace(pos, replace.size() - 1, replace);
				pos += replace.size();
			}

			t_ += STRING_BEGIN + i_ + STRING_END;

			if (it != data->hates.end() - 1)
				t_ += NVP_SEPARATOR;
		}
		t_ += ARRAY_END;
		t_ += NVP_SEPARATOR;

		t_ += STRING_BEGIN + "moods" + STRING_END;
		t_ += NVP_INIT;
		t_ += ARRAY_BEGIN;
		for (std::vector<std::string>::iterator it = data->moods.begin(); it
				!= data->moods.end(); ++it) {
			std::string i_ = *it;
			int pos = 0;
			std::string replace = "\\\"";
			while (true) {
				pos = i_.find("\"", pos);
				if (pos == std::string::npos)
					break;

				i_.replace(pos, replace.size() - 1, replace);
				pos += replace.size();
			}

			t_ += STRING_BEGIN + i_ + STRING_END;

			if (it != data->moods.end() - 1)
				t_ += NVP_SEPARATOR;
		}
		t_ += ARRAY_END;
		t_ += NVP_SEPARATOR;

		t_ += STRING_BEGIN + "locations" + STRING_END;
		t_ += NVP_INIT;
		t_ += ARRAY_BEGIN;
		for (std::vector<std::string>::iterator it = data->from.begin(); it
				!= data->from.end(); ++it) {
			std::string i_ = *it;
			int pos = 0;
			std::string replace = "\\\"";
			while (true) {
				pos = i_.find("\"", pos);
				if (pos == std::string::npos)
					break;

				i_.replace(pos, replace.size() - 1, replace);
				pos += replace.size();
			}

			t_ += STRING_BEGIN + i_ + STRING_END;

			if (it != data->from.end() - 1)
				t_ += NVP_SEPARATOR;
		}
		t_ += ARRAY_END;
		t_ += NVP_SEPARATOR;

		t_ += STRING_BEGIN + "others" + STRING_END;
		t_ += NVP_INIT;
		t_ += ARRAY_BEGIN;
		for (std::vector<std::string>::iterator it = data->vals.begin(); it
				!= data->vals.end(); ++it) {
			std::string i_ = *it;
			int pos = 0;
			std::string replace = "\\\"";
			while (true) {
				pos = i_.find("\"", pos);
				if (pos == std::string::npos)
					break;

				i_.replace(pos, replace.size() - 1, replace);
				pos += replace.size();
			}

			t_ += STRING_BEGIN + i_ + STRING_END;

			if (it != data->vals.end() - 1)
				t_ += NVP_SEPARATOR;
		}
		t_ += ARRAY_END;
		t_ += NVP_SEPARATOR;

		t_ += STRING_BEGIN + "info" + STRING_END;
		t_ += NVP_INIT;
		t_ += ARRAY_BEGIN;
		for (std::vector<std::string>::iterator it = data->info.begin(); it
				!= data->info.end(); ++it) {
			std::string i_ = *it;
			int pos = 0;
			std::string replace = "\\\"";
			while (true) {
				pos = i_.find("\"", pos);
				if (pos == std::string::npos)
					break;

				i_.replace(pos, replace.size() - 1, replace);
				pos += replace.size();
			}

			t_ += STRING_BEGIN + i_ + STRING_END;

			if (it != data->info.end() - 1)
				t_ += NVP_SEPARATOR;
		}
		t_ += ARRAY_END;

		t_ += OBJECT_END;

		char* r_ = strdup((char*) t_.c_str());
		return r_;

	}
};
