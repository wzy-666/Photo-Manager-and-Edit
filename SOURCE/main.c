#include "head.h"
#include "svga.h"
#include "mouse.h"
#include "menu.h"

void main()
{
	SetSVGA();		//��ʼ��SVGA
	MouseReset();	//��ʼ��MOUSE
	Welcome();		//Weclome����
	DrawMenu();		//WorkSpace����
	MenuManager();	//��Ϣ�������
}