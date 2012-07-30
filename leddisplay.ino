
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;


// A lookup table to store the alphabet and numbers 0-9.

String charactersLookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
// A lookup table to store the bit values.
// Note: A String object acts like an array. You can use it to access items at an index by saying bitsLookupTable[0], etc.
String bitsLookupTable;

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("reset");
  
  bitsLookupTable[0] = '0'; // A
  bitsLookupTable[1] = '0'; // B
  bitsLookupTable[2] = 0; // C
  bitsLookupTable[3] = 0; // etc (i'm not copy and pasting all that...)
  bitsLookupTable[4] = 0;
  bitsLookupTable[5] = 0;
  bitsLookupTable[6] = 0;
  bitsLookupTable[7] = 0;
  bitsLookupTable[8] = 0;
  bitsLookupTable[9] = 0;
  bitsLookupTable[10] = 0;
  bitsLookupTable[11] = 0;
  bitsLookupTable[12] = 0;
  bitsLookupTable[13] = 0;
  bitsLookupTable[14] = 0;
  bitsLookupTable[15] = 0;
  bitsLookupTable[16] = 0;
  bitsLookupTable[17] = 0;
  bitsLookupTable[18] = 0;
  bitsLookupTable[19] = 0;
  bitsLookupTable[20] = 0;
  bitsLookupTable[21] = 0;
  bitsLookupTable[22] = 0;
  bitsLookupTable[23] = 0;
  bitsLookupTable[24] = 0;
  bitsLookupTable[25] = 0;
  bitsLookupTable[26] = 0;
  bitsLookupTable[27] = 0;
  bitsLookupTable[28] = 0;
  bitsLookupTable[29] = 0;
  bitsLookupTable[30] = 0;
  bitsLookupTable[31] = 0;
  bitsLookupTable[32] = 0;
  bitsLookupTable[33] = 0;
  bitsLookupTable[34] = 0;
  bitsLookupTable[35] = 0;
  
  // That can also be expressed as bitsLookupTable[36] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  // instead of doing the assignments on each line. However, it's readable.
   

}

void loop() 
{  
  
  for (int i = 0; i < 36; i++) 
  {
    // This will still write all of the letters once you fill in bit values up in setup();
    // However if you want to do displayWrite('A'), you would want to do displayWrite(charToInt('A')); instead.

    displayWrite(bitsLookupTable[i]);
    delay(500);
  }
}  
void displayWrite(int value) 
{
    value = int(value);
    int bitToWrite = bitsLookupTable[value];
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, bitToWrite);  
    digitalWrite(latchPin, HIGH);
}

int charToInt(char character)
{  
  // Convert a letter to a number, represented like A=0, B=1 etc
  // i.e. you could do charToInt('A') and it will return 0;
  
  int theInt;
  boolean continueSearchBool = 1;
  
  int i = 0;
  
  do
  {
      if (charactersLookup[i] == character)
        {
            continueSearchBool = 0;
            theInt = i;
        }
        
       i++;
      
  }
  while (continueSearchBool && i < 36);
  
  return theInt;
  
}
