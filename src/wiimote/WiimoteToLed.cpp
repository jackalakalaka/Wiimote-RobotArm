/**
 * cpp file for the ZedBoard class to perform the functions  
 *		    regarding the LED's
 *
 * */
 
 
//Library includes
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include <cmath>
#include "WiimoteToLed.h" //include header file
#include "ZedBoard.h" //include zedbaord header to use its functions
#include "RoboticArm.h"

/**Constructor for WiimoteToLed
 *
 *
 *
 * @param	constructor will take a ZedBoard object pointer
 * @returns	none: saves the pointer to the private field *zed
 * @brief	        the constructor takes in an ibject poitner 
                  for Zedboard and stores it in the private variable
 */
WiimoteToLed::WiimoteToLed(ZedBoard *zedBoard){
      //set the private variable zed to the argument
      zed = zedBoard;
}//end of class constructor


/**
 * Function Definition for AccelerationEvent
 * 
 *
 * @param code:      takes in code to know which axis is being used
 *                   acceleration is code 3. actions are only taken
 *                    when code=3
 * @param acceleration:  takes in the acceleration value 
 *                       the value is only relevant if code =3
 * @return:              none: the correct number of LED's turned on bc Accel
 * @brief:                the function determines if there was an Accel and 
 *                        turns on the right number of LED based on its value
 *					"+" -> use for base
 *					"1" -> use for bicep
 *					"2" -> use for elbow
 * 					"A" -> use for wrist
 *					"B" -> use for gripper
 */
void WiimoteToLed::Events(int accelCode, int acceleration, int buttonCode, int buttonVal, RoboticArm *robotic_arm){

      

sleep(1);
//determine if code = 4. use button press to adjust angle
  if(accelCode == 4){ // y axis 
     
      //truncate the values to a range of -100 to 100 (use math.abs())
      //try to truncate it such that the numbers will be in the range 0-7
      //a good way is to multiply by (8/100)
      //the 100 puts all values in a range of 0-1 (0/100=0, 100/100=1)
      //multiplying by 8 then casts all those values back up to a range
      //0-180 (0*180=0, 1*180 =180)
      
      int truncAccel = 90 + (90 * ((double)acceleration/100.0));
         
    //adjsut button inputs to code to right thing for robotic arm
    switch(buttonCode){
      case 151://case for when plus button hit (base)
      {
        buttonCode = 0; //set code value to the right servo -> base when plus
         robotic_arm->baseAngle = truncAccel; //adjust base angle to the adjsuted accel
         robotic_arm->MoveServo(buttonCode, robotic_arm->baseAngle, 90);
	  usleep(200000);//stop loop to give it a chance to move 
        break;
      }//end of case for plus button
      case 1: //case when 1 (bicep hit)
      {
        robotic_arm->bicepAngle = truncAccel; //adjust bicep to accel value
        robotic_arm->MoveServo(buttonCode, robotic_arm->bicepAngle, 90);
     usleep(200000);//stop loop to give it a chance to move    
	break;
      }//end of bicep case
      case 2: //case when 2 (elbow) hit
      {
        robotic_arm->elbowAngle = truncAccel;
        robotic_arm->MoveServo(buttonCode,robotic_arm->elbowAngle, 90);
	usleep(200000);//stop loop to give it a chance to move 
        break;
      }//end of elbow case
      case 48: //case for "a" hit for wrist (servo 3) pressed
      {
        buttonCode = 3; //set code to 3 for a button 
        robotic_arm->wristAngle = truncAccel;
        robotic_arm->MoveServo(buttonCode, robotic_arm->wristAngle, 90);
     	usleep(200000);//stop loop to give it a chance to move    
	break;
      }//end of "a" case
      case 49: 
      {
        buttonCode =4; //case for when "b" - gripper -pressed
       robotic_arm-> gripperAngle = truncAccel;
        robotic_arm->MoveServo(buttonCode, robotic_arm->gripperAngle, 90);
	usleep(200000);//stop loop to give it a chance to move 
        break;
      }//end of "B" case
    }//end of switch
    
      
      
  }//end of if
  //if the code is not 3. the function is not needed
 
}//end of AccelerationEvent definition
