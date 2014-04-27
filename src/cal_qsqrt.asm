;***********************************************************************; 
;*                                                                     *;
;* File Name     : qsqrt.asm                                           *;
;*               64位开方，输入放在ACC:P，输出放在ACC                  *;
;***********************************************************************;
;* Tylor Series Approximation of SQRT:                                 *;                                   
;* The following equation approximates the sqrt(x), where 0.5<= x <=1.0*;
;*  0.5*sqrt(x)= 0.7274475*x-0.672455*x^2+0.553406*x^3-0.2682495*x^4   *;
;*              +0.0560605*x^5+0.1037903                               *;
;***********************************************************************;
  	.global _filldata 
    .text
_filldata:
	DEC AL	
	RPT AL
||	MOV *XAR4++,AH
    LRETR

        .def _qsqrt

a0      .set    06a48h          ; 0.1037903  scaled by 2^18
a1      .set    05d1dh          ; 0.7274475 scaled by 2^15 
a2      .set    0a9edh          ; -0.672455 scaled by 2^15
a3      .set    046d6h          ; 0.553406 scaled by 2^15
a4      .set    0bb54h          ; -0.2682495 scaled by 2^16 
a5      .set    00e5ah          ; 0.0560605 scaled by 2^16 

SQRT2   .set    05a82h           ;(1/sqrt(2)) in Q15 format
                                ; Also sqrt(2) in Q14 format
SQRT21  .set    0b504h
SQRT20  .set    0f333h           ;SQRT21:SQRT20 1/sqrt(2)in Q32   
                               
            .sect "xc_program"  
_qsqrt: 
            TEST    ACC          ; ACC=X in Q16 format
            B qsqrt32,EQ
            
            SETC SXM
            LSR64 ACC:P,#1       ;ACC:P=X in Q63 format
            CSB ACC
            LSL64 ACC:P,T
            
            TBIT @T,#0
                                                                                                                                                                                                                                 MOV AR7,T
            MOVL XAR1,ACC
            MOVL XAR0,P
            MOV AH,T
            LSR AH,#1    
            MOV AR7,AH             ;AR7=AH=n/2
            
            MOV ACC,#a5
            LSL ACC,#16
            MOVL XT,ACC
            IMPYL P,XT,XAR1
            QMPYL ACC,XT,XAR1
            ADD ACC,#a4<<15      ;Q63
            MOVL XAR3,ACC
            MOVL XAR2,P
            
            
            
            MOVL XT,XAR1
            QMPYUL P,XT,XAR2
            MOVL @XAR2,P
            MOVL XAR4,#0
            
            MOVL XT,XAR3
            QMPYXUL P,XT,XAR0
            MOV @T,#32
            LSL64 ACC:P,T
            ASR64 ACC:P,T
            MOVL @XAR5,P
            MOVL @XAR6,ACC
            
            MOVL XT,XAR3
            IMPYL P,XT,XAR1
            QMPYL ACC,XT,XAR1
            
            ADDUL P,@XAR2
            ADDCL ACC,@XAR4
            
            ADDUL P,@XAR5
            ADDCL ACC,@XAR6  
            ADD ACC,#a3<<15     ;Q62
            MOVL XAR3,ACC
            MOVL XAR2,P                                
           
           
                          
           
            MOVL XT,XAR1
            QMPYUL P,XT,XAR2
            MOVL @XAR2,P
            MOVL XAR4,#0
            
            MOVL XT,XAR3
            QMPYXUL P,XT,XAR0
            MOV @T,#32
            LSL64 ACC:P,T
            ASR64 ACC:P,T
            MOVL @XAR5,P
            MOVL @XAR6,ACC
            
            MOVL XT,XAR3
            IMPYL P,XT,XAR1
            QMPYL ACC,XT,XAR1
            
            ADDUL P,@XAR2
            ADDCL ACC,@XAR4
            
            ADDUL P,@XAR5
            ADDCL ACC,@XAR6  
            ADD ACC,#a2<<14       ;Q61
            MOVL XAR3,ACC
            MOVL XAR2,P
            
            
            
            MOVL XT,XAR1
            QMPYUL P,XT,XAR2
            MOVL @XAR2,P
            MOVL XAR4,#0
            
            MOVL XT,XAR3
            QMPYXUL P,XT,XAR0
            MOV @T,#32
            LSL64 ACC:P,T
            ASR64 ACC:P,T
            MOVL @XAR5,P
            MOVL @XAR6,ACC
            
            MOVL XT,XAR3
            IMPYL P,XT,XAR1
            QMPYL ACC,XT,XAR1
            
            ADDUL P,@XAR2
            ADDCL ACC,@XAR4
            
            ADDUL P,@XAR5
            ADDCL ACC,@XAR6 
            ADD ACC,#a1<<13      ;Q60
            MOVL XAR3,ACC
            MOVL XAR2,P
            
            
            
            MOVL XT,XAR1
            QMPYUL P,XT,XAR2
            MOVL @XAR2,P
            MOVL XAR4,#0
            
            MOVL XT,XAR3
            QMPYXUL P,XT,XAR0
            MOV @T,#32
            LSL64 ACC:P,T
            ASR64 ACC:P,T
            MOVL @XAR5,P
            MOVL @XAR6,ACC
            
            MOVL XT,XAR3
            IMPYL P,XT,XAR1
            QMPYL ACC,XT,XAR1
            
            ADDUL P,@XAR2
            ADDCL ACC,@XAR4
            
            ADDUL P,@XAR5
            ADDCL ACC,@XAR6
            ADD ACC,#a0<<9       ;Q59
            LSL64 ACC:P,#4
            MOVL XAR5,ACC
            MOVL XAR4,P
            ;ACC=0.5sqrt(s*x) in Q59
            ;ACC=sqrt(s*x) in Q58
           
                
            ;MOVL XAR1,ACC ;Q26 
            MOVL XT,ACC 
            ;MOV @AH,#SQRT21 
            ;MOV @AL,#SQRT20 
            MOV ACC,#SQRT2  
            LSL ACC,#16
            LSL ACC,#1  
            MOVL XAR3,ACC
            
            IMPYXUL P,XT,XAR3
            MOVL XAR2,P
            QMPYXUL P,XT,XAR3
            MOVL ACC,P
            MOVL P,XAR2
            MOVL XAR3,ACC      ;Q58
            MOVL XAR2,P
             
                
            MOVL ACC,XAR5
            MOVL P,XAR4
            MOVL XAR3,ACC,NTC  ;n is even
            MOVL ACC,P
            MOVL XAR2,ACC,NTC
            
            MOVL ACC,XAR3
            MOVL P,XAR2
            
            MOV T,AR7
            LSR64 ACC:P,T
            LSL64 ACC:P,#2
            LRET
            
            
