#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           left3,         tmotorVex393HighSpeed_MC29, openLoop)
<<<<<<< HEAD
#pragma config(Motor,  port4,           puncher,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           intake,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           right1,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           right2,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          right3,        tmotorVex393HighSpeed_HBridge, openLoop, reversed)
=======
#pragma config(Motor,  port4,           left2,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           left1,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           right3,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           right2,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           right1,        tmotorVex393HighSpeed_MC29, openLoop)
>>>>>>> 9aae422c1c4deebf35760fd6988cc507c7e6a559
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

// PID using optical shaft encoder
//
// Shaft encoder has 360 pulses per revolution
//

#define LEFT_SENSOR_INDEX    leftEncoder
#define RIGHT_SENSOR_INDEX   rightEncoder
#define PID_SENSOR_SCALE     1

#define PID_MOTOR_SCALE     -1

#define PID_DRIVE_MAX       80
#define PID_DRIVE_MIN     (-80)

#define PID_INTEGRAL_LIMIT  50

// These could be constants but leaving
// as variables allows them to be modified in the debugger "live"
float  pid_Kp = 2.0;
float  pid_Ki = 0.04;
float  pid_Kd = 0.0;

static int   pidRunning = 1;
static float pidRequestedValue;

// SmartMotorLibrary
#include "jpearman/SmartMotorLib.c"
// Other files
#include "functions.c"

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
	SmartMotorLinkMotors(left1,left3);
	SmartMotorLinkMotors(right1,right2);
	SmartMotorLinkMotors(right1,right3);
	// Current monitor
	SmartMotorCurrentMonitorEnable();
	// Smart motor start
	SmartMotorRun();
}

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

}

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
	// Drive program
	while(true){
<<<<<<< HEAD
		drive();{
		}

		// Intake program
		if (vexRT[Btn5U]==1){
			motor[intake]=127;
			}else if (vexRT[Btn5D]==1){
			motor[intake]=-127;
			} else{
			motor[intake]=0;
		}

		// Puncher program
		if (vexRT[Btn6U]==1){
			motor[puncher]=127;
			} else{
			motor[puncher]=0;
		}


=======
		drive();
>>>>>>> 9aae422c1c4deebf35760fd6988cc507c7e6a559
	}
}
