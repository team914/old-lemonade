#pragma config(Sensor, in1,    leftPotent,     sensorPotentiometer)
#pragma config(Sensor, in2,    rightPotent,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           left1,         tmotorVex393HighSpeed_HBridge, openLoop, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port2,           left2,         tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           left3,         tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           leftlift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           intake,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           puncher,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightlift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           right1,        tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port9,           right2,        tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port10,          right3,        tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

// SmartMotorLibrary
#include "jpearman/SmartMotorLib.c"

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
	SmartMotorLinkMotors(left1,right3);

	// Lift motors
	SmartMotorLinkMotors(leftlift,rightlift);

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

// Sensors and driver control functions

// Lift potentiometers
int liftPotent(){
	return(((SensorValue[leftPotent])*(SensorValue[rightPotent]))/2);
}

// Drive encoders
int leftDriveEncode(){
	return(SensorValue[leftEncoder]);
}
int rightDriveEncode(){
	return(SensorValue[rightEncoder]);
}
// Drive function
void driveFunc(int power1, int power2){
	SetMotor(left1,power1);
	SetMotor(right1,power2);
	SetMotor(left2,power1);
	SetMotor(right2,power2);
	SetMotor(left3,power1);
	SetMotor(right3,power2);
}

// User control drive functions
void drive(){
	driveFunc(vexRT[Ch2], vexRT[Ch3]);
}

// Lift function
void liftFunc(int power){
	SetMotor(leftlift,power);
	SetMotor(rightlift,power);
}

// User control lift functions
void liftUp(){
	SetMotor(leftlift,100);
	SetMotor(rightlift,100);
}
void liftDown(){
	SetMotor(leftlift,-100);
	SetMotor(rightlift,-100);
}
void liftStay(){
	SetMotor(leftlift,0);
	SetMotor(rightlift,0);
}

// User control flipper functions
//void flipperUp(){
//	SetMotor(flipper,100);
//}
//void flipperDown(){
//	SetMotor(flipper,-50);
//}
//void flipperStay(){
//	SetMotor(flipper,0);
//}

// User control claw functions
//void clawOpen(){
//	SetMotor(claw,25);
//}
//void clawClose(){
//	SetMotor(claw,-50);
//}
//void clawStay(){
//	SetMotor(claw,0);
//}

// User control intake functions
void intakeUp(){
	SetMotor(intake,100);
}
void intakeDown(){
	SetMotor(intake,-100);
}
void intakeStay(){
	SetMotor(intake,0);
}

// User control puncher functions
void puncherShoot(){
	SetMotor(puncher,80);
}
void puncherStay(){
	SetMotor(puncher,0);
}

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
		drive();
	}

	// Lift program
	if(vexRT[Btn6U]==1){
		liftUp();
		}else if (vexRT[Btn6D]==1){
		liftDown();
		}else {
		liftStay();
	}

	// Flipper program
	//if (vexRT[Btn8U]==1){
	//	flipperUp();
	//	}else if(vexRT[Btn8D]==1){
	//	flipperDown();
	//	}else {
	//	flipperStay();
	//}

	// Claw program
	//if (vexRT[Btn8R]==1){
	//	clawOpen();
	//	}else if(vexRT[Btn8L]==1){
	//	clawClose();
	//	}else {
	//	clawStay();
	//}

	// Intake program
	if (vexRT[Btn5U]==1){
		intakeUp();
		}else if(vexRT[Btn5D]==1){
		intakeDown();
		}else {
		intakeStay();
	}

	// Puncher program
	if (vexRT[Btn7U]==1){
		puncherShoot();
		}else {
		puncherStay();
	}

}
