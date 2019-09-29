#ifndef IMAGE_H
#define IMAGE_H

#include "head.h"
#include "svga.h"
#include "mouse.h"

#include "bmp.h"	//������
#include "pic.h"	//ͼ�ο�
#include "box.h"	//���ڿ�
#include "color.h"	//ɫ�ʿ�


//ͼ�����
int ImageZoom(BMPATTR* bmpattr, double times, u8 patton);
int ImageXY(int* position, int boundary, int origin);
u32 ImageRGB(int x1, int x2, int y1, int y2, double x, double y, u8 patton);

//ͼ���ļ�����
int ImageFileZoom(FILEATTR fileattr);
u32 ImageFileRGB(FILE* fp, int x1, int x2, int y1, int y2, double x, double y, u32 linebytes, u16 h);

int ImageTailor(BMPATTR *bmpattr);	//ͼ��ü�
int ImageRot(BMPATTR* bmpattr);		//ͼ����ת
int ImageMirror(BMPATTR bmpattr);	//ͼ����

int ImageContrast(BMPATTR bmpattr, int value);	//ͼ��Աȶ�
u8 ContrastCalc(u8 color, int value);			//ͼ��Աȶȼ���
int ImageSaturation(BMPATTR bmpattr, int value);//ͼ�񱥺Ͷ�
int ImageLightness(BMPATTR bmpattr,int value);	//ͼ������
//int ImageAdjustment(BMPATTR* bmpattr);//ͼ�����


int ImageZoomSet(u8* patton);		//ģʽѡ��


#endif
