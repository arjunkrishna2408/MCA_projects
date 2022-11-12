	AREA RESET, CODE, READONLY
	ENTRY
	
Main
	LDR R1,=0x40000000 ; load the address 0x4000 0000
	LDR R2,[R1] ; read the value 1 present in 0x4000 0000
	ADD R1,R1,#0x4 ; increment the address by 0x4
	LDR R3,[R1] ; read the value 2 in 0x4000 0004
	CMP R2,R3 ; compare the value 1 and 2
	BHI DONE ; check whether value 1 is greater than 2, if yes them jump to DONE, otherwise continue
	MOV R2,R3 ; store the value 2 which is bigger than value 1 
	
DONE
	LDR R1,=0x4000000C
	STR R2,[R1]
	
	NOP
	END