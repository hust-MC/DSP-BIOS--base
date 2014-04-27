;***********************************************************************; 
;* File Name     : div32.asm                                           *;
;*              ACC=Num32(Qx),P=Den32(Qy)                              *;
;*             ACC:P=Num32/Den32 in(32+Qx-Qy)format                    *;
;*            有符号数32位除以32位，结果64位                           *;
;***********************************************************************;
	.def _div32
	.sect "xc_program"
_div32:   
	MOVL XAR2,P      	;将分子暂存在XAR2中
	MPY P,T,#0       	;将分子扩展至64位，P=0为分子的低位
	TBIT @AH,#15
	SBF flag_div0,NTC	;TC=分子标志位
	NEG64 ACC:P
flag_div0:
	MOVL @XAR3,P         ;Temp保存分子低位到XAR3
	MOVL P,@ACC
	MOVL ACC,@XAR2
	ABSTC ACC
	MOVL XT,@ACC
	MOVB ACC,#0
	RPT #31
	||SUBCUL ACC,@XT  
	MOVL @XAR4,P         ;保存高位商到XAR4
	MOVL P,@XAR3         ;用低位分子装载P
	RPT #31
	||SUBCUL ACC,@XT
	MOVL ACC,@XAR4       ;保存XAR4的高位商到ACC
	SBF flag_div1,NTC
	NEG64 ACC:P

flag_div1:
	LRET

	.end
