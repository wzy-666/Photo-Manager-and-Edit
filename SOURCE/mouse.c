#include "mouse.h"

int Cursor[19][12] = {

	{2,0,0,0,0,0,0,0,0,0,0,0},
	{2,2,0,0,0,0,0,0,0,0,0,0},
	{2,1,2,0,0,0,0,0,0,0,0,0},
	{2,1,1,2,0,0,0,0,0,0,0,0},
	{2,1,1,1,2,0,0,0,0,0,0,0},
	{2,1,1,1,1,2,0,0,0,0,0,0},
	{2,1,1,1,1,1,2,0,0,0,0,0},
	{2,1,1,1,1,1,1,2,0,0,0,0},
	{2,1,1,1,1,1,1,1,2,0,0,0},
	{2,1,1,1,1,1,1,1,1,2,0,0},
	{2,1,1,1,1,1,1,1,1,1,2,0},
	{2,1,1,1,1,1,1,1,1,1,1,2},
	{2,1,1,1,1,1,1,2,2,2,2,2},
	{2,1,1,1,2,1,1,2,0,0,0,0},
	{2,1,1,2,2,1,1,2,0,0,0,0},
	{2,1,2,0,0,2,1,1,2,0,0,0},
	{2,2,0,0,0,2,1,1,2,0,0,0},
	{0,0,0,0,0,0,2,1,2,0,0,0},
	{0,0,0,0,0,0,0,2,0,0,0,0}
};

u32 m_bk[19][12];

	
/*����ʼ��*/
unsigned int MouseInit(void)
{
	union REGS m;
	m.x.ax = 0;
	int86(0x33, &m, &m);
	return m.x.ax;
}

/*��������ƶ���Χ*/
void MouseRange(int x1, int y1, int x2, int y2)
{
	union REGS m;
	m.x.ax = 7;
	m.x.cx = x1;
	m.x.dx = x2;
	int86(0x33, &m, &m);

	m.x.ax = 8;
	m.x.cx = y1;
	m.x.dx = y2;
	int86(0x33, &m, &m);
}

/*��ȡ���״̬������ָ���ṹ*/
int MouseStatus(MOUSE* m)
{
	union REGS mouse;
	mouse.x.ax = 3;
	int86(0x33, &mouse, &mouse);
	m->x = mouse.x.cx;
	m->y = mouse.x.dx;
	m->button = mouse.x.bx;
	return m->button;
}

/*�ж��������Ƿ���ָ��λ�ð���*/
int MouseDown(int x1, int y1, int x2, int y2)
{
	MOUSE m = { 0,0,0 };
	MouseStatus(&m);

	if ((m.x >= x1)
		&& (m.x <= x2)
		&& (m.y >= y1)
		&& (m.y <= y2)
		&& (m.button & 1) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*�ж��������Ƿ���ָ��λ���ɿ�*/
int MouseUp(int x1, int y1, int x2, int y2)
{
	MOUSE m = { 0,0,0 };
	MouseStatus(&m);

	if ((m.x >= x1)
		&& (m.x <= x2)
		&& (m.y >= y1)
		&& (m.y <= y2)
		&& (m.button & 1) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*�ж��������Ƿ���ָ��λ�����ɿ�*/
int MouseOutUp(int x1, int y1, int x2, int y2)
{
	MOUSE m = { 0,0,0 };
	MouseStatus(&m);

	if (((m.x < x1)
		|| (m.x > x2)
		|| (m.y < y1)
		|| (m.y > y2))
		&& (m.button & 1) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*�洢������ڵ����ֵ��Դ�����*/
void MouseStoreBk(int x, int y)
{
	int i, j;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (Cursor[i][j] != 0)
			{
				m_bk[i][j] = GetPixel(x + j, y + i);
			}
		}
	}
}

/*�ָ�����굲ס���ֵ��Դ�*/
void MousePutBk(int x, int y)
{
	int i, j;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (Cursor[i][j] != 0)
			{
				PutPixel(x + j, y + i, m_bk[i][j]);
			}
		}
	}
}

/*��긴λ*/
void MouseReset(void)
{
	if (MouseInit() != 0xffff)
	{
		printf("Error MouseInit!\n");
		getch();
		exit(1);
	}
	MouseRange(0, 0, SCR_WIDTH - 1, SCR_HEIGHT - 1);
	MouseStoreBk(0, 0);
}

/*����꺯��*/
void MouseDraw(MOUSE m)
{
	int i, j;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (Cursor[i][j] == 0)
			{
				continue;
			}
			else if (Cursor[i][j] == 1)
			{
				PutPixel(m.x + j, m.y + i, 0xffffff);
			}
			else if (Cursor[i][j] == 2)
			{
				PutPixel(m.x + j, m.y + i, 0);
			}
		}
	}
}