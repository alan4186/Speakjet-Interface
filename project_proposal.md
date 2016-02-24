# Project Proposal

Alan Ehret

Speakjet IC interface

## What is the Speakjet IC
The Speakjet is a small synthesizer in an 18 pin DIP package.  It can generate a large number of sound effects or natural speech.  It has one analog output for a speaker and one serial port to receive commands from a master device.  The Speakjet also has 8 "event inputs" to quickly execute predetermined phrases.  The Speakjet has a demonstration mode and software so that a user can start making noise quickly as well as a small dictionary of words formatted to be sent to the Speakjet over the serial port.  However there is no library for micro-controllers to interface with the Speakjet.

## Project Goals
I will write a simple set of functions for a micro-controller to execute and control the Speakjet.  I will attempt to fit the Speakjet's dictionary in the micro-controllers memory so that the embedded system can create dynamic speech beyond a few hard coded phrases.  Fitting the entire Speakjet Dictionary in the memory of an ATMEGA328p will be a challenge because the dictionary is 52kB and the ATMEGA328p has only 32KB of flash memory.  
