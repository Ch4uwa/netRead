#include "HttpRequest.h"


HttpRequest::HttpRequest()
{
	http.setHost(HOSTNAME, PORT);
}

std::string HttpRequest::postToServer(std::string ID, int data1, int data2)
{
	std::ostringstream stream;
	stream << SENDURI << ID << "|Player1=" << data1 << "Player2=" << data2;
	request.setUri(stream.str());
	request.setHttpVersion(1, 1);
	std::string sendResponse;
	sf::Http::Response response = http.sendRequest(request);
	if (response.getStatus() == sf::Http::Response::Ok)
	{
		LOG("Status: " << response.getStatus() << "\n" << "Send success");
		LOG("Response: " << response.getBody());
		sendResponse = response.getBody();
	}
	else
	{
		LOG("Request Failed\n");
	}
	return sendResponse;
}

std::string HttpRequest::readFromServer(std::string ID)
{
	std::stringstream stream, stream1;
	stream << "/services/data/" << EMAIL << "-" << ID << ".csv";
	request.setUri(stream.str());
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

