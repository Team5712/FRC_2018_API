#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

#include "./3rdParty/tcpsockets/tcpacceptor.h"
#include "./3rdParty/tcpsockets/tcpconnector.h"
#include "./3rdParty/tcpsockets/tcpstream.h"

#include "WPILib.h"

#include "./3rdParty/json.hpp"

using json = nlohmann::json;

using namespace std;
using namespace std::chrono;


class Client {

public:

	const char *REMOTE_ADDR = "127.0.0.1";
	const int REMOTE_PORT = 9000;
	const int UPDATE_INTERVAL = 25;

	json commands;

	TCPConnector *connector;
	TCPStream *stream;

	void connect();
	// like the server, this will just sit and wait for data
	void recieve();


	void sendData();
	size_t jsonToChar(json j, char data[]);
	json charToJson(const char* data);
	json charToJson(vector<char> data);
};

/* for finding delta time

chrono::steady_clock::time_point start = chrono::steady_clock::now();

someFunction()

chrono::steady_clock::time_point end = chrono::steady_clock::now();

chrono::steady_clock::duration delta = end - start;

chrono::duration_cast<chrono::microseconds>(delta).count();

*/
