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

	drive = new DifferentialDrive(testTalon, testTalon);

	// Safety feature to prevent this call from hanging
	drive->SetExpiration(0.1);

}

RobotCore::~RobotCore() {
	// Upon de-constructing this object, disable the motors
	drive->TankDrive(0.0, 0.0);
}

double getRightEncoderTicks()
{

	return 0.0;
}
double getLeftEncoderTicks()
{

	return 0.0;
}

float getVelocity()
{

	return 0.0f;
}
void setVelocity(float velocity)
{

}

float getVoltage()
{

	return 0.0f;
}
void setVoltage(float voltage)
{

}

double getServoAngle(int servoIndex)
{

	return 0.0;
}
void setServoAngle(int servoIndex, double angle)
{

}

std::vector<std::vector<double>> getImage()
{
	std::vector<std::vector<double>> rgbComp;

	// RGB components
	rgbComp.push_back(std::vector<double>()); // R
	rgbComp.push_back(std::vector<double>()); // G
	rgbComp.push_back(std::vector<double>()); // B

	return rgbComp;
}
std::vector<float> getJostickInput()
{
	std::vector<float> inputs;

	return inputs;
}




