/**
 * Implementation to create a C++ class to do the same thing
 * 		as the code described in 4.6 of the lab
 *
 */

//Library includes
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include "WiimoteAccel.h" //include header file

/**Constructor for WiimoteAccel
 *
 *
 *
 * @param	none
 * @returns	none: just opens the file and reports errors
 * @brief	the constructor opens a virtual memory file and sets it to fd
 */
WiimoteAccel::WiimoteAccel(){
	//open /dev/input/events0 
	//assign the open call to fd
	fda = open("/dev/input/event0", O_RDONLY);
	  
  //buttons   
  fdb = open("/dev/input/event2", O_RDONLY | O_NONBLOCK);
	
	//check for errors in opening the file
	if(fda == -1){//accel
		std::cerr << "Error: Could not open the event file -";
		std::cerr << " forgot sudo?\n";
		exit(1);
   }
   if(fdb == -1){//button
		std::cerr << "Error: Could not open the event file -";
		std::cerr << " forgot sudo?\n";
		exit(1);
	}//end of if
}//end of class constructor


/**Function for Listen
 *
 * @param	none: function just listens for events
 * @return	none: just passes button events in the form
 *			of a code and a value to another function
 * @brief	function enters an infinite loop where a new event 
 * 			is read from the virtual file
 * 			when an event is ready, its associated code and accel
 * 			are passed to AccelerationEvent by invoking it
 * */
void WiimoteAccel::Listen(RoboticArm *robotic_arm){
     
	//create an infinite loop to listen for a new event
	while (true)
	{
     //read for accels
               // Read a packet of 16 bytes from Wiimote
               char buffer[16];
               read(fda, buffer, 16);
              
               // Extract code (byte 10) and value (byte 12) from packet
               int accelCode = buffer[10];
               short acceleration = * (short *) (buffer + 12);
                              
              
               
               
               //read for btns
               // Read a packet of 32 bytes from Wiimote
               char bufferBtns[32];
               read(fdb, bufferBtns, 32);
                
               // Extract code (byte 10) and value (byte 12) from packet
               int buttonCode = bufferBtns[10];
               int buttonVal = bufferBtns[12]; 
     
	
	
		//pass the values to Acceleration Event()
		Events(accelCode, acceleration, buttonCode, buttonVal, robotic_arm);
   
   
   
   
	}//end of while loop
}//end of listen function

/**Function for ButtonEvent()
 *
 * @brief:		Declare as virtual so it can later be inherited 
 * @param code		the code representing a specific button is gained
 * 			it will be 10 bytes and from the packet
 * 			there will be codes for each button
 *
 * @param acceleration	the acceleration from the packet and contain 12 bytes 
 * 			what acceleration the remote underwent
 * @return		none: function just prints out the code and accel
 */
/*void WiimoteAccel::AccelerationEvent(int code, int acceleration){
	//print out the code and value
	std::cout << "Code = " << code << 
			", acceleration = " << acceleration << '\n'; 
   
}//end of AccelerationEvent function
*/
/**Class destructor for WiimoteBtns
 *
 * @param 	none: fd can be accessed by the destructor already
 * @return	0 is returned after the file is closed
 * @brief	the destructor simply calls close on fd and returns 0	
 *
 */
WiimoteAccel::~WiimoteAccel(){
	//close the file using the file descriptor
	close(fda);
  close(fdb);
}//end of class destructor

