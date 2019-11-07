#ifndef FILE_H
#define FILE_H

#include "head.h"
#include "svga.h"
#include "mouse.h"	

#include "text.h"	//�����
#include "bmp.h"	//������
#include "box.h"	//���ڿ�
#include "color.h"	//ɫ�ʿ�
#include "image.h"	//ͼ�����

#include "dir.h"	//����findfirst��findnext�����ļ�����
#include "io.h"		//����removeɾ���ļ��ĺ���

int FileList(BMPATTR* bmpattr);						//�ļ��б�
int FileNew(BMPATTR* bmpattr);						//�½��ļ�
int FileOpen(BMPATTR* bmpattr);						//���ļ�
int FileSave(BMPATTR* bmpattr);						//�����ļ�
int FindFile(int n, struct ffblk* dir);				//�����ļ�
int FileInfo(FILEATTR* fileattr, char* filename);	//�ļ���Ϣ
int FileInfoShow(FILEATTR attr, struct ffblk dir);	//��ʾ��Ϣ
int FindAllFile(int* n);							//�����ļ�
int FileListShow(int i);							//��ʾ�б�



#endif
