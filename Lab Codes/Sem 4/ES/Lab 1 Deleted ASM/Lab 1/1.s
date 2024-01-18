	AREA RESET, DATA, READONLY
	EXPORT __Vectors
 
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
 
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	MOV R0, #12
	MOV R1, #0X12
	MOV R2, #-12
	MOV R4, #2_10101010
	MOV R5, #8_1763

STOP
	B STOP
	END