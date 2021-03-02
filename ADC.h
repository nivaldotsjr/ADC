//******************************************************************************
// Library to ADC to 16F877 
// Developed by Nivaldo T. Schiefler Jr.  Dr eng.
// Build under XC8 compiler
// 15/09/2017 
// Updates: 
// 
//******************************************************************************

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
//******************************************************************************
unsigned int read_adc(unsigned char channel);
void adc_off(void);
void init_adc(unsigned char set_ports);
//******************************************************************************


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

