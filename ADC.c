//******************************************************************************
// Library to ADC to 16F877 
// Developed by Nivaldo T. Schiefler Jr.  Dr eng.
// Build under XC8 compiler
// 15/09/2017 
// Updates: 
// 
//******************************************************************************


#include <xc.h>
#include "config.h"
//******************************************************************************
void init_adc(unsigned char set_ports)
{
   ADCON0 = 0x81;              
   // ADCS1 = 1  ->Clock Selection FOSC/2    
   // ADON = 1   -> AD ON
   ADCON1 = 0x07;   // Left justified all digitals 
   // ADFM = 0   -> Left justified  pag 132
   // ADFM = 1   -> Right justified  pag 132
   // ADCS2 = 0  -> >Clock Selection FOSC/2 
   // PCFG3 PCFG2 PCFG1 PCFG0  -> config ports
   ADCON1 =    ((ADCON1 & 0xF0) | (set_ports & 0x0F));
    //ADCON1 &=  set_ports;
}
//******************************************************************************
void adc_off(void)
{
   ADCON0 = 0x01;                
}
//******************************************************************************
unsigned int read_adc(unsigned char channel)
{
 unsigned int read_value;

 if (channel == 0)    //000 = Channel 0 (AN0)
     ADCON0 = 0b10000001;
 else if(channel == 1)//001 = Channel 1 (AN1)
     ADCON0 = 0b10001001;
 else if(channel == 2)//010 = Channel 2 (AN2)
     ADCON0 = 0b10010001;
 else if(channel == 3)//011 = Channel 3 (AN3)
     ADCON0 = 0b10011001;
 else if(channel == 4)//100 = Channel 4 (AN4)
     ADCON0 = 0b10100001;
 else if(channel == 5)//101 = Channel 5 (AN5)
     ADCON0 = 0b10101001;
 else if(channel == 6)//110 = Channel 6 (AN6)
     ADCON0 = 0b10110001;
 else if(channel == 7)//111 = Channel 7 (AN7)  
     ADCON0 = 0b10100001;
 else               //000 = Channel 0 (AN0)
     ADCON0 = 0b00000111;  // AD off
//******************************************************************************

 GO_nDONE = 1;     // A/D conversion in progress
 while(GO_nDONE);  // wait conversion
 GO_nDONE = 0;     // A/D conversion not in progress
  //          justified mode to left
  //***********        mount 16 bits word         **************
  read_value =  (unsigned int)((ADRESH << 8) + ADRESL);
  //*********      Move to left do get 10 bits          ********
  read_value = read_value >> 6;
 //***************************************************************************** 
 return  read_value;   
}
//******************************************************************************


