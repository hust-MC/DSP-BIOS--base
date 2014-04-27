;***********************************************************************; 
;*                                                                     *;
;* File Name     : qsinlt.asm                                          *;
;* 使用BootRom中的正旋函数表(Q30)   input：ACC，Q31                    *; 
;                                   output:ACC,Q31                     *;                                   
;* Date          : 25/1/2007                                           *;
;***********************************************************************;

; 使用ACC传递参数 
                
                .def    _qsinlt     
                .sect "xc_program"              
_qsinlt:    
            SETC    SXM,OVM        
			;MOVL    XAR5,#3FF000h    ;BootROM正旋表首地址
            MOVL    XAR5,#3FE000h    ;BootROM正旋表首地址
            MOVB    XAR0,#0   
            MOVL    XAR2,ACC         ; store ACC                   
            LSR     AH,#7
            LSL     AH,#1     
            MOV     AR0,AH           ; AR0=indice (alpha/2^23)*2

            MOVL    ACC,XAR2
			ANDB    AH,#7Fh 
            MOVL    XT,ACC           ; XT=(X-X1) in Q23 format
            
			SPM     0
            MOVL    ACC,*+XAR5[AR0]  ; ACC=Y1=*(SINTAB_360 + indice) Q30
			CMP     AH,#4000h
            SBF     flag_sin,NEQ
            MOV     AH,#3FFFh       
			MOV     AL,#0FFFFh
flag_sin:	MOVL    XAR3,ACC         ;store Y1
            ADDB    XAR0,#2
            MOVL    P,*+XAR5[AR0]    ; P=Y2 in Q30
            SUBL    P,ACC            ; P=Y2-Y1 in Q30
            MOVL    XAR2,P 
            IMPYL   P,XT,XAR2
            QMPYL   ACC,XT,XAR2
			LSR64   ACC:P,#8 
			LSR64   ACC:P,#15        ;右移23位	
             
            MOVL    ACC,XAR3
            ADDL    ACC,P            ; Y=Y1+(Y2-Y1)*(X-X1) Q30
            LSL     ACC,#1           ; ACC=Y in Q31 format  ***bug
            CLRC    OVM,SXM
            LRET
            .end
