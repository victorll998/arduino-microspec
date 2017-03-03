/*
  c12880.h - Library for interacting with the Hamamatsu C128880 microspectrometer
  Created by Craig Wm. Versek, 2017-03-01
 */
#ifndef _C12880_H_INCLUDED
#define _C12880_H_INCLUDED

#include <Arduino.h>
#include <ADC.h> /* https://github.com/pedvide/ADC */

#define C128880_NUM_CHANNELS 288
/*******************************************************************************
  C128880_Class
  
*******************************************************************************/
class C128880_Class{
public:
  C128880_Class(const int TRG_pin,
                const int ST_pin,
                const int CLK_pin,
                const int VIDEO_pin
               );
  //Configuration methods
  void begin();
  void set_integration_time(float seconds);
  //Functionality methods
  void read_into(uint16_t *buffer);
private:
  //helper methods
  void _pulse_clock(int times);
  //Attributes
  int _TRG_pin;
  int _ST_pin;
  int _CLK_pin;
  int _VIDEO_pin;
  ADC *_adc; // adc object
  int _clock_delay_micros;
  float _integ_time;
  int   _integ_clock_cycles;
};



#endif /* _C12880_H_INCLUDED */
