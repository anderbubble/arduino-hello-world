/*
  Hello, world!

  Outputs "HELLO, WORLD!" in morse code via the built-in LED.
  
  The speed of the output is adjustable via analog input.
 */


#include "morse.h"


void setup ()
{
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}


// the loop routine runs over and over again forever:
void loop ()
{
  morse_message("HELLO, WORLD!");
  Serial.println();
}

