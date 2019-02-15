#include "HttpRequest.h"



HttpRequest::HttpRequest()
{
	http.setHost(HOSTNAME, PORT);
}

void HttpRequest::postToServer(int data1,int data2)
{
	std::ostringstream stream;
	stream << SENDURI << "Player1=" << data1 << "Player2=" << data2;
	request.setUri(stream.str());
	request.setHttpVersion(1, 1);

	sf::Http::Response response = http.sendRequest(request);
	if (response.getStatus() == sf::Http::Response::Ok)
	{
		LOG("Status: " << response.getStatus() << "\n" << "Send success");
	}
	else
	{
		LOG("Request Failed\n");
	}
}

std::string HttpRequest::readFromServer()
{

	request.setUri(URI);
	request.setHttpVersion(1, 1);

	sf::Http::Response response = http.sendRequest(request);

	if (response.getStatus() == sf::Http::Response::Ok)
	{
		LOG("Status: " << response.getStatus() << "\n" << "connected\n");
		dataFromServer = response.getBody();
		
	}
	else
	{
		LOG("Request Failed\n");
	}
	return dataFromServer;
}

