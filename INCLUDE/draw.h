#ifndef DRAW_H
#define DRAW_H

#include "head.h"
#include "svga.h"
#include "mouse.h"	

#include "image.h"
#include "bmp.h"	//ͼ�������
#include "pic.h"	//ͼ�ο�
#include "box.h"	//���ڿ�
#include "color.h"	//ɫ�ʿ�



int SelectSize(u8* size1, u8* size2);								//ѡ����ƹ��

int DrawPen(BMPATTR* bmpattr, MENUSTATE* state);						//����
int DrawPicture(BMPATTR* bmpattr, MENUSTATE* state);					//��ͼ
int DrawLine(BMPATTR* bmpattr, MENUSTATE* state);					//���û��ߺ���
int DrawTriangle(BMPATTR* bmpattr, MENUSTATE* state);				//���û������κ���
int DrawRectangle(BMPATTR* bmpatttr, MENUSTATE* state);				//���û����κ���
int DrawCircle(BMPATTR* bmpattr, MENUSTATE* state);					//���û�Բ����




#endif