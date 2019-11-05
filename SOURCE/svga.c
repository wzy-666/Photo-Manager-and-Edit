#include "svga.h"

void SetSVGA()
{
	union REGS r;

	r.x.ax = 0x4f02;
	r.x.bx = 0x115;
	int86(0x10, &r, &r);

	//SVGAģʽ����ʧ��
	if (r.x.ax != 0x004f)
	{
		printf("SET SVGA ERROR!\n");
		delay(5000);
		exit(1);
	}
}

void SelectPage(register u8 page)
{
	union REGS r;
	static unsigned char old_page = 0;
	static unsigned char flag = 0;

	r.x.ax = 0x4f05;
	r.x.bx = 0;

	//��ʼѡҳ
	if (flag == 0)
	{
		old_page = page;
		r.x.dx = page;
		int86(0x10, &r, &r);
		flag++;
	}

	//ҳ��ı�ʱ���л�ҳ
	if (page != old_page)
	{
		old_page = page;
		r.x.dx = page;
		int86(0x10, &r, &r);
	}
}

void PutPixel(int x, int y, u32 color)
{
	//�Դ�ָ��
	u32 far* const buf = (u32 far*)0xa0000000L;

	u8  new_page;
	u32 page;

	//�����˳�
	if (x < 0 || x >(SCR_WIDTH - 1) || y < 0 || y >(SCR_HEIGHT - 1))
	{
		return;
	}

	//ÿ64K��4=2^14�����ػ�ҳ
	page = ((u32)y * 800) + x;
	new_page = page >> 14;

	SelectPage(new_page);

	//�Դ渳ֵ
	buf[page] = color;
}

u32 GetPixel(int x, int y)
{
	u32 far* const buf = (u32 far*)0xa0000000L;

	u8 new_page;
	u32 page;

	if (x < 0 || x >(SCR_WIDTH - 1) || y < 0 || y >(SCR_HEIGHT - 1))
	{
		return 0;
	}

	page = ((u32)y * 800) + x;
	new_page = page >> 14;
	SelectPage(new_page);

	return buf[page];
}

void Bar(int x1, int y1, int x2, int y2, u32 color)
{
	int i, j;
	int temp;

	//������ֵ
	if (x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y1 > y2)
	{
		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	//����
	if (x1 < 0  )
	{
		x1 = 0;
	}
	if (x2 > (SCR_WIDTH - 1))
	{
		x2 = SCR_WIDTH - 1;
	}
	if (y1 < 0)
	{
		y1 = 0;
	}
	if (y2 > (SCR_HEIGHT - 1))
	{
		y2 = SCR_HEIGHT - 1;
	}

	//���л���
	for (i = x1; i <= x2; i++)
	{
		for (j = y1; j <= y2; j++)
		{
			PutPixel(i, j, color);
		}
	}
}