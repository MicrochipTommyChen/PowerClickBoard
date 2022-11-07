/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  dsPIC33CK256MP506
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdint.h>                               // include standard integer data types
#include <stdbool.h>                              // include standard boolean data types
#include <stddef.h>                               // include standard definition data types

// 3p3z Controller Include Files
#include "VCOMP.h"                                // include 'VCOMP' controller header file

#define VREF_TARGET 3832

volatile uint16_t Vref = 0;
bool bEnable = false;

volatile uint16_t VCOMP_ControlObject_Initialize(void);
/*
                         Main application
 */
int main(void)
{
    VCOMP_ControlObject_Initialize();
    
    // initialize the device
    SYSTEM_Initialize();
    while (1)
    {
        // Add your application code
    }
    return 1; 
}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _T1Interrupt (  )
{
    /* Check if the Timer Interrupt/Status is set */

    //***User Area Begin
    static uint16_t cnt = 0;
    static uint16_t uDelay = 0;
    
    if(cnt > 1000)
    {
        LED2_Toggle();
        cnt = 0;
        if(uDelay > 50)
        {
            bEnable = true;
        }
        else
        {
            uDelay++;
        }
    }
    else
    {
        cnt++;
    }
    
    IFS0bits.T1IF = false;
}

void __attribute__ ( ( __interrupt__ , auto_psv ) ) _ADCAN0Interrupt ( void )
{
    LED3_SetHigh();
    
    uint16_t valchannel_AN0;
    //Read the ADC value from the ADCBUF
    valchannel_AN0 = ADCBUF0;
    
    if(bEnable == true)
    {
        if(Vref < VREF_TARGET)
        {
            Vref = Vref + 1;
        }
        else
        {
            Vref = VREF_TARGET;
        }
        
        VCOMP_Update(&VCOMP);
    }
    else
    {
        Vref = 0;
        PG1DC = 0;
    }
    
    //clear the channel_AN0 interrupt flag
    IFS5bits.ADCAN0IF = 0;
    
    LED3_SetLow();
}

volatile uint16_t VCOMP_ControlObject_Initialize(void)
{
    volatile uint16_t retval = 0;                 // Auxiliary variable for function call verification (initially set to ZERO = false)

    /* Controller Input and Output Ports Configuration */

    // Configure Controller Primary Input Port
    VCOMP.Ports.Source.ptrAddress = &ADCBUF0;       // Pointer to primary feedback source (e.g. ADC buffer register or variable)
    VCOMP.Ports.Source.Offset = 0;                  // Primary feedback signal offset
    VCOMP.Ports.Source.NormScaler = 0;              // Primary feedback normalization factor bit-shift scaler
    VCOMP.Ports.Source.NormFactor = 0x7FFF;         // Primary feedback normalization factor fractional

    // Configure Controller Primary Output Port
    VCOMP.Ports.Target.ptrAddress = &PG1DC;         // Pointer to primary output target (e.g. SFR register or variable)
    VCOMP.Ports.Target.Offset = 0;                  // Primary output offset value
    VCOMP.Ports.Target.NormScaler = 0;              // Primary output normalization factor bit-shift scaler
    VCOMP.Ports.Target.NormFactor = 0x7FFF;         // Primary output normalization factor fractional

    // Configure Control Reference Port
    VCOMP.Ports.ptrControlReference = &Vref; // Pointer to control reference (user-variable)

    /* Controller Output Limits Configuration */

    // Primary Control Output Limit Configuration
    VCOMP.Limits.MinOutput = 0;             // Minimum control output value
    VCOMP.Limits.MaxOutput = 15992;          // Maximum control output value

    /* Advanced Parameter Configuration */

    // Initialize User Data Space Buffer Variables
    VCOMP.Advanced.usrParam0 = 0;                 // No additional advanced control options used
    VCOMP.Advanced.usrParam1 = 0;                 // No additional advanced control options used
    VCOMP.Advanced.usrParam2 = 0;                 // No additional advanced control options used
    VCOMP.Advanced.usrParam3 = 0;                 // No additional advanced control options used
    VCOMP.Advanced.usrParam4 = 0;                 // No additional advanced control options used
    VCOMP.Advanced.usrParam5 = 0;                 // No additional advanced control options used
    VCOMP.Advanced.usrParam6 = 0;                 // No additional advanced control options used
    VCOMP.Advanced.usrParam7 = 0;                 // No additional advanced control options used

    /* Controller Status Word Configuration */


    // Call Assembler Control Library Initialization Function
    retval = VCOMP_Initialize(&VCOMP);            // Initialize controller data arrays and number scalers

    return(retval);

}
/**
 End of File
*/

