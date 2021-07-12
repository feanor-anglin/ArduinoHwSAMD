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

#ifndef _VARIANT_GOWIRED_GW_
#define _VARIANT_GOWIRED_GW_

#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC (32768ul)

/** Master clock frequency */
#define VARIANT_MCK     (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT                 (38u)
//#define NUM_DIGITAL_PINS           (22u)
//#define NUM_ANALOG_INPUTS    (6u)
//#define NUM_ANALOG_OUTPUTS   (1u)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

/*// LEDs
#define PIN_LED_13 (16u)
#define PIN_LED_RXL LED_ORANGE
#define PIN_LED_TXL LED_ORANGE
#define PIN_LED LED_BLUE
#define PIN_LED2 LED_RED
#define PIN_LED4 LED_GREEN
#define LED_BUILTIN LED_YELLOW

#define LED_1 (16u)
#define LED_2 (17u)
#define LED_3 (18u)
#define LED_4 (19u)
#define LED_5 (20u)

#define LED_BLUE (16u)
#define LED_RED (17u)
#define LED_GREEN (18u)
#define LED_YELLOW (19u)
#define LED_ORANGE (20u)
/*
 * Analog pins
 *
#define PIN_A0               (14ul)
#define PIN_A1               (15ul)
#define PIN_A2               (8ul)
#define PIN_A3               (9ul)
#define PIN_A4               (36ul)
#define PIN_A5               (37ul)

static const uint8_t A0    = PIN_A0;
static const uint8_t A1    = PIN_A1;
static const uint8_t A2    = PIN_A2;
static const uint8_t A3    = PIN_A3;
static const uint8_t A4    = PIN_A4;
static const uint8_t A5    = PIN_A5;
#define ADC_RESOLUTION       12

// Other pins
//#define PIN_ATN              (38ul)
// static const uint8_t ATN = PIN_ATN;

/*
 * Serial interfaces
 */
// Serial (RS485_1)
#define PIN_SERIAL_RX        (25ul)
#define PIN_SERIAL_TX        (19ul)
#define PAD_SERIAL_TX        (UART_TX_PAD_2)
#define PAD_SERIAL_RX        (SERCOM_RX_PAD_3)

// Serial1 (RS485_2)
#define PIN_SERIAL1_RX       (16ul)
#define PIN_SERIAL1_TX       (15ul)
#define PAD_SERIAL1_TX       (UART_TX_PAD_2)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_3)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 3

// SPI0 (W5500)
#define PIN_SPI_MISO         (10u)
#define PIN_SPI_MOSI         (11u)
#define PIN_SPI_SCK          (13u)
#define PIN_SPI_SS           (0u)
#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_0_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_2
static const uint8_t SS    = PIN_SPI_SS;         // SPI Slave SS not used. Set here only for reference.
static const uint8_t MOSI  = PIN_SPI_MOSI;
static const uint8_t MISO  = PIN_SPI_MISO;
static const uint8_t SCK   = PIN_SPI_SCK;

// SPI1 (MCP25625)
#define PIN_SPI1_MISO        (1u)
#define PIN_SPI1_MOSI        (22u)
#define PIN_SPI1_SCK         (32u)
#define PIN_SPI1_SS          (2u)
#define PERIPH_SPI1          sercom2
#define PAD_SPI1_TX          SPI_PAD_0_SCK_1
#define PAD_SPI1_RX          SERCOM_RX_PAD_2
static const uint8_t SS1   = PIN_SPI1_SS;
static const uint8_t MOSI1 = PIN_SPI1_MOSI;
static const uint8_t MISO1 = PIN_SPI1_MISO;
static const uint8_t SCK1  = PIN_SPI1_SCK;

// SPI2 (SD & Panel)
#define PIN_SPI2_MISO        (6u)
#define PIN_SPI2_MOSI        (20u)
#define PIN_SPI2_SCK         (12u)
#define PIN_SPI1_SS1         (9u)
#define PIN_SPI1_SS2         (7u)
#define PIN_SPI1_SS3         (30u)
#define PERIPH_SPI2          sercom3
#define PAD_SPI2_TX          SPI_PAD_0_SCK_1
#define PAD_SPI2_RX          SERCOM_RX_PAD_2
static const uint8_t SS2_1 = PIN_SPI2_SS1;
static const uint8_t SS2_2 = PIN_SPI2_SS2;
static const uint8_t SS2_3 = PIN_SPI2_SS3;
static const uint8_t MOSI2 = PIN_SPI2_MOSI;
static const uint8_t MISO2 = PIN_SPI2_MISO;
static const uint8_t SCK2  = PIN_SPI2_SCK;

//#define SPI_USER SPI2

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (4u)
#define PIN_WIRE_SCL         (3u)
#define PERIPH_WIRE          sercom0
#define WIRE_IT_HANDLER      SERCOM0_Handler

static const uint8_t SDA   = PIN_WIRE_SDA;
static const uint8_t SCL   = PIN_WIRE_SCL;

/*
 * USB
 */
//#define PIN_USB_HOST_ENABLE LED_ORANGE
#define PIN_USB_DM           (28ul)
#define PIN_USB_DP           (29ul)

#ifdef __cplusplus
}
#endif

/*
 * Onboard hardware
 */

// RS485_1
#define SERIAL_DE            (33u)

// RS485_2
#define SERIAL1_DE           (17u)

// MCP25625
#define CAN_STANDBY          (23u)
#define CAN_RESET            (24u)

// W5500
#define LAN_RESET            (5u)

// SD card
#define SDCARD_DETECT        (18ul)
#define SDCARD_CS            (PIN_SPI2_SS1)

// Relay
#define RELAY_PIN            (8u)

// Connector
#define CONNECTOR_CS1        (PIN_SPI2_SS2)
#define CONNECTOR_CS2        (PIN_SPI2_SS3)
#define CONNECTOR_PIN1       (31u)
#define CONNECTOR_PIN2       (26u)

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial;
extern Uart Serial1;

#endif

#ifdef __cplusplus
extern "C" {
#endif
unsigned int PINCOUNT_fn();
#ifdef __cplusplus
}
#endif

// These serial port names are intended to allow libraries and
// architecture-neutral
// sketches to automatically default to the correct port name for a particular
// type
// of use.  For example, a GPS module would normally connect to
// SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another
// use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial
// Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge
// library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.
// Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE_OPEN   SerialUSB
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
//#define SERIAL_PORT_HARDWARE        Serial1
//#define SERIAL_PORT_HARDWARE_OPEN   Serial1


//#define Serial SerialUSB
#endif /* _VARIANT_GOWIRED_GW_ */
