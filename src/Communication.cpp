/*
 * Communication.cpp
 */

#include "Communication.h"
#include <thread>

Communication::Communication() {

	connector = new TCPConnector(); // Optional line
	connect();
	lastDump = steady_clock::now();


	thread t_1(&Communication::listen, this);
	t_1.detach();
}


Communication::~Communication() {

}

void Communication::connect() {

	stream = connector->connect(CONNECTION_IP, PORT);

	if(stream != NULL) {
		char str[80];
		sprintf(str, "Connected to the Jetson!");
		DriverStation::ReportError(str);
	}
}


void Communication::listen()
{

	while(true) {

		// if pointer has been assigned eg. connected to a client.
		if(stream != NULL) {


			vector<char> buffer;

			size_t len;
			char line[256];
			int size = 0;


			// while the data we receive into
			while ((len = stream->receive(line, sizeof(line), 5/*5s timeout*/)) > 0)
			{
				size += len;
				for(auto i = 0; i < len; i++)
					buffer.push_back(line[i]);
			}

			json msg = json::parse(buffer);

        	char str[80];
        	sprintf(str, "Json Recieved");
        	DriverStation::ReportError(str);
		}
	}

}

void Communication::sendData(json data) {


}


void Communication::dumpClientData()
{

}

void logMessage(std::string msg) {
	DriverStation::ReportError(msg);
}

void logMessage(std::string msg, double value) {
	char str[msg.length() + 15];
	// TODO: See if this throws an error
	sprintf(str, "%s $f", msg.c_str(), value);
	DriverStation::ReportError(str);
}

