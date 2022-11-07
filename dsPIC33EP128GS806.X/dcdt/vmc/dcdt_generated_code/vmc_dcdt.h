/**
  Summary:
  This header file was created using Microchip Digital Compensator Design Tool (DCDT)
  and includes system summary and digital compensator coefficients. This file
  should be included in the MPLAB X project directory.

  File Name:     vmc_dcdt.h
  Project Name:  vmc
  Date:          11/4/2022
  Time:          17:13.52

  Software License Agreement

  Copyright ? 2022 Microchip Technology Inc.  All rights reserved.
  Microchip licenses to you the right to use, modify, copy and distribute
  Software only when embedded on a Microchip microcontroller or digital
  signal controller, which is integrated into your product or third party
  product (pursuant to the sublicense terms in the accompanying license
  agreement).

  You should refer to the license agreement accompanying this Software
  for additional information regarding your rights and obligations.

  SOFTWARE AND DOCUMENTATION ARE PROVIDED ¡§AS IS¡¨ WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
  OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
  PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
  OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
  BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
  DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
  INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
  COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
  CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
  OR OTHER SIMILAR COSTS.
 **/
#ifndef _VMC_DCDT_DEFINES_H
#define _VMC_DCDT_DEFINES_H

/**
  Compensator Type:  3P3Z
      Entry                Value  
    ---------            ---------
  Pole 0                 5.0000e+02 Hz
  Pole 2                 6.0290e+03 Hz
  Pole 3                 1.2500e+05 Hz
  Zero 1                 1.8680e+03 Hz
  Zero 2                 1.8680e+03 Hz
  Gain(Kdc)              1.000
  Warp                   false
  PWM Frequency          2.5000e+05
  PWM Sampling Ratio     1
  Sampling Frequency     2.5000e+05
  PWM Max Resolution     1.0600e-09
  Computational Delay    1.5000e-06
  Gate Drive Delay       1.5000e-07
  Control Output Min.    0
  Control Output Max.    32767
  Kuc Gain               3.0410e+00
  Use Kuc Gain           false


  PWM Calculations
      Name                Value  
    ---------           ---------
  Bits of Resolution    11.882
  Gain                  2.651e-04


  s-domain transfer function

               Wp0   Wp2(Wp3)(Wz1 + s)(Wz2 + s)
  H(s) = Kdc X --- X --------------------------
                s    Wz1(Wz2)(Wp2 + s)(Wp3 + s)

                 3.14e+03   3.79e+04(7.85e+05)(1.17e+04 + s)(1.17e+04 + s)
  H(s) = 1.000 X -------- X ----------------------------------------------
                    s       1.17e+04(1.17e+04)(3.79e+04 + s)(7.85e+05 + s)



  Digital Compensator Coefficients

  Name    Value     Normalized    Q15      Hex
  ----    -----     ----------    ---      ---
  a1      1.637     1.000         32764    0x7FFC
  a2      -0.446    -0.273        -8933    0xDD1B
  a3      -0.191    -0.117        -3817    0xF117
  b0      0.514     0.314         10286    0x282E
  b1      -0.467    -0.285        -9343    0xDB81
  b2      -0.513    -0.313        -10265   0xD7E7
  b3      0.468     0.286         9364     0x2494


  z-domain transfer function

         u(z)  B0 + B1z^(-1) + B2z^(-2) + B3z^(-3)
  H(z) = --- = -----------------------------------
         e(z)  A0 - A1z^(-1) - A2z^(-2) - A3z^(-3)

          (0.514) + (-0.467)z^(-1) + (-0.513)z^(-2) + (0.468)z^(-3)
  H(z) = -----------------------------------------------------------
          1 - (1.637)z^(-1) - (-0.446)z^(-2) - (-0.191)z^(-3)

**/


// Compensator Coefficient Defines
#define VMC_COMP_3P3Z_COEFF_A1      0x7FFC
#define VMC_COMP_3P3Z_COEFF_A2      0xDD1B
#define VMC_COMP_3P3Z_COEFF_A3      0xF117
#define VMC_COMP_3P3Z_COEFF_B0      0x282E
#define VMC_COMP_3P3Z_COEFF_B1      0xDB81
#define VMC_COMP_3P3Z_COEFF_B2      0xD7E7
#define VMC_COMP_3P3Z_COEFF_B3      0x2494
#define VMC_COMP_3P3Z_POSTSCALER    0x68C9
#define VMC_COMP_3P3Z_POSTSHIFT     0xFFFF
#define VMC_COMP_3P3Z_PRESHIFT      0x0000


// Compensator Clamp Limits
#define VMC_COMP_3P3Z_MIN_CLAMP    0x0000
#define VMC_COMP_3P3Z_MAX_CLAMP    0x7FFF


#endif
