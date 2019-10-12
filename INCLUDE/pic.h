#ifndef PIC_H
#define PIC_H

#include "svga.h"
#include "head.h"
#include "bmp.h"

int ImgRectangle(int x1, int y1, int x2, int y2, u32 color, u8 size);	//������
int ImgLine(BMPATTR bmpattr, int x1, int y1, int x2, int y2, u32 color, u8 size); //��ֱ��
int Line(int x1, int y1, int x2, int y2, u32 color, u8 size);//��ֱ�ߣ����棩
int ImgTriangle(BMPATTR bmpattr, int x1, int y1, int x2, int y2, int x3, int y3, u32 color, u8 size); //��������
int Triangle(int x1, int y1, int x2, int y2, int x3, int y3, u32 color, u8 size);//�������Σ����棩
int ImgCircle(BMPATTR bmpattr, int x, int y, int r, u32 color, u8 size); //��Բ
int Circle(int x, int y, int r, u32 color, u8 size);//��Բ�����棩
void DrawImgCircle_8(BMPATTR bmpattr, int x, int y, int a, int b, u32 color, u8 size); //Բ�İ˶Գ���
void DrawCircle_8(int x, int y, int a, int b, u32 color, u8 size);//Բ�İ˶Գ��ԣ����棩
int ImgDrawPixel(BMPATTR bmpattr, int x, int y, u32 color, u8 size);	//����
int DrawPixel(int x, int y, u32 color, u8 size);					//���㣨���棩

#endif