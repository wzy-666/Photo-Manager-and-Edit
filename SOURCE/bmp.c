#include "bmp.h"

/**
 *  @ brief		BmpPut
 *
 *  @ param		x		横坐标
 *				y		纵坐标
 *				path	文件路径
 *
 *	@ note		打开文件
 *
 *	@ return	正常返回	1
 *				错误返回	-1
 **/

int BmpPut(int x, int y, char* path)
{
	int i, j;
	BGR* buffer;
	u32 color24;
	u32 linebytes;
	FILE* fp = fopen(path, "rb");
	BITMAPFILEHEADER bmphead;
	BITMAPINFOHEADER bmpinfo;

	if (fp)
	{
		fseek(fp, 28L, 0);
		fread(&bmpinfo.biBitCount, 2, 1, fp);
		if (bmpinfo.biBitCount != 24U)
		{
			fclose(fp);
			return 0;
		}

		fseek(fp, 30L, 0);
		fread(&bmpinfo.biCompression, 4, 1, fp);
		if (bmpinfo.biCompression != 0UL)
		{
			fclose(fp);
			return -1;
		}

		fseek(fp, 18L, 0);
		fread(&bmpinfo.biWidth, 4, 1, fp);
		if (bmpinfo.biWidth > SCR_WIDTH)
		{
			fclose(fp);
			return -1;
		}

		fread(&bmpinfo.biHeight, 4, 1, fp);
		if (bmpinfo.biHeight > SCR_HEIGHT)
		{
			fclose(fp);
			return -1;
		}

		linebytes = (3 * bmpinfo.biWidth) % 4;
		if (!linebytes)
		{
			linebytes = 3 * bmpinfo.biWidth;
		}
		else
		{
			linebytes = 3 * bmpinfo.biWidth + 4 - linebytes;
		}

		if ((buffer = (BGR*)malloc(linebytes)) == 0)
		{
			fclose(fp);
			return -1;
		}

		fseek(fp, 54L, 0);
		for (i = bmpinfo.biHeight - 1; i > -1; i--)
		{
			fread(buffer, linebytes, 1, fp);
			for (j = 0; j < bmpinfo.biWidth; j++)
			{
				color24 = ((u32)buffer[j].r) << 16 | ((u32)buffer[j].g) << 8 | ((u32)buffer[j].b);
				PutPixel(j + x, i + y, color24);
			}
		}

		free(buffer);
		fclose(fp);
	}
	else
	{
		//打开失败
		return -1;
	}
	return 1;
}

/**
 *  @ brief		BmpSave
 *
 *  @ param		x1、x2	横坐标
 *				y1、y2	纵坐标
 *				path	文件路径
 *
 *	@ note		保存文件
 *
 *	@ return	正常返回	1
 *				错误返回	-1
 **/

