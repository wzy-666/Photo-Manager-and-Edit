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

/**
*  ������      ImgShading
*  �������    x1        ����һ������ĺ�����
			   y1        ����һ�������������
			   x2        ������һ���ԽǶ���ĺ�����
			   y2        ������һ���ԽǶ����������
			   color1    ���ڽ������ɫֵ
			   color2    �����������ɫֵ
*  ����        ���������
*  ����ֵ      ��
**/
void ImgShading(int x1, int y1, int x2, int y2, u32 color1, u32 color2)
{
	int i = 0, j = 0;           //ѭ������
	int temp1, temp2;           //���ڽ�������ʱ����
	HSL tHSL1, tHSL2;           //�洢HSL����ʱ����
	RGB tRGB1, tRGB2;           //�洢RGB����ʱ����
	int tHue0;                  //���ڼ���ɫ�����ʱ����
	double dLightness;          //ÿ�н�������ȵ�ֵ
	double dSaturation;         //ÿ�н���ı��Ͷȵ�ֵ
	double dHue;                //ÿ�н����ɫ���ֵ

	U32TRGB(&tRGB1, color1);    //��ȡcolor��RGBֵ
	U32TRGB(&tRGB2, color2);
	RGB2HSL(tRGB1, &tHSL1);     //��RGBת��ΪHSL
	RGB2HSL(tRGB2, &tHSL2);

	tHue0 = tHSL1.h;                                      //����ֵ

	dLightness = (tHSL2.l - tHSL1.l) / fabs(y1 - y2);     //����ÿ�н�������ȵ�ֵ
	dSaturation = (tHSL2.s - tHSL1.s) / fabs(y1 - y2);    //����ÿ�н���ı��Ͷȵ�ֵ
	dHue = (tHSL2.h - tHSL1.h) / fabs(y1 - y2);           //����ÿ�н����ɫ���ֵ

	delay(100);

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

	//���䱳��
	for (i = y1; i <= y2; i++)
	{
		for (j = x1; j <= x2; j++)
		{
			PutPixel(j, i, color1);
		}

		/*���㽥��һ�к��HSLֵ*/
		tHSL1.l = tHSL1.l + dLightness;
		tHSL1.s = tHSL1.s + dSaturation;
		tHSL1.h = (int)(tHue0 + dHue * i + 0.5);

		HSL2RGB(&tRGB1, tHSL1);                         //��HSLת��ΪRGB
		color1 = RGB2U32(tRGB1.r, tRGB1.g, tRGB1.b);    //��RGBת��Ϊ��ɫֵ����color
	}
}

/**
*  ������      ImgMix
*  �������    x1        ��Ͼ�������һ������ĺ�����
			   y1        ��Ͼ�������һ�������������
			   x2        ��Ͼ���������һ���ԽǶ���ĺ�����
			   y2        ��Ͼ���������һ���ԽǶ����������
			   color1    ���ڽ������ɫֵ
			   color2    �����������ɫֵ
*  ����        �����������ͼƬ�������
*  ����ֵ      ��
**/
void ImgMix(int x1, int y1, int x2, int y2, u32 color1, u32 color2)
{
	int i, j;                      //ѭ������
	int temp1, temp2;              //���ڽ�������ʱ����
	const double percent = 0.7;    //���ʱ����ͼ����ռ�ı���
	u32 color_scr1;                //���ڻ�ȡ����ͼ������ɫֵ
	u32	color_scr2;                //���ڻ�ȡ������ε���ɫֵ
	u32 color_dst;                 //���ڼ������ý������ɫֵ
	RGB tRGB;                      //������������ɫֵת��ΪRGB
	RGB tRGB1;                     //������ͼ������ɫֵת��ΪRGB
	RGB tRGB2;                     //��������ε���ɫֵת��ΪRGB
	FILE* fp;                      //������ͼ��ÿһ�����ɫֵ��ȡ���������ļ��У��ٴ��ļ��ж�ȡ��ɫֵ���ڼ���

	/*�Զ�����ֻдģʽ����ʱ�ļ�������ļ���ʧ�ܣ��˳�*/
	if ((fp = fopen("DATA//temp2", "wb")) == NULL)
	{
		exit(0);
	}

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

	/*��ȡÿһ�����ɫֵ����д���ļ�*/
	for (j = y1; j <= y2; j++)
	{
		for (i = x1; i <= x2; i++)
		{
			color_scr1 = GetPixel(i, j);
			fwrite(&color_scr1, 4, 1, fp);
		}
	}

	fclose(fp);    //�ر��ļ�

	ImgShading(x1, y1, x2, y2, color1, color2);    //���������

	/*�Զ�����ֻ��ģʽ����ʱ�ļ�������ļ���ʧ�ܣ��˳�*/
	if ((fp = fopen("DATA//temp2", "rb")) == NULL)
	{
		exit(0);
	}

	/*������ͼ������ɫֵ�������뽥����ε�RGB��һ���������*/
	for (j = y1; j <= y2; j++)
	{
		for (i = x1; i <= x2; i++)
		{
			/*�ֱ��ȡ����ͼ���ͽ�����ε���ɫֵ��������ת��ΪRGB*/
			fread(&color_scr1, 4, 1, fp);
			color_scr2 = GetPixel(i, j);
			U32TRGB(&tRGB1, color_scr1);
			U32TRGB(&tRGB2, color_scr2);

			/*�����Ϻ��RGB*/
			if (tRGB1.r <= 128)
			{
				tRGB.r = (unsigned char)(tRGB1.r * tRGB2.r / 128);
			}
			else
			{
				tRGB.r = (unsigned char)(255 - (255 - tRGB1.r) * (255 - tRGB2.r) / 128);
			}

			if (tRGB1.g <= 128)
			{
				tRGB.g = (unsigned char)(tRGB1.g * tRGB2.g / 128);
			}
			else
			{
				tRGB.g = (unsigned char)(255 - (255 - tRGB1.g) * (255 - tRGB2.g) / 128);
			}

			if (tRGB1.b <= 128)
			{
				tRGB.b = (unsigned char)(tRGB1.b * tRGB2.b / 128);
			}
			else
			{
				tRGB.b = (unsigned char)(255 - (255 - tRGB1.b) * (255 - tRGB2.b) / 128);
			}

			//tRGB.r = (unsigned char)(percent * tRGB1.r + (1 - percent) * tRGB2.r);
			//tRGB.g = (unsigned char)(percent * tRGB1.g + (1 - percent) * tRGB2.g);
			//tRGB.b = (unsigned char)(percent * tRGB1.b + (1 - percent) * tRGB2.b);

			tRGB.r = (unsigned char)(percent * tRGB1.r + (1 - percent) * tRGB.r);
			tRGB.g = (unsigned char)(percent * tRGB1.g + (1 - percent) * tRGB.g);
			tRGB.b = (unsigned char)(percent * tRGB1.b + (1 - percent) * tRGB.b);

			/*����Ϻ��RGBת��Ϊ��ɫֵ��������*/
			color_dst = RGB2U32(tRGB.r, tRGB.g, tRGB.b);
			PutPixel(i, j, color_dst);
		}
	}

	fclose(fp);    //�ر��ļ�
}