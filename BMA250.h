#include <I2C.h>

#ifndef BMA250_h
#define BMA250_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define BMA_ADD    (uint8_t)0x18	// default I2C address

// Bandwidth values for register R10
// #define BW7P81              0x08 //7.81Hz bandwith
// #define BW15P63             0x09 //15.63Hz bandwith
// #define BW31P25             0x0A //31.25Hz bandwith
// #define BW62P5              0x0B //62.50Hz bandwith
// #define BW125		        0x0C //125 Hz bandwith
// #define BW250               0x0D //250 Hz bandwith
// #define BW500               0x0E //500 Hz bandwith
// #define BW1000              0x0F //1000 Hz bandwith

// G range selection register R0F values
// #define GSEL2               0x03	// +/- 2g (default value after reset)
// #define GSEL4				0x05	// +/- 4g
// #define GSEL8				0x08	// +/- 8g
// #define GSEL16				0x0C	// +/- 16g

struct registersBMA250
{
	uint8_t R0F;	// g-range selection
	uint8_t R10;	// bandwidths
	uint8_t R11;	// power modes
	uint8_t R16;	// Interrupt settings
	uint8_t R17;	// Interrupt settings
	uint8_t R19;	// Interrupt to pin mapping
	uint8_t R1A;	// Interrupt to pin mapping
	uint8_t R1B;	// Interrupt to pin mapping
	uint8_t R20;	// Interrupt pin eleectrical behaviour
	uint8_t R21;	// Interrupt reset and mode selection
	uint8_t R25;	// delay time for high-g interrupt
	uint8_t R26;	// threshold for high-g interrupt
	uint8_t R27;	// number of samples for slope interrupt
	uint8_t R28;	// threshold for slope interrupt
};

class BMA250
{
	public:
		BMA250(I2C *iic);
		void init(uint8_t, uint16_t);
		void configureMotion();
		void configureInterrupts();
		void enableInterrupts();
		void disableInterrupts();
		registersBMA250 config;
	private:
		I2C *i2c;
};
#endif
