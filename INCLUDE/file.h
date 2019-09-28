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

void DrawNewBox(void);
void DrawOpenBox(void);
void DrawSaveBox(void);
void DrawListBox(void);
int FileList(BMPATTR* bmpattr);
int FileNew(BMPATTR* bmpattr);
int FileOpen(BMPATTR* bmpattr);
int FileSave(BMPATTR* bmpattr);
int FindFile(int n, struct ffblk* dir);
int FileInfo(FILEATTR* fileattr, char* filename);
int FileInfoShow(FILEATTR attr, struct ffblk dir);
int FindAllFile(int* n);
int FileListShow(int i);


#endif
