ORG 0000H
CLR A
UP : MOV DPTR,#SINE
MOV R0,#24
LABEL: MOVC A,@A+DPTR
MOV P2,A
       CLR A
    INC DPTR
    DJNZ R0,LABEL
    SJMP UP
ORG 050H
SINE :
DB 127,160,191,217,237,250,255,250,237,217,191,160,127,94,63,37,17,4,0,4,17,37,63,94,127
END