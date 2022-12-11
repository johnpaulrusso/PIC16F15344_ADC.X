/* 
 * File:   adc.h
 * Author: John
 *
 * Created on December 10, 2022, 7:47 PM
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

const unsigned char CH_RA0 = 0;
const unsigned char CH_RA1 = 1;
const unsigned char CH_RA2 = 2;
const unsigned char CH_RA4 = 4;
const unsigned char CH_RA5 = 5;

/**
 * InitializeAnalogIO
 */
void ADC_Initialize(void);

/**
 * Register an ADC channel with an optional on change callback.
 * @param channel
 * @param onChangeCallback
 */
void ADC_RegisterChannel(unsigned char channel, 
                          void (*onChangeCallback)(unsigned short));

/**
* Run the ADC 
 */
void ADC_Run(void);

/*START - private to file scope (static)*/
static unsigned char numberOfRegisteredChannels = 0;
static unsigned char iterator = 0;

static unsigned char channelIds[] = {0xff, 0xff, 0xff, 0xff, 0xff};
static void (*onChangeCallbacks[])(unsigned short) = {0,0,0,0,0};
/*END - private to file scope (static)*/

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

