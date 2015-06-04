/*
  Hello_Arduino.ino
  Scrolls "Hello Arduino" on Display
  By TinkerTroniks.com
  Created by Serg, June 2, 2015.
  Released into the public domain.
*/
/*
 Alright, lets get started!
 We need:
 - Either the Bubble Backpack (4-digits)
    or the Double Bubble Backpack (8-digits)
 - A 5v Arduino
 - 4.5v - 5.5v power supply

 First thing is first, we need to get the Arduino and the Backpack to talk to eachother.
 We can use three pins we want ( as long as we tell the Arduino which pins we are using) but its best to avid pin 0, 1 and 13.
 In this example, we will use pins 2, 3, and 4.
 Connect:
 Backpack -> Arduino
 5v -> VCC ( or the + on your power supplies)
 GND -> GND
 CLK -> Pin 2
 CS -> Pin 3
 Din -> Pin 4

As far as connection goes, thats it!
Head on down and we can begin with the code
*/

// Make sure to tell the compiler to include the library
// To download and install library visit https://github.com/sergioser/BubbleBackpack
#include "BubbleBackpack.h"


void setup() {

}

void loop() {
  // Lets tell Arduino which pins we are using on the (CLK, CS, DIN) lines.
  // Calling 'BubbleBackpack' creates an object(our board) called 'display'
  BubbleBackpack display(2, 3, 4);
  // To set up display we evoke the function 'setupDisplay'
  // which takes two values (the number of digits on the display, number of displays)
  // In our case we are using a Bubble Display which has 4 digits
  //(if you have a Dubble Bubble Display type 8, since it has 8 digits)
  // We are using a single display so the second number we pass down is 1.
  display.setUpDisplay(4, 1);
  //These devices can get very bright so lets tell it to go to the lowest brightness.
  display.setDisplayIntensity(1); // takes any value from 0 - 15, 15 is the brightest.
  //Lets set up an array for the text we are going to send
  char text[] = "Hello arduino";
  // Keeps track of the current digit position
  int counter = 0;
  int i = 0;

  // Go through all 13 charachters of the text
  while(i < 13 ){
    // numOfDigits returns the number of digits per display
    if (counter < display.numOfDigits()) {
      // Writes a digit or a letter in the format: (digit position, value of digit, on which display)
      display.writeDigit(counter, text[i], 1);
      delay(320);
      i++;
      counter++;
    }
    else {
      counter = 0;
      //Lets clear the display so it looks nice and neat
      display.clearDisplay();
    }
  }
}


