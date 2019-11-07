#include "draw.h"

/**
*  ������      DrawPen
*  �������    bmpattr    ͼƬ
			   state      �˵�״̬
*  ��������    ����
*  ����ֵ      0          ͼƬδ��
			   1          �˳����ʺ���
			   20         �л�Ϊ�򿪹���
			   30         �л�Ϊ���湦��
			   40         �л�Ϊ�½�����
			   45         �л�Ϊͼ�⹦��
			   60         �л�Ϊ�ü�����
			   65         �л�Ϊ��ͼ�ι���
			   70         �л�Ϊ��������
			   85         �л�Ϊ���ù���
			   90         �л�Ϊ��С����
			   95         �л�Ϊ�Ŵ���
			   100        �л�Ϊ��ת����
			   105        �л�Ϊ��ת����
			   120        �л�Ϊ�˾�����
**/
int DrawPen(BMPATTR* bmpattr, MENUSTATE* state)
{
	MOUSE mouse_old, mouse_new;    //���������������

	/*��ͼƬδ�򿪣���ʾ������˳�����*/
	if (bmpattr->flag == 0)
	{
		WarnBox("ͼƬδ��");
		return 0;
	}

	ImgRectangle(12, 52, 68, 98, 0xff0000, 2);    //������ͼ�����Ϻ���������������ڻ���״̬
	MouseStatus(&mouse_old);                      //��ȡ�����״̬
	MouseStoreBk(mouse_old.x, mouse_old.y);       //��¼�����ı���ͼ��
	MouseDraw(mouse_old);                         //�������

	/*�ƶ���ִ꣬�л��ʹ���*/
	while (1)
	{
		MouseStatus(&mouse_new);    //��ȡ�����״̬

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
			mouse_old = mouse_new;                     //�������

			if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2))                     //�����ͼƬ�ڲ����
			{
				MouseStatus(&mouse_old);                                                       //��¼������״̬
				ImgDrawPixel(*bmpattr, mouse_old.x, mouse_old.y, state->color, state->size);    //�Ե�ǰ��ɫ�ͻ��ʴ�ϸ����괦��һ����
			}

			/*�����л�*/
			else if (MouseDown(10, 0, 70, 50))
			{
				//��
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 20;
			}
			else if (MouseDown(70, 0, 130, 50))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 30;
			}
			else if (MouseDown(130, 0, 190, 50))
			{
				//�½�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 40;
			}
			else if (MouseDown(190, 0, 250, 50))
			{
				//ͼ��
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 45;
			}
			else if (MouseDown(10, 50, 70, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 1;
			}
			else if (MouseDown(70, 50, 130, 100))
			{
				//�ü�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 60;
			}
			else if (MouseDown(130, 50, 190, 100))
			{
				//ͼ��
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 65;
			}
			else if (MouseDown(650, 50, 700, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 70;
			}
			else if (MouseDown(700, 50, 750, 100))
			{
				//��ϸ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectSize(&state->size, &state->size2);
				MouseStatus(&mouse_old);
				MouseStoreBk(mouse_old.x, mouse_old.y);
			}
			else if (MouseDown(750, 50, 800, 100))
			{
				//��ɫ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectColor(&state->color);
				MouseStatus(&mouse_old);
				MouseStoreBk(mouse_old.x, mouse_old.y);
			}
			else if (MouseDown(703, 570, 735, 600))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 85;
			}
			else if (MouseDown(735, 570, 767, 600))
			{
				//��С
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 90;
			}
			else if (MouseDown(767, 570, 800, 600))
			{
				//�Ŵ�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 95;
			}
			else if (MouseDown(0, 570, 42, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 100;
			}
			else if (MouseDown(42, 570, 84, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 105;
			}
			else if (MouseDown(84, 570, 126, 600))
			{
				//ʰɫ��
				MousePutBk(mouse_new.x, mouse_new.y);
				PickColor(&state->color,0);
				MouseStatus(&mouse_old);
				MouseStoreBk(mouse_old.x, mouse_old.y);
			}
			else if (MouseDown(700, 0, 750, 50))
			{
				//�˾�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(12, 52, 68, 98, ThemeColor2, 2);
				return 120;
			}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				exit(0);
			}
		}
	}
}

