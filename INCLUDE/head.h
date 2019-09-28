#ifndef HEAD.H
#define HEAD.H

#include <bios.h> 	   /**bioskey()函数头文件**/
#include <stdio.h>     /**文件操作函数头文件**/
#include <conio.h>     /**getch()函数头文件**/
#include <stdlib.h>	   /**rand()、exit()等函数头文件**/
#include <string.h>    /**字符串处理函数头文件**/
#include <dos.h>       /**int86()等关于中断的头文件**/
#include <math.h>      /**数学函数的头文件**/

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
#define Silvery 0xe4e8eb	//银色

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
	int flag;						//文件状态
	char name[18];					//文件名称
	double scale;					//图像放缩
	int x1, y1;						//图像坐标
	unsigned int width, heigth;		//图像长宽
	unsigned int nWidth, nHeigth;		//图像长宽
} FILEATTR;

//菜单状态变量
typedef struct {
	u8 size;		//画笔大小
	u8 size2;		//图形大小
	u8 patton;		//放大模式	1双线性内插法 0临近点插值法
	u32 color;		//颜色
} MENUSTATE;


#endif