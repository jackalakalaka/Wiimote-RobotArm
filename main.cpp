#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include <cmath>
#include "WiimoteAccel.h" //include header file for WiimoteAccel
#include "ZedBoard.h" //include header for zedboard
#include "WiimoteToLed.h"
#include <unistd.h>
#include "RoboticArm.h"

int main()
{
        // Instantiate ZedBoard object statically
        ZedBoard zed_board;

        // Instantiate object statically, passing a pointer to the
        // recently created ZedBoard object.
	WiimoteToLed wiimote_to_led(&zed_board);        
 RoboticArm robotic_arm;

        

	//move arm to default values
	  robotic_arm.MoveServo(0, 90, 180);
		robotic_arm.MoveServo(1, 90, 180);
		robotic_arm.MoveServo(2, 90, 180);
		robotic_arm.MoveServo(3, 90, 180);
		robotic_arm.MoveServo(4, 90, 180);
                
        while (true)
        {
                 // Enter infinite loop listening to events. The overridden function
                 // WiimoteToLed::AccelerationEvent() will be invoked when the user moves
                 // the Wiimote.
                 //when a button and accel registerd, arm will move
                 wiimote_to_led.Listen(&robotic_arm);
		
                
           
        }
}


     /*code for throwing, ignore
     //Moving toward object movements: Bicep, Wrist, Gripper
                robotic_arm.MoveServo(1, 20, 45);
                robotic_arm.MoveServo(3, 50,45);
                sleep(5);
                
                //Gripping object movements
                robotic_arm.MoveServo(4, 0, 45);
                sleep(3);
                
                //Throwing object movements: Bicep, Wrist, Gripper
                robotic_arm.MoveServo(1, 95, 180);
                robotic_arm.MoveServo(3, 95, 140);
                sleep(.39);
                robotic_arm.MoveServo(4, 180, 30);
                sleep(10);
        */
