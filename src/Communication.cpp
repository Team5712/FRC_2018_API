///*
// * Communication.cpp
// */
//
//#include "Communication.h"
//
//Communication::Communication() {
//
//	connector = new TCPConnetor(connectionIP, PORT);
//
//}
//
//
//Communication::~Communication() {
//
//}
//
//void Communication::connect() {
//
//	stream = socket->connect("2323", 9000, 1000000);
//
//	if(socket != NULL) {
//
//    	char str[80];
//    	sprintf(str, "Connected to El Jetson");
//    	DriverStation::ReportError(str);
//	}
//}
//
//
//std::string Communication::listen()
//{
//
//	while(true) {
//
//		// if pointer has been assigned eg. connected to a client.
//		if(stream != NULL) {
//
//
//			vector<char> buffer;
//
//			ssize_t len;
//			char line[256];
//			int size = 0;
//
//
//			// while the data we recieve into
//			while ((len = stream->receive(line, sizeof(line), 5/*5s timeout*/)) > 0)
//			{
//				size += len;
//				for(auto i = 0; i < len; i++)
//					buffer.push_back(line[i]);
//			}
//
//			json commands = json::parse(buffer);
//
//        	char str[80];
//        	sprintf(str, "Json Recieved");
//        	DriverStation::ReportError(str);
//		}
//	}
//
//}
//
//void Communication::sendData(json data) {
//
//
//}
