	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10004000
	DCD Reset_Handler
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC
	LDR R1,[R0]
	LDR R6, =NUM
	LDR R2,[R6]
	LDR R4, =RES
	MOV R5,#10
Check_Equal
	CMP R1,R2
	BNE Not_Equal
	STR R0,[R4],#4
Not_Equal
	LDR R1,[R0,#4]!
	SUBS R5,#1
	BNE Check_Equal
STOP
	B STOP
SRC DCD 0x1, 0x2, 0x3, 0x4, 0x5, 0x2, 0x2, 0x6, 0x2, 0x7
NUM DCD 0x2
	AREA mydata, DATA, READWRITE
RES DCD 0x10000000
	END