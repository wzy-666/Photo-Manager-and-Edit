#ifndef HEAD.H
#define HEAD.H

#include <bios.h> 	   /**bioskey()����ͷ�ļ�**/
#include <stdio.h>     /**�ļ���������ͷ�ļ�**/
#include <conio.h>     /**getch()����ͷ�ļ�**/
#include <stdlib.h>	   /**rand()��exit()�Ⱥ���ͷ�ļ�**/
#include <string.h>    /**�ַ���������ͷ�ļ�**/
#include <dos.h>       /**int86()�ȹ����жϵ�ͷ�ļ�**/
#include <math.h>      /**��ѧ������ͷ�ļ�**/

#define SCR_WIDTH 800
#define SCR_HEIGHT 600

#define BMP_WIDTH_MAX 780
#define BMP_WIDTH_MIN 30
#define BMP_HEIGTH_MAX 470
#define BMP_HEIGTH_MIN 30

#define ESC 0x011b
#define Tab 0x0f09
#define Enter 0x1c0d
#define Delete 0x530D
#define Backspace 0x0e08

#define White 0xffffff
#define Gray 0xa9b6c2
#define Silvery 0xe4e8eb	//��ɫ
#define Blue 0x728fa8

#define ThemeColor1 Blue
#define ThemeColor2 Gray

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

typedef unsigned int UINT16;
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned int WORD;

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

typedef struct {
	unsigned char b;
	unsigned char g;
	unsigned char r;
} BGR;

typedef struct {
	int h;
	double s;
	double l;
} HSL;


typedef struct {
	int flag;						//�ļ�״̬
	char name[18];					//�ļ�����
	double scale;					//ͼ�����
	int x1, y1;						//ͼ������
	unsigned int width, heigth;		//ͼ�񳤿�
	unsigned int nWidth, nHeigth;		//ͼ�񳤿�
} FILEATTR;

//�˵�״̬����
typedef struct {
	u8 size;		//���ʴ�С
	u8 size2;		//ͼ�δ�С
	u8 patton;		//�Ŵ�ģʽ	1˫�����ڲ巨 0�ٽ����ֵ��
	u32 color;		//��ɫ
} MENUSTATE;

//BMPͼ������
typedef struct {
	int flag;						//ͼ��״̬
	int save;						//����״̬
	char name[18];					//ͼ������
	double scale;					//ͼ�����
	int x1, y1, x2, y2;				//ͼ������
	unsigned int width, heigth;		//��ǰ����
	unsigned int oWidth, oHeigth;	//ԭʼ����
	int contrast;					//�Աȶ�ѽ
	double saturation, lightness;	//��������
} BMPATTR;


#endif