/*
 * Communication.h
 *
 *  Created on: Nov 9, 2017
 *      Author: robotics
 */

#ifndef SRC_COMMUNICATION_H_
#define SRC_COMMUNICATION_H_

#include <string>
#include <vector>

#include "./3rdParty/tcpsockets/tcpacceptor.h"
#include "./3rdParty/tcpsockets/tcpconnector.h"
#include "./3rdParty/tcpsockets/tcpstream.h"
#include <./3rdParty/json.hpp>

#include "WPILib.h"

using json = nlohmann::json;
using namespace chrono;

class Communication {
public:
	Communication();
	virtual ~Communication();

	std::vector<json> commands;

	void connect();
	void update();
	void receiveData();
	void sendData(json data);
	//std::string listen();


private:
	const int PORT = 9000;
	const char CONNECTION_IP[10] = "127.0.0.1"; // MAKE SURE TO UPDATE SIZE
	const bool IS_SERVER = false;
	const int DUMP_INTERVAL = 25;

	TCPConnector *connector;
	TCPStream *stream;

	// Receiving variables
	vector<char> msgBuffer;
	ssize_t length;
	char line[256];
	int size = 0;
	bool isReceiving = false;

	steady_clock::time_point lastDump; // Last time data was dumped to the Jetson server

	void dumpClientData(); // Used only if the RoboRio is the Client

	void logMessage(std::string msg);
	void logMessage(std::string msg, double value);


};

#endif /* SRC_COMMUNICATION_H_ */
