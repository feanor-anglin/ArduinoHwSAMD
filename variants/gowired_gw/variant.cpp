/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number |  Label/Name      |  PIN   | Notes           | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          |                  |  PA11  | Not connected   | EIC/EXTINT[11] ADC/AIN[19]           PTC/X[3]  SERCOM0/PAD[3]  SERCOM2/PAD[3]  TCC0/WO[3]  TCC1/WO[1]
 * | 1          | SPI1_MISO        |  PA10  | CAN MISO        | EIC/EXTINT[10] ADC/AIN[18]           PTC/X[2]  SERCOM0/PAD[2] *SERCOM2/PAD[2]  TCC0/WO[2]  TCC1/WO[0]
 * | 2          | SPI1_CS          |  PA14  | CAN CS          | EIC/EXTINT[14]                                 SERCOM2/PAD[2]  SERCOM4/PAD[2]  TC3/WO[0]   TCC0/WO[4]
 * | 3          | SCL              |  PA09  |                 | EIC/EXTINT[9]  ADC/AIN[17]           PTC/X[1] *SERCOM0/PAD[1]  SERCOM2/PAD[1]  TCC0/WO[1]  TCC1/WO[3]
 * | 4          | SDA              |  PA08  |                 | EIC/NMI        ADC/AIN[16]           PTC/X[0] *SERCOM0/PAD[0]  SERCOM2/PAD[0]  TCC0/WO[0]  TCC1/WO[2]
 * | 5          | LAN_RESET        |  PA15  | Digital output  | EIC/EXTINT[15]                                 SERCOM2/PAD[3]  SERCOM4/PAD[3]  TC3/WO[1]   TCC0/WO[5]
 * | 6          | SPI2_MISO        |  PA20  | SDCARD & CONN   | EIC/EXTINT[4]                        PTC/X[8]  SERCOM5/PAD[2] *SERCOM3/PAD[2]              TCC0/WO[6]
 * | 7          | SPI2_CS2         |  PA21  | Connector CS1   | EIC/EXTINT[5]                        PTC/X[9]  SERCOM5/PAD[3]  SERCOM3/PAD[3]              TCC0/WO[7]
 * | 8          | RELAY_PIN        |  PA06  | Digital output  | EIC/EXTINT[6]  ADC/AIN[6]  AC/AIN[2] PTC/Y[4]  SERCOM0/PAD[2]                  TCC1/WO[0]
 * | 9          | SPI2_CS1         |  PA07  | SDCARD CS       | EIC/EXTINT[7]  ADC/AIN[7]  AC/AIN[3] PTC/Y[5]  SERCOM0/PAD[3]                 *TCC1/WO[1]
 * | 10         | SPI0_MISO        |  PA18  | LAN MISO        | EIC/EXTINT[2]                        PTC/X[6] *SERCOM1/PAD[2]  SERCOM3/PAD[2]  TC3/WO[0]   TCC0/WO[2]
 * | 11         | SPI0_MOSI        |  PA16  | LAN MOSI        | EIC/EXTINT[0]                        PTC/X[4] *SERCOM1/PAD[0]  SERCOM3/PAD[0]  TCC2/WO[0]  TCC0/WO[6]
 * | 12         | SPI2_SCK         |  PA19  | SDCARD & CONN   | EIC/EXTINT[3]                        PTC/X[7]  SERCOM1/PAD[3] *SERCOM3/PAD[3]  TC3/WO[1]   TCC0/WO[3]
 * | 13         | SPI0_SCK         |  PA17  | LAN SCK         | EIC/EXTINT[1]                        PTC/X[5] *SERCOM1/PAD[1]  SERCOM3/PAD[1]  TCC2/WO[1]  TCC0/WO[7]
 * | 14         |                  |  PA02  | Not connected   | EIC/EXTINT[2]  ADC/AIN[0]  DAC/VOUT  PTC/Y[0]
 * | 15         | UART1_TX         |  PB08  | RS485_1 TX      | EIC/EXTINT[8]  ADC/AIN[2]            PTC/Y[14]                *SERCOM4/PAD[0]  TC4/WO[0]
 * | 16         | UART1_RX         |  PB09  | RS485_1 RX      | EIC/EXTINT[9]  ADC/AIN[3]            PTC/Y[15]                *SERCOM4/PAD[1]  TC4/WO[1]
 * | 17         | DE_1             |  PA04  | RS485_1 DE      | EIC/EXTINT[4]  ADC/AIN[4]  AC/AIN[0] PTC/Y[2]  SERCOM0/PAD[0]                  TCC0/WO[0]
 * | 18         | SDCARD_DET       |  PA05  | Digital input   | EIC/EXTINT[5]  ADC/AIN[5]  AC/AIN[1] PTC/Y[5]  SERCOM0/PAD[1]                  TCC0/WO[1]
 * | 19         | UART0_TX         |  PB02  | RS485_0 TX      | EIC/EXTINT[2]  ADC/AIN[10]           PTC/Y[8] 				  *SERCOM5/PAD[0]
 * | 20         | SPI2_MOSI        |  PA22  | SDCARD & CONN   | EIC/EXTINT[6]                        PTC/X[10]*SERCOM3/PAD[0]  SERCOM5/PAD[0]  TC4/WO[0]   TCC0/WO[4]
 * | 21         |                  |  PA23  | Not connected   | EIC/EXTINT[7]                        PTC/X[11] SERCOM3/PAD[1]  SERCOM5/PAD[1]  TC4/WO[1]   TCC0/WO[5]
 * | 22         | SPI1_MOSI        |  PA12  | CAN MOSI        | EIC/EXTINT[12]                                *SERCOM2/PAD[0]  SERCOM4/PAD[0]  TCC2/WO[0]  TCC0/WO[6]
 * | 23         | CAN_STBY         |  PB10  | MCP25625 STANDBY| EIC/EXTINT[10]                                 SERCOM4/PAD[2]  TC5/WO[0]       TCC0/WO[4]
 * | 24         | CAN_RESET        |  PB11  | MCP25625 RESET  | EIC/EXTINT[11]                                 SERCOM4/PAD[3]  TC5/WO[1]       TCC0/WO[5]
 * | 25         | UART0_RX         |  PB03  | RS485_0 RX      | EIC/EXTINT[3]  ADC/AIN[11]           PTC/Y[9]                 *SERCOM5/PAD[1]  TC6/WO[1]   TCC3/WO[3]
 * | 26         | CONN_OUT2        |  PA27  | CONNECTOR PIN   | EIC/EXTINT[15]                                                                 TCC3/WO[6]
 * | 27         |                  |  PA28  | Not connected   | EIC/EXTINT[8]
 * | 28         |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 29         |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * | 30         | SPI2_CS3         |  PB22  | CONNECTOR CS2   | SERCOM5/PAD[2]
 * | 31         | CONN_OUT1        |  PB23  | CONNECTOR PIN   | SERCOM5/PAD[3]
 * | 38         | SPI1_SCK         |  PA13  | CAN SCK         | EIC/EXTINT[13]                                *SERCOM2/PAD[1]  SERCOM4/PAD[1]  TCC2/WO[1]  TCC0/WO[7]
 * | 42         | DE_0             |  PA03  | RS485_0 DE      | EIC/EXTINT[3]  [ADC|DAC]/VREFA ADC/AIN[1] PTC/Y[1]
 * | 44         |                  |  PA30  | SWCLK           | EXTINT[10]                                                     SERCOM1/PAD[2]  TCC1/WO[0]
 * | 45         |                  |  PA31  | SWDIO           | EXTINT[11]                                                     SERCOM1/PAD[3]  TCC1/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |32.768KHz Crystal |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |                  |  PA00  | XIN32           | EIC/EXTINT[0] SERCOM1/PAD[0] TCC2/WO[0]
 * |            |                  |  PA01  | XOUT32          | EIC/EXTINT[1] SERCOM1/PAD[1] TCC2/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */
 
#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
  { PORTA, 11, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // NOT USED
  { PORTA, 10, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // MISO: SERCOM2/PAD[2]
  { PORTA, 14, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14 },	// DIGITAL OUTPUT (CS)
  { PORTA,  9, PIO_SERCOM, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, // SCL: SERCOM0/PAD[1]
  { PORTA,  8, PIO_SERCOM, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI },  // SDA: SERCOM0/PAD[0]
  { PORTA, 15, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 }, // DIGITAL OUTPUT (LAN RESET)
  { PORTA, 20, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, // MISO: SERCOM3/PAD[2]
  { PORTA, 21, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // DIGITAL OUTPUT (CS)
  { PORTA,  6, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // DIGITAL OUTPUT (RELAY)
  { PORTA,  7, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // DIGITAL OUTPUT (CS)
  { PORTA, 18, PIO_SERCOM, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // MISO: SERCOM1/PAD[2]
  { PORTA, 16, PIO_SERCOM, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0 }, // MOSI: SERCOM1/PAD[0]
  { PORTA, 19, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // SCK: SERCOM3/PAD[3]
  { PORTA, 17, PIO_SERCOM, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1 }, // SCK: SERCOM1/PAD[1]
  { PORTA,  2, PIO_ANALOG, 		(PIN_ATTR_ANALOG),  ADC_Channel0, 	NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // NOT USED
  { PORTB,  8, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, // TX: SERCOM4/PAD[0]
  { PORTB,  9, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, // RX: SERCOM4/PAD[1]
  { PORTA,  4, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, // DIGITAL OUTPUT (DE)
  { PORTA,  5, PIO_DIGITAL,     (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // DIGITAL INPUT (SDCARD DET)
  { PORTB,  2, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // TX: SERCOM5/PAD[0]
  { PORTA, 22, PIO_SERCOM, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // MOSI: SERCOM3/PAD[0]
  { PORTA, 23, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // NOT USED
  { PORTA, 12, PIO_SERCOM, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 }, // MOSI: SERCOM2/PAD[0]
  { PORTB, 10, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // DIGITAL OUTPUT (CAN STBY)
  { PORTB, 11, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // DIGITAL OUTPUT (CAN RESET)
  { PORTB,  3, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RX: SERCOM5/PAD[1]
  { PORTA, 27, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DIGITAL OUTPUT (CONNECTOR)
  { PORTA, 28, PIO_COM, 		(PIN_ATTR_NONE), 	No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB Host enable // NOT USED
  { PORTA, 24, PIO_COM, 		(PIN_ATTR_NONE), 	No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM, 		(PIN_ATTR_NONE), 	No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
  { PORTB, 22, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DIGITAL OUTPUT (CS)
  { PORTB, 23, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DIGITAL OUTPUT (CONNECTOR)
  { PORTA, 13, PIO_SERCOM, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 }, // SCK: SERCOM2/PAD[1]
  { PORTA,  3, PIO_OUTPUT, 		(PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DIGITAL OUTPUT (DE)
  { PORTA, 30, PIO_PWM, 		(PIN_ATTR_DIGITAL|PIO_SERCOM), No_ADC_Channel, NOT_ON_PWM, TCC1_CH0, EXTERNAL_INT_10 }, // SWCLK
  { PORTA, 31, PIO_PWM, 		(PIN_ATTR_DIGITAL|PIO_SERCOM), No_ADC_Channel, NOT_ON_PWM, TCC1_CH1, EXTERNAL_INT_11 }, // SWDIO
  
  //{ PORTA, 22, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SDA: SERCOM3/PAD[0]
  //{ PORTA, 23, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCL: SERCOM3/PAD[1]
  //{ PORTA, 19, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MISO: SERCOM1/PAD[3]
  //{ PORTA, 16, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MOSI: SERCOM1/PAD[0]
  //{ PORTA, 18, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SS: SERCOM1/PAD[2]
  //{ PORTA, 17, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCK: SERCOM1/PAD[1]
  //{ PORTA, 21, PIO_PWM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM0_CH7, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // Pin 7
  //{ PORTA,  6, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM1_CH0, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // Pin 8
  //{ PORTA,  7, PIO_PWM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM1_CH1, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // Pin 9
  //{ PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // DAC/VOUT
} ;

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
    }
}

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom4, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;
Uart Serial( &sercom5, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;

void SERCOM4_Handler()
{
  Serial1.IrqHandler();
}

void SERCOM5_Handler()
{
  Serial.IrqHandler();
}
