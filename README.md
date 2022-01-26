# Wiimote-RobotArm: C++ module
An exploration of the controlling of a Robotic Arm's servo motors via a Wiimote, using a combined software (C++) & hardware (Simulink) Zedboard FPGA-and-ARM-processor system.
## Project summary
Using Simulink, a configurable speed in degrees per second for the robotic arm to move at was established using two comparators and a counter. Along with the speed setter,
an angle input was added to the design such that a certain servo would go to a position between 0 and 180 degrees in a certain amount of time. This design was verified
through testing, and an AXI interface was then connected to the Zedboard for software development. Both of these processes were done using an HDL Workflow Advisor. With
the angle and speed inputs manipulable, a relatively simple C++ program was written and tested multiple times that successfully picked up a whiteboard eraser and threw
it at teammate Nicholas Rizzo! The experiment concluded with the task of controlling the arm freely with a Wiimote. This was made possible by first establishing a Bluetooth
connection, and was successfully completed through numerous additions to and tests concerning a given set of C++ header, source, and main files.
