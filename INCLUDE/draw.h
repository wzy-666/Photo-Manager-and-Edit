#ifndef DRAW_H
#define DRAW_H

#include "head.h"
#include "svga.h"
#include "mouse.h"	

#include "bmp.h"	//ͼ�������
#include "pic.h"	//ͼ�ο�
#include "box.h"	//���ڿ�
#include "color.h"	//ɫ�ʿ�



int SelectSize(u8* size1, u8* size2);								//ѡ����ƹ��

int DrawPen(BMPATTR bmpattr, MENUSTATE* state);						//����
int DrawPixel(BMPATTR bmpattr, int x, int y, u32 color, u8 size);	//����



#endif