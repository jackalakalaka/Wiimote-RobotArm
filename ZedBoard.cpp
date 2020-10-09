/**
 * Program to create a ZedBoard class to perform 
 *		    regarding the board itself
 *
 * */
#include <iostream>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cmath>
#include "ZedBoard.h" //include header file


/**
 * * Initialize general-purpose I/O
 * * - Opens access to physical memory /dev/mem
 * * - Maps memory at offset 'gpio_address' into virtual address space
 * *
 * * @param fd File descriptor passed by reference, where the result
 * * of function 'open' will be stored.
 * * @return Address to virtual memory which is mapped to physical,
 * * or MAP_FAILED on error.
 * */
char *Initialize(int *fd)
{
        *fd = open( "/dev/mem", O_RDWR);
        return (char *) mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED                ,*fd, gpio_address);
}


/**Constructor for ZedBoard
 *
 *
 *
 * @param	none
 * @returns	none: just initializes the file mapping and reports errors
 * @brief	the constructor opens a virtual memory file and sets it to fd
 */
ZedBoard::ZedBoard(){ 
			pBase = Initialize(&fd);//initialize mapping. pass fd	
	
    // Check error
  	if (pBase == MAP_FAILED)
    {
      cout << "Mapping I/O memory failed - Did you run with 'sudo'?\n";
      exit(1); // Returns 1 to the operating system;
    }//end of if

}//end of constructor
		
/**Destructor for ZedBoard
 *
 *
 *
 * @param	none
 * @returns	none: just closes the file mapping 
 * @brief	the constructor closes a virtual memory file that is set to fd
 */
ZedBoard::~ZedBoard(){
			munmap(pBase, gpio_size);
			close(fd);
}//end of deconstrucotr





/**
 * * Write a 4-byte value at the specified general-purpose I/O location.
 * *
 * * @param pBase Base address returned by 'mmap'.
 * * @parem offset Offset where device is mapped.
 * * @param value Value to be written.
 * */
void ZedBoard::RegisterWrite(int offset, int value)
{
	* (int *) (pBase + offset) = value;
}


/**
* Read a 4-byte value from the specified general-purpose I/O location. 
*@param pBase Base address returned by 'mmap'.
*@param offset Offset where device is mapped.
*@return Value read.
*/
int ZedBoard::RegisterRead(int offset)
{
	return * (int *) (pBase + offset);
}


/**Changes the state of an LED (ON or OFF)
 *@param pBase 		base address of I/O
 *@param ledNum		LED number (0 to 7)
 *@param state		State to change to (ON or OFF)
 */	
void ZedBoard::Write1Led(int ledNum, int state)
{
	int ledOffset;		//variable to store the mem address of that LED
	
	//there is a constant difference of 4 memory blocs between each offsets
	//4*ledNum will produce the address offset from the first LED
	//as led 1 is refered to as LED number 0, the calcualtion can 
	//begin relative to that LED
	//thus led Offset = the address of led1 + the offset from led 1 
	ledOffset = gpio_led1_offset + (4 * ledNum);  	// the offset 

	//now that the correct location of the led is known, call RegisterWrite
	RegisterWrite(ledOffset, state); // write that the led should be on
}


/**Set the state of the LED's with the given value.
*
* @param pbase		base address for general-purpose I/O
* @param value		Value between 0 and 255 written to the LED's
*/
void ZedBoard::WriteAllLeds(int value)
{
	int countLed = 0; //counter for which Led being worked with. start at 0
	int state; // state to turn the LEd
	
	//convert the input decimal number to binary
	while(countLed!=8)
	{
		state = value%2; // the result of this is on/off
		Write1Led(countLed, state);// write to the led
		countLed++; //increment to lext led
		value = value/2; // divide nunber by 2 to prepare for next
	}//end of while
}//end of function WriteAllLeds

