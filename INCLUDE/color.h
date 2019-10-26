#ifndef COLOR_H
#define COLOR_H

#include "head.h"
#include "svga.h"
#include "mouse.h"

#include "bmp.h"	//������
#include "text.h"	//�ı���
//#include "box.h"	//���ڿ�

void DrawColorBox(void);

int SelectColor(u32* color);							//ѡɫ����

int FreshColor(u32 color, HSL* nowhsl);					//��ʼ��Ϣ
int RefreshColor(HSL hsl, u32* nowcolor);				//ˢ����Ϣ

RGB* U32TRGB(RGB* rgb, u32 color);						//U32 to RGB
u32 RGB2U32(u8 r, u8 g, u8 b);							//RGB to U32
int HSL2RGB(RGB* rgb, HSL hsl);							//HSL to RGB
int RGB2HSL(RGB rgb, HSL*hsl);							//RGB to HSL
double ToRGB(double p, double q, double tC);			//HSL2RGB���Ӽ�����

int PickColor(u32* color);						//ʰɫ��

#endif


