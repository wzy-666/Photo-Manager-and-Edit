#ifndef MENU_H
#define MENU_H

#include "head.h"
#include "svga.h"
#include "mouse.h"
#include "bmp.h"
#include "file.h"
#include "image.h"

//�˵�״̬����
typedef struct {
	u8 size;		//���ʴ�С
	u8 size2;		//ͼ�δ�С
	u8 patton;		//�Ŵ�ģʽ	1˫�����ڲ巨 0�ٽ����ֵ��
	u32 color;		//��ɫ
} MENUSTATE;



void DrawMenu();
void MenuManager();

#endif
