/*
 * Robot.h
 *
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>

#include "Communication.h"

class Robot: public frc::IterativeRobot
{
public:
	Robot();
	~Robot();

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();

	Communication *comm;

};



#endif /* SRC_ROBOT_H_ */
