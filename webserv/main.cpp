#include <iostream>
#include "parser.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "ServerParameters.hpp"

void print (std::vector<std::string> str) {
	for (size_t i = 0; i < str.size(); i++)
		std::cout << str[i] << std::endl;
}
//int findParam(std::vector<std::string> config, std::vector<std::string> param) {
//
//	for (size_t i = 0; i < file.size(); i++) {
//		for (size_t j = 0; j < parameters.size(); j++) {
//			found = file[i].find(parameters[j]);
//			if (found != file[i].npos) {
//				len = 0;
//				found = 0;
//				while(file[i][found] == ' ' || file[i][found] == '\t')
//					found++;
//				len = found;
//				while(file[i][len] != ' ')
//					len++;
//				needle = file[i].substr(found, len - found);
//				if (parameters[j] == needle)
//					std::cout << "\"" << parameters[j] << "\" at: " << found << std::endl;
//			}
//		}
//	}
//	return 0;
//}

int checkBrackets(std::vector<std::string> file, size_t pos) {
	size_t i = 0;
	size_t openBracket = 0;
	size_t closeBracket = 0;

	while(i < file[i].size() || file[i].find("server")) {
		while(file[i][pos]) {
			if (file[i][pos] == '{')
				openBracket++;
			else if (file[i][pos] == '}')
				closeBracket++;
			if (!openBracket && file[i][pos] != ' ' && file[i][pos] != '\t')
				break ;
			if (openBracket == 1 && closeBracket == openBracket)
				break ;
			pos++;
		}
		pos = 0;
		i++;
	}
	if (openBracket != closeBracket)
		return -1;
	return 0;
}

int checkServer(std::vector<std::string> file) {
	size_t len = 0;
	size_t pos;

	pos = file[0].find("server");
	if (pos != file[0].npos) {
		for (size_t x = 0; x < pos; x++) {
			if (file[0][x] != ' ' && file[0][x] != '\t')
				len++;
		}
		for (size_t x = pos; file[0][x] != ' ' && file[0][x] != '\t'; x++)
			len++;
		if (strlen("server") == len)
			return checkBrackets(file, pos + len);
	}
	return -1;
}

int parseInfo(std::vector<std::string> file, std::vector<std::string> parameters) {
//	std::vector<std::string> parameters;
	ft::ServerParameters serverParameters = {};
	std::cout<< serverParameters.Index << std::endl;
	std::string param;
	size_t pos;
	size_t len = 0;

	for (size_t i = 0; i < file.size(); i++) {
		for (size_t j = 0; j < parameters.size(); j++) {
			pos = file[i].find(parameters[j]);
		if (pos != file[i].npos) {
			pos = 0;
			while(file[i][pos] == ' ' || file[i][pos] == '\t')
				pos++;
			len = pos;
			while(file[i][len] != ' ')
				len++;
			param = file[i].substr(pos, len - pos);
			if (parameters[j] == param)
				std::cout << "\"" << parameters[j] << "\" at: " << pos << std::endl;
			}
		}
	}
	return 0;
}

void getInfo (std::string filePath) {
	std::ifstream file(filePath);
	std::string buffer;
	std::vector<std::string> tmp;
	std::vector<std::string> parameters={
		"listen", "server_name", "autoindex",
		"root", "index", "methods", "location", "redirection" };
//	std::vector<std::string> server = {"{"};
//	parameters =

	if (!(file.is_open())){
		std::cerr << "File not find\n";
		return ;
	}
	else {
		while (!file.eof()) {
			getline(file, buffer);
			if (buffer[0] == '#' || buffer.empty()) {
				continue;
			}
			else if (buffer.find('#')) {
				buffer = buffer.substr(0, buffer.find('#'));
			}
			tmp.push_back(buffer);
		}
		if (!checkServer(tmp)) {
			std::cout << "SERVER FOUND AND BRACKETS IS OK" << std::endl;
			parseInfo(tmp, parameters);
		}
		else
			std::cout << "PARSE ERROR" << std::endl;
	}
	buffer.clear();
	file.close();
//	print(tmp);
	tmp.clear();
}

int main(int argc, const char **argv) {
//	std::vector<ft::ServerParameters> serverParameters;
//	Pars::Parser parser;
	std::string filePath;

//	if (argc == 1)
//		serverParametres = parseConfig(DEFAULT_CONFIG)
	if (argc == 2) {
//		serverParametres = parseConfig(argv[1]);
		filePath = argv[1];
		getInfo(filePath);
	}
	else {
		std::cerr << "Invalid arguments!" << std::endl;
		return 1;
	}
//	run(filePath);

	return 0;
}
