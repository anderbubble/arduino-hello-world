#include "morse.h"
#include "Arduino.h"


void morse_message (char * message)
{ 
  int i;

  for (i=0; i<strlen(message); i++)
  {
    morse_char(message[i]);
  }
}


void morse_char (char message_char)
{
  if (message_char == ' ')
  {
    morse_word_break();
  }

  else
  {
    switch (message_char)
    {
      case 'H': dot(); dot(); dot(); dot(); break;
      case 'E': dot(); break;
      case 'L': dot(); dash(); dot(); dot(); break;
      case 'O': dash(); dash(); dash(); break;
      case ',': dash(); dash(); dot(); dot(); dash(); dash(); break;
      case 'W': dot(); dash(); dash(); break;
      case 'R': dot(); dash(); dot(); break;
      case 'D': dash(); dot(); dot(); break;
      case '!': dash(); dot(); dash(); dot(); dash(); dash(); break;
    }
    morse_char_break();
  }
  Serial.print(message_char);
}


void morse_char_break ()
{
  munged_delay(LETTER_BREAK);
}


void morse_word_break ()
{
  munged_delay(WORD_BREAK);
}


void dash ()
{
  digitalWrite(LED, HIGH);
  munged_delay(DASH);
  digitalWrite(LED, LOW);
  munged_delay(DOT);
}


void dot ()
{
  digitalWrite(LED, HIGH);
  munged_delay(DOT);
  digitalWrite(LED, LOW);
  munged_delay(DOT);
}


int munge (int value)
{
  int pot = analogRead(POT);
  unsigned long new_value = (long) value * pot / 1024;
  return new_value;
}


void munged_delay (int value)
{
  delay(munge(value));
}

