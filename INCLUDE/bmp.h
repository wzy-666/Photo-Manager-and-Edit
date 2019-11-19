#ifndef BMP_H
#define BMP_H

#include "head.h"
#include "svga.h"

typedef struct tagBITMAPFILEHEADER
{
	UINT16 bfType;
	DWORD bfSize;
	UINT16 bfReserved1;
	UINT16 bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER;

int BmpPut(int x, int y, char* path);						//��ͼƬ
int BmpSave(int x1, int y1, int x2, int y2, char* path);	//�ļ�����
int BmpInfo(BMPATTR* bmpattr, char* filename);				//��ȡ���ж��ļ���Ϣ��
int BmpName(char* filename);								//��鲢��ȫ�ļ���չ������׺.bmp��
int DataSave(BMPATTR* bmpattr,const char* path);					//���ݴ���

#endif