// 花指令.cpp : 
//

#include"stddfx.h"
#include <iostream>
#include<windows.h>

void great(LPCWSTR flag, LPCWSTR number) {
	_FLOWER_XX1
	_FLOWER_XX4
	MessageBox(NULL, flag, number, MB_OK);
	_FLOWER_XX3
}

int main()
{
	_FLOWER_XX0
	char keybuf[20];
	_FLOWER_XX2
	char realkey[9] = "hl2017";	
	_FLOWER_XX1
	char info1[11] = "input key:";
	printf(info1);
	scanf("%s",keybuf);	
	if (strcmp(keybuf,realkey)==0) {
		_FLOWER_XX1
		LPCWSTR flag = TEXT("flag{78asdcw452445sad23}");		
		_FLOWER_XX2
		LPCWSTR number = TEXT("20171120178");
		_FLOWER_XX3
		great(flag, number);
	}
	else {
		_FLOWER_XX2
		_FLOWER_XX3
		return 0;
		_FLOWER_XX3
	}
}
