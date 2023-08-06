/* lcd4bit driver*/
#include <LPC21XX.H>
#include "header.h"
#define Rs(1<<17) //p1.17
#define Rs(1<<18) //p1.18
#define Rs(1<<19) //p1.19

void lcd_init (void)
{
IODIR1|=0x00FE0000; //P1.17-P1-23
                    //OUT DIRECTION
PINSEL2=0; //SET P1 PIN TO GPIO
IOCLR1=EN; //EN=0
lcd_cmd(0x02);
lcd_cmd(0x03);
lcd_cmd(0x28);
lcd_cmd(0x0E);
lcd_cmd(0x01);
}
void lcd_data(unsigned char data)
{
unsigned int temp=0;
IOCLR1=0x00FE0000; //clear P1.17-P1.23
temp=(data&0xF0)<<16;
IOSET1=temp; //WRITE HIGHER 4 BITS
IOSET1=RS;//RW=1
IOCLR1=RW;//RW=0
IOSET1=EN;//EN=1
delay_ms(2);
IOCLR1=EN;//EN=0

IOCLR1=0x00FE0000;//CLEAR P1.17-P1.23
temp=(data&0x0F)<<20;
IOSET1=temp;//write lower 4bits
IOSET1=RS;//RS=1
IOCLR1=RW;//RS=0
IOSET1=EN;//EN=1
delay_ms(2);
IOCLR1=EN;//EN=0

}
void lcd_cmd(unsigned char data)
{
unsigned int temp=0;
IOCLR1=0x00FE0000; //clear P1.17-P1.23
temp=(cmd&0xF0)<<16;
IOSET1=temp; //WRITE HIGHER 4 BITS
IOSET1=RS;//RW=1
IOCLR1=RW;//RW=0
IOSET1=EN;//EN=1
delay_ms(2);
IOCLR1=EN;//EN=0

IOCLR1=0x00FE0000;//CLEAR P1.17-P1.23
temp=(cmd&0x0F)<<20;
IOSET1=temp;//write lower 4bits
IOSET1=RS;//RS=1
IOCLR1=RW;//RS=0
IOSET1=EN;//EN=1
delay_ms(2);
IOCLR1=EN;//EN=0
}

//string function 
void lcd_string(char *ptr)
{
  while(*ptr !=0)
{
lcd_data(*ptr);
ptr++;
}
}



