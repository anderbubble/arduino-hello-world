const int LED = 13;
const int POT = 2;

/*
  dot set to baseline 100ms. Other definitions taken
  from http://en.wikipedia.org/wiki/Morse_code
  */
const int DOT = 100;
const int DASH = 300;         // 3 * DOT
const int LETTER_BREAK = 300; // DASH / 3 * DOT
const int WORD_BREAK = 700;   // 7 * DOT

void morse_message (char * message);
void morse_char (char message_char);
void morse_char_break ();
void morse_word_break ();
void munged_delay (int value);
void dot();
void dash();
