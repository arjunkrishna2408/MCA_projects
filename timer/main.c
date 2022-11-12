#include "pll.h"
#include "timer.h"
#include <LPC214x.h>

int main(){
	IO0DIR=0xffffffff;
  init_pll();
	IO0SET = 0xffffffff;
	delay_milliseconds(1000);
	IO0CLR = 0xffffffff;
	delay_milliseconds(1000);
}