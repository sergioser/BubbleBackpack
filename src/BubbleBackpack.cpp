/*
  BubbleBackpack.cpp - A library for The Bubble Backpacks
  By TinkerTroniks.com
  Created by Serg, May 27, 2015.
  Updated June 6, 2015
  Released into the public domain.
*/
#include "BubbleBackpack.h" 

const static byte  digitReg[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
const static byte  fontArray[] = {
  0b1111110, // 0
  0b0110000, // 1
  0b1101101, // 2
  0b1111001, // 3
  0b0110011, // 4
  0b1011011, // 5
  0b1011111, // 6
  0b1110000, // 7
  0b1111111, // 8
  0b1111011, // 9
  0b1110111, // 10  "A"
  0b0011111, // 11  "B"
  0b1001110, // 12  "C"
  0b0111101, // 13  "D"
  0b1001111, // 14  "E"
  0b1000111, // 15  "F"
  0b0000000, // 16  NO DISPLAY
  0b0000000, // 17  NO DISPLAY
  0b0000000, // 18  NO DISPLAY
  0b0000000, // 19  NO DISPLAY
  0b0000000, // 20  NO DISPLAY
  0b0000000, // 21  NO DISPLAY
  0b0000000, // 22  NO DISPLAY
  0b0000000, // 23  NO DISPLAY
  0b0000000, // 24  NO DISPLAY
  0b0000000, // 25  NO DISPLAY
  0b0000000, // 26  NO DISPLAY
  0b0000000, // 27  NO DISPLAY
  0b0000000, // 28  NO DISPLAY
  0b0000000, // 29  NO DISPLAY
  0b0000000, // 30  NO DISPLAY
  0b0000000, // 31  NO DISPLAY
  0b0000000, // 32 ' '
  0b0000000, // 33 '!'  NO DISPLAY
  0b0100010, // 34 '"'
  0b0000000, // 35 '#'  NO DISPLAY
  0b0000000, // 36 '$'  NO DISPLAY
  0b0000000, // 37 '%'  NO DISPLAY
  0b0000000, // 38 '&'  NO DISPLAY
  0b0100000, // 39 '''
  0b1001110, // 40 '('
  0b1111000, // 41 ')'
  0b0000000, // 42 '*'  NO DISPLAY
  0b0000000, // 43 '+'  NO DISPLAY
  0b0000100, // 44 ','
  0b0000001, // 45 '-'
  0b0000000, // 46 '.'  NO DISPLAY
  0b0000000, // 47 '/'  NO DISPLAY
  0b1111110, // 48 '0'
  0b0110000, // 49 '1'
  0b1101101, // 50 '2'
  0b1111001, // 51 '3'
  0b0110011, // 52 '4'
  0b1011011, // 53 '5'
  0b1011111, // 54 '6'
  0b1110000, // 55 '7'
  0b1111111, // 56 '8'
  0b1111011, // 57 '9'
  0b0000000, // 58 ':'  NO DISPLAY
  0b0000000, // 59 ';'  NO DISPLAY
  0b0000000, // 60 '<'  NO DISPLAY
  0b0000000, // 61 '='  NO DISPLAY
  0b0000000, // 62 '>'  NO DISPLAY
  0b0000000, // 63 '?'  NO DISPLAY
  0b0000000, // 64 '@'  NO DISPLAY
  0b1110111, // 65 'A'
  0b0011111, // 66 'B'
  0b1001110, // 67 'C'
  0b0111101, // 68 'D'
  0b1001111, // 69 'E'
  0b1000111, // 70 'F'
  0b1011110, // 71 'G'
  0b0110111, // 72 'H'
  0b0110000, // 73 'I'
  0b0111000, // 74 'J'
  0b0000000, // 75 'K'  NO DISPLAY
  0b0001110, // 76 'L'
  0b0000000, // 77 'M'  NO DISPLAY
  0b0010101, // 78 'N'
  0b1111110, // 79 'O'
  0b1100111, // 80 'P'
  0b1110011, // 81 'Q'
  0b0000101, // 82 'R'
  0b1011011, // 83 'S'
  0b0001111, // 84 'T'
  0b0111110, // 85 'U'
  0b0000000, // 86 'V'  NO DISPLAY
  0b0000000, // 87 'W'  NO DISPLAY
  0b0000000, // 88 'X'  NO DISPLAY
  0b0111011, // 89 'Y'
  0b0000000, // 90 'Z'  NO DISPLAY
  0b1001110, // 91 '['
  0b0000000, // 92 '\'  NO DISPLAY
  0b1111000, // 93 ']'
  0b0000000, // 94 '^'  NO DISPLAY
  0b0001000, // 95 '_'
  0b0000010, // 96 '`'
  0b1110111, // 97 'a' SAME AS CAP
  0b0011111, // 98 'b' SAME AS CAP
  0b0001101, // 99 'c'
  0b0111101, // 100 'd' SAME AS CAP
  0b1101111, // 101 'e'
  0b1000111, // 102 'f' SAME AS CAP
  0b1011110, // 103 'g' SAME AS CAP
  0b0010111, // 104 'h'
  0b0010000, // 105 'i'
  0b0111000, // 106 'j' SAME AS CAP
  0b0000000, // 107 'k'  NO DISPLAY
  0b0110000, // 108 'l'
  0b0000000, // 109 'm'  NO DISPLAY
  0b0010101, // 110 'n' SAME AS CAP
  0b0011101, // 111 'o'
  0b1100111, // 112 'p' SAME AS CAP
  0b1110011, // 113 'q' SAME AS CAP
  0b0000101, // 114 'r' SAME AS CAP
  0b1011011, // 115 's' SAME AS CAP
  0b0001111, // 116 't' SAME AS CAP
  0b0011100, // 117 'u'
  0b0000000, // 118 'b'  NO DISPLAY
  0b0000000, // 119 'w'  NO DISPLAY
  0b0000000, // 120 'x'  NO DISPLAY
  0b0000000, // 121 'y'  NO DISPLAY
  0b0000000, // 122 'z'  NO DISPLAY
  0b0000000, // 123 '0b'  NO DISPLAY
  0b0000000, // 124 '|'  NO DISPLAY
  0b0000000, // 125 ','  NO DISPLAY
  0b0000000, // 126 '~'  NO DISPLAY
  0b0000000, // 127 'DEL'  NO DISPLAY
};

//Sets up data pins connected to the display
// Free to use any digital IO pin but its best to avoid pin 0,1 and 13.
BubbleBackpack::BubbleBackpack(int clkPin, int csPin, int dinPin) {
  // Let the rest of the code know the csPin
  _csPin = csPin;
  _clkPin = clkPin;
  _dinPin = dinPin;
}

//Initates The Bubble Backpack in form: (Number of digits on the backpack (4 or 8), Number of backpacks cascaded together)
void BubbleBackpack::setupDisplay(int numberOfDigits, int numberOfDisplays){ 
    // initate the SPI pins
  pinMode(_csPin, OUTPUT);
  pinMode(_clkPin, OUTPUT);
  pinMode(_dinPin, OUTPUT);
  
  byte intensityReg = 0x0a; // 0 - 15
  byte modeReg = 0x0f;
  byte decodeReg = 0x09;
  byte scanReg = 0x0b;
  byte shutdownReg = 0x0c;

  //Let the rest of the program know how many displays and digits we have
  _cascadedDevices = numberOfDisplays;
  _numberOfDigits = numberOfDigits;
  
  //Set up every display
  for (int i = 1; i <= _cascadedDevices; i++) {
    // Turn off Test Mode
    spiTransfer(modeReg, 0, i);

    //Set the default display intensity to 6 out of 15
    spiTransfer(intensityReg, 6, i);

    //Turn off Shutdown Mode
    spiTransfer(shutdownReg, 1, i);

    // Put it into 'No Decode Mode'
    spiTransfer(decodeReg, 0, i);

    //Set Scan Rate (Depends on the number of digits on the display)
    spiTransfer(scanReg, (_numberOfDigits - 1), i);
  }
   clearDisplay();
}

// Clears the display
void BubbleBackpack::clearDisplay(void) {
  for (int c = 1; c <= _cascadedDevices; c++) {
    for (int i = 1; i < (_numberOfDigits + 1); i++) {
      spiTransfer(i, 0, c);
    }
  }
}

//Set the display intensity from 0 to 15
void BubbleBackpack::setDisplayIntensity(int intensity) {
  byte intensityReg = 0x0a; // 0 - 15

  // Set both displays to the same intensity
  for (int i = 1; i <= _cascadedDevices; i++) {
    //Set the display intensity to 6 out of 15
    spiTransfer(intensityReg, intensity, i);
  }
}

// Sets the digit at position 0 - 7 to the desired value
void BubbleBackpack::writeDigit(int digit, int value, int numDisplays) {
  // Turn off Test Mode
  spiTransfer(digitReg[digit], fontArray[value], numDisplays);
}

// Turns on a specific segment
// Segment value 0 = dot, A = 1 ... G = 7.
void BubbleBackpack::writeSegment(int digit, int segment, int numDisplays) {
  byte bits = 0;
  // Writes a one to bit at location 'segment'
  bitSet(bits, (7 - segment));
  spiTransfer(digitReg[digit], bits, numDisplays);
}

// Runs through 0 - 9 on every digit, on every display
void BubbleBackpack::quickTest(void){
  for (int i = 1; i <= _cascadedDevices; i++) {
    for (int c = 0; c < 10; c++) {
      writeDigit(0, c, i);
      writeDigit(1, c, i);
      writeDigit(2, c, i);
      writeDigit(3, c, i);
      writeDigit(4, c, i);
      writeDigit(5, c, i);
      writeDigit(6, c, i);
      writeDigit(7, c, i);
      delay(500);
    }
  }
}

// Reads data from serial and writes it to the display
void BubbleBackpack::readFromSerial(void) {
  int input;
  int digitPosition = 0;
  
  Serial.begin(9600);
  
  Serial.println("Type a number or digit to display and press 'enter'");
  //stay in this loop so that the text does not get repeted or the variables reinitiated
  while (true) {
    input = Serial.read();
    // only write valid input data
    if (input != -1) {
      Serial.println("Digit sent to display");//Serial.println(input);
      for (int i = 1; i <= _cascadedDevices; i++) {
        writeDigit(digitPosition, input, i);
      }
      // reset counter back to zero
      if (digitPosition == (_numberOfDigits - 1)) {
        // set to -1 since it will always add one below
        digitPosition = -1;
      }
      digitPosition++;
    }
  }
}

// Transfers data to the chip. Adress 1 = first board, Adress 2 = the second cascaded board (one who's DIN is connected to the first board's DOUT)
void BubbleBackpack::spiTransfer(byte reg, byte data, int adress) {
  digitalWrite(_csPin, LOW);
  // Go up the cascade to the next chip if needed
  for (int i = adress; i < _cascadedDevices; i++) {
    // Send two bytes of 0s to push data to the appropriate chip
    shiftOut(_dinPin, _clkPin, MSBFIRST, 0);
    shiftOut(_dinPin, _clkPin, MSBFIRST, 0);
  }
  // Send Data and Register
  shiftOut(_dinPin, _clkPin, MSBFIRST, reg);
  shiftOut(_dinPin, _clkPin, MSBFIRST, data);
  // Go down the cascade to the previous chip if needed
 for (int i = 1; i < (_cascadedDevices - (_cascadedDevices - adress)) ; i++) {
    // Send two bytes of 0s to push data to  the appropriate chip
    shiftOut(_dinPin, _clkPin, MSBFIRST, 0);
    shiftOut(_dinPin, _clkPin, MSBFIRST, 0);
  }
  digitalWrite(_csPin, HIGH);
}


