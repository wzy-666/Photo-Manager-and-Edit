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


//BMPͼ������
typedef struct {
	int flag;						//ͼ��״̬
	char name[18];					//ͼ������
	double scale;					//ͼ�����
	int x1, y1, x2, y2;				//ͼ������
	unsigned int width, heigth;		//ͼ�񳤿�
	unsigned int oWidth, oHeigth;
} BMPATTR; 

int BmpPut(int x, int y, char* path);						//��ͼƬ
int BmpSave(int x1, int y1, int x2, int y2, char* path);	//�ļ�����
int BmpInfo(BMPATTR* bmpattr, char* filename);				//��ȡ���ж��ļ���Ϣ��
int BmpName(char* filename);								//��鲢��ȫ�ļ���չ������׺.bmp��

#endif