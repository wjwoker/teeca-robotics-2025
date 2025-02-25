#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FR = motor(PORT11, ratio18_1, true);
motor BR = motor(PORT12, ratio18_1, true);

motor FL = motor(PORT18, ratio18_1, false);
motor BL = motor(PORT19, ratio18_1, false);

motor Grabber = motor(PORT14, ratio18_1, false);


controller Controller1 = controller(primary);




// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  return;
}