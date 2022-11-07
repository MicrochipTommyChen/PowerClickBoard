
/**
  CMP1 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    cmp1.c

  @Summary
    This is the generated driver implementation file for the CMP1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for CMP1. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  dsPIC33EP128GS806
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB             :  MPLAB X v5.50
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

#include "cmp1.h"

/**
  Section: Driver Interface
*/

void CMP1_Initialize(void)
{           



    // DACOE enabled; HYSPOL Rising Edge; ALTINP Comparator; FLTREN disabled; FCLKSEL System Clock; CMPSTAT disabled; EXTREF AVDD; CMPPOL Not Inverted; CMPSIDL disabled; CMPON enabled; HYSSEL No hysteresis; INSEL CMP1C; RANGE AVDD is the maximum DAC output voltage; 
    // Disable the CMP module before the initialization
    CMP1CON = 0x8181 & ~(0x8000);

    // CMREF 0; 
    CMP1DAC = 0x00;
    

    CMP1_Enable(true);

}

void CMP1_Enable(bool enable)
{
    (CMP1CONbits.CMPON) = enable;
}

void CMP1_SetInputSource(CMP1_INPUT inpSrc)
{
    (CMP1CONbits.INSEL) = inpSrc;
}

bool CMP1_DACOutputStatusGet(void)
{
    return (CMP1CONbits.DACOE);
}

bool CMP1_StatusGet(void)
{
    return (CMP1CONbits.CMPSTAT);
}


void __attribute__ ((weak)) CMP1_CallBack(void)
{
    // Add your custom callback code here
}

void CMP1_Tasks(void)
{
	if(IFS1bits.AC1IF)
	{
		// CMP1 callback function 
		CMP1_CallBack();
	
		// clear the CMP1 interrupt flag
		IFS1bits.AC1IF = 0;
	}
}


/**
  End of File
*/