qsqrt32:    SETC    SXM             ; Set the sign ext. mode
            MOVL    ACC,P
            MPY     P,T,#0          ; P=0 
            LSR64   ACC:P,#1        ; X=X/2
            
            
            CSB     ACC             ; Count sign bits, T=E
            LSL64   ACC:P,T         ; ACC=x=X/(2^(E-15) in  Q31 format

            TBIT    @T,#0           ; TC=odd/even shift indicator
            MOV     AR4,T           ; AH=n             
            MOVL    XT,ACC          ; T=x in Q31
            MOV     AH,AR4          ; AH=n
            LSR     AH,#1           ; AH=n/2
            MOV     AR4,AH          ; AR4=n/2
   
            MPY     ACC,T,#a5       ; ACC=x*a5 in Q31 
            ADD     ACC,#a4<<15     ; ACC=a4+x*a5 in Q31
 
            QMPYL   ACC,XT,@ACC     ; ACC=x*(a4+x*a5) in Q30
            ADD     ACC, #a3<<15    ; ACC=a3+x*(a4+x*a5) in Q30
            
            QMPYL   ACC,XT,@ACC     ; ACC=x*(a3+(a4+x*a5)) in Q29
            ADD     ACC, #a2<<14    ; ACC=a2+x*(a3+(a4+x*a5)) in Q29
            
            QMPYL   ACC,XT,@ACC     ; ACC=x*(a2+x*(a3+(a4+x*a5))) in Q28
            ADD     ACC, #a1<<13    ; ACC=a1+x*(a2+x*(a3+(a4+x*a5))) in Q28 
            
            QMPYL   ACC,XT,@ACC     ; ACC=x*(a1+x*(a2+x*(a3+(a4+x*a5)))) in Q27
            ADD     ACC, #a0<<9     ; ACC=a0+x*(a1+x*(a2+x*(a3+(a4+x*a5)))) in Q27
                                    ; ACC=0.5sqrt(s*x) in Q27
                                    ; ACC=sqrt(s*x) in Q26

;*********** De-normalise the result ****************************   
        
            MOVH    T,ACC<<5        ; ACC=sqrt(s*x) in Q15
            MPY     P,T,#SQRT2      ; P=sqrt(s*x)*(1/sqrt(2)) in Q30 format
                                    
            LSL     ACC,#4          ; ACC=sqrt(s*x) in Q30  
            MOVL    P,ACC,NTC       ; P=sqrt(s*x) in Q30, if n is odd
            MOVL    ACC,P

            MOV     T,AR4
            LSRL    ACC,T           ; ACC=sqrt(x) in Q30
          
            MOVH    AL,ACC<<2       ; AL=sqrt(x)  
            MOV     AH,#0  
            LRET
                
           .end              
