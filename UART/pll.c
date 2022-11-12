#include "pll.h"
#include <LPC214x.h>

void init_pll(){
	PLL0CON=0x01;		//enable PLL, Fosc=12Mhz,CCLK=60Mhz,PCLK=60MHz
  PLL0CFG=0x24;	//MSEL and PSEL bits (M+1 = 5, p=2)
  PLL0FEED=0xaa; // send feed sequence
  PLL0FEED=0x55;
  while(!(PLL0STAT&(1<<10))); //check the lock bit
  PLL0CON=0x03;	//connect and enable pll
  PLL0FEED=0xaa;	//send feed sequence
  PLL0FEED=0x55;
  VPBDIV=0x01;	//60 Mhz
}