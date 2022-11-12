; Find the length of a CR terminated string

	;TTL Ch6Ex1 - strlencr
	AREA Program, CODE, READONLY
	ENTRY

Main
	LDR R0, =Data1 ; Load the address of the lookup table

	EOR R1, R1, R1 ; Clear R1 to store count
Loop
	LDRB R2, [R0], #1 ; Load the first byte into R2
	CMP R2, #CR ; Is it the terminator ?
	BEQ Done ; Yes => Stop loop
	ADD R1, R1, #1 ; No => Increment count
	BAL Loop ; Read next char

Done
	;STR R1, CharCount ; Store result
	LDR R0,CharCount
	STR R1,[R0]

	;AREA Data1, DATA
	
	ALIGN
Data1 	DCB "Hello, World", CR
	ALIGN

	;AREA Result, DATA
CharCount	DCD &40000000 ; Storage for count
CR	EQU 0x0D
	END