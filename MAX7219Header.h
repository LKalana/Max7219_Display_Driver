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

// Note:- To use DP, instead of using 0000 use 1000 (0x80).
// Example = to display 0x1F with DP, Use 0x9F.

// ----------------------------------------------------- Letters.
signed int lttrA[9]={0x00,0xFC,0x12,0x12,0x12,0xFC,0x00,0x00};   
signed int lttrB[9]={0x00,0xFE,0x92,0x92,0x92,0x6C,0x00,0x00};
signed int lttrC[9]={0x00,0x7C,0x82,0x82,0x82,0x44,0x00,0x00};
signed int lttrD[9]={0x00,0xFE,0x82,0x82,0x82,0x7C,0x00,0x00};
signed int lttrE[9]={0x00,0xFE,0x92,0x92,0x92,0x82,0x00,0x00};
signed int lttrF[9]={0x00,0xFE,0x12,0x12,0x12,0x02,0x00,0x00};
signed int lttrG[9]={0x00,0x7C,0x82,0x92,0x92,0x74,0x00,0x00};
signed int lttrH[9]={0x00,0xFE,0x10,0x10,0x10,0xFE,0x00,0x00};
signed int lttrI[9]={0x00,0x00,0x82,0xFE,0x82,0x00,0x00,0x00};
signed int lttrJ[9]={0x00,0x40,0x82,0x82,0x82,0x7E,0x00,0x00};
signed int lttrK[9]={0x00,0xFE,0x10,0x10,0x28,0xC6,0x00,0x00};
signed int lttrL[9]={0x00,0xFE,0x80,0x80,0x80,0x80,0x00,0x00};
signed int lttrM[9]={0x00,0xFE,0x04,0x08,0x04,0xFE,0x00,0x00};
signed int lttrN[9]={0x00,0xFE,0x08,0x10,0x20,0xFE,0x00,0x00};
signed int lttrO[9]={0x00,0x7C,0x82,0x82,0x82,0x7C,0x00,0x00};
signed int lttrP[9]={0x00,0xFE,0x12,0x12,0x12,0x0C,0x00,0x00};
signed int lttrQ[9]={0x00,0x7C,0x82,0xA2,0xC2,0xFC,0x00,0x00};
signed int lttrR[9]={0x00,0xFE,0x12,0x12,0x12,0xEC,0x00,0x00};
signed int lttrS[9]={0x00,0x4C,0x92,0x92,0x92,0x64,0x00,0x00};
signed int lttrT[9]={0x00,0x02,0x02,0xFE,0x02,0x02,0x00,0x00};
signed int lttrU[9]={0x00,0x7E,0x80,0x80,0x80,0x7E,0x00,0x00};
signed int lttrV[9]={0x00,0x3E,0x40,0x80,0x40,0x3E,0x00,0x00};
signed int lttrW[9]={0x00,0xFE,0x40,0x20,0x40,0xFE,0x00,0x00};
signed int lttrX[9]={0x00,0xC6,0x28,0x10,0x28,0xC6,0x00,0x00};
signed int lttrY[9]={0x00,0x06,0x08,0xF0,0x08,0x06,0x00,0x00};
signed int lttrZ[9]={0x00,0xC2,0xA2,0x92,0x8A,0x86,0x00,0x00};
//---------------------------------------------------- Numbers.
//---------------------------------------------------- Special Characters.
signed int spchar[9] = {0x80,0x44,0x28,0x11,0x29,0x45,0x03,0x1F};
signed int mx_pos=0x00;
    
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
   for(signed int i=0x01;i<0x09;i++)
     {
        SS = 0;
        xc8_spi_write(i);
        xc8_spi_write(0x00);
        SS = 1;
 }
}
//-------------------------------------------------------------------------------------------------------------------- Display Special Character.
void max7219_disp_sp_char()
{
    mx_pos = 0x01;
   for(signed int i=0x00;i<0x09;i++)
        {
            SS = 0;// Enable Chip Select.
            xc8_spi_write(mx_pos);// Digit Register.
            xc8_spi_write(spchar[i]);// Segments.
            SS = 1;// Disable Chip Select.
            mx_pos++;// Increment my_pos.
        }
}
//-------------------------------------------------------------------------------------------------------------------- Display Single Character.
void max7219_disp_char(char data)
{
// Switch condition
  switch (data)
  {
      // If data = A.
      case 'A' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrA[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = B.
      case 'B' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrB[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = C.
      case 'C' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrC[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = D.
      case 'D' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrD[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = E.
      case 'E' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrE[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = F.
      case 'F' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrF[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = G.
      case 'G' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrG[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = H.
      case 'H' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrH[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = I.
      case 'I' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrI[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = J.
      case 'J' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrJ[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = K.
      case 'K' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrK[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;

      // If data = L.
      case 'L' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrL[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = M.
      case 'M' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrM[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = N.
      case 'N' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrN[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = O.
      case 'O' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrO[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = P.
      case 'P' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrP[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = Q.
      case 'Q' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrQ[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = R.
      case 'R' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrR[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;

      // If data = S.
      case 'S' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrS[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = T.
      case 'T' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrT[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = U.
      case 'U' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrU[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = V.
      case 'V' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrV[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = W.
      case 'W' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrW[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = X.
      case 'X' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrX[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = Y.
      case 'Y' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;// Enable Chip Select.
                       xc8_spi_write(mx_pos);// Digit Register.
                       xc8_spi_write(lttrY[i]);// Segments.
                       SS = 1;// Disable Chip Select.
                       mx_pos++;// Increment my_pos.
                    }
                break;
      // If data = Z.
      case 'Z' :mx_pos = 0x01;
                for(signed int i=0x00;i<0x09;i++)
                    {
                       SS = 0;
                       xc8_spi_write(mx_pos);
                       xc8_spi_write(lttrZ[i]);
                       SS = 1;
                       mx_pos++;
                    }
                break;
      // If data = Default. 
      default  :SS = 0;
                xc8_spi_write(0x01); // Digit Register.
                xc8_spi_write(0x00);// Segments.
                SS = 1;
                break;
  }   
}
#ifdef	__cplusplus
}
#endif

#endif	/* MAX7219HEADER_H */

