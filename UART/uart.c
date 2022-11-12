#include "uart.h"
#include <LPC214X.H>

void init_uart0(){
	PINSEL0=0X5;
  U0LCR=0X83;            //8-data bits, 1 Stop bit, Disable Parity and Enable DLAB
  U0DLL=0x87;
  U0DLM=0x1;
  U0LCR=0X03;  
}

void transmit_char_uart0(unsigned char c){
	while((U0LSR & (1<<5)) == 0);
	U0THR = c;
}

char receive_char_uart0(){
	unsigned char temp_recv_var;
	while((U0LSR & (1<<0)) == 0);         //Checking RDR bit
  temp_recv_var = U0RBR;
  return temp_recv_var;
}