int BmpSave(int x1,int y1,int x2,int y2,char* path)
{
	int i, j;
	FILE* fp;
	BGR* buffer;
	u16 width = x2 - x1;
	u16 height = y2 - y1;
	u32 color24;
	u32 bmpbytes;
	u32 linebytes;
	BITMAPFILEHEADER bmphead;
	BITMAPINFOHEADER bmpinfo;

	linebytes = (3 * width) % 4;
	if (!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	bmpbytes = linebytes * height + 54;
	bmphead.bfType = 0x4d42;
	bmphead.bfSize = bmpbytes;
	bmphead.bfReserved1 = 0;
	bmphead.bfReserved2 = 0;
	bmphead.bfOffBits = 0x36;
	bmpinfo.biSize = 0x28;
	bmpinfo.biWidth = width;
	bmpinfo.biHeight = height;
	bmpinfo.biPlanes = 1;
	bmpinfo.biBitCount = 0x18;
	bmpinfo.biCompression = 0;
	bmpinfo.biSizeImage = bmpbytes - 54;
	bmpinfo.biXPelsPerMeter = 0;
	bmpinfo.biYPelsPerMeter = 0;
	bmpinfo.biClrUsed = 0;
	bmpinfo.biClrImportant = 0;

	if ((buffer = (BGR*)malloc(3 * width)) == 0)
	{
		//无法开辟内存
		return -1;
	}
	if ((fp = fopen(path, "wb")) == NULL)
	{
		//无法创建文件
		return -1;
	}

	fwrite(&bmphead, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(&bmpinfo, sizeof(BITMAPINFOHEADER), 1, fp);

	fseek(fp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		for (j = width - 1; j > -1; j--)
		{
			color24 = GetPixel(x1 + j, y1 + i);
			buffer[j].r = color24 >> 16 & 0xff;
			buffer[j].g = color24 >> 8 & 0xff;
			buffer[j].b = color24 & 0xff;
		}
		fwrite(buffer, linebytes, 1, fp);
	}

	free(buffer);
	fclose(fp);
	return 1;
}

/**
 *  @ brief		BmpInfo
 *
 *  @ param		bmpattr		图像信息指针
 *				filename	文件名
 *
 *	@ note		获取文件信息
 *
 *	@ return	正常返回	1
 *				错误返回	-1
 **/

int BmpInfo(BMPATTR* bmpattr,char* filename)
{
	FILE* fp;
	u16 bit;			//位深
	u32 compression;	//压缩

	BmpName(filename);	//添加文件类型后缀

	if ((fp=fopen(filename,"rb"))==NULL)
	{
		return 0;
	}
	else
	{
		//位深
		fseek(fp, 28L, 0);
		fread(&bit, 2, 1, fp);
		if (bit != 24U)
		{
			fclose(fp);
			return 0;
		}
		//压缩
		fseek(fp, 30L, 0);
		fread(&compression, 4, 1, fp);
		if (compression != 0UL)
		{
			fclose(fp);
			return 0;
		}
		//宽度
		fseek(fp, 18L, 0);
		fread(&bmpattr->width, 4, 1, fp);
		if (bmpattr->width > BMP_WIDTH_MAX || bmpattr->width < BMP_WIDTH_MIN)
		{
			bmpattr->width = bmpattr->oWidth;
			fclose(fp);
			return 0;
		}
		//高度
		fread(&bmpattr->heigth, 4, 1, fp);
		if (bmpattr->heigth > BMP_HEIGTH_MAX || bmpattr->heigth < BMP_HEIGTH_MIN)
		{
			bmpattr->heigth = bmpattr->oHeigth;
			fclose(fp);
			return 0;
		}

		//计算坐标
		bmpattr->x1 = SCR_WIDTH / 2 - bmpattr->width / 2;
		bmpattr->x2 = SCR_WIDTH / 2 + bmpattr->width / 2;
		bmpattr->y1 = SCR_HEIGHT / 2 - bmpattr->heigth / 2 + 35;
		bmpattr->y2 = SCR_HEIGHT / 2 + bmpattr->heigth / 2 + 35;

		//图像打开状态改变
		bmpattr->flag = 1;

		//初始化放缩状态
		bmpattr->scale = 1.0;

		//记录原始长宽
		bmpattr->oHeigth = bmpattr->heigth;
		bmpattr->oWidth = bmpattr->width;

		//初始化调整属性
		bmpattr->contrast = 0;
		bmpattr->saturation = 1.0;
		bmpattr->lightness = 1.0;

		//复制名称
		strcpy(bmpattr->name, filename);

		fclose(fp);
	}
	return 1;
}

/**
 *  @ brief		BmpName
 *
 *  @ param		filename	文件名
 *				
 *	@ note		修饰文件名
 *
 *	@ return	正常返回	1
 *				错误返回	0
 **/

int BmpName(char* filename)
{
	char path[18] = "bmp/";
	if (filename[0] == '\0')
	{
		return 0;
	}
	else
	{
		if ((strstr(filename, ".bmp") == NULL) && strstr(filename, ".BMP") == NULL)
		{
			strcat(filename, ".bmp");
		}
		else
		{
			;
		}
		if ((strstr(filename, "bmp/") == NULL) && strstr(filename, "BMP/") == NULL)
		{
			strcat(path, filename);
			strcpy(filename, path);
		}
		else
		{
			;
		}
		return 1;
	}
}

/**
 *  @ brief		DataSave
 *
 *  @ param		
 *
 *	@ note		纯二进制形式保存图像
 *
 *	@ return	
 *				
 **/

int DataSave(BMPATTR* bmpattr, const char* path)
{
	FILE* fp;                      //将背景图案每一点的颜色值读取出来存入文件中，再从文件中读取颜色值用于计算

	int x1 = bmpattr->x1;
	int x2 = bmpattr->x1 + bmpattr->width;
	int y1 = bmpattr->y1;
	int y2 = bmpattr->y1 + bmpattr->heigth;

	int i, j;	//循环变量

	u32 color;

	/*以二进制只写模式打开临时文件，如果文件打开失败，退出*/
	if ((fp = fopen(path, "wb")) == NULL)
	{
		exit(0);
	}

	/*读取每一点的颜色值，并写入文件*/
	for (j = y1; j <= y2; j++)
	{
		for (i = x1; i <= x2; i++)
		{
			color = GetPixel(i, j);
			fwrite(&color, 4, 1, fp);
		}
	}

	fclose(fp);    //关闭文件

	return 0;
}
