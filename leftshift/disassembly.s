	AREA RESET, CODE, READONLY
	ENTRY

Main
	LDR R1, Value ; loading the byte value into R1
	LDR R2, Mask ;
	MOV R3,R1, LSR #0x4 
	MOV R3,R3, LSL #0x8 
	AND R1,R1,R2
	ADD R1,R1,R3
	
	LDR R4,Result
	STR R1,[R4]
	
	NOP
	
Value	DCB &5F
	ALIGN
Mask	DCW &000F
	ALIGN
Result	DCD &40000000
	END