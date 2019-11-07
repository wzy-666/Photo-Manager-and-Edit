#include "color.h"

/**
 *  @ brief		RGB2HSL
 *
 *  @ param		rgb		RGBɫ�ʿռ�
 *				hsl		HSLɫ�ʿռ�
 *
 *	@ note		��RGBɫ�ʿռ�ת��ΪHSLɫ�ʿռ�
 *
 *	@ return	��������	1
 *				���󷵻�	0
 **/

int RGB2HSL(RGB rgb, HSL* hsl)
{
	double rr, gg, bb;
	double Max, Min;
	int* h = &hsl->h;
	double* s = &hsl->s;
	double* l = &hsl->l;

	rr = (double)rgb.r / 255.0;
	gg = (double)rgb.g / 255.0;
	bb = (double)rgb.b / 255.0;

	Max = rr;
	if (Max < gg)
	{
		Max = gg;
	}
	if (Max < bb)
	{
		Max = bb;
	}

	Min = rr;
	if (Min > gg)
	{
		Min = gg;
	}
	if (Min > bb)
	{
		Min = bb;
	}

	//��������
	*l = (Max + Min) / 2.0;

	//����ɫ��
	if (Max == Min)
	{
		*h = 0;

	}
	else if (Max == rr && gg >= bb)
	{
		*h = 60 * (gg - bb) / (Max - Min) + 0;
	}
	else if (Max == rr && gg < bb)
	{
		*h = 60 * (gg - bb) / (Max - Min) + 360;
	}
	else if (Max == gg)
	{
		*h = 60 * (bb - rr) / (Max - Min) + 120;
	}
	else if (Max == bb)
	{
		*h = 60 * (rr - gg) / (Max - Min) + 240;
	}
	else
	{
		return 0;
	}


	//���㱥�Ͷ�
	if (*l == 0 || Max == Min)
	{
		*s = 0;
	}
	else if (*l > 0 && *l <= 0.5)
	{
		*s = (Max - Min) / (Max + Min);
	}
	else if (*l > 0.5)
	{
		*s = (Max - Min) / (2 - (Max + Min));
	}
	else
	{
		return 0;
	}

	return 1;
}

/**
 *  @ brief		HSL2RGB
 *
 *  @ param		rgb		RGBɫ�ʿռ�
 *				hsl		HSLɫ�ʿռ�
 *
 *	@ note		��HSLɫ�ʿռ�ת��ΪRGBɫ�ʿռ�
 *
 *	@ return	��������	1
 *				���󷵻�	0
 **/

int HSL2RGB(RGB* rgb, HSL hsl)
{
	double tR, tG, tB;
	double p, q;
	double hk;
	u8* r = &rgb->r;
	u8* g = &rgb->g;
	u8* b = &rgb->b;

	if (hsl.s == 0)
	{
		tR = hsl.l;
		tG = hsl.l;
		tB = hsl.l;
	}
	else
	{
		if (hsl.l < 0.5)
		{
			q = hsl.l * (1.0 + hsl.s);
		}
		else
		{
			q = hsl.l + hsl.s - (hsl.l * hsl.s);
		}
		p = 2.0 * hsl.l - q;
		hk = (double)hsl.h / 360.0;
		tR = hk + 1.0 / 3.0;
		tG = hk + 0;
		tB = hk - 1.0 / 3.0;
		tR = ToRGB(p, q, tR);
		tG = ToRGB(p, q, tG);
		tB = ToRGB(p, q, tB);
	}
	*r = (int)(tR * 255.0 + 0.5);
	*g = (int)(tG * 255.0 + 0.5);
	*b = (int)(tB * 255.0 + 0.5);
	return 1;
}

/**
 *  @ brief		ToRGB
 *
 *  @ param		p��q	HSL2RGB�е���ʱ����
 *				tC		��ɫ����
 *
 *	@ note		����HSLɫ�ʿռ��ת��
 *
 *	@ return	ɫ�ʷ���
 **/

double ToRGB(double p, double q, double tC)
{
	double ColorC;
	if (tC < 0)
	{
		tC = tC + 1.0;
	}
	else if (tC > 1)
	{
		tC = tC - 1.0;
	}
	else
	{
		;
	}
	if (tC < (1.0 / 6.0))
	{
		ColorC = p + ((q - p) * 6 * tC);
	}
	else if (tC >= (1.0 / 6.0) && tC < 0.5)
	{
		ColorC = q;
	}
	else if (tC >= 0.5 && tC < (2.0 / 3.0))
	{
		ColorC = p + ((q - p) * 6 * (2.0 / 3.0 - tC));
	}
	else
	{
		ColorC = p;
	}

	return ColorC;
}

/**
 *  @ brief		RGB2U32
 *
 *  @ param		r��g��b		RGB��ɫ����
 *
 *	@ note		��RGBɫ�ʿռ�ת��Ϊunsigned long��ʽ
 *
 *	@ return	unsigned long��ʽ��RGB����
 **/

u32 RGB2U32(u8 r,u8 g,u8 b)
{
	return ((u32)r << 16) | ((u32)g << 8) | (u32)b;
}

/**
 *  @ brief		U32TRGB
 *
 *  @ param		rgb		RGBɫ�ʿռ�
 *				color	unsigned long��ʽ��RGB����
 *
 *	@ note		��unsigned long��ʽ��RGB����ת��ΪRGBɫ�ʿռ����
 *
 *	@ return	RGBɫ�ʿռ����
 **/

RGB* U32TRGB(RGB* rgb, u32 color)
{
	rgb->r = (color & 0xff0000) >> 16;
	rgb->g = (color & 0x00ff00) >> 8;
	rgb->b = (color & 0x0000ff);
	return rgb;
}

/**
 *  @ brief		RefreshColor
 *
 *  @ param		hsl			HSLɫ�ʿռ�
 *				nowcolor	��ǰ��ɫ
 *
 *	@ note		ˢ�µ�ǰ��ɫ��Ϣ
 *
 *	@ return	1
 **/

int RefreshColor(HSL hsl, u32* nowcolor)
{
	int i,j;
	RGB tRGB;
	char colorinfo[3][8];
	HSL2RGB(&tRGB, hsl);
	sprintf(colorinfo[0], "R%d", tRGB.r);
	sprintf(colorinfo[1], "G%d", tRGB.g);
	sprintf(colorinfo[2], "B%d", tRGB.b);
	*nowcolor = RGB2U32(tRGB.r, tRGB.g, tRGB.b);
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 36; j++)
		{
			hsl.l = (double)i / 100.0;
			HSL2RGB(&tRGB, hsl);
			PutPixel(455 + j, 245 + i, RGB2U32(tRGB.r, tRGB.g, tRGB.b));
		}
	}
	Bar(505, 295, 540, 315, *nowcolor);
	Bar(505, 245, 540, 285, 0xdeebf3);
	TextASC12(507, 245, 8, 0, colorinfo[0]);
	TextASC12(507, 257, 8, 0, colorinfo[1]);
	TextASC12(507, 269, 8, 0, colorinfo[2]);
	return 1;
}

/**
 *  @ brief		FreshColor
 *
 *  @ param		nowhsl	��ǰHSLɫ�ʿռ�
 *				color	��ǰ��ɫ
 *
 *	@ note		��ʼ����ɫ��Ϣ
 *
 *	@ return	1
 **/

int FreshColor(u32 color, HSL* nowhsl)
{
	int i, j;
	RGB tRGB;
	HSL tHSL;
	char colorinfo[3][8];
	U32TRGB(&tRGB, color);
	RGB2HSL(tRGB, nowhsl);
	sprintf(colorinfo[0], "R%d", tRGB.r);
	sprintf(colorinfo[1], "G%d", tRGB.g);
	sprintf(colorinfo[2], "B%d", tRGB.b);
	RGB2HSL(tRGB, &tHSL);
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 36; j++)
		{
			tHSL.l = (double)i / 100.0;
			HSL2RGB(&tRGB, tHSL);
			PutPixel(455 + j, 245 + i, RGB2U32(tRGB.r, tRGB.g, tRGB.b));
		}
	}
	Bar(505, 295, 540, 315, color);
	Bar(505, 245, 540, 285, 0xdeebf3);
	TextASC12(507, 245, 8, 0, colorinfo[0]);
	TextASC12(507, 257, 8, 0, colorinfo[1]);
	TextASC12(507, 269, 8, 0, colorinfo[2]);
	return 1;
}

/**
 *  @ brief		DrawColorBox
 *
 *  @ param		
 *
 *	@ note		����ѡɫ������
 *
 *	@ return	
 **/

void DrawColorBox()
{
	int i, j;
	RGB tRGB;
	HSL hsl = { 0,0.0,0.5 };
	BmpPut(248, 198, "UI//COLOR");
	for (i = 0; i < 180; i++)
	{
		hsl.h = i * 2;
		for (j = 0; j < 100; j++)
		{	
			hsl.s = (double)j / 100.0;
			HSL2RGB(&tRGB, hsl);
			PutPixel(260 + i, 245 + j, RGB2U32(tRGB.r, tRGB.g, tRGB.b));
		}
	}
}

/**
 *  @ brief		SelectColor
 *
 *  @ param		color	��ǰ��ɫֵ
 *
 *	@ note		ѡɫ��������
 *
 *	@ return	0
 **/

int SelectColor(u32* color)
{
	HSL nowhsl = { 0,0,0 };
	u32 nowcolor = *color;
	MOUSE mouse_old, mouse_new;

	BmpSave(248, 198, 552, 352, "DATA//BK4");
	DrawColorBox();
	FreshColor(*color, &nowhsl);

	MouseStatus(&mouse_old);
	MouseStoreBk(mouse_old.x, mouse_old.y);
	while (1)
	{
		MouseStatus(&mouse_new);
		if (mouse_new.x == mouse_old.x && mouse_new.y == mouse_old.y && mouse_old.button == mouse_new.button)
		{
			;
		}
		else
		{
			MousePutBk(mouse_old.x, mouse_old.y);
			MouseStoreBk(mouse_new.x, mouse_new.y);
			MouseDraw(mouse_new);
			mouse_old = mouse_new;
			if (MouseDown(260, 245, 440, 345))
			{
				//ɫ��(ɫ���뱥�Ͷ�)
				nowhsl.h = (mouse_old.x - 260) * 2;
				nowhsl.s = (double)(mouse_old.y - 245)/100.0;
				nowhsl.l = 0.5;
				RefreshColor(nowhsl, &nowcolor);
			}
			else if (MouseDown(455, 245, 490, 345))
			{
				//����
				nowhsl.l = (double)(mouse_old.y - 245) / 100.0;
				RefreshColor(nowhsl, &nowcolor);
				MouseDraw(mouse_new);
			}
			else if (MouseDown(505, 325, 540, 345))
			{
				//ȷ��
				*color = nowcolor;
				MousePutBk(mouse_old.x, mouse_old.y);
				BmpPut(248, 198, "DATA//BK4");
				return 0;
			}
			else if (MouseDown(500, 200, 550, 240))
			{
				//�ر�
				MousePutBk(mouse_old.x, mouse_old.y);
				BmpPut(248, 198, "DATA//BK4");
				return 0;
			}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				exit(0);
			}
			else
			{
				;
			}
		}
	}

}

/**
*  ������      PickColor
*  �������    color      ��ǰ��ɫֵ
*  ����        ʰɫ��
*  ����ֵ      0          �˳�ʰɫ��
			   20         �л�Ϊ�򿪹���
			   30         �л�Ϊ���湦��
			   40         �л�Ϊ�½�����
			   45         �л�Ϊͼ�⹦��
			   50         �л�Ϊ���ʹ���
			   60         �л�Ϊ�ü�����
			   65         �л�Ϊͼ�ι���
			   70         �л�Ϊ��������
			   75         �л�Ϊ��ϸ����
			   80         �л�Ϊѡɫ����
			   85         �л�Ϊ���ù���
			   90         �л�Ϊ��С����
			   95         �л�Ϊ�Ŵ���
			   100        �л�Ϊ��ת����
			   105        �л�Ϊ��ת����
			   120        �л�Ϊ�˾�����
**/

int PickColor(u32* color, int flag)
{
	int x, y;						//��ʰȡ��ɫ����x,y����
	RGB tRGB;						//RGB��ʱ������������ʾ��ǰ��ɫ��RGBֵ
	char colorstring[20];			//���ڴ����ʾ��Ϣ���ַ�����
	MOUSE mouse_old, mouse_new;		//���������������

	U32TRGB(&tRGB, *color);                                            //��ȡ��ǰ��ɫ��RGBֵ
	sprintf(colorstring, "R:%d G:%d B:%d", tRGB.r, tRGB.g, tRGB.b);    //���ַ���������ʾ��Ϣ
	TextGB16(200, 580, 14, 0, "��ǰ��ɫΪ��");
	Bar(300, 580, 320, 590, *color);                                   //��ʾ��ǰ��ɫ
	TextASC16(400, 580, 14, 0, colorstring);                           //�����ǰ��ɫ��RGBֵ

	MouseStatus(&mouse_old);                   //��ȡ�����״̬
	MouseStoreBk(mouse_old.x, mouse_old.y);    //��¼�����ı���ͼ��
	MouseDraw(mouse_old);                      //�������

	/*�ƶ���ִ꣬��ʰɫ������*/
	while (1)
	{
		MouseStatus(&mouse_new);              //��ȡ�����״̬

		/*������״̬δ�ı䣬��ִ���κβ���*/
		if (mouse_new.x == mouse_old.x && mouse_new.y == mouse_old.y && mouse_new.button == mouse_old.button)
		{
			;
		}
		else
		{
			MousePutBk(mouse_old.x, mouse_old.y);      //��ȥ�����
			MouseStoreBk(mouse_new.x, mouse_new.y);    //��¼�����ı���ͼ��
			MouseDraw(mouse_new);                      //�������

			if (mouse_new.button == mouse_old.button)  //��������״̬δ�ı䣬��ִ��ʰɫ������
			{
				mouse_old = mouse_new;
				continue;
			}

			/*�����л�*/
			if (MouseDown(10, 0, 70, 50))
			{
				//��
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 20;
			}
			else if (MouseDown(70, 0, 130, 50))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 30;
			}
			else if (MouseDown(130, 0, 190, 50))
			{
				//�½�
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 40;
			}
			else if (MouseDown(190, 0, 250, 50))
			{
				//ͼ��
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 45;
			}
			else if (MouseDown(10, 50, 70, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 50;
			}
			else if (MouseDown(70, 50, 130, 100))
			{
				//�ü�
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 60;
			}
			else if (MouseDown(130, 50, 190, 100))
			{
				//ͼ��
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 65;
			}
			else if (MouseDown(650, 50, 700, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 70;
			}
			else if (MouseDown(700, 50, 750, 100))
			{
				//��ϸ
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 75;
			}
			else if (MouseDown(750, 50, 800, 100))
			{
				//��ɫ
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 80;
			}
			else if (MouseDown(703, 570, 735, 600))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 85;
			}
			else if (MouseDown(735, 570, 767, 600))
			{
				//��С
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 90;
			}
			else if (MouseDown(767, 570, 800, 600))
			{
				//�Ŵ�
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 95;
			}
			else if (MouseDown(0, 570, 42, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 100;
			}
			else if (MouseDown(42, 570, 84, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 105;
			}
			else if (MouseDown(84, 570, 126, 600))
			{
				//�ٴε�����˳�ʰɫ��
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 0;
			}
			else if (MouseDown(700, 0, 750, 50))
			{
				//�˾�
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 120;
			}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				exit(0);
			}
			else if (MouseDown(190, 50, 250, 100) && flag == 1)
			{
				//ֱ��
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 125;
			}
			else if (MouseDown(250, 50, 300, 100) && flag == 1)
			{
				//������
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 130;
			}
			else if (MouseDown(300, 50, 380, 100) && flag == 1)
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 135;
			}
			else if (MouseDown(380, 50, 450, 100) && flag == 1)
			{
				//Բ
				MousePutBk(mouse_new.x, mouse_new.y);
				Bar(200, 570 + 1, 700, 600, Gray);
				return 140;
			}
			else if (MouseDown(1, 1, 800, 600))    //����Ļ�ڵ��������ʰɫ������
			{
				x = mouse_new.x - 1;        //ʰȡ������ϽǴ�����ɫ
				y = mouse_new.y - 1;
				*color = GetPixel(x, y);    //��ȡ�ô���ɫ���������޸�Ϊ��ǰ��ɫ

				/*��ʾ��ǰ��ɫ��Ϣ*/
				U32TRGB(&tRGB, *color);
				Bar(200, 570 + 1, 700, 600, Gray);
				sprintf(colorstring, "R:%d G:%d B:%d", tRGB.r, tRGB.g, tRGB.b);
				TextGB16(200, 580, 14, 0, "��ǰ��ɫΪ��");
				Bar(300, 580, 320, 590, *color);
				TextASC16(400, 580, 14, 0, colorstring);
			}
			else
			{
				;
			}

			mouse_old = mouse_new;    //�������
		}
	}
}