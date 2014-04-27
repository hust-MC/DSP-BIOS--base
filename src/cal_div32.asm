;***********************************************************************; 
;* File Name     : div32.asm                                           *;
;*              ACC=Num32(Qx),P=Den32(Qy)                              *;
;*             ACC:P=Num32/Den32 in(32+Qx-Qy)format                    *;
;*            �з�����32λ����32λ�����64λ                           *;
;***********************************************************************;
	.def _div32
	.sect "xc_program"
_div32:   
	MOVL XAR2,P      	;�������ݴ���XAR2��
	MPY P,T,#0       	;��������չ��64λ��P=0Ϊ���ӵĵ�λ
	TBIT @AH,#15
	SBF flag_div0,NTC	;TC=���ӱ�־λ
	NEG64 ACC:P
flag_div0:
	MOVL @XAR3,P         ;Temp������ӵ�λ��XAR3
	MOVL P,@ACC
	MOVL ACC,@XAR2
	ABSTC ACC
	MOVL XT,@ACC
	MOVB ACC,#0
	RPT #31
	||SUBCUL ACC,@XT  
	MOVL @XAR4,P         ;�����λ�̵�XAR4
	MOVL P,@XAR3         ;�õ�λ����װ��P
	RPT #31
	||SUBCUL ACC,@XT
	MOVL ACC,@XAR4       ;����XAR4�ĸ�λ�̵�ACC
	SBF flag_div1,NTC
	NEG64 ACC:P

flag_div1:
	LRET

	.end
