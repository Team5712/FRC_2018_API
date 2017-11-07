/*
 * RobotCore.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: robotics
 */

#include <RobotCore.h>
#include "RobotCore.h"

using namespace CTRE::MotorControl::CAN;

RobotCore::RobotCore() {

	// Initialize the parts of RobotCore here
	leftMotor = new TalonSRX(PortMapping::LEFT_MOTOR_PORT);
	rightMotor = new TalonSRX(PortMapping::RIGHT_MOTOR_PORT);

	drive = new DifferentialDrive(leftMotor, rightMotor);

	// Safety feature to prevent this call from hanging
	drive->SetExpiration(0.1);

}

RobotCore::~RobotCore() {
}

