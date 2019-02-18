#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include "defines.hpp"
#include <string>
#include <SFML/Network.hpp>
#include <iostream>
#include <sstream>

class HttpRequest
{
private:
	std::string EMAIL = "martin.karlsson@stud.sti.se";
	std::string SENDURI = "/services/sendform.aspx?xdata=" + EMAIL + "|";
	std::string HOSTNAME = "primat.se";
	unsigned short PORT = 80;

	std::string dataFromServer;

	sf::Http http;
	sf::Http::Request request;
public:
	HttpRequest();

	std::string postToServer(std::string ID, int data1, int data2);
	std::string readFromServer(std::string ID);

	//void httpUpdate();
	//void httpDraw();



	~HttpRequest() {}
};

#endif // !HTTPREQUEST_H
