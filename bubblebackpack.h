/*
  bubblebackpack.h - A library for The Bubble Backpacks
  By TinkerTroniks.com
  Created by Serg, May 27, 2015.
  Updated December 16, 2015
  Released into the public domain.
*/


#ifndef bubblebackpack_H
#define bubblebackpack_H

#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif




class BubbleBackpack {
    int _csPin, _clkPin, _dinPin;
    int _numberOfDigits, _cascadedDevices;
  public:
    // Sets up data pins connected to the display
    // Free to use any digital IO pin but its best to avoid pin 0 and 1.
    BubbleBackpack(int clkPin, int csPin, int dinPin);

    // Initates The Bubble Backpack in form: (Number of digits on the backpack (4 or 8), Number of backpacks cascaded together)
    void setUpDisplay(int numberOfDigits, int numberOfDisplays);

    // Clears the display
    void clearDisplay(void);
    
    // Puts device in Shutdown Mode
    // Device still retains data and consumes about 150uA
    void shutDown(boolean shutItDown);

    // Set the display intensity from 0 to 15
    void setDisplayIntensity(int intensity);

    // Sets the digit at position 0 - 7 to the desired value
    void writeDigit(int digit, int value, int numDisplays);

    // Turns on a specific segment at 0 = dot, A = 1 ... G = 7.
    void writeSegment(int digit, int segment, int numDisplays);

    // Runs through 0 - 9 on every digit, on every display.
    void quickTest(void);

    // Reads data from serial and writes it to the display
    void readFromSerial(void);

    // Returns the number of  cascaded displays
    int numOfDisplays(void) {
      return _cascadedDevices;
    }

    // Returns the number of digits per display
    int numOfDigits(void) {
      return _numberOfDigits;
    }

    // Transfers data to the chip.
    // Adress 1 = first board, Adress 2 = the second cascaded board (one who's DIN is connected to the first board's DOUT)
    void spiTransfer(byte reg, byte data, int adress);
};

#endif
