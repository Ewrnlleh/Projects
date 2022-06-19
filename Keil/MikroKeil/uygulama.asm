ORG 0H
BASLA:	MOV DPTR,#TABLO
	MOV TMOD,#11H
	MOV TH0,#0H
	MOV R5,#0
	MOV TL0,#0H
	SETB TR0
	SETB P1.0
KONTROL:	MOV A,R7
	MOV P3,A
	RL A
	MOV R7,A
	MOV A,@R0
	MOV P2,A
	ACALL YENILE
	INC R0
	INC R5
YENILE:	MOV TH1,#0DCH
	MOV TL1,#0
	SETB TR1
BURASI:	JNB TF1,BURASI
	CLR TR1
	CLR TF1
	RET
ORG 0090H
TABLO:	DB 11111111B,11111111B,10100100B,10110000B,10011001B,10010010B,10000010B,11111000B,10000000B,10010000B
TABLO2: DB 11111111B,10100100B,10100100B,10110000B,10011001B,10010010B,10000010B,11111000B,10000000B,10010000B
END
