/*
 * PortMapping.h
 *
 */

#ifndef SRC_PORTMAPPING_H_
#define SRC_PORTMAPPING_H_

/**
 * Class that will define all (or the majority of) the ports for the
 * different devices on the Robot. This allows for easy access to
 * all of the ports, and will enable easy changing if devices
 * are switched around or moved.
 */
class PortMapping
{
public:

	// Motor controller mappings
	static const int LEFT_MOTOR_PORT = 1;
	static const int RIGHT_MOTOR_PORT = 2;

};



#endif /* SRC_PORTMAPPING_H_ */
