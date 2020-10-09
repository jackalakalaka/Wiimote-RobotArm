/**
 * Header file for the ZedBoard class to perform the functions  
 *		    regarding the LED's
 *
 * */
 #ifndef WIIMOTETOLED_H
#define WIIMOTETOLED_H

#include <iostream>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cmath>
//include headerfiles from other classes
#include "WiimoteAccel.h"
#include "ZedBoard.h"
#include "RoboticArm.h"



using namespace std;


/**
 * * Class Definition for WiimoteToLed (inherits from WiiMoteAccel) 
 * * @param    constructor will take a ZedBoard object pointer
 * *
 * * @return    none: the class just deals with interactions between the mote
 * *            and the LED's on the board 
 * */
class WiimoteToLed:public WiimoteAccel{
  private:
  	//private zedboard object pointer
  	ZedBoard *zed;
  public:
	//class constructor protype. takes *Zedboard object
	WiimoteToLed(ZedBoard *zedBoard);

	//overides the virtual function from the parent class
	void Events(int accelCode, int acceleration, int buttonCode, int buttonVal, RoboticArm *robotic_arm);
}; //end of class definition

#endif
