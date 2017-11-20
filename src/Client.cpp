#include "Client.h"


void Client::connect() {
	 //if pointer has been assigned eg. connected to the server
	if((stream = connector->connect(REMOTE_ADDR, REMOTE_PORT)) != NULL) {
		cout << "connected to server!" << endl;
	} else {
		throw -1;
	}

	// need to resolve errors
//	thread t1(&Client::recieve, this);
//	t1.detach();

	recieve();
}

void Client::recieve() {

	chrono::steady_clock::time_point start = chrono::steady_clock::now();

	while(true) {

		//send data or something to the jetson at a set interval
		if(chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() >= UPDATE_INTERVAL) {
			start = chrono::steady_clock::now();

			sendData();
		}

		vector<char> buffer;

		ssize_t len;
		char line[256];
		int size = 0;


		// while the data we receive into is greater than 0
		while ((len = stream->receive(line, sizeof(line), 5)) > 0)
		{
			size += len;
			DriverStation::ReportError(line);
			for(auto i = 0; i < len; i++)
				buffer.push_back(line[i]);
		}

		//commands = charToJson(buffer);
		DriverStation::ReportError("JSON Received!");
		cout << charToJson(buffer) << endl;
	}

}

size_t Client::jsonToChar(json j, char data[]) {
	string decodedjson = j.dump();
	strcpy(data, decodedjson.c_str());

	return decodedjson.length();
}

json Client::charToJson(const char* data) {
	string strdata(data);
	return json::parse(strdata);
}

json Client::charToJson(vector<char> data) {
	string strdata(data.begin(), data.end());
	return json::parse(strdata);
}



void Client::sendData() {
	stream->send("hey now", 9);
}
