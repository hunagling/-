#define _WJQ_USED_FLOWER //开关控制编译器是否使用花指令,注销此行，花指令无效	
#ifndef _WJQ_USED_FLOWER
#define _FLOWER_XX0  _asm nop
#define _FLOWER_XX1  _asm nop
#define _FLOWER_XX2  _asm nop
#define _FLOWER_XX3  _asm nop
#define _FLOWER_XX4  _asm nop
#else
#define _FLOWER_XX0  \
{\
	_asm jz  $ + 0xd  	/*本指令6 bytes len*/ \
	_asm jnz $ + 7 		/*本指令6 bytes len*/ \
	_asm _emit 0xe8 	/*本指令1 bytes len*/ \
}


#define _FLOWER_XX1 \
	{\
    _asm jmp $+6 /*本指令5 bytes len*/\
    _asm _emit 0xe9 \
    _asm push eax \
    _asm pop  eax \
	}

#define _FLOWER_XX2 \
   {\
   _asm mov eax, 1h \
   _asm xor eax,eax \
   _asm test eax, eax \
   _asm jz  $ + 0xd\
   _asm jnz $ +0x1000\
   _asm _emit  0xeb   \
   }
//插入字符串的花指令：“Y are cxk？”最后加0xe8进行call指令的混洗
#define _FLOWER_XX3 \
	{\
    _asm jmp $+18 /*本指令5 bytes len*/\
    _asm _emit 0x00 \
    _asm _emit 0x59 \
    _asm _emit 0x20 \
    _asm _emit 0x61 \
    _asm _emit 0x72 \
    _asm _emit 0x65 \
    _asm _emit 0x20 \
    _asm _emit 0x63 \
    _asm _emit 0x78 \
    _asm _emit 0x6b \
    _asm _emit 0x3f \
    _asm _emit 0x00 \
    _asm _emit 0xe8 \
	}
#define _FLOWER_XX4 \
	{\
    _asm jmp $+19 /*本指令5 bytes len*/\
    _asm _emit 0xe9 \
    _asm pop  eax \
    _asm push eax \
    _asm call $+20 \
    _asm jmp $+12\
    _asm _emit 0xe8\
	}



#endif
