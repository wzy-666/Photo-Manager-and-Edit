#include "pic.h"

/**
*  ������      ImgRectangle
*  �������    x1       ����һ������ĺ�����
			   y1       ����һ�������������
			   x2       ������һ���ԽǶ���ĺ�����
			   y2       ������һ���ԽǶ����������
			   color    ��ǰ��ɫֵ
			   size     ��ǰͼ�δ�ϸֵ
*  ����        ������
*  ����ֵ      0           size����
			   1           �����ɹ�����
**/
int ImgRectangle(int x1, int y1, int x2, int y2, u32 color, u8 size)
{
	int temp1, temp2;    //���ڽ�������ʱ����
	int i, j;            //ѭ������

	/*ȷ��x1 < x2*/
	if (x1 > x2)
	{
		temp1 = x1;
		x1 = x2;
		x2 = temp1;
	}

	/*ȷ��y1 < y2*/
	if (y1 > y2)
	{
		temp2 = y1;
		y1 = y2;
		y2 = temp2;
	}

	if (2 * size > x2 - x1 || 2 * size > y2 - y1)
	{
		//size����
		return 0;
	}

	/*��㽫���λ���*/
	for (j = y1; j <= y2; j++)
	{
		for (i = x1; i <= x2; i++)
		{
			if (i > x1 + size && i < x2 - size && j > y1 + size && j < y2 - size)
			{
				continue;
			}
			PutPixel(i, j, color);
		}
	}

	return 1;
}

/**
*  ������      ImgLine
*  �������    bmpattr    ͼƬ
			   x1         ֱ��һ���˵�ĺ�����
			   y1         ֱ��һ���˵��������
			   x2         ֱ����һ���˵�ĺ�����
			   y2         ֱ����һ���˵��������
			   color      ��ǰ��ɫֵ
			   size       ��ǰͼ�δ�ϸֵ
*  ����        ��ͼƬ�ڻ�ֱ��
*  ����ֵ      1           �����ɹ�����
**/
int ImgLine(BMPATTR bmpattr, int x1, int y1, int x2, int y2, u32 color, u8 size)
{
	int x, y;             //��һ��Ҫ���ĵ������
	int dx, dy;           //x,y����x2,y2���յ㣩�ֱ��ж�Զ
	int s1, s2;           //��һ��Ҫ���ĵ�ķ���
	int error;                //����б����
	int temp;             //���ڽ���dx��dy����ʱ����
	int interchange;      //�Ƿ񽻻�
	int i;                //ѭ������

	x = x1;               //�����ĵ�һ����Ϊֱ�ߵ�һ���˵�
	y = y1;
	dx = abs(x2 - x1);    //x�����յ����ĳ�ʼֵ
	dy = abs(y2 - y1);    //y�����յ����ĳ�ʼֵ

	/*���x2 > x1, ���һ���*/
	if (x2 > x1)
	{
		s1 = 1;
	}

	/*�������󻭵�*/
	else
	{
		s1 = -1;
	}

	/*���y2 > y1, ���»���*/
	if (y2 > y1)
	{
		s2 = 1;
	}

	/*�������ϻ���*/
	else
	{
		s2 = -1;
	}

	/*���y��������յ��Զ����dx,dy����*/
	if (dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
	}
	else
	{
		interchange = 0;
	}

	error = 2 * dy - dx;    //����б�����ĳ�ʼֵ

	/*���λ���ÿһ���㣬��dx�������õ���(x1,y1)��(x2,y2)��ֱ��*/
	for (i = 1; i <= dx; i++)
	{
		ImgDrawPixel(bmpattr, x, y, color, size);    //��ͼƬ�ڻ���

		/*�������б��������0�������ھ����յ�Ͻ��ķ�����ǰ�ƶ�һ��*/
		if (error >= 0)
		{
			/*��dx��dyδ����������y�����ƶ�һ����������x�����ƶ�һ��*/
			/*���ھ���Ͻ��ķ����ƶ�һ��*/
			if (interchange == 0)
			{
				y = y + s2;
			}
			else
			{
				x = x + s1;
			}

			/*��ʱ������б����Ϊ*/
			error = error - 2 * dx;
		}

		/*��dx��dyδ����������x�����ƶ�һ����������y�����ƶ�һ��*/
		/*��ÿһ��ѭ�������ھ����Զ�ķ����ƶ�һ��*/
		if (interchange == 0)
		{
			x = x + s1;
		}
		else
		{
			y = y + s2;
		}

		/*ÿһ��ѭ��������б������Ϊ*/
		error = error + 2 * dy;
	}

	return 1;
}

/**
*  ������      Line
*  �������    x1         ֱ��һ���˵�ĺ�����
			   y1         ֱ��һ���˵��������
			   x2         ֱ����һ���˵�ĺ�����
			   y2         ֱ����һ���˵��������
			   color      ��ǰ��ɫֵ
			   size       ��ǰͼ�δ�ϸֵ
*  ����        ��ֱ��
*  ����ֵ      1           �����ɹ�����
**/
int Line(int x1, int y1, int x2, int y2, u32 color, u8 size)
{
	int x, y;
	int dx, dy;
	int s1, s2;
	int error;
	int temp;
	int interchange;
	int i;

	x = x1;
	y = y1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	if (x2 > x1)
	{
		s1 = 1;
	}
	else
	{
		s1 = -1;
	}

	if (y2 > y1)
	{
		s2 = 1;
	}
	else
	{
		s2 = -1;
	}

	if (dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
	}
	else
	{
		interchange = 0;
	}

	error = 2 * dy - dx;

	for (i = 1; i <= dx; i++)
	{
		DrawPixel(x, y, color, size);    //����

		if (error >= 0)
		{
			if (interchange == 0)
			{
				y = y + s2;
			}
			else
			{
				x = x + s1;
			}

			error = error - 2 * dx;
		}

		if (interchange == 0)
		{
			x = x + s1;
		}
		else
		{
			y = y + s2;
		}

		error = error + 2 * dy;
	}

	return 1;
}

/**
*  ������      ImgTriangle
*  �������    bmpattr    ͼƬ
			   x1         �����ε�һ������ĺ�����
			   y1         �����ε�һ�������������
			   x2         �����εڶ�������ĺ�����
			   y2         �����εڶ��������������
			   x3         �����ε���������ĺ�����
			   y3         �����ε����������������
			   color      ��ǰ��ɫֵ
			   size       ��ǰͼ�δ�ϸֵ
*  ����        ��ͼƬ�ڻ�������
*  ����ֵ      1           �����ɹ�����
**/
int ImgTriangle(BMPATTR bmpattr, int x1, int y1, int x2, int y2, int x3, int y3, u32 color, u8 size)
{
	ImgLine(bmpattr, x1, y1, x2, y2, color, size);
	ImgLine(bmpattr, x1, y1, x3, y3, color, size);
	ImgLine(bmpattr, x2, y2, x3, y3, color, size);
	return 1;
}

/**
*  ������      Triangle
*  �������    bmpattr    ͼƬ
			   x1         �����ε�һ������ĺ�����
			   y1         �����ε�һ�������������
			   x2         �����εڶ�������ĺ�����
			   y2         �����εڶ��������������
			   x3         �����ε���������ĺ�����
			   y3         �����ε����������������
			   color      ��ǰ��ɫֵ
			   size       ��ǰͼ�δ�ϸֵ
*  ����        ��������
*  ����ֵ      1           �����ɹ�����
**/
int Triangle(int x1, int y1, int x2, int y2, int x3, int y3, u32 color, u8 size)
{
	Line(x1, y1, x2, y2, color, size);
	Line(x1, y1, x3, y3, color, size);
	Line(x2, y2, x3, y3, color, size);
	return 1;
}

/**
*  ������      ImgCircle
*  �������    bmpattr    ͼƬ
			   x          Բ�ĵĺ�����
			   y          Բ�ĵ�������
			   r          Բ�İ뾶
			   color      ��ǰ��ɫֵ
			   size       ��ǰͼ�δ�ϸֵ
*  ����        ��ͼƬ�ڻ�Բ
*  ����ֵ      1           �����ɹ�����
**/
int ImgCircle(BMPATTR bmpattr, int x, int y, int r, u32 color, u8 size)
{
	int a = 0;            //����������λ�������Բ�ĵĺ����꣬������ֵ�����Ȼ�Բ�����·�����뾶�����Ǹ��㣩
	int	b = r;            //����������λ�������Բ�ĵ������꣬������ֵ�����Ȼ�Բ�����·�����뾶�����Ǹ��㣩
	int	error = 3 - 2 * r;    //��������б������������ֵ

	// ���Բ��ͼƬ�ɼ������⣬ֱ���˳�
	if (x - r < bmpattr.x1 || x + r > bmpattr.x1 + bmpattr.width || y - r < bmpattr.y1 || y + r > bmpattr.y1 + bmpattr.heigth)
	{
		return 0;
	}

	/*��һ��1/8Բ������㻭Բ��һ�λ�8���㣩*/
	while (a <= b)
	{
		DrawImgCircle_8(bmpattr, x, y, a, b, color, size);    //����Բ�İ˶Գ�����ͼƬ�ڻ�Բ

		/*�������б����С��0��ֱ�ӽ�����б�����޸�Ϊ*/
		if (error < 0)
		{
			error = error + 4 * a + 6;
		}

		/*���򣬽�����б�����޸�Ϊ*/
		/*����������λ�õ�������-1*/
		else
		{
			error = error + 4 * (a - b) + 10;
			b--;
		}

		/*ÿһ��ѭ����������λ�õĺ�����+1*/
		a++;
	}

	return 1;
}

