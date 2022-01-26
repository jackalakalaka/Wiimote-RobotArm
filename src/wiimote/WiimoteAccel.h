/**
 * header for the WiimoteAccel Class
 * 		as the code described in 4.6 of the lab
 *
 */
#ifndef WIIMOTEACCEL_H
#define WIIMOTEACCEL_H

//Library includes
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include "RoboticArm.h"

/** 
 *Class Defenition of WiimoteAccel
 *
 *
 *@param	none: just lists the variables and function prototypes
 *@returns	none: just creates the variables and function protoypes
 *@brief	covnerts the code from part 4.6 of the lab to a C++ class
 * */
class WiimoteAccel{
	//list private variables and functions
	private:
		int fda;
    int fdb;
	//list public variables and functions
	public:
		//constructor for the class 
		WiimoteAccel();
	
		//destructor for the file
		~WiimoteAccel();
	
		//function to listen for events
		void Listen(RoboticArm *robotic_arm);
		
   //function to see if code is 3
    bool tilted(int code);
    
		//function that displays a message screen reporting values
		virtual void Events(int accelCode, int acceleration,int buttonCode, int buttonVal, RoboticArm *robotic_arm)=0;
		
};//end of class defenition

#endif
