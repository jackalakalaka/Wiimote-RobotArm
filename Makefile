project: main.o  ZedBoard.o WiimoteAccel.o WiimoteToLed.o
	g++ main.o ZedBoard.o WiimoteAccel.o WiimoteToLed.o -o project 

main.o: main.cpp ZedBoard.h WiimoteAccel.h WiimoteToLed.h RoboticArm.h
	g++ -g -Wall -c main.cpp
 
WiimoteToLed.o: WiimoteToLed.cpp WiimoteToLed.h WiimoteAccel.h ZedBoard.h RoboticArm.h
	g++ -g -Wall -c WiimoteToLed.cpp

ZedBoard.o: ZedBoard.h ZedBoard.cpp
	g++ -g -Wall -c ZedBoard.cpp

WiimoteAccel.o: WiimoteAccel.cpp WiimoteAccel.h RoboticArm.h
	g++ -g -Wall -c WiimoteAccel.cpp
 
RoboticArm.o: RoboticArm.cpp RoboticArm.h
	g++ -g -Wall -c RoboticArm.cpp           

clean:
	rm main.o ZedBoard.o WiimoteAccel.o WiimoteToLed.o RoboticArm.h project 
