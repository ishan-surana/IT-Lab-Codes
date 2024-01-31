	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0, #10 ;n
	MOV R2, #0 ;sum
	MOV R4, #1 ;multiplier
My_Loop
	MLA R3, R0, R4, R2
	MOV R2, R3
	SUBS R0, R0, #1
	CMP R0, #0
	BNE My_Loop
STOP
	B STOP
VALUE DCD 0x10000000
	AREA data, DATA, READWRITE
	END