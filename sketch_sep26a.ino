
#include <avr/io.h>
#include <util/delay.h>
#define latchPin 0//8
#define clockPin 1//12
#define dataPin 2//11

 byte myArr[] = {0b00000000,0b00000001,0b00000011,0b00000111,0b00001111,
                 0b00011111,0b00111111,0b01111111,0b11111111,0b11111110,
                 0b11111100,0b11111000,0b11110000,0b11100000,0b11000000,
                 0b10000000,0b00000000};
int main( void )
{
 DDRB |= (1<<latchPin);
 DDRB |= (1<<clockPin);
 DDRB |= (1<<dataPin);

while(1){  
  for (unsigned int i=0; i<sizeof(myArr);i++){
      PORTB &= ~(1<<latchPin);
      shiftOut(dataPin, clockPin, MSBFIRST, myArr[i]);
      PORTB |= (1<<latchPin); 
      _delay_ms(200);
  }
  _delay_ms(1000);
}
}
