/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Wyatt Woker                                               */
/*    Created:      2/21/2025, 5:06:32 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "robot-config.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

//Print centered text in exact center of workable area
/*
void printCenteredText(std::string input, fontType font) {
  //Turning our input into a char array
  char inputc[input.length()+1];
  strcpy(inputc, input.c_str());

  Brain.Screen.setFont(font);
  int x = 240-(Brain.Screen.getStringWidth(inputc)/2);
  int y = 120-(Brain.Screen.getStringHeight(inputc)/2);
  Brain.Screen.printAt(x, y, true, inputc);
}*/

void moveStraight(double dist, int speed = 50) {
  double bigTarget = (dist/15.7079632679)*360;
  double smallTarget = (dist/12.566370614)*360;

  FR.spinFor(directionType::fwd, bigTarget, rotationUnits::deg, speed, velocityUnits::pct, false);
  BR.spinFor(directionType::fwd, bigTarget, rotationUnits::deg, speed, velocityUnits::pct, false);
  
  FL.spinFor(directionType::fwd, bigTarget, rotationUnits::deg, speed, velocityUnits::pct, false);
  BL.spinFor(directionType::fwd, bigTarget, rotationUnits::deg, speed, velocityUnits::pct, true);
}

void turnDeg(float deg, bool dir) {
  deg = deg*5.6;
  if(dir) {
    FR.spinFor(directionType::rev, deg, rotationUnits::deg, 25, velocityUnits::pct, false);
    BR.spinFor(directionType::rev, deg, rotationUnits::deg, 25, velocityUnits::pct, false);
    
    FL.spinFor(directionType::fwd, deg, rotationUnits::deg, 25, velocityUnits::pct, false);
    BL.spinFor(directionType::fwd, deg, rotationUnits::deg, 25, velocityUnits::pct, true);
  } else {
    FR.spinFor(directionType::fwd, deg, rotationUnits::deg, 25, velocityUnits::pct, false);
    BR.spinFor(directionType::fwd, deg, rotationUnits::deg, 25, velocityUnits::pct, false);
    
    FL.spinFor(directionType::rev, deg, rotationUnits::deg, 25, velocityUnits::pct, false);
    BL.spinFor(directionType::rev, deg, rotationUnits::deg, 25, velocityUnits::pct, true);
  }
}

void pre_auton(void) {
  /*
  Brain.Screen.setOrigin(0, 32);

  FR.setBrake(brakeType::brake);
  MR.setBrake(brakeType::brake);
  BR.setBrake(brakeType::brake);

  FL.setBrake(brakeType::brake);
  ML.setBrake(brakeType::brake);
  BL.setBrake(brakeType::brake);

  intakeFront.setBrake(brakeType::brake);
  intakeBack.setBrake(brakeType::brake);
  intakeTop.setBrake(brakeType::brake);

  intakeBack.setMaxTorque(0.7,torqueUnits::Nm);
  */
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

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  
  /*
  moveStraight(24);
  wait(900, timeUnits::msec);
  turnDeg(45, true);
  wait(900, timeUnits::msec);
  moveStraight(12);
  wait(900, timeUnits::msec);
  turnDeg(45, false);
  wait(900, timeUnits::msec);
  moveStraight(60, 70);
  wait(900, timeUnits::msec);
  turnDeg(45, true);
  wait(900, timeUnits::msec);
  moveStraight(40);
  wait(900, timeUnits::msec);
  turnDeg(40, false);
  wait(900, timeUnits::msec);
  moveStraight(10);
  wait(900, timeUnits::msec);
  unload();
  */
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

void usercontrol(void) {
  // User control code here, inside the loop

  // Printing to the screen
  vex::color c = vex::color(207, 185, 145);
  Brain.Screen.setPenColor(c);
  //printCenteredText("Boiler Up!!", mono60);

  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //Tying the drive to the joysticks

    int leftStick = Controller1.Axis3.value();
    int rightStick = Controller1.Axis1.value();

    int rightMotors = leftStick - rightStick;
    int leftMotors = leftStick + rightStick;

    FR.spin(directionType::fwd, rightMotors, velocityUnits::pct);
    BR.spin(directionType::fwd, rightMotors, velocityUnits::pct);

    FL.spin(directionType::fwd, leftMotors, velocityUnits::pct); 
    BL.spin(directionType::fwd, leftMotors, velocityUnits::pct);


    // Toggling the intake
    if (Controller1.ButtonA.pressing()) {
      Grabber.spinToPosition(-150, degrees, false);
    }

    if (Controller1.ButtonB.pressing()) {
      Grabber.spinToPosition(0, degrees, false);
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}