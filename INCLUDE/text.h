#ifndef TEXT_H
#define TEXT_H

#include "head.h"
#include "svga.h"


int TextASC24(int x, int y, int part, u32 color, unsigned char* str);	//����24λ
int TextASC16(int x, int y, int part, u32 color, unsigned char* str);	//����16λ
int TextASC12(int x, int y, int part, u32 color, unsigned char* str);	//����24λ
int TextGB16(int x, int y, int part, u32 color, unsigned char* str);	//����16λ ֧��Ӣ�ĺͺ���
int TextGB32(int x, int y, int part, u32 color, unsigned char* str);	//����32λ ֻ֧�ֺ���
int TextGB64(int x, int y, int part, u32 color, unsigned char* str, int delayus);	//̶��64λ ֻ֧�ֺ���
int TextASC64(int x, int y, int part, u32 color, unsigned char* str, int delayus);	//�۱�64λ
int TextASC128(int x, int y, int part, u32 color, unsigned char* str, int delayus); //�۱�128λ

#endif
