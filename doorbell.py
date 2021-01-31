# Authors: Luke Olson and Brandon Imig
# Date: 1/30/2021
# This file plays a sound when it receives a signal over wifi

#TODO: Find way to detect a signal

import os

import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)

while 1:
    if(ser.readline()):
        os.system('/usr/bin/omxplayer /home/pi/Desktop/Fart.mp3')