#include "timer.h"
#include <LPC214X.H>

void delay_milliseconds(unsigned int milliseconds){
	T0CTCR = 0x00;                //Select Timer Mode
  T0TCR = 0x00;                 //Timer off
  T0PR = 59999;                 //Prescaler value for 1ms
  T0TCR = 0x02;                 //Timer reset
  T0TCR = 0x01;                 //Timer ON
  while(T0TC<milliseconds);           
  T0TCR = 0x00;                 //Timer OFF
  T0TC = 0;
}

void delay_microseconds(unsigned int microseconds){
	T0CTCR = 0x00;                //Select Timer Mode
  T0TCR = 0x00;                 //Timer off
  T0PR = 59;                 //Prescaler value for 1ms
  T0TCR = 0x02;                 //Timer reset
  T0TCR = 0x01;                 //Timer ON
  while(T0TC<microseconds);           
  T0TCR = 0x00;                 //Timer OFF
  T0TC = 0;
}