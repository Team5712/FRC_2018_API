/*
 * RobotCore.h
 *
 */

#ifndef SRC_ROBOTCORE_H_
#define SRC_ROBOTCORE_H_

#include "./ctre/phoenix/MotorControl/CAN/TalonSRX.h"
#include <WPILib.h>

#include "PortMapping.h"

class RobotCore {

public:
	RobotCore();
	virtual ~RobotCore();



private:

	CTRE::MotorControl::CAN::TalonSRX* leftMotor;
	CTRE::MotorControl::CAN::TalonSRX* rightMotor;

	RobotDriveBase* drive;

};

#endif /* SRC_ROBOTCORE_H_ */
