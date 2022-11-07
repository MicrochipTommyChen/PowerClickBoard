/**
  PWM Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm.c

  @Summary
    This is the generated driver implementation file for the PWM driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for PWM.
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

#include "pwm.h"

/**
  Section: Driver Interface
*/

void PWM_Initialize (void)
{
    // PCLKDIV 1; 
    PTCON2 = 0x00;
    // SYNCOEN disabled; SEIEN disabled; SESTAT disabled; SEVTPS 1; SYNCSRC SYNCI1; SYNCEN disabled; EIPU disabled; SYNCPOL disabled; 
    STCON = 0x00;
    // PCLKDIV 1; 
    STCON2 = 0x00;
    // STPER 65528; 
    STPER = 0xFFF8;
    // SSEVTCMP 0; 
    SSEVTCMP = 0x00;
    // PTPER 3773; 
    PTPER = 0xEBD;
    // SEVTCMP 0; 
    SEVTCMP = 0x00;
    // MDC 0; 
    MDC = 0x00;
    // CHOPCLK 0; CHPCLKEN disabled; 
    CHOP = 0x00;
    // PWMKEY 0; 
    PWMKEY = 0x00;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; 
    PWMCON1 = 0x00;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; 
    PWMCON2 = 0x00;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; 
    PWMCON3 = 0x00;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; 
    PWMCON4 = 0x00;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; 
    PWMCON5 = 0x00;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; 
    PWMCON6 = 0x00;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; 
    PWMCON7 = 0x00;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; 
    PWMCON8 = 0x00;
    //FLTDAT PWM1L Low, PWM1H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM1L Low, PWM1H Low; OVRDAT PWM1L Low, PWM1H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON1, 0xC000, &PWMKEY);
    //FLTDAT PWM2L Low, PWM2H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM2L Low, PWM2H Low; OVRDAT PWM2L Low, PWM2H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON2, 0xC000, &PWMKEY);
    //FLTDAT PWM3L Low, PWM3H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM3L Low, PWM3H Low; OVRDAT PWM3L Low, PWM3H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON3, 0xC000, &PWMKEY);
    //FLTDAT PWM4L Low, PWM4H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM4L Low, PWM4H Low; OVRDAT PWM4L Low, PWM4H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON4, 0xC000, &PWMKEY);
    //FLTDAT PWM5L Low, PWM5H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM5L Low, PWM5H Low; OVRDAT PWM5L Low, PWM5H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON5, 0xC000, &PWMKEY);
    //FLTDAT PWM6L Low, PWM6H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM6L Low, PWM6H Low; OVRDAT PWM6L Low, PWM6H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON6, 0xC000, &PWMKEY);
    //FLTDAT PWM7L Low, PWM7H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM7L Low, PWM7H Low; OVRDAT PWM7L Low, PWM7H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON7, 0xC000, &PWMKEY);
    //FLTDAT PWM8L Low, PWM8H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM8L Low, PWM8H Low; OVRDAT PWM8L Low, PWM8H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON8, 0xC000, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM1H, PWM1L pins to FLTDAT values- Latched; IFLTMOD disabled; FLTSRC FLT1; 
    __builtin_write_PWMSFR(&FCLCON1, 0x408, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM2H, PWM2L pins to FLTDAT values- Latched; IFLTMOD disabled; FLTSRC FLT1; 
    __builtin_write_PWMSFR(&FCLCON2, 0x408, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM3H, PWM3L pins to FLTDAT values- Latched; IFLTMOD disabled; FLTSRC FLT1; 
    __builtin_write_PWMSFR(&FCLCON3, 0x408, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM4H, PWM4L pins to FLTDAT values- Latched; IFLTMOD disabled; FLTSRC FLT1; 
    __builtin_write_PWMSFR(&FCLCON4, 0x408, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM5H, PWM5L pins to FLTDAT values- Latched; IFLTMOD disabled; FLTSRC FLT1; 
    __builtin_write_PWMSFR(&FCLCON5, 0x408, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM6H, PWM6L pins to FLTDAT values- Latched; IFLTMOD disabled; FLTSRC FLT1; 
    __builtin_write_PWMSFR(&FCLCON6, 0x408, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM7H, PWM7L pins to FLTDAT values- Latched; IFLTMOD disabled; FLTSRC FLT1; 
    __builtin_write_PWMSFR(&FCLCON7, 0x408, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM8H, PWM8L pins to FLTDAT values- Latched; IFLTMOD disabled; FLTSRC FLT1; 
    __builtin_write_PWMSFR(&FCLCON8, 0x408, &PWMKEY);
    // PDC1 1886; 
    PDC1 = 0x00;
    // PDC2 0; 
    PDC2 = 0x00;
    // PDC3 0; 
    PDC3 = 0x00;
    // PDC4 0; 
    PDC4 = 0x00;
    // PDC5 0; 
    PDC5 = 0x00;
    // PDC6 0; 
    PDC6 = 0x00;
    // PDC7 0; 
    PDC7 = 0x00;
    // PDC8 0; 
    PDC8 = 0x00;
    // PHASE1 0; 
    PHASE1 = 0x00;
    // PHASE2 0; 
    PHASE2 = 0x00;
    // PHASE3 0; 
    PHASE3 = 0x00;
    // PHASE4 0; 
    PHASE4 = 0x00;
    // PHASE5 0; 
    PHASE5 = 0x00;
    // PHASE6 0; 
    PHASE6 = 0x00;
    // PHASE7 0; 
    PHASE7 = 0x00;
    // PHASE8 0; 
    PHASE8 = 0x00;
    // DTR1 188; 
    DTR1 = 0xBC;
    // DTR2 0; 
    DTR2 = 0x00;
    // DTR3 0; 
    DTR3 = 0x00;
    // DTR4 0; 
    DTR4 = 0x00;
    // DTR5 0; 
    DTR5 = 0x00;
    // DTR6 0; 
    DTR6 = 0x00;
    // DTR7 0; 
    DTR7 = 0x00;
    // DTR8 0; 
    DTR8 = 0x00;
    // ALTDTR1 188; 
    ALTDTR1 = 0xBC;
    // ALTDTR2 0; 
    ALTDTR2 = 0x00;
    // ALTDTR3 0; 
    ALTDTR3 = 0x00;
    // ALTDTR4 0; 
    ALTDTR4 = 0x00;
    // ALTDTR5 0; 
    ALTDTR5 = 0x00;
    // ALTDTR6 0; 
    ALTDTR6 = 0x00;
    // ALTDTR7 0; 
    ALTDTR7 = 0x00;
    // ALTDTR8 0; 
    ALTDTR8 = 0x00;
    // SDC1 0; 
    SDC1 = 0x00;
    // SDC2 0; 
    SDC2 = 0x00;
    // SDC3 0; 
    SDC3 = 0x00;
    // SDC4 0; 
    SDC4 = 0x00;
    // SDC5 0; 
    SDC5 = 0x00;
    // SDC6 0; 
    SDC6 = 0x00;
    // SDC7 0; 
    SDC7 = 0x00;
    // SDC8 0; 
    SDC8 = 0x00;
    // SPHASE1 0; 
    SPHASE1 = 0x00;
    // SPHASE2 0; 
    SPHASE2 = 0x00;
    // SPHASE3 0; 
    SPHASE3 = 0x00;
    // SPHASE4 0; 
    SPHASE4 = 0x00;
    // SPHASE5 0; 
    SPHASE5 = 0x00;
    // SPHASE6 0; 
    SPHASE6 = 0x00;
    // SPHASE7 0; 
    SPHASE7 = 0x00;
    // SPHASE8 0; 
    SPHASE8 = 0x00;
    // TRGCMP 0; 
    TRIG1 = 100;
    // TRGCMP 0; 
    TRIG2 = 0x00;
    // TRGCMP 0; 
    TRIG3 = 0x00;
    // TRGCMP 0; 
    TRIG4 = 0x00;
    // TRGCMP 0; 
    TRIG5 = 0x00;
    // TRGCMP 0; 
    TRIG6 = 0x00;
    // TRGCMP 0; 
    TRIG7 = 0x00;
    // TRGCMP 0; 
    TRIG8 = 0x00;
    // TRGDIV 1; TRGSTRT 0; DTM disabled; 
    TRGCON1 = 0x00;
    // TRGDIV 1; TRGSTRT 0; DTM disabled; 
    TRGCON2 = 0x00;
    // TRGDIV 1; TRGSTRT 0; DTM disabled; 
    TRGCON3 = 0x00;
    // TRGDIV 1; TRGSTRT 0; DTM disabled; 
    TRGCON4 = 0x00;
    // TRGDIV 1; TRGSTRT 0; DTM disabled; 
    TRGCON5 = 0x00;
    // TRGDIV 1; TRGSTRT 0; DTM disabled; 
    TRGCON6 = 0x00;
    // TRGDIV 1; TRGSTRT 0; DTM disabled; 
    TRGCON7 = 0x00;
    // TRGDIV 1; TRGSTRT 0; DTM disabled; 
    TRGCON8 = 0x00;
    // STRGCMP 0; 
    STRIG1 = 0x00;
    // STRGCMP 0; 
    STRIG2 = 0x00;
    // STRGCMP 0; 
    STRIG3 = 0x00;
    // STRGCMP 0; 
    STRIG4 = 0x00;
    // STRGCMP 0; 
    STRIG5 = 0x00;
    // STRGCMP 0; 
    STRIG6 = 0x00;
    // STRGCMP 0; 
    STRIG7 = 0x00;
    // STRGCMP 0; 
    STRIG8 = 0x00;
    // PWMCAP 0; 
    PWMCAP1 = 0x00;
    // PWMCAP 0; 
    PWMCAP2 = 0x00;
    // PWMCAP 0; 
    PWMCAP3 = 0x00;
    // PWMCAP 0; 
    PWMCAP4 = 0x00;
    // PWMCAP 0; 
    PWMCAP5 = 0x00;
    // PWMCAP 0; 
    PWMCAP6 = 0x00;
    // PWMCAP 0; 
    PWMCAP7 = 0x00;
    // PWMCAP 0; 
    PWMCAP8 = 0x00;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON1 = 0x00;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON2 = 0x00;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON3 = 0x00;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON4 = 0x00;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON5 = 0x00;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON6 = 0x00;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON7 = 0x00;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON8 = 0x00;
    // LEB 0; 
    LEBDLY1 = 0x00;
    // LEB 0; 
    LEBDLY2 = 0x00;
    // LEB 0; 
    LEBDLY3 = 0x00;
    // LEB 0; 
    LEBDLY4 = 0x00;
    // LEB 0; 
    LEBDLY5 = 0x00;
    // LEB 0; 
    LEBDLY6 = 0x00;
    // LEB 0; 
    LEBDLY7 = 0x00;
    // LEB 0; 
    LEBDLY8 = 0x00;
    // CHOPLEN disabled; HRDDIS disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; HRPDIS disabled; 
    AUXCON1 = 0x00;
    // CHOPLEN disabled; HRDDIS disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; HRPDIS disabled; 
    AUXCON2 = 0x00;
    // CHOPLEN disabled; HRDDIS disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; HRPDIS disabled; 
    AUXCON3 = 0x00;
    // CHOPLEN disabled; HRDDIS disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; HRPDIS disabled; 
    AUXCON4 = 0x00;
    // CHOPLEN disabled; HRDDIS disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; HRPDIS disabled; 
    AUXCON5 = 0x00;
    // CHOPLEN disabled; HRDDIS disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; HRPDIS disabled; 
    AUXCON6 = 0x00;
    // CHOPLEN disabled; HRDDIS disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; HRPDIS disabled; 
    AUXCON7 = 0x00;
    // CHOPLEN disabled; HRDDIS disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; HRPDIS disabled; 
    AUXCON8 = 0x00;

    // SYNCOEN disabled; SEIEN disabled; SESTAT disabled; SEVTPS 1; SYNCSRC SYNCI1; SYNCEN disabled; PTSIDL disabled; PTEN enabled; EIPU disabled; SYNCPOL disabled; 
    PTCON = 0x8000;
}

void __attribute__ ((weak)) PWM_SpecialEvent_CallBack(void)
{
    // Add Application code here
}

void PWM_SpecialEvent_Tasks ( void )
{
    if(IFS3bits.PSEMIF)
    {
        // PWM SpecialEvent callback function 
        PWM_SpecialEvent_CallBack();

        // clear the PWM SpecialEvent interrupt flag
        IFS3bits.PSEMIF = 0;
    }
}

void __attribute__ ((weak)) PWM_Generator1_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator1_Tasks ( void )
{
	if(IFS3bits.PSEMIF)
	{
		// PWM Generator1 callback function 
		PWM_Generator1_CallBack();
		
		// clear the PWM Generator1 interrupt flag
		IFS5bits.PWM1IF = 0;
	}
}

void __attribute__ ((weak)) PWM_Generator2_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator2_Tasks ( void )
{
	if(IFS3bits.PSEMIF)
	{
		// PWM Generator2 callback function 
		PWM_Generator2_CallBack();
		
		// clear the PWM Generator2 interrupt flag
		IFS5bits.PWM2IF = 0;
	}
}

void __attribute__ ((weak)) PWM_Generator3_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator3_Tasks ( void )
{
	if(IFS3bits.PSEMIF)
	{
		// PWM Generator3 callback function 
		PWM_Generator3_CallBack();
		
		// clear the PWM Generator3 interrupt flag
		IFS6bits.PWM3IF = 0;
	}
}

void __attribute__ ((weak)) PWM_Generator4_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator4_Tasks ( void )
{
	if(IFS3bits.PSEMIF)
	{
		// PWM Generator4 callback function 
		PWM_Generator4_CallBack();
		
		// clear the PWM Generator4 interrupt flag
		IFS6bits.PWM4IF = 0;
	}
}

void __attribute__ ((weak)) PWM_Generator5_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator5_Tasks ( void )
{
	if(IFS3bits.PSEMIF)
	{
		// PWM Generator5 callback function 
		PWM_Generator5_CallBack();
		
		// clear the PWM Generator5 interrupt flag
		IFS6bits.PWM5IF = 0;
	}
}

void __attribute__ ((weak)) PWM_Generator6_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator6_Tasks ( void )
{
	if(IFS3bits.PSEMIF)
	{
		// PWM Generator6 callback function 
		PWM_Generator6_CallBack();
		
		// clear the PWM Generator6 interrupt flag
		IFS6bits.PWM6IF = 0;
	}
}

void __attribute__ ((weak)) PWM_Generator7_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator7_Tasks ( void )
{
	if(IFS3bits.PSEMIF)
	{
		// PWM Generator7 callback function 
		PWM_Generator7_CallBack();
		
		// clear the PWM Generator7 interrupt flag
		IFS6bits.PWM7IF = 0;
	}
}

void __attribute__ ((weak)) PWM_Generator8_CallBack(void)
{
    // Add Application code here
}

void PWM_Generator8_Tasks ( void )
{
	if(IFS3bits.PSEMIF)
	{
		// PWM Generator8 callback function 
		PWM_Generator8_CallBack();
		
		// clear the PWM Generator8 interrupt flag
		IFS6bits.PWM8IF = 0;
	}
}


/**
 End of File
*/
