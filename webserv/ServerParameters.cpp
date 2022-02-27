#include "ServerParameters.hpp"

//ft::ServerParameters::ServerParameters () {
////	Ports = 0;
////	ServerNames
//}

ft::ServerParameters::ServerParameters() {
//	this->Ports = new Ports;
//	this->ServerNames = "";
//	this->Locations = 0;
//	this->ErrorPages = "";
//	this->Path = "";
	this->Index = "";
	this->LocUrl = "";
	this->Bin = "";
	this->MaxBodySize = 0;
	this->RedirCode = 0;
	this->Methods = ' ';
	this->Autoindex = false;
}

ft::ServerParameters &ft::ServerParameters::operator=(const ServerParameters &other) {
	if (this == &other)
		return *this;
	this->Ports = other.Ports;
	this->ServerNames = other.ServerNames;
	this->Locations = other.Locations;
	this->ErrorPages = other.ErrorPages;
	this->Path = other.Path;
	this->Index = other.Index;
	this->LocUrl = other.LocUrl;
	this->Bin = other.Bin;
	this->MaxBodySize = other.MaxBodySize;
	this->RedirCode = other.RedirCode;
	this->Methods = other.Methods;
	this->Autoindex = other.Autoindex;
	return *this;
}

ft::ServerParameters::~ServerParameters() {
	delete [] this; //check this
}
