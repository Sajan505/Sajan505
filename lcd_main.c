#include "header.h"
main()
{
  lcd_init();
  while(1)
    {
      int i;
      for(i=0;i<16;i++)
        {
          lcd_cmd(0x80+i);
          lcd_string("vector");
          delay_ms(1000);
          lcd_cmd(0x01);
        }
    }
}
