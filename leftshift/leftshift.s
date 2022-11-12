;Shift left one bit

		AREA program, CODE, READONLY
		ENTRY
	
MAIN
		LDR R1,value
		MOV R1, R1, LSL #0x1
		LDR R0,result
		STR R1,[R0]
	
value	DCD &4242
result 	DCD &40000000
	
		END