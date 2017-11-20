/*
 * Communication.cpp
 */

#include "Communication.h"

Communication::Communication() {

	connector = new TCPConnector(); // Optional line
	connect();
	lastDump = steady_clock::now();

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

void Communication::update()
{

	if(chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - lastDump).count() >= DUMP_INTERVAL)
	{
		lastDump = steady_clock::now();
	}

}

std::string Communication::listen()
{

	while(true) {

		// if pointer has been assigned eg. connected to a client.
		if(stream != NULL) {


			vector<char> buffer;

			ssize_t len;
			char line[256];
			int size = 0;


			// while the data we recieve into
			while ((len = stream->receive(line, sizeof(line), 5/*5s timeout*/)) > 0)
			{
				size += len;
				for(auto i = 0; i < len; i++)
					buffer.push_back(line[i]);
			}

			json commands = json::parse(buffer);

        	char str[80];
        	sprintf(str, "Json Recieved");
        	DriverStation::ReportError(str);
		}
	}

}

void Communication::sendData(json data) {


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

