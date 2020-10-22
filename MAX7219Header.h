/* 
 * File:   MAX7219Header.h
 * Author: Kalana
 *
 * Created on October 19, 2020, 10:47 PM
 */

#ifndef MAX7219HEADER_H
#define	MAX7219HEADER_H

#ifdef	__cplusplus
extern "C" {
#endif
//----------------------------------------------------------------------------------------------------------- Initialize Max7219 Chip.
/*
 For the changes, Refer Datasheet.
*/

int lttrA[5]={0x1F,0x24,0x24,0x1F};   
int mx_pos;
    
void max7219_init()
{
/* Decode Mode Register */
SS = 0;
xc8_spi_write(0x09);
xc8_spi_write(0x00);
SS = 1;
/* Intensity Register */
SS = 0;
xc8_spi_write(0x0A);
xc8_spi_write(0x0F);
SS = 1;
/* Scan Limit Register */
SS = 0;
xc8_spi_write(0x0B);
xc8_spi_write(0x07);
SS = 1;
/* Shutdown Register */
SS = 0;
xc8_spi_write(0x0C);
xc8_spi_write(0x01);
SS = 1;
/* Display Test Register */
SS = 0;
xc8_spi_write(0x0F);
xc8_spi_write(0x00);
SS = 1;
	
}
//------------------------------------------------------------------------------------------------------------------- Clear Function.
void max7219_disp_clear()
{
   for(int i=0x01;i<0x09;i++)
     {
        SS = 0;
        xc8_spi_write(i);
        xc8_spi_write(0x00);
        SS = 1;
 }
}
//-------------------------------------------------------------------------------------------------------------------- Display Single Character.
void max7219_disp_char(char data)
{
// Switch condition
  switch (data)
  {
      // If data = A.
      case 'A' :mx_pos = 0x03;
                for(int i=0;i<4;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrA[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = B.
      case 'B' :mx_pos = 0x03;
                for(int i=0;i<4;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrA[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
                
      default  :SS = 0;
                xc8_spi_write(0x01);
                xc8_spi_write(0x00);
                SS = 1;
                break;
  }   
}
#ifdef	__cplusplus
}
#endif

#endif	/* MAX7219HEADER_H */

