#include "vex.h"

using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FR;
extern motor BR;

extern motor FL;
extern motor BL;

extern motor Grabber;


extern controller Controller1;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );