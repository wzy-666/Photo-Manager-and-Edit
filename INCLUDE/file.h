#ifndef FILE_H
#define FILE_H

#include "head.h"
#include "svga.h"
#include "text.h"
#include "color.h"
#include "mouse.h"
#include "bmp.h"
#include "image.h"
#include "dir.h"	//����findfirst��findnext�����ļ�����
#include "io.h"		//����removeɾ���ļ��ĺ���

void DrawNewBox();
void DrawOpenBox();
void DrawSaveBox();
int FileList(BMPATTR* bmpattr);
int FileNew(BMPATTR* bmpattr);
int FileOpen(BMPATTR* bmpattr);
int FileSave(BMPATTR* bmpattr);
int FindFile(int n, struct ffblk* dir);
int FileInfo(FILEATTR* fileattr, char* filename);
int FileInfoShow(FILEATTR attr, struct ffblk dir);
int FindAllFile(int* n);
int FileListShow(int i);
int WarnBox(char* error);					//���󴰿�



#endif
