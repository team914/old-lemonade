#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  jumper5,        sensorTouch)
#pragma config(Sensor, dgtl6,  jumper6,        sensorTouch)
#pragma config(Sensor, dgtl7,  jumper7,        sensorTouch)
#pragma config(Sensor, dgtl8,  jumper8,        sensorTouch)
#pragma config(Sensor, dgtl9,  jumper9,        sensorTouch)
#pragma config(Sensor, dgtl10, jumper10,       sensorTouch)
#pragma config(Sensor, dgtl11, jumper11,       sensorTouch)
#pragma config(Sensor, dgtl12, jumper12,       sensorTouch)
#pragma config(Motor,  port1,           left1,         tmotorVex393HighSpeed_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port2,           left2,         tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           intake1,       tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           puncher1,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           puncher2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           puncher3,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           intake2,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           right1,        tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port10,          right2,        tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Auton vars (for PID)
// Left
/*float  pid_Kp = 0.7;
float  pid_Ki = 0.03;
float  pid_Kd = 0.1;

// Right
float  pd_Kp = 1.0;
float  pd_Ki = 0.00;
float  pd_Kd = 0.4;*/

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

// SmartMotorLibrary
#include "jpearman/SmartMotorLib.c"
// Joystick Controls
// #include "JoystickDriver.c"
// Other files
#include "functions.c"
#include "auton.c"
// #include "leftPID.c"

#include "Vex_Competition_Includes.c"  // Main competition background code...do not modify!
#pragma systemFile

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

// Main competition background code...do not modify!

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
	// Enable smart motor library
	SmartMotorsInit();

	// Define motors plugged into power expander
	// SmartMotorsAddPowerExtender( motorA, motorB, motorC, motorD );

	// Link motors
	// Drive motors
	SmartMotorLinkMotors(left1,left2);
	SmartMotorLinkMotors(right1,right2);
	// Intake motors
	SmartMotorLinkMotors(intake1,intake2);
	// Puncher motors
	SmartMotorLinkMotors(puncher1,puncher2);

	// Current monitor
	SmartMotorCurrentMonitorEnable();
	// Smart motor start
	SmartMotorRun();

	// Reset encoders
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
} // End of task pre_auton

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{

	/*if(SensorValue[jumper5]==1){
	autonR();
	}
	if(SensorValue[jumper6]==1){
	autonB();
	}*/
	if(SensorValue[jumper7]==1){ // 100%
		autonR1(); // Red flag 3 pt.
	}
	if(SensorValue[jumper8]==1){ // 100%
		autonB1(); // Blue flag 3 pt.
	}
	if(SensorValue[jumper9]==1){
		autonR3(); // Red cap 4 pt.
	}
	if(SensorValue[jumper10]==1){
		autonB3(); // Blue cap 4 pt.
	}
	if(SensorValue[jumper11]==1){
		autonR2(); // Red flag 6 pt.
	}
	if(SensorValue[jumper12]==1){
		autonB2(); // Blue flag 6 pt.
	}

} // End of task autonomous

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

// User control code here, inside the loop

// This is the main execution loop for the user control program.
// Each time through the loop your program should update motor + servo
// values based on feedback from the joysticks.

// ........................................................................
// Insert user code here. This is where you use the joystick values to
// update your motors, etc.
// ........................................................................

task usercontrol()
{
	while(true){

		// Drive program
		drive();{
			if (vexRT[Ch3] > 10){
				intakeIn();
				} else if (vexRT[Ch2] > 10){
				intakeIn();
				} else if (vexRT[Ch3] < 10){
				intakeStay();
				} else if (vexRT[Ch2] < 10){
				intakeStay();
			}
		}

		// Intake program
		if (vexRT[Btn6D]==1){ // Right bottom trigger
			intakeIn();
			}else if (vexRT[Btn5U]==1){ // Left top trigger
			intakeOut();
		} /*else{
		intakeStay();
		}*/

		// Puncher program
		if (vexRT[Btn6U]==1){ // Right top trigger
			puncherShoot();
			} else{
			puncherStay();
		}

	} // End of while true
} // End of task usercontrol
