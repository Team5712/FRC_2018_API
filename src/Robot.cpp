#include <iostream>
#include <memory>
#include <string>

#include "Robot.h"

Robot::Robot()
{
	client = new Client();
}

Robot::~Robot()
{

}

void Robot::RobotInit()
{
}

void Robot::AutonomousInit()
{
	client->connect();
}

void Robot::AutonomousPeriodic()
{

}

void Robot::TeleopInit()
{

}

void Robot::TeleopPeriodic()
{

}

void Robot::TestPeriodic()
{

}


// OLD FORMATTING:
//class Robot: public frc::IterativeRobot {
//public:
//	void RobotInit() {
//
//	}
//
//	void AutonomousInit() override {
//
//	}
//
//	void AutonomousPeriodic() {
//
//	}
//
//	void TeleopInit() {
//
//	}
//
//	void TeleopPeriodic() {
//
//	}
//
//	void TestPeriodic() {
//
//	}
//
//private:
//
//
//
//};

START_ROBOT_CLASS(Robot)
