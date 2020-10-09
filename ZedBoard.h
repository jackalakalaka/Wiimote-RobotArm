/**
 * Header file for the ZedBoard class to perform the functions  
 *			on the board itself
 *
 * */
#include <iostream>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cmath>

#ifndef ZEDBOARD_H
#define ZEDBOARD_H

using namespace std;


// Physical base address of GPIO
const unsigned gpio_address = 0x400d0000;

// // Length of memory-mapped IO window
const unsigned gpio_size = 0xff;

const int gpio_led1_offset = 0x12C; // Offset for LED1
const int gpio_led2_offset = 0x130; // Offset for LED2
const int gpio_led3_offset = 0x134; // Offset for LED3
const int gpio_led4_offset = 0x138; // Offset for LED4
const int gpio_led5_offset = 0x13C; // Offset for LED5
const int gpio_led6_offset = 0x140; // Offset for LED6
const int gpio_led7_offset = 0x144; // Offset for LED7
const int gpio_led8_offset = 0x148; // Offset for LED8

/**Class Defenition for ZedBoard class
* holds all the prototypes and variables of the class 
*/
class ZedBoard{
	private:
		char *pBase; //this varaible will be a private class variable
		int fd; //needs to file descriptor to use functions
	public:	
		//constructor prototypes
    //constructor prototypes
		ZedBoard(); //constructor prototype
    ~ZedBoard(); //destructor protype
   
		//below are function prototypes 
		void RegisterWrite(int offset, int value); 
		int RegisterRead(int offset);
		void Write1Led(int ledNum, int state); 
		void WriteAllLeds(int value);

};//end of class definition
   
#endif    
   
   
   
   
   