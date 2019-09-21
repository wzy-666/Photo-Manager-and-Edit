#ifndef DRAW_H
#define DRAW_H

#include "head.h"
#include "svga.h"
#include "menu.h"
#include "bmp.h"
#include "mouse.h"

void DrawSizeBox();

int SelectSize(u8* size1, u8* size2);								//ѡ����ƹ��

int Rectangle(int x1, int y1, int x2, int y2, u32 color, u8 size);	//������
int DrawPen(BMPATTR bmpattr, MENUSTATE* state);						//����
int DrawPixel(BMPATTR bmpattr, int x, int y, u32 color, u8 size);	//����



#endif