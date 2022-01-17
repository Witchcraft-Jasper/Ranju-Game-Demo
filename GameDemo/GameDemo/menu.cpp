/*program name:menu.cpp
programmer:������
student number:19301014
date:2020-07-11
use:���û�չʾ�˵�
*/

#include"mean.h"//�������Ӷ��塢ͼƬת������������Զ���ͷ�ļ�
#include"crucial.h"//�������ṹ�嶨�弰���ֺ����Ķ�����Զ���ͷ�ļ�
#pragma comment(lib,"Winmm.lib")//�������ֲ��ź��������ݿ�

void getName(int steps) {//���û�ѡ�񱣴�ɼ�ʱִ�еĺ���
	FILE* f1;
	f1 = fopen("TopList.txt", "r+");//�򿪴����������ļ�
	char name[100];


	InputBox(name, 50, "��������������(����ʹ��Ӣ��)");//ͨ����ʾ���ȡ�û�����
	fseek(f1, 0, SEEK_END);
	fprintf(f1, "\n%s %d", name, steps);//���ļ�ĩβ������д���ļ�
	fclose(f1);//�ر��ļ�
	return;
}


void RulesMenu(int i) {
	IMAGE rules, back, menu,info;
	loadimage(&back, _T("image/background.png"), 900, 600);//���ر���ͼƬ
	loadimage(&rules, _T("image/DetailedRules.png"), 600, 400);//������Ϸ����ͼƬ
	loadimage(&menu, _T("image/exitToMenu.png"), 300, 250);//���ط������˵���ťͼƬ
	loadimage(&info, _T("image/AuthorInfo.png"), 600, 400);//����������Ϣ��ͼƬ
	
	
	putimage(0, 0, &back);//�������ͼƬ
	if (i == 1) { 
		drawAlpha(&rules, 150, 60); //���û�����鿴����ʱ
	}
	else drawAlpha(&info, 150, 60);//���û�����鿴����ʱ
	drawAlpha(&menu, 600, 450);//����������˵�ͼƬ


	MOUSEMSG m;
	while (true) {
		m = GetMouseMsg();//��ȡ�����Ϣ
		if (m.uMsg == WM_LBUTTONUP) {
			if (m.x > 630 && m.x < 880 && m.y >550 && m.y < 600) {//������������˵���ťʱ����
				return;//����
			}
		}
	}
}

void submenu(Point CheckerStatus[15][15]) {
	IMAGE background, title, circle, PVP, PVC, line, situation,top;

	loadimage(&background, _T("image/background.jpg"), 900, 600);//��ʾ����ͼƬ
	loadimage(&title, _T("image/title.png"), 400, 400);//��ʾ�������ֵ�ͼƬ
	loadimage(&circle, _T("image/temp.png"), 400, 400);//��ʾ����logo��ͼƬ
	loadimage(&PVP, _T("image/PVP.png"), 240, 200);//��ʾ���˶�ս���ֵ�ͼƬ
	loadimage(&PVC, _T("image/PVC.png"), 240, 200);//��ʾ�˻���ս���ֵ�ͼƬ
	loadimage(&line, _T("image/line.png"), 200, 15);//��ʾ�»��ߵ�ͼƬ
	loadimage(&top, _T("image/top.png"), 240, 200);//��ʾ�鿴�������ֵ�ͼƬ

	putimage(0, 0, &background);
	drawAlpha(&title, 10, 100);
	drawAlpha(&circle, 0, 100);
	drawAlpha(&PVP, 550, 50);
	drawAlpha(&PVC, 550, 200);
	drawAlpha(&top, 550, 350);//�������������
	getimage(&situation, 0, 0, 900, 600);//��ȡ��ǰ���ͼƬ

	MOUSEMSG m;
	while (true) {
		m = GetMouseMsg();//��ȡ�����Ϣ
		putimage(0, 0, &situation);
		if (m.uMsg == WM_LBUTTONUP) {
			if (m.x > 580 && m.x < 750 && m.y >130 && m.y < 170) {//��ѡ�����˶�սʱ
				CheckerBoard();//��ʾ����
				touch(CheckerStatus, 0, NULL);//��ʼ��ֶ�ս����������
				break;
			}
			if (m.x > 580 && m.x < 750 && m.y >270 && m.y < 330) {//��ѡ���˻���սʱ
				CheckerBoard();//��ʾ����
				Play(CheckerStatus, 0, NULL);//��ʼ��ֶ�ս���������
				break;
			}
			if (m.x > 580 && m.x < 750 && m.y >420 && m.y < 460) {//��ѡ��鿴����ʱ
				TopList();//��ʾ����
				break;
			}

		}
		if (m.uMsg == WM_MOUSEMOVE) {//�������ͣ��������ʱ��ʾ�»��߸�����ʾ
			if (m.x > 580 && m.x < 750 && m.y >120 && m.y < 160) {
				drawAlpha(&line, 590, 165);
				continue;
			}
			if (m.x > 580 && m.x < 750 && m.y >270 && m.y < 330) {
				drawAlpha(&line, 590, 315);
				continue;
			}
			if (m.x > 580 && m.x < 750 && m.y >420 && m.y < 460) {
				drawAlpha(&line, 590, 470);
				continue;
			}
		}
	}
	return;
}

void mainmenu(Point CheckerStatus[15][15]) {//��ʾ��������˵�
	IMAGE background,title,start,load,rules,exit,author,circle,musicon,musicoff,menu,line;
	loadimage(&background, _T("image/background.jpg"), 900, 600);//��ʾ����ͼƬ
	loadimage(&title, _T("image/title.png"), 400, 400);//��ʾ�������ֵ�ͼƬ
	loadimage(&start, _T("image/start.png"), 240, 200);//��ʾ��ʼ��Ϸ���ֵ�ͼƬ
	loadimage(&load, _T("image/load.png"), 240, 200);//��ʾ������Ϸ���ֵ�ͼƬ
	loadimage(&rules, _T("image/rules.png"), 240, 200);//��ʾ�����ͼƬ
	loadimage(&exit, _T("image/exit.png"), 240, 200);//��ʾ�˳���Ϸ��ͼƬ
	loadimage(&author, _T("image/author.png"), 240, 200);//��ʾ������Ϣ��ͼƬ
	loadimage(&circle, _T("image/temp.png"), 400, 400);//��ʾ����logo��ͼƬ
	loadimage(&musicon, _T("image/music1.png"), 50, 50);//��ʾ������ʱ��ͼƬ
	loadimage(&musicoff, _T("image/music2.png"), 50, 50);//��ʾ������ʱ��ͼƬ
	loadimage(&line, _T("image/line.png"), 200, 15);//��ʾ�»��ߵ�ͼƬ
	

	mciSendString("open background.mp3 alias mymusic", 0, 0, 0);//�������ļ�
	mciSendString("play mymusic repeat", 0, 0, 0);//ѭ����������

	int i, j, k = 0;//��i��j���к���ѭ������k��ʾ���ֲ���״̬

	while (true) {
		putimage(0, 0, &background);
		drawAlpha(&title, 10, 100);
		drawAlpha(&circle, 0, 100);
		drawAlpha(&start, 550, 50);
		drawAlpha(&load, 550, 150);
		drawAlpha(&rules, 550, 250);
		drawAlpha(&author, 550, 350);
		drawAlpha(&exit, 550, 450);//�����ϼ��ص�ͼƬȫ����ʾ
		getimage(&menu, 0, 0, 900, 600);
		if (k == 0) { 
			drawAlpha(&musicon, 0, 550);
		}
		else drawAlpha(&musicoff, 0, 550);//�����������޲��������ͬͼƬ

		
		MOUSEMSG m;
		while (true) {
			m = GetMouseMsg();//��ȡ�����Ϣ
			putimage(0, 0, &menu);
			if (k == 0) {
				drawAlpha(&musicon, 0, 550);
			}
			else drawAlpha(&musicoff, 0, 550);//�����������޲��������ͬͼƬ
			if (m.uMsg == WM_LBUTTONUP) {
				for (i = 0; i < 15; i++) {
					for (j = 0; j < 15; j++) {
						CheckerStatus[i][j].status = StatusBlank;
						CheckerStatus[i][j].row = i;
						CheckerStatus[i][j].line = j;//��ʼ���ṹ������
					}
				}
				if (m.x > 580 && m.x < 750 && m.y >130 && m.y < 170) {//������ʼ��Ϸʱ
					submenu(CheckerStatus);//�����Ӳ˵�
					break;
				}
				if (m.x > 580 && m.x < 750 && m.y >230 && m.y < 270) {//����������Ϸʱ
					loadGame(CheckerStatus);//����Ծ�
					break;
				}
				if (m.x > 580 && m.x < 750 && m.y >330 && m.y < 370) {//�鿴��Ϸ����ʱ
					RulesMenu(1);//��ʾ��Ϸ����
					break;
				}
				if (m.x > 580 && m.x < 750 && m.y >430 && m.y < 470) {//�鿴������Ϣʱ
					RulesMenu(2);//��ʾ������Ϣ
					break;
				}
				if (m.x > 580 && m.x < 750 && m.y >530 && m.y < 570) {//�����˳���Ϸʱ
					return;
				}
				if (m.x > 0 && m.x < 50 && m.y > 550 && m.y < 600) {//��������ֲ��Ű�ťʱ
					if (k == 0) {
						mciSendString("stop mymusic", 0, 0, 0);
						putimage(0, 0, &menu);
						drawAlpha(&musicoff, 0, 550);
						k = 1;
					}
					else {
						mciSendString("play mymusic repeat", 0, 0, 0);
						putimage(0, 0, &menu);
						drawAlpha(&musicon, 0, 550);
						k = 0;
					}//�����������޲��������ͬͼƬ���ı�kֵ
				}
			}
			if (m.uMsg == WM_MOUSEMOVE) {//�������ͣ��������ʱ��ʾ�»��߸�����ʾ
				if (m.x > 580 && m.x < 750 && m.y >130 && m.y < 170) {
					drawAlpha(&line, 590, 170);
					continue;
				}
				if (m.x > 580 && m.x < 750 && m.y >230 && m.y < 270) {
					drawAlpha(&line, 590, 270);
					continue;
				}
				if (m.x > 580 && m.x < 750 && m.y >330 && m.y < 370) {
					drawAlpha(&line, 590, 370);
					continue;
				}
				if (m.x > 580 && m.x < 750 && m.y >430 && m.y < 470) {
					drawAlpha(&line, 590, 470);
					continue;
				}
				if (m.x > 580 && m.x < 750 && m.y >530 && m.y < 570) {
					drawAlpha(&line, 590, 570);
					continue;
				}
			}
		}

		for (i = 0; i < 15; i++) {
			for (j = 0; j < 15; j++) {
				CheckerStatus[i][j].status = StatusBlank;
				CheckerStatus[i][j].row = i;
				CheckerStatus[i][j].line = j;
			}
		}//��ʼ���ṹ������
	}
	mciSendString("close mymusic", 0, 0, 0);//ֹͣ��������
}

void victorymenu(int i,Point *head,int steps) {//�����˻�ʤʱִ�еĺ���
	IMAGE background,victory,BlackWin,WhiteWin,rendering,exit,line,situation,save;
	loadimage(&background, _T("image/background.png"), 900, 600);//��ʾ����ͼƬ
	loadimage(&victory, _T("image/victory.png"), 380, 380);//��ʾʤ����logoͼƬ
	loadimage(&BlackWin, _T("image/blackWin.png"), 400, 400);//��ʾ�ڷ���ʤ������ͼƬ
	loadimage(&WhiteWin, _T("image/whiteWin.png"), 400, 400);//��ʾ�׷���ʤ������ͼƬ
	loadimage(&rendering, _T("image/rendering.png"), 300, 250);//��ʾ�ع�������ֵ�ͼƬ
	loadimage(&exit, _T("image/exitToMenu.png"), 300, 250);//��ʾ�˳����ֵ�ͼƬ
	loadimage(&line, _T("image/line.png"), 220, 20);//��ʾ�»���ͼƬ
	loadimage(&save, _T("image/SaveScore.png"), 300, 250);//��ʾ����ɼ�ͼƬ
	
	while (true) {
		putimage(0, 0, &background);
		drawAlpha(&victory, 80, 90);
		if (i == 2) {
			drawAlpha(&WhiteWin, 70, 90);
		}
		else drawAlpha(&BlackWin, 70, 90);
		drawAlpha(&rendering, 500, 0);
		drawAlpha(&save, 500, 150);
		drawAlpha(&exit, 500, 300);
		getimage(&situation, 0, 0, 900, 600);
		//������ͼƬ���

		MOUSEMSG m;
		while (true) {
			m = GetMouseMsg();//��ȡ�����Ϣ
			putimage(0, 0, &situation);
			if (m.uMsg == WM_LBUTTONUP) {
				if (m.x > 490 && m.x < 750 && m.y >90 && m.y < 150) {//������ع����ʱ
					Rendering(head);//�ع����ִ�еĺ���
					break;
				}
				if (m.x > 470 && m.x < 780 && m.y >245 && m.y < 300) {//���������ɼ�ʱ
					getName(steps);
					break;
				}
				if (m.x > 470 && m.x < 780 && m.y >400 && m.y < 450) {//������������˵�ʱ
					return;//����
				}
			}
			if (m.uMsg == WM_MOUSEMOVE) {//�������ͣ��������ʱ��ʾ�»��߸�����ʾ
				if (m.x > 490 && m.x < 750 && m.y >90 && m.y < 150) {
					drawAlpha(&line, 550, 150);
					continue;
				}
				if (m.x > 470 && m.x < 780 && m.y >245 && m.y < 300) {
					drawAlpha(&line, 540, 300);
					continue;
				}
				if (m.x > 470 && m.x < 780 && m.y >400 && m.y < 450) {
					drawAlpha(&line, 540, 450);
					continue;
				}
			}
		}
	}
}

