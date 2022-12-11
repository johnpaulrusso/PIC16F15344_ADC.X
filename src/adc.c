#include "adc.h"
#include <xc.h>

void ADC_Initialize(void)
{
    ANSELA = 0b00000000; //PORT A - DEFAULT ALL DIGITAL.
    ANSELB = 0;          //PORT B - ALL DIGITAL.
    ANSELC = 0;          //PORT C - ALL DIGITAL.
    
    ADCON0bits.CHS = 0; //Starting channel
    ADCON0bits.ADON = 1;

    ADCON1 = 0b10100000; //Right justified, Fosc/32, Vdd ref. (Tad = 1us)
    ADCON1 = 0b10100011; //Right justified, Fosc/64, FVR ref.
    
    //Voltage Reference
    FVRCON = 0b10001111; //ADC Gain = 1x, (1.024V)
    DAC1CON0 = 0b10101000; //FVR output on DACOUT1
    DAC1CON1 = 0b00011111; //Output highest value (FVR)
}

void ADC_RegisterChannel(unsigned char channel, 
                         void (*onChangeCallback)(unsigned short))
{
    iterator = 0;
    for(; iterator < numberOfRegisteredChannels; ++iterator)
    {
        if(channelIds[iterator] == 0xff)
        {
            channelIds[iterator] = channel;
            
            onChangeCallbacks[iterator] = onChangeCallback;
            
            numberOfRegisteredChannels++;
            break;
        }
    }
}

void ADC_Run(void)
{
    //TODO
}