#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <algorithm>

namespace ft {
	class Parser {
	private:

	public:
		const char** config;

		Parser() {}
		Parser(const Parser &src) {}
		Parser(const char** str) { config = str; }
		~Parser(){}

		Parser& operator=(const Parser& src);
	};
}


#endif
