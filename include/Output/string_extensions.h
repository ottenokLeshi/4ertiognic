#ifndef STRING_EXTENSIONS_H
#define STRING_EXTENSIONS_H

#include <algorithm>
#include <cctype>
#include <string>
#include "MArray.h"

inline bool space(char c) {
	return (std::isspace(c) ? true : false);
}
inline bool notspace(char c) {
	return !std::isspace(c);
}

inline Array<std::string> stringSplit(const std::string& s) {
	typedef std::string::const_iterator iter;
	Array<std::string> words;
	iter word_start = s.begin();
	while (word_start != s.end()) {
		word_start = std::find_if(word_start, s.end(), notspace);
		iter word_stop = std::find_if(word_start, s.end(), space);
		if (word_start != s.end()) {
			words.push_back(std::string(word_start, word_stop));
			word_start = word_stop;
		}
	}
	return words;
}

#endif