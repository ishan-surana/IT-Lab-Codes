	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors 
	DCD 0x10001000
    DCD Reset_Handler
    ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=05
	BL FACT
STOP B STOP
FACT
	PUSH {R4,R14} 
	MOV R4, R0
 	CMP R0, #0
	BNE Loop
	MOV R0, #1
 	B Popper
Loop 
 	SUB R0,R0,#1
 	BL FACT
 	MOV R1, R4
 	MUL R0,R0,R1
Popper
 	POP {R4,R14}
	BX LR
	END