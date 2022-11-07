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
        Device            :  dsPIC33EP128GS806
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

// Standard Include Files
#include <stdint.h>                               // include standard integer data types
#include <stdbool.h>                              // include standard boolean data types
#include <stddef.h>                               // include standard definition data types

// 3p3z Controller Include Files
#if 0
#include "VCOMP.h"                                // include 'VCOMP' controller header file
#else
#include "smps_control.h"
#include "../dsPIC33EP128GS806.X/dcdt/vmc/../vmc/dcdt_generated_code/vmc_dcdt.h"
SMPS_3P3Z_T controller3P3Z;
int16_t controller3P3ZACoefficient[3] __attribute__ ((space (xmemory), far));
int16_t controller3P3ZControlHistory[3] __attribute__ ((space (ymemory), far));
int16_t controller3P3ZBCoefficient[4] __attribute__ ((space (xmemory), far));
int16_t controller3P3ZErrorHistory[4] __attribute__ ((space (ymemory), far));
#endif

#define VREF_TARGET 3832
volatile uint16_t Vref = 0;
volatile uint16_t Iref = 0;
volatile uint16_t VcompOut = 0;

bool bSS = false;
bool bEnable = false;

#if 0
volatile uint16_t VCOMP_ControlObject_Initialize(void);
#else
void VCM_Control_Initialize(void);
#endif
/*
                         Main application
 */
int main(void)
{
    // initialize the device
#if 0
    VCOMP_ControlObject_Initialize();
#else
    VCM_Control_Initialize();
#endif
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
    
//    if( SW1_GetValue() == 0 )
//    {
//        if(uDelay > 3000)
//        {
//            bEnable ^= 1;
//        }
//        else
//        {
//            uDelay++;
//        }
//    }
//    else
//    {
//        uDelay = 0;
//    }
    
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
    #if 1
        if(Vref < VREF_TARGET)
        {
            Vref = Vref + 1;
        }
        else
        {
            Vref = VREF_TARGET;
        }
    #if 0
        VCOMP_Update(&VCOMP);
//        VCOMP_PTermUpdate(&VCOMP);
    #else
        SMPS_Controller3P3ZUpdate(&controller3P3Z,&ADCBUF0,Vref,&VcompOut);
        VcompOut = __builtin_muluu(VcompOut, 5041) >> 10;
        if(VcompOut > 3773)
            VcompOut = 3773;
        PDC1 = VcompOut;
    #endif
    #else
        if(bSS == false)
        {
            if(PDC1 < 1572)
            {
                PDC1 = PDC1 + 1;
            }
            else
            {
                PDC1 = 1572;
                bSS = true;
            }
        }
        else
        {
            VCOMP_PTermUpdate(&VCOMP);
        }
    #endif
    }
    else
    {
        Vref = 0;
        bSS = false;
        PDC1 = 0;
    }
    
    CMP1DAC = valchannel_AN0;
    
    //clear the channel_AN0 interrupt flag
    IFS6bits.ADCAN0IF = 0;
    
    LED3_SetLow();
}

#if 0
volatile uint16_t VCOMP_ControlObject_Initialize(void)
{
    volatile uint16_t retval = 0;                 // Auxiliary variable for function call verification (initially set to ZERO = false)

    /* Controller Input and Output Ports Configuration */

    // Configure Controller Primary Input Port
    VCOMP.Ports.Source.ptrAddress = &ADCBUF0; // Pointer to primary feedback source (e.g. ADC buffer register or variable)
    VCOMP.Ports.Source.Offset = 0;     // Primary feedback signal offset
    VCOMP.Ports.Source.NormScaler = 0; // Primary feedback normalization factor bit-shift scaler
    VCOMP.Ports.Source.NormFactor = 0x7FFF; // Primary feedback normalization factor fractional

    // Configure Controller Primary Output Port
    VCOMP.Ports.Target.ptrAddress = &PDC1; // Pointer to primary output target (e.g. SFR register or variable)
    VCOMP.Ports.Target.Offset = 0;     // Primary output offset value
    VCOMP.Ports.Target.NormScaler = 0; // Primary output normalization factor bit-shift scaler
    VCOMP.Ports.Target.NormFactor = 0x7FFF; // Primary output normalization factor fractional

    // Configure Control Reference Port
    VCOMP.Ports.ptrControlReference = &Vref; // Pointer to control reference (user-variable)

    /* Controller Output Limits Configuration */

    // Primary Control Output Limit Configuration
    VCOMP.Limits.MinOutput = 0;        // Minimum control output value
    VCOMP.Limits.MaxOutput = 3773;        // Maximum control output value

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
#else
void VCM_Control_Initialize(void)
{
    controller3P3Z.aCoefficients = &controller3P3ZACoefficient[0]; // Set up pointer to derived coefficients
    controller3P3Z.bCoefficients = &controller3P3ZBCoefficient[0]; // Set up pointer to derived coefficients
    controller3P3Z.controlHistory = &controller3P3ZControlHistory[0]; // Set up pointer to controller history
    controller3P3Z.errorHistory = &controller3P3ZErrorHistory[0]; // Set up pointer to error history
    controller3P3Z.preShift = VMC_COMP_3P3Z_PRESHIFT; // Normalization shift for error amplifier into Q15 format
    controller3P3Z.postShift = VMC_COMP_3P3Z_POSTSHIFT; // Normalization shift for control loop results to peripheral
    controller3P3Z.postScaler = VMC_COMP_3P3Z_POSTSCALER; // Normalization shift for control loop results to peripheral
    controller3P3Z.minOutput = VMC_COMP_3P3Z_MIN_CLAMP; // Clamp value for minimum duty ratio
    controller3P3Z.maxOutput = VMC_COMP_3P3Z_MAX_CLAMP; // Clamp value for maximum duty ratio
    //It's recommended to clean up the error-history and controller-history arrays before start-up using the following instruction:
    SMPS_Controller3P3ZInitialize(&controller3P3Z); // Clear history   
    
    controller3P3Z.aCoefficients[0] = VMC_COMP_3P3Z_COEFF_A1;
    controller3P3Z.aCoefficients[1] = VMC_COMP_3P3Z_COEFF_A2;
    controller3P3Z.aCoefficients[2] = VMC_COMP_3P3Z_COEFF_A3;
    controller3P3Z.bCoefficients[0] = VMC_COMP_3P3Z_COEFF_B0;
    controller3P3Z.bCoefficients[1] = VMC_COMP_3P3Z_COEFF_B1;
    controller3P3Z.bCoefficients[2] = VMC_COMP_3P3Z_COEFF_B2;
    controller3P3Z.bCoefficients[3] = VMC_COMP_3P3Z_COEFF_B3;
    
    Vref = 0;
}
#endif
/**
 End of File
*/

