#pragma once

#define VCC                 3300.       //mV
#define kr                  392.1568    //Constante de conversion a resistencia de potenciometrosen ohmios
#define RESOLUTION_ANALOG   4095.     //Resolucion de las entradas analogicas

//TEMP
#define ADC_DIR             0x48    // Direction of the ADC
#define SHT21_DIR          	0x40    // Direction of the SHT21

#include "sckBase.h"
// #include <Wire.h>



class SckUrban {
public:
	void setup();
	//void setup();

	// Noise
	float GetNoise();
	void gainChange(uint8_t value);
	void writeResistorRaw(byte resistor, int value);
	int gain_step = 0;
	float sounddB = 0;
	
	// Temp and humidity
	uint16_t readSHT(uint8_t type);
	float getHumidity();
	float getTemperature();

	void ADCini();
	void writeI2C(byte deviceaddress, byte address, byte data );
	byte readI2C(int deviceaddress, byte address);

};


/*
NOTAS

-- Por I2C tenemos:
	* El potenciometro digital
	* Humidity
	* Temperature
	* UV
	* Light

-- Por pines analogicos
	* CO Sensor
	* NO Sensor
	* CO Current
	* NO Current
	* Sound Sensor

*/