#!/bin/bash
# WiimoteConnect.bash

bluez-simple-agent hci0 8C:56:C5:40:04:41 
bluez-test-device trusted 8C:56:C5:40:04:41 yes
bluez-test-input connect 8C:56:C5:40:04:41 