/**
*  ������      Circle
*  �������    x          Բ�ĵĺ�����
			   y          Բ�ĵ�������
			   r          Բ�İ뾶
			   color      ��ǰ��ɫֵ
			   size       ��ǰͼ�δ�ϸֵ
*  ����        ��ͼƬ�ڻ�Բ
*  ����ֵ      1           �����ɹ�����
**/
int Circle(int x, int y, int r, u32 color, u8 size)
{
	int a = 0;
	int	b = r;
	int	error = 3 - 2 * r;

	while (a <= b)
	{
		DrawCircle_8(x, y, a, b, color, size);

		if (error < 0)
		{
			error = error + 4 * a + 6;
		}
		else
		{
			error = error + 4 * (a - b) + 10;
			b--;
		}

		a++;
	}

	return 1;
}

/**
*  ������      DrawImgCircle_8
*  �������    bmpattr    ͼƬ
			   x          Բ�ĵĺ�����
			   y          Բ�ĵ�������
			   a          ������λ�������Բ�ĵĺ�����
			   b          ������λ�������Բ�ĵ�������
			   color      ��ǰ��ɫֵ
			   size       ��ǰͼ�δ�ϸֵ
*  ����        ����Բ�İ˶Գ��Ի���8����
*  ����ֵ      ��
**/
void DrawImgCircle_8(BMPATTR bmpattr, int x, int y, int a, int b, u32 color, u8 size)
{
	ImgDrawPixel(bmpattr, x + a, y + b, color, size);
	ImgDrawPixel(bmpattr, x - a, y + b, color, size);
	ImgDrawPixel(bmpattr, x + a, y - b, color, size);
	ImgDrawPixel(bmpattr, x - a, y - b, color, size);
	ImgDrawPixel(bmpattr, x + b, y + a, color, size);
	ImgDrawPixel(bmpattr, x - b, y + a, color, size);
	ImgDrawPixel(bmpattr, x + b, y - a, color, size);
	ImgDrawPixel(bmpattr, x - b, y - a, color, size);
}

/**
*  ������      DrawCircle_8
*  �������    x          Բ�ĵĺ�����
			   y          Բ�ĵ�������
			   a          ������λ�������Բ�ĵĺ�����
			   b          ������λ�������Բ�ĵ�������
			   color      ��ǰ��ɫֵ
			   size       ��ǰͼ�δ�ϸֵ
*  ����        ����Բ�İ˶Գ��Ի���8����
*  ����ֵ      ��
**/
void DrawCircle_8(int x, int y, int a, int b, u32 color, u8 size)
{
	DrawPixel(x + a, y + b, color, size);
	DrawPixel(x - a, y + b, color, size);
	DrawPixel(x + a, y - b, color, size);
	DrawPixel(x - a, y - b, color, size);
	DrawPixel(x + b, y + a, color, size);
	DrawPixel(x - b, y + a, color, size);
	DrawPixel(x + b, y - a, color, size);
	DrawPixel(x - b, y - a, color, size);
}

/**
*  ������      ImgDrawPixel
*  �������    bmpattr    ͼƬ
			   x          ������λ�õĺ�����
			   y          ������λ�õ�������
			   color    ��ǰ��ɫֵ
			   size     ��ǰ���ʣ�ͼ�Σ���ϸֵ
*  ����        ��ͼƬ�ڻ���
*  ����ֵ      1           �����ɹ�����
**/
int ImgDrawPixel(BMPATTR bmpattr, int x, int y, u32 color, u8 size)
{
	int rx = bmpattr.x1;    //���������㣨ʵ�ľ��Σ�����һ������ĺ����꣬������ֵΪͼƬ���Ͻǵĺ�����
	int ry = bmpattr.y1;    //���������㣨ʵ�ľ��Σ�����һ������������꣬������ֵΪͼƬ���Ͻǵ�������

	/*���sizeû�г���ͼƬ���Ե�����������εĿ��Ϊ������size*/
	if (rx < x - size)
	{
		rx = x - size;
	}

	/*���sizeû�г���ͼƬ�ϱ�Ե�����������εĸ߸�Ϊ������size*/
	if (ry < y - size)
	{
		ry = y - size;
	}

	/*��(x,y)�������õ㣨ʵ�ľ��Σ�*/
	Bar(rx, ry, x, y, color);
	return 1;
}

/**
*  ������      DrawPixel
*  �������    x          ������λ�õĺ�����
			   y          ������λ�õ�������
			   color    ��ǰ��ɫֵ
			   size     ��ǰ���ʣ�ͼ�Σ���ϸֵ
*  ����        ����
*  ����ֵ      1           �����ɹ�����
**/
int DrawPixel(int x, int y, u32 color, u8 size)
{
	int rx = x - size;
	int ry = y - size;
	Bar(rx, ry, x, y, color);
	return 1;
}