int SelectSize(u8* size1, u8* size2)
{
	int s1 = *size1, s2 = *size2;
	char c1[2], c2[2];
	MOUSE mouse_old, mouse_new;

	BmpSave(248, 198, 552, 352, "DATA//BK4");
	DrawSizeBox();
	itoa(s1, c1, 10);
	itoa(s2, c2, 10);
	TextASC24(385, 260, 24, 0, c1);
	TextASC24(385, 300, 24, 0, c2);

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
			if (MouseDown(425, 265, 450, 285))
			{
				if (s1 < 8)
				{
					s1++;
					itoa(s1, c1, 10);
					Bar(380, 260, 415, 290, ThemeColor2);
					TextASC24(385, 260, 24, 0, c1);
				}
				else
				{
					;
				}
			}
			else if (MouseDown(455, 265, 480, 285))
			{
				if (s1 > 1)
				{
					s1--;
					itoa(s1, c1, 10);
					Bar(380, 260, 415, 290, ThemeColor2);
					TextASC24(385, 260, 24, 0, c1);
				}
				else
				{
					;
				}
			}
			else if (MouseDown(425, 305, 450, 325))
			{
				if (s2 < 5)
				{
					s2++;
					itoa(s2, c2, 10);
					Bar(380, 300, 415, 330, ThemeColor2);
					TextASC24(385, 300, 24, 0, c2);
				}
				else
				{
					;
				}
			}
			else if (MouseDown(455, 305, 480, 325))
			{
				if (s2 > 1)
				{
					s2--;
					itoa(s2, c2, 10);
					Bar(380, 300, 415, 330, ThemeColor2);
					TextASC24(385, 300, 24, 0, c2);
				}
				else
				{
					;
				}
			}
			else if (MouseDown(490, 265, 535, 285))
			{
				//ȷ��
				*size1 = s1;
				*size2 = s2;
				MousePutBk(mouse_new.x, mouse_new.y);
				BmpPut(248, 198, "DATA//BK4");
				return 0;
			}
			else if (MouseDown(490, 305, 535, 325))
			{
				//ȡ��
				MousePutBk(mouse_new.x, mouse_new.y);
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
*  ������      DrawPicture
*  �������    bmpattr    ͼƬ
			   state      �˵�״̬
*  ����        ��ͼ��
*  ����ֵ      0          ͼƬδ��
			   1          �˳���ͼ�κ���
			   20         �л�Ϊ�򿪹���
			   30         �л�Ϊ���湦��
			   40         �л�Ϊ�½�����
			   45         �л�Ϊͼ�⹦��
			   50         �л�Ϊ���ʹ���
			   60         �л�Ϊ�ü�����
			   70         �л�Ϊ��������
			   85         �л�Ϊ���ù���
			   90         �л�Ϊ��С����
			   95         �л�Ϊ�Ŵ���
			   100        �л�Ϊ��ת����
			   105        �л�Ϊ��ת����
			   120        �л�Ϊ�˾�����
**/
int DrawPicture(BMPATTR* bmpattr, MENUSTATE* state)
{
	int flag = 0;                  //��¼��������ֵ
	MOUSE mouse_old, mouse_new;    //���������������

	/*��ͼƬδ�򿪣���ʾ������˳�����*/
	if (bmpattr->flag == 0)
	{
		WarnBox("ͼƬδ��");
		return	0;
	}

	ImgRectangle(132, 52, 188, 98, 0xff0000, 2);         //������ͼ�����Ϻ���������������ڻ���״̬
	Line(207, 61, 234, 89, 0x000000, 2);                 //��ʾ��ֱ�߹��ܵ�ͼ��
	Triangle(275, 61, 256, 89, 293, 89, 0x000000, 2);    //��ʾ�������ι��ܵ�ͼ��
	ImgRectangle(322, 61, 371, 89, 0x000000, 2);         //��ʾ�����ι��ܵ�ͼ��
	Circle(418, 75, 14, 0x000000, 2);                    //��ʾ��Բ���ܵ�ͼ��

	MouseStatus(&mouse_old);                   //��ȡ�����״̬
	MouseStoreBk(mouse_old.x, mouse_old.y);    //��¼�����ı���ͼ��
	MouseDraw(mouse_old);                      //�������

	/*�ƶ���ִ꣬�л�ͼ�ι���*/
	while (1)
	{
		MouseStatus(&mouse_new);    //��ȡ�����״̬

		/*������״̬δ�ı䣬��ִ���κβ���*/
		if (mouse_new.x == mouse_old.x && mouse_new.y == mouse_old.y && mouse_new.button == mouse_old.button)
		{
			;
		}
		else
		{
			MousePutBk(mouse_old.x, mouse_old.y);          //��ȥ�����
			MouseStoreBk(mouse_new.x, mouse_new.y);        //��¼�����ı���ͼ��
			MouseDraw(mouse_new);                          //�������

			if (mouse_new.button == mouse_old.button)      //��������״̬δ�ı䣬��ִ�л�ͼ�β���
			{
				mouse_old = mouse_new;
				continue;
			}

			if (MouseDown(190, 50, 250, 100) || flag == 125)              //������ֱ��ͼ����ִ�л�ֱ�߲���
			{
				MousePutBk(mouse_new.x, mouse_new.y);      //��ȥ�����
				flag = 125;           //���û�ֱ�ߺ���

				/*if (flag)
				{
					MousePutBk(mouse_new.x, mouse_new.y);
					ImgRectangle(132, 52, 188, 98, Gray, 2);
					switch (flag)
					{
						case 130:
							DrawTriangle(bmpattr, state);
							break;
						case 135:
							DrawRectangle(bmpattr, state);
							break;
						case 140:
							DrawCircle(bmpattr, state);
							break;
						default:
							Bar(192, 52, 518, 98, Gray);
							break;
					}
					return flag;
				}*/
			}
			else if (MouseDown(250, 50, 300, 100) || flag == 130)         //������������ͼ����ִ�л������β���
			{
				MousePutBk(mouse_new.x, mouse_new.y);      //��ȥ�����
				flag = 130;       //���û������κ���
			}
			else if (MouseDown(300, 50, 380, 100) || flag == 135)         //����������ͼ����ִ�л����β���
			{
				MousePutBk(mouse_new.x, mouse_new.y);      //��ȥ�����
				flag = 135;      //���û����κ���
			}
			else if (MouseDown(380, 50, 450, 100) || flag == 140)      //������Բͼ����ִ�л�Բ����
			{
				MousePutBk(mouse_new.x, mouse_new.y);      //��ȥ�����
				flag = 140;         //���û�Բ����
			}

			/*�����л�*/
			else if (MouseDown(10, 0, 70, 50))
			{
				//��
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 20;
			}
			else if (MouseDown(70, 0, 130, 50))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 30;
			}
			else if (MouseDown(130, 0, 190, 50))
			{
				//�½�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 40;
			}
			else if (MouseDown(190, 0, 250, 50))
			{
				//ͼ��
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 45;
			}
			else if (MouseDown(10, 50, 70, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 50;
			}
			else if (MouseDown(70, 50, 130, 100))
			{
				//�ü�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 60;
			}
			else if (MouseDown(130, 50, 190, 100))
			{
				//ͼ��
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 1;
			}
			else if (MouseDown(650, 50, 700, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 70;
			}
			else if (MouseDown(700, 50, 750, 100))
			{
				//��ϸ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectSize(&state->size, &state->size2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(750, 50, 800, 100))
			{
				//��ɫ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectColor(&state->color);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(703, 570, 735, 600))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 85;
			}
			else if (MouseDown(735, 570, 767, 600))
			{
				//��С
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 90;
			}
			else if (MouseDown(767, 570, 800, 600))
			{
				//�Ŵ�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 95;
			}
			else if (MouseDown(0, 570, 42, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 100;
			}
			else if (MouseDown(42, 570, 84, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 105;
			}
			else if (MouseDown(84, 570, 126, 600))
			{
				//ʰɫ��
				MousePutBk(mouse_new.x, mouse_new.y);
				PickColor(&state->color,1);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(700, 0, 750, 50))
			{
				//�˾�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(132, 52, 188, 98, Gray, 2);
				Bar(192, 52, 518, 98, Gray);
				return 120;
			}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				exit(0);
			}

			mouse_old = mouse_new;    //�������
		}
		if (flag)
		{
			switch (flag)
			{
			case 125:
				flag = DrawLine(bmpattr, state);
				MouseStatus(&mouse_new);                   //��ȡ������״̬
				MouseStoreBk(mouse_new.x, mouse_new.y);    //��¼�����ı���ͼ��
				break;
			case 130:
				flag = DrawTriangle(bmpattr, state);
				MouseStatus(&mouse_new);                   //��ȡ������״̬
				MouseStoreBk(mouse_new.x, mouse_new.y);    //��¼�����ı���ͼ��
				break;
			case 135:
				flag = DrawRectangle(bmpattr, state);
				MouseStatus(&mouse_new);                   //��ȡ������״̬
				MouseStoreBk(mouse_new.x, mouse_new.y);    //��¼�����ı���ͼ��
				break;
			case 140:
				flag = DrawCircle(bmpattr, state);
				MouseStatus(&mouse_new);                   //��ȡ������״̬
				MouseStoreBk(mouse_new.x, mouse_new.y);    //��¼�����ı���ͼ��
				break;
			default:
				Bar(192, 52, 518, 98, ThemeColor2);
				break;
			}
		}
	}
}

/**
*  ������      DrawLine
*  �������    bmpattr    ͼƬ
			   state      �˵�״̬
*  ����        ��ֱ��
*  ����ֵ      0          �˳���ֱ�ߺ���
			   20         �л�Ϊ�򿪹���
			   30         �л�Ϊ���湦��
			   40         �л�Ϊ�½�����
			   45         �л�Ϊͼ�⹦��
			   50         �л�Ϊ���ʹ���
			   60         �л�Ϊ�ü�����
			   65         �л�Ϊͼ�ι���
**/
int DrawLine(BMPATTR* bmpattr, MENUSTATE* state)
{
	int x1, y1, x2, y2;            //����ֱ�������˵��x,y����
	int tx1, ty1, tx2, ty2;        //����ֱ�������˵��x,y�������
	int flag = 0;                  //��¼���������ֱ�ߵĵڼ����˵�
	MOUSE mouse_old, mouse_new;    //���������������
	char xystring1[16];            //���ڴ�ŵ�һ���˵����ʾ��Ϣ���ַ�����
	char xystring2[16];            //���ڴ�ŵڶ����˵����ʾ��Ϣ���ַ�����

	/*��ֱ��ͼ�����Ϻ���������������ڻ�ֱ��״̬*/
	ImgRectangle(132, 52, 188, 98, Gray, 2);
	ImgRectangle(192, 52, 248, 98, 0xff0000, 2);
	ImgRectangle(252, 52, 298, 98, Gray, 2);
	ImgRectangle(302, 52, 378, 98, Gray, 2);
	ImgRectangle(382, 52, 448, 98, Gray, 2);

	MouseStatus(&mouse_old);                   //��ȡ�����״̬
	MouseStoreBk(mouse_old.x, mouse_old.y);    //��¼�����ı���ͼ��
	MouseDraw(mouse_old);                      //�������

	/*�ƶ���ִ꣬�л�ֱ�߹���*/
	while (1)
	{
		MouseStatus(&mouse_new);    //��ȡ�����״̬

		/*������״̬δ�ı䣬��ִ���κβ���*/
		if (mouse_new.x == mouse_old.x && mouse_new.y == mouse_old.y && mouse_new.button == mouse_old.button)
		{
			;
		}
		else
		{
			MousePutBk(mouse_old.x, mouse_old.y);        //��ȥ�����
			MouseStoreBk(mouse_new.x, mouse_new.y);      //��¼�����ı���ͼ��
			MouseDraw(mouse_new);                        //�������

			if (mouse_new.button == mouse_old.button)    //��������״̬δ�ı䣬��ִ�л�ֱ�߲���
			{
				mouse_old = mouse_new;
				continue;
			}

			/*������ͼƬ�ڲ�����¼ֱ�ߵĵ�һ���˵�����*/
			if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 0)
			{
				x1 = mouse_new.x;
				y1 = mouse_new.y;
				flag = 1;
				tx1 = x1 - bmpattr->x1;
				ty1 = y1 - bmpattr->y1;

				/*��ʾֱ�ߵ�һ���˵��������Ϣ*/
				Bar(200, 570 + 1, 700, 600, Gray);
				sprintf(xystring1, "����1:%d,%d", tx1, ty1);
				TextGB16(200, 580, 14, 0, xystring1);
			}

			/*������ͼƬ�ڲ�����¼ֱ�ߵĵڶ����˵�����*/
			else if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 1)
			{
				x2 = mouse_new.x;
				y2 = mouse_new.y;
				flag = 0;
				tx2 = x2 - bmpattr->x1;
				ty2 = y2 - bmpattr->y1;

				/*��ʾֱ�ߵڶ����˵��������Ϣ*/
				sprintf(xystring2, "����2:%d,%d", tx2, ty2);
				TextGB16(450, 580, 14, 0, xystring2);

				MousePutBk(mouse_new.x, mouse_new.y);                            //��ȥ�����
				ImgLine(*bmpattr, x1, y1, x2, y2, state->color, state->size2);    //��ͼƬ�ڻ�ֱ��
				MouseStatus(&mouse_new);                                         //��ȡ������״̬
				MouseStoreBk(mouse_new.x, mouse_new.y);                          //��¼�����ı���ͼ��
			}
			else if (MouseDown(190, 50, 250, 100))
			{
				//�ٴε�����˳�����
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(192, 52, 248, 98, Gray, 2);
				ImgRectangle(132, 52, 188, 98, 0xff0000, 2);
				return 0;
			}
			else if (MouseDown(700, 50, 750, 100))
			{
				//��ϸ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectSize(&state->size, &state->size2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(750, 50, 800, 100))
			{
				//��ɫ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectColor(&state->color);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(84, 570, 126, 600))
			{
				//ʰɫ��
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				PickColor(&state->color,1);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			//else if (MouseDown(10, 0, 70, 50))
			//{
			//	//��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(192, 52, 248, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 20;
			//}
			//else if (MouseDown(70, 0, 130, 50))
			//{
			//	//����
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(192, 52, 248, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 30;
			//}
			//else if (MouseDown(130, 0, 190, 50))
			//{
			//	//�½�
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(192, 52, 248, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 40;
			//}
			//else if (MouseDown(190, 0, 250, 50))
			//{
			//	//ͼ��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(192, 52, 248, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 45;
			//}
			//else if (MouseDown(10, 50, 70, 100))
			//{
			//	//����
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(192, 52, 248, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 50;
			//}
			//else if (MouseDown(70, 50, 130, 100))
			//{
			//	//�ü�
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(192, 52, 248, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 60;
			//}
			//else if (MouseDown(130, 50, 190, 100))
			//{
			//	//ͼ��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(192, 52, 248, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 65;
			//}
			else if (MouseDown(250, 50, 300, 100))
			{
				//������
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(192, 52, 248, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 130;
			}
			else if (MouseDown(300, 50, 380, 100))
			{
				//����
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(192, 52, 248, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 135;
			}
			else if (MouseDown(380, 50, 450, 100))
			{
				//Բ
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(192, 52, 248, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 140;
			}
			//else if (MouseDown(650, 50, 700, 100))
			//{
			//	//����
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImageAdjustment(bmpattr);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//}
			//else if (MouseDown(0, 570, 42, 600))
			//{
			//	//��ת
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImageRot(bmpattr);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//}
			//else if (MouseDown(42, 570, 84, 600))
			//{
			//	//��ת
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImageMirror(bmpattr);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//}
			//else if (MouseDown(703, 570, 735, 600))
			//{
			//	//����
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImageZoomSet(&state->patton);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//}
			//else if (MouseDown(735, 570, 767, 600))
			//{
			//	//��С
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImageZoom(bmpattr, 0.8, state->patton);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//}
			//else if (MouseDown(767, 570, 800, 600))
			//{
			//	//�Ŵ�
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImageZoom(bmpattr, 1.25, state->patton);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//}
			//else if (MouseDown(700, 0, 750, 50))
			//{
			//	//�˾�
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	DrawShading(bmpattr);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				Exit(bmpattr);
			}

			mouse_old = mouse_new;    //�������
		}
	}
}

/**
*  ������      DrawTriangle
*  �������    bmpattr    ͼƬ
			   state      �˵�״̬
*  ����        ��������
*  ����ֵ      0          �˳��������κ���
**/
int DrawTriangle(BMPATTR* bmpattr, MENUSTATE* state)
{
	int x1, y1, x2, y2, x3, y3;
	int tx1, ty1, tx2, ty2, tx3, ty3;
	int flag = 0;
	char xystring1[16];
	char xystring2[16];
	char xystring3[16];
	MOUSE mouse_old, mouse_new;

	ImgRectangle(132, 52, 188, 98, Gray, 2);
	ImgRectangle(192, 52, 248, 98, Gray, 2);
	ImgRectangle(252, 52, 298, 98, 0xff0000, 2);
	ImgRectangle(302, 52, 378, 98, Gray, 2);
	ImgRectangle(382, 52, 448, 98, Gray, 2);

	MouseStatus(&mouse_old);
	MouseStoreBk(mouse_old.x, mouse_old.y);
	MouseDraw(mouse_old);

	while (1)
	{
		MouseStatus(&mouse_new);

		if (mouse_new.x == mouse_old.x && mouse_new.y == mouse_old.y && mouse_new.button == mouse_old.button)
		{
			;
		}
		else
		{
			MousePutBk(mouse_old.x, mouse_old.y);
			MouseStoreBk(mouse_new.x, mouse_new.y);
			MouseDraw(mouse_new);

			if (mouse_new.button == mouse_old.button)
			{
				mouse_old = mouse_new;
				continue;
			}

			if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 0)
			{
				x1 = mouse_new.x;
				y1 = mouse_new.y;
				flag = 1;
				tx1 = x1 - bmpattr->x1;
				ty1 = y1 - bmpattr->y1;

				Bar(200, 570 + 1, 600, 600, Gray);
				sprintf(xystring1, "��1:%d,%d", tx1, ty1);
				TextGB16(200, 580, 14, 0, xystring1);
			}
			else if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 1)
			{
				x2 = mouse_new.x;
				y2 = mouse_new.y;
				flag = 2;
				tx2 = x2 - bmpattr->x1;
				ty2 = y2 - bmpattr->y1;

				sprintf(xystring2, "��2:%d,%d", tx2, ty2);
				TextGB16(350, 580, 14, 0, xystring2);
			}
			else if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 2)
			{
				x3 = mouse_new.x;
				y3 = mouse_new.y;
				flag = 0;
				tx3 = x3 - bmpattr->x1;
				ty3 = y3 - bmpattr->y1;

				sprintf(xystring3, "��3:%d,%d", tx3, ty3);
				TextGB16(500, 580, 14, 0, xystring3);

				MousePutBk(mouse_new.x, mouse_new.y);
				ImgTriangle(*bmpattr, x1, y1, x2, y2, x3, y3, state->color, state->size2);
			}
			else if (MouseDown(250, 50, 300, 100))
			{
				//�ٴε�����˳���������
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(252, 52, 298, 98, Gray, 2);
				ImgRectangle(132, 52, 188, 98, 0xff0000, 2);
				return 0;
			}
			else if (MouseDown(700, 50, 750, 100))
			{
				//��ϸ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectSize(&state->size, &state->size2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(750, 50, 800, 100))
			{
				//��ɫ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectColor(&state->color);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(84, 570, 126, 600))
			{
				//ʰɫ��
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				PickColor(&state->color,1);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			//else if (MouseDown(10, 0, 70, 50))
			//{
			//	//��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(252, 52, 298, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 20;
			//}
			//else if (MouseDown(70, 0, 130, 50))
			//{
			//	//����
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(252, 52, 298, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 30;
			//}
			//else if (MouseDown(130, 0, 190, 50))
			//{
			//	//�½�
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(252, 52, 298, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 40;
			//}
			//else if (MouseDown(190, 0, 250, 50))
			//{
			//	//ͼ��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(252, 52, 298, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 45;
			//}
			//else if (MouseDown(10, 50, 70, 100))
			//{
			//	//����
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(252, 52, 298, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 50;
			//}
			//else if (MouseDown(70, 50, 130, 100))
			//{
			//	//�ü�
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(252, 52, 298, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 60;
			//}
			//else if (MouseDown(130, 50, 190, 100))
			//{
			//	//ͼ��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(252, 52, 298, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 65;
			//}
			else if (MouseDown(190, 50, 250, 100))
			{
				//ֱ��
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(252, 52, 298, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 125;
			}
			else if (MouseDown(300, 50, 380, 100))
			{
				//����
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(252, 52, 298, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 135;
			}
			else if (MouseDown(380, 50, 450, 100))
			{
				//Բ
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(252, 52, 298, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 140;
			}
			else if (MouseDown(650, 50, 700, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageAdjustment(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(0, 570, 42, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageRot(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(42, 570, 84, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageMirror(*bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(703, 570, 735, 600))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoomSet(&state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(735, 570, 767, 600))
			{
				//��С
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoom(bmpattr, 0.8, state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(767, 570, 800, 600))
			{
				//�Ŵ�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoom(bmpattr, 1.25, state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(700, 0, 750, 50))
			{
				//�˾�
				MousePutBk(mouse_new.x, mouse_new.y);
				DrawShading(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				exit(0);
			}

			mouse_old = mouse_new;
		}
	}
}

/**
*  ������      DrawRectangle
*  �������    bmpattr    ͼƬ
			   state      �˵�״̬
*  ����        ������
*  ����ֵ      0          �˳������κ���
**/
int DrawRectangle(BMPATTR* bmpattr, MENUSTATE* state)
{
	int x1, y1, x2, y2;
	int tx1, ty1, tx2, ty2;
	int flag = 0;
	char xystring1[16];
	char xystring2[16];
	MOUSE mouse_old, mouse_new;

	ImgRectangle(132, 52, 188, 98, Gray, 2);
	ImgRectangle(192, 52, 248, 98, Gray, 2);
	ImgRectangle(252, 52, 298, 98, Gray, 2);
	ImgRectangle(302, 52, 378, 98, 0xff0000, 2);
	ImgRectangle(382, 52, 448, 98, Gray, 2);

	MouseStatus(&mouse_old);
	MouseStoreBk(mouse_old.x, mouse_old.y);
	MouseDraw(mouse_old);

	while (1)
	{
		MouseStatus(&mouse_new);

		if (mouse_new.x == mouse_old.x && mouse_new.y == mouse_old.y && mouse_new.button == mouse_old.button)
		{
			;
		}
		else
		{
			MousePutBk(mouse_old.x, mouse_old.y);
			MouseStoreBk(mouse_new.x, mouse_new.y);
			MouseDraw(mouse_new);

			if (mouse_new.button == mouse_old.button)
			{
				mouse_old = mouse_new;
				continue;
			}

			if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 0)
			{
				x1 = mouse_new.x;
				y1 = mouse_new.y;
				flag = 1;
				tx1 = x1 - bmpattr->x1;
				ty1 = y1 - bmpattr->y1;

				Bar(200, 570 + 1, 700, 600, Gray);
				sprintf(xystring1, "����1:%d,%d", tx1, ty1);
				TextGB16(200, 580, 14, 0, xystring1);
			}
			else if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 1)
			{
				x2 = mouse_new.x;
				y2 = mouse_new.y;
				flag = 0;
				tx2 = x2 - bmpattr->x1;
				ty2 = y2 - bmpattr->y1;

				sprintf(xystring2, "����2:%d,%d", tx2, ty2);
				TextGB16(450, 580, 14, 0, xystring2);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(x1, y1, x2, y2, state->color, state->size2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(300, 50, 380, 100))
			{
				//�ٴε�����˳�������
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(302, 52, 378, 98, Gray, 2);
				ImgRectangle(132, 52, 188, 98, 0xff0000, 2);
				return 0;
			}
			else if (MouseDown(700, 50, 750, 100))
			{
				//��ϸ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectSize(&state->size, &state->size2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(750, 50, 800, 100))
			{
				//��ɫ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectColor(&state->color);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(84, 570, 126, 600))
			{
				//ʰɫ��
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				PickColor(&state->color,1);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			//else if (MouseDown(10, 0, 70, 50))
			//{
			//	//��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(302, 52, 378, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 20;
			//}
			//else if (MouseDown(70, 0, 130, 50))
			//{
			//	//����
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(302, 52, 378, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 30;
			//}
			//else if (MouseDown(130, 0, 190, 50))
			//{
			//	//�½�
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(302, 52, 378, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 40;
			//}
			//else if (MouseDown(190, 0, 250, 50))
			//{
			//	//ͼ��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(302, 52, 378, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 45;
			//}
			//else if (MouseDown(10, 50, 70, 100))
			//{
			//	//����
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(302, 52, 378, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 50;
			//}
			//else if (MouseDown(70, 50, 130, 100))
			//{
			//	//�ü�
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(302, 52, 378, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 60;
			//}
			//else if (MouseDown(130, 50, 190, 100))
			//{
			//	//ͼ��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(302, 52, 378, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 65;
			//}
			else if (MouseDown(190, 50, 250, 100))
			{
				//ֱ��
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(302, 52, 378, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 125;
			}
			else if (MouseDown(250, 50, 300, 100))
			{
				//������
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(302, 52, 378, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 130;
			}
			else if (MouseDown(380, 50, 450, 100))
			{
				//Բ
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(302, 52, 378, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 140;
			}
			else if (MouseDown(650, 50, 700, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageAdjustment(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(0, 570, 42, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageRot(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(42, 570, 84, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageMirror(*bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(703, 570, 735, 600))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoomSet(&state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(735, 570, 767, 600))
			{
				//��С
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoom(bmpattr, 0.8, state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(767, 570, 800, 600))
			{
				//�Ŵ�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoom(bmpattr, 1.25, state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(700, 0, 750, 50))
			{
				//�˾�
				MousePutBk(mouse_new.x, mouse_new.y);
				DrawShading(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				exit(0);
			}

			mouse_old = mouse_new;
		}
	}
}

/**
*  ������      DrawCircle
*  �������    bmpattr    ͼƬ
			   state      �˵�״̬
*  ����        ��Բ
*  ����ֵ      0          �˳���Բ����
**/
int DrawCircle(BMPATTR* bmpattr, MENUSTATE* state)
{
	int x1, y1, x2, y2;
	int tx1, ty1;
	int r;
	int flag = 0;
	char xystring[16];
	char rstring[16];
	MOUSE mouse_old, mouse_new;

	ImgRectangle(132, 52, 188, 98, Gray, 2);
	ImgRectangle(192, 52, 248, 98, Gray, 2);
	ImgRectangle(252, 52, 298, 98, Gray, 2);
	ImgRectangle(302, 52, 378, 98, Gray, 2);
	ImgRectangle(382, 52, 448, 98, 0xff0000, 2);
	ImgRectangle(452, 52, 518, 98, Gray, 2);

	MouseStatus(&mouse_old);
	MouseStoreBk(mouse_old.x, mouse_old.y);
	MouseDraw(mouse_old);

	while (1)
	{
		MouseStatus(&mouse_new);

		if (mouse_new.x == mouse_old.x && mouse_new.y == mouse_old.y && mouse_new.button == mouse_old.button)
		{
			;
		}
		else
		{
			MousePutBk(mouse_old.x, mouse_old.y);
			MouseStoreBk(mouse_new.x, mouse_new.y);
			MouseDraw(mouse_new);

			if (mouse_new.button == mouse_old.button)
			{
				mouse_old = mouse_new;
				continue;
			}

			if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 0)
			{
				x1 = mouse_new.x;
				y1 = mouse_new.y;
				flag = 1;
				tx1 = x1 - bmpattr->x1;
				ty1 = y1 - bmpattr->y1;

				Bar(200, 570 + 1, 700, 600, Gray);
				sprintf(xystring, "����:%d,%d", tx1, ty1);
				TextGB16(200, 580, 14, 0, xystring);
			}
			else if (MouseDown(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2) && flag == 1)
			{
				x2 = mouse_new.x;
				y2 = mouse_new.y;
				flag = 0;
				r = (int)sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));

				sprintf(rstring, "�뾶:%d", r);
				TextGB16(450, 580, 14, 0, rstring);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgCircle(*bmpattr, x1, y1, r, state->color, state->size2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(380, 50, 450, 100))
			{
				//�ٴε�����˳���Բ
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(382, 52, 448, 98, Gray, 2);
				ImgRectangle(132, 52, 188, 98, 0xff0000, 2);
				return 0;
			}
			else if (MouseDown(700, 50, 750, 100))
			{
				//��ϸ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectSize(&state->size, &state->size2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(750, 50, 800, 100))
			{
				//��ɫ
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectColor(&state->color);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(84, 570, 126, 600))
			{
				//ʰɫ��
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				PickColor(&state->color,1);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			//else if (MouseDown(10, 0, 70, 50))
			//{
			//	//��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(382, 52, 448, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 20;
			//}
			//else if (MouseDown(70, 0, 130, 50))
			//{
			//	//����
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(382, 52, 448, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 30;
			//}
			//else if (MouseDown(130, 0, 190, 50))
			//{
			//	//�½�
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(382, 52, 448, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 40;
			//}
			//else if (MouseDown(190, 0, 250, 50))
			//{
			//	//ͼ��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(382, 52, 448, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 45;
			//}
			//else if (MouseDown(10, 50, 70, 100))
			//{
			//	//����
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(382, 52, 448, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 50;
			//}
			//else if (MouseDown(70, 50, 130, 100))
			//{
			//	//�ü�
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(382, 52, 448, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 60;
			//}
			//else if (MouseDown(130, 50, 190, 100))
			//{
			//	//ͼ��
			//	Bar(200, 570 + 1, 700, 600, Gray);
			//	MousePutBk(mouse_new.x, mouse_new.y);
			//	ImgRectangle(382, 52, 448, 98, Gray, 2);
			//	MouseStatus(&mouse_new);
			//	MouseStoreBk(mouse_new.x, mouse_new.y);
			//	return 65;
			//}
			else if (MouseDown(190, 50, 250, 100))
			{
				//ֱ��
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(382, 52, 448, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 125;
			}
			else if (MouseDown(250, 50, 300, 100))
			{
				//������
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(382, 52, 448, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 130;
			}
			else if (MouseDown(300, 50, 380, 100))
			{
				//����
				Bar(200, 570 + 1, 700, 600, Gray);
				MousePutBk(mouse_new.x, mouse_new.y);
				ImgRectangle(382, 52, 448, 98, Gray, 2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 135;
			}
			else if (MouseDown(650, 50, 700, 100))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageAdjustment(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(0, 570, 42, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageRot(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(42, 570, 84, 600))
			{
				//��ת
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageMirror(*bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(703, 570, 735, 600))
			{
				//����
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoomSet(&state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(735, 570, 767, 600))
			{
				//��С
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoom(bmpattr, 0.8, state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(767, 570, 800, 600))
			{
				//�Ŵ�
				MousePutBk(mouse_new.x, mouse_new.y);
				ImageZoom(bmpattr, 1.25, state->patton);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(700, 0, 750, 50))
			{
				//�˾�
				MousePutBk(mouse_new.x, mouse_new.y);
				DrawShading(bmpattr);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
			}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				exit(0);
			}
			mouse_old = mouse_new;
		}
	}
}

/**
*  ������      DrawShading
*  �������    bmpattr    ͼƬ

*  ����        �˾�
*  ����ֵ      0          ͼƬδ��
               -1         ȡ��
			   -2         �ر�
			   1          �ɹ����˾�
**/
int DrawShading(BMPATTR* bmpattr)
{
	u32 color1, color2;                 //���ڴ洢���ڽ������ɫֵ����ʱ����
	const u32 ColorStart = 0x7ecef4;    //�˾�Ĭ��ֵ
	const u32 ColorEnd = 0xf09fc3;      //�˾�Ĭ��ֵ
	MOUSE mouse_old, mouse_new;

	/*��ͼƬδ�򿪣���ʾ������˳�����*/
	if (bmpattr->flag == 0)
	{
		WarnBox("ͼƬδ��");
		return 0;
	}

	MouseStatus(&mouse_old);
	MouseStoreBk(mouse_old.x, mouse_old.y);
	MouseDraw(mouse_old);

	color1 = ColorStart;
	color2 = ColorEnd;
	
	BmpSave(248, 198, 552, 352, "DATA//BK8");    //������ʾ���·���ͼƬ
	DrawShadingBox();                            //��ʾ��

	while (1)
	{
		MouseStatus(&mouse_new);

		if (mouse_new.x == mouse_old.x && mouse_new.y == mouse_old.y && mouse_new.button == mouse_old.button)
		{
			;
		}
		else
		{
			MousePutBk(mouse_old.x, mouse_old.y);
			MouseStoreBk(mouse_new.x, mouse_new.y);
			MouseDraw(mouse_new);

			if (mouse_new.button == mouse_old.button)
			{
				mouse_old = mouse_new;
				continue;
			}

			if (MouseDown(348, 260, 400, 282))
			{
				/*ѡ�����ڽ������ɫ*/
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectColor(&color1);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);

				Bar(348 + 1, 260 + 1, 400 - 1, 282 - 1, color1);    //��ʾ��ɫһ
			}
			else if (MouseDown(348, 300, 400, 325))
			{
				/*ѡ�񽥱��������ɫ*/
				MousePutBk(mouse_new.x, mouse_new.y);
				SelectColor(&color2);
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);

				Bar(348 + 1, 300 + 1, 400 - 1, 325 - 1, color2);    //��ʾ��ɫ��
			}
			else if (MouseDown(455, 260, 512, 282))
			{
				//���ȷ�ϣ���ɫһĬ��ΪColorStart����ɫ��Ĭ��ΪColorEnd��
				MousePutBk(mouse_new.x, mouse_new.y);
				BmpPut(248, 198, "DATA//BK8");                                             //��ʾ֮ǰ�����ͼƬ
				ImgMix(bmpattr->x1, bmpattr->y1, bmpattr->x2, bmpattr->y2, color1, color2);    //���˾�
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return 1;
			}
			else if (MouseDown(455, 300, 512, 325))
			{
				//ȡ��
				MousePutBk(mouse_new.x, mouse_new.y);
				BmpPut(248, 198, "DATA//BK8");    //��ʾ֮ǰ�����ͼƬ
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return -1;
			}
			else if (MouseDown(500, 200, 550, 240))
			{
				//�ر�
				MousePutBk(mouse_new.x, mouse_new.y);
				BmpPut(248, 198, "DATA//BK8");    //��ʾ֮ǰ�����ͼƬ
				MouseStatus(&mouse_new);
				MouseStoreBk(mouse_new.x, mouse_new.y);
				return -2;
			}
			else if (MouseDown(750, 0, 800, 50))
			{
				//�˳�
				exit(0);
			}
			mouse_old = mouse_new;
		}
	}
}