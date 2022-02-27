#ifndef ServerParameters_hpp
#define ServerParameters_hpp

#include "ServerParameters.hpp"
#include "parser.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

namespace ft {

	struct port_type {
		std::vector<int> type;
	};

	struct Location {
		std::string location;
		bool GET;
		bool POST;
		bool DELETE;
	};

	class RequestParser;

//	std::vector<ft::ServerParameters> serverParameters;

	struct ServerParameters {
		std::vector<port_type>			Ports;
		std::vector<std::string>		ServerNames;
		std::vector<Location>			Locations;
		std::map<int, std::string>		ErrorPages;
		std::pair<char, std::string>	Path;
		std::string						Index;
		std::string						LocUrl;
		std::string						Bin;
		size_t							MaxBodySize;
		int								RedirCode;
		char							Methods;
		bool							Autoindex;

		ServerParameters();
		ServerParameters(const ServerParameters &other);
		~ServerParameters();

		ServerParameters &operator=(const ServerParameters &other);
	};
}

#endif /* ServerParameters_hpp */
