/*
 * Communication.h
 *
 *  Created on: Nov 9, 2017
 *      Author: robotics
 */

#ifndef SRC_COMMUNICATION_H_
#define SRC_COMMUNICATION_H_

#include <string>
#include <./3rdParty/json.hpp>
#include <vector>

#include "./3rdParty/tcpsockets/tcpacceptor.h"
#include "./3rdParty/tcpsockets/tcpconnector.h"
#include <thread>

using json = nlohmann::json;


class Communication {
public:
	Communication();
	virtual ~Communication();

	std::vector<json> commands;

	void connect();
	void sendData(json data);
	std::string listen();
	void sendMessage(std::string message);


private:
	const int PORT = 5800;
	const char connectionIP[10] = "127.0.0.1"; // MAKE SURE TO UPDATE SIZE

	TCPConnector *socket;
	TCPStream *stream;

	void logMessage(std::string msg);
};

#endif /* SRC_COMMUNICATION_H_ */
