/*
 * RobotCore.h
 *
 */

#ifndef SRC_ROBOTCORE_H_
#define SRC_ROBOTCORE_H_

#include <vector>
#include "./ctre/phoenix/MotorControl/CAN/TalonSRX.h"
#include <WPILib.h>

#include "PortMapping.h"

class RobotCore {

public:
	RobotCore();
	virtual ~RobotCore();

	// BEGIN API FUNCTIONS
	// Documentation for all of the functions can be found here:
	// https://docs.google.com/document/d/179Ak10bY4e5jxSNROtnO94GOIJD48hIszoiiU598u3o/edit#
	double getRightEncoderTicks();
	double getLeftEncoderTicks();
	float getVelocity();
	void setVelocity(float velocity);
	float getVoltage();
	void setVoltage(float voltage);
	double getServoAngle(int servoIndex);
	void setServoAngle(int servoIndex, double angle);
	std::vector<std::vector<double>> getImage();
	std::vector<float> getJostickInput();
	// END API FUNCTIONS

private:

	CTRE::MotorControl::CAN::TalonSRX* leftMotor;
	CTRE::MotorControl::CAN::TalonSRX* rightMotor;

	Talon testTalon{1};
	DifferentialDrive* drive;
	DifferentialDrive differential{testTalon, testTalon};

};

#endif /* SRC_ROBOTCORE_H_ */
