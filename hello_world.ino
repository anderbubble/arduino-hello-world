/*
  Hello, world!

  Outputs "HELLO, WORLD!" in morse code via the built-in LED.
  
  The speed of the output is adjustable via analog input.
 */


const int LED = 13;
const int POT = 2;

/*
  dot set to baseline 100ms. Other definitions taken
  from http://en.wikipedia.org/wiki/Morse_code
  */
int DOT = 100;
int DASH = 3 * DOT;
int LETTER_BREAK = DASH;
int WORD_BREAK = 7 * DOT;


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
  delay(munge(LETTER_BREAK));
}


void morse_word_break ()
{
  delay(munge(WORD_BREAK));
}


void dash ()
{
  digitalWrite(LED, HIGH);
  delay(munge(DASH));
  digitalWrite(LED, LOW);
  delay(munge(DOT));
}


void dot ()
{
  digitalWrite(LED, HIGH);
  delay(munge(DOT));
  digitalWrite(LED, LOW);
  delay(munge(DOT));
}


int munge (int value)
{
  int pot = analogRead(POT);
  unsigned long new_value = (long) value * pot / 1024;
  return new_value;
}

