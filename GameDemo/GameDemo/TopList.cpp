/*program name:TopList.cpp
programmer:������
student number:19301014
date:2020-07-11
use:�鿴���޸�����ִ�еĺ���
*/
#include"mean.h"//�������Ӷ��塢ͼƬת������������Զ���ͷ�ļ�
#include"crucial.h"//�������ṹ�嶨�弰���ֺ����Ķ�����Զ���ͷ�ļ�

int TopList() {
	FILE* f1;
	f1 = fopen("TopList.txt", "r+");
	fseek(f1, 0, SEEK_SET);//�������ļ����ƶ�����ͷ

	Top* head = (Top*)malloc(sizeof(Top));
	Top* link = head;//��������ͷָ��


	LOGFONT f;
	f.lfHeight = 40;
	f.lfWeight = 0;
	f.lfOrientation = 0;
	_tcscpy(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);//������ĸ���������е���


	IMAGE background, call, rank, score,menu;//����ͼƬ
	loadimage(&background, _T("image/background.jpg"), 900, 600);//���ر���ͼƬ
	loadimage(&call, _T("image/name.png"), 200, 160);//�����������ֵ�ͼƬ
	loadimage(&rank, _T("image/rank.png"), 200, 160);//�����������ֵ�ͼƬ
	loadimage(&score, _T("image/score.png"), 200, 160);//���ز������ֵ�ͼƬ
	loadimage(&menu, _T("image/exitToMenu.png"), 300, 250);//���ط������˵���ͼƬ


	putimage(0, 0, &background);
	drawAlpha(&call, 320, 50);
	drawAlpha(&rank, 160, 50);
	drawAlpha(&score, 470, 50);
	drawAlpha(&menu, 600, 450);//������ͼƬ���


	
	int total = 0;//���ڼ�¼�ܲ���
	
	while (true) {
		Top* TempValue = (Top*)malloc(sizeof(Top));
		fscanf(f1, "%s %d", &TempValue->name, &TempValue->steps);//���ļ��ж�ȡ����
		TempValue->next = NULL;
		link->next = TempValue;
		link = link->next;//Ϊ�����½��ڵ㲢�����ȡ��ֵ
		total++;
		if (feof(f1))
			break;//����ȡ���ļ�ĩβʱ����ѭ��
	}
	setbkmode(TRANSPARENT);//�������ֱ���͸��
	settextcolor(BLACK);//����������ɫ
	
	Top temp;
	Top* p1;
	Top* p2;//ͨ��ð�����������ղ�����С�����˳������
	for (p1 = head->next; p1->next!=NULL; p1 = p1->next) {
		for (p2 = head->next; p2->next != NULL; p2 = p2->next) {
			if (p2->steps > p2->next->steps) {
				strcpy(temp.name, p2->name);
				temp.steps = p2->steps;
				p2->steps = p2->next->steps;
				strcpy(p2->name, p2->next->name);
				p2->next->steps = temp.steps;
				strcpy(p2->next->name, temp.name);
			}
		}
	}
	if (total > 5)
		total = 5;//�������ݴ���5ʱֻ���ǰ5��

	TCHAR Rank[5];//�������ε����
	TCHAR num[5];//���ڽ��������
	int TempSteps;//���ڳ�������ÿһ�ڵĲ���
	int i;
	Top* head3 = head;//��ȡ����ͷָ��
	for (i = 0; i < total; i++) {
		if (head3->next == NULL) {
			break;//�����������ĩβʱ����
		}
		head3 = head3->next;
		TempSteps = head3->steps;
		_stprintf_s(Rank, _T("%d"), i + 1);
		_stprintf_s(num, _T("%d"), TempSteps);
		outtextxy(380, 150 + 65 * i, head3->name);
		outtextxy(560, 150 + 65 * i, num);
		outtextxy(230, 150 + 65 * i, Rank);//����ҵ�����������������ȫ�����
	}

	MOUSEMSG m;
	while (true) {
		m = GetMouseMsg();//��ȡ�����Ϣ
		if (m.uMsg == WM_LBUTTONUP) {
			if (m.x > 630 && m.x < 880 && m.y >550 && m.y < 600) {//������������˵���ťʱ����
				break;//����
			}
		}
	}

	fclose(f1);//�ر��ļ�
	return 0;
}