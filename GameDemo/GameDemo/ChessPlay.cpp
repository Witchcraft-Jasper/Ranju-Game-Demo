/*program name:ChessPlay.cpp
programmer:吕炎明
student number:19301014
date:2020-07-11
use:用于进行棋局对战
*/

#include"mean.h"//包含棋子定义、图片转化函数定义的自定义头文件
#include"crucial.h"//包含各结构体定义及各种函数的定义的自定义头文件

void PrintAgain(Point CheckerStatus[15][15]) {
	IMAGE black, white, save, musicon, musicoff, undo, Noundo;
	loadimage(&black, _T("image/black.png"), 20, 20);//加载黑棋图片
	loadimage(&white, _T("image/white.png"), 20, 20);//加载白棋图片
	loadimage(&save, _T("image/save.png"), 300, 250);//加载保存棋局文字的图片
	loadimage(&undo, _T("image/undo.png"), 300, 250);//加载悔棋文字图片

	CheckerBoard();//显示棋盘
	drawAlpha(&save, 500, 150);//显示图片
	drawAlpha(&undo, 500, 50);


	int i, j, row, line;//i、j用户循环 row、line用于将位置确定
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			row = i * 25 + 150;
			line = j * 25 + 100;//将数组中坐标转化为像素位置

			if (CheckerStatus[i][j].status != StatusBlank) {
				if (CheckerStatus[i][j].status == StatusBlack) {
					drawAlpha(&black, row - 10, line - 10);
				}
				else drawAlpha(&white, row - 10, line - 10);//根据数据在棋盘添加棋子
			}
		}
	}
	return;
}

void CheckerBoard()//显示棋盘的函数
{
	IMAGE back,black,white;
	loadimage(&back, _T("image/background.png"), 900, 600);//加载背景图片
	putimage(0, 0, &back);

	int i;
	setlinecolor(BLACK);//设置画线颜色

	for (i = 0; i < 15; i++) {
		line(150, 100 + 25 * i, 500, 100 + 25 * i);
		line(150 + 25 * i, 100, 150 + 25 * i, 450);//画棋盘线
	}
	for (i = 0; i < 5; i++) {
		line(138, 88 + i, 512, 88 + i);
		line(138 + i, 88, 138 + i, 462);
		line(512 - i, 88, 512 - i, 462);
		line(138, 462 - i, 512, 462 - i);//画边框线
	}

	setbkmode(TRANSPARENT);//设置文字背景透明
	settextcolor(BLACK);//设置文字颜色

	char s = 'A';
	TCHAR num[5];
	for (i = 0; i < 15; i++) {
		_stprintf_s(num, _T("%d"), i + 1);
		outtextxy(148 + 25 * i, 73, s);
		outtextxy(120, 96 + 25 * i, num);//画行数和列数标记
		s++;
	}
	return;
}

int touch(Point CheckerStatus[15][15],int j,Point * head1) {//进行棋局的函数
	IMAGE black, white, save, musicon, musicoff, undo, Noundo, situation, line1, line2;
	loadimage(&black, _T("image/black.png"), 20, 20);//加载黑棋图片
	loadimage(&white, _T("image/white.png"), 20, 20);//加载白棋图片
	loadimage(&save, _T("image/save.png"), 300, 250);//加载保存棋局文字的图片
	loadimage(&undo, _T("image/undo.png"), 300, 250);//加载悔棋图片
	loadimage(&Noundo, _T("image/NoUndo.png"), 300, 250);//加载无法悔棋提示图片
	loadimage(&line1, _T("image/line.png"), 200, 15);
	loadimage(&line2, _T("image/line.png"), 150, 15);//加载不同规格下划线
	
	Point* head = (Point*)malloc(sizeof(Point));//设置链表头指针
	Point* link = head;
	if (head1 == NULL) {
		Point* link = head;
	}
	else {
		head = head1;
		Point* link = head;
		while (link->next != NULL) {
			link = link->next;//根据情况将链表完善
		}
	}

	int row = -1,line = -1,temp,k = 0;
	MOUSEMSG m;
	drawAlpha(&save, 500, 150);//显示图片
	drawAlpha(&undo, 500, 50);
	getimage(&situation, 0, 0, 900, 600);//获取棋局图片

	while (true) {
		m = GetMouseMsg();//获取鼠标信息
		
		if (m.uMsg == WM_LBUTTONUP) {
			if (m.x > 550 && m.x < 750 && m.y>240 && m.y < 300) {//如果点击保存棋局
				saveGame(head);//执行保存棋局函数
				return 0;
			}
			if (m.x > 600 && m.x < 700 && m.y>140 && m.y < 200) {//如果点击悔棋
				Point* Undo1, * Undo2;
				Undo1 = head;
				Undo2 = Undo1->next;
				//CheckerStatus[Undo2->row][Undo2->line].status = StatusBlank;
				if ((row == -1) || (line == -1) || Undo1->next == NULL) {//当无法继续悔棋时
					drawAlpha(&Noundo, 450, 50);//给予提示
					Sleep(1000);//进行停顿
					PrintAgain(CheckerStatus);//重新输出棋盘当前情况
					continue;
				}
				while (Undo2->next != NULL) {
					Undo1 = Undo2;
					Undo2 = Undo1->next;
				}
				CheckerStatus[Undo2->row][Undo2->line].status = StatusBlank;
				Undo1->next = NULL;
				link = Undo1;
				free(Undo2);
				PrintAgain(CheckerStatus);//当可以悔棋时删除链表最新节点
				getimage(&situation, 0, 0, 900, 600);
				j--;//总步数减少
				continue;
			}


			if (m.x % 25 >= 12.5)
				m.x += 25;
			m.x /= 25;
			m.x *= 25;
			if (m.y % 25 >= 12.5)
				m.y += 25;
			m.y /= 25;
			m.y *= 25;
			//通过坐标变化保证落在棋盘交叉线处


			if (JudgeChecker(CheckerStatus, m.x, m.y) == 0) {//判断落子是否在合理位置
				Sleep(1000);
				putimage(0, 0, &situation);
				continue;
			}

			row = (m.x - 150) / 25;
			line = (m.y - 100) / 25;//将像素点坐标转化为行数和列数
			
			if (j % 2 == 0) {
				drawAlpha(&black, m.x - 10, m.y - 10);
				CheckerStatus[row][line].status = StatusBlack;
			}
			else {
				drawAlpha(&white, m.x - 10, m.y - 10);
				CheckerStatus[row][line].status = StatusWhite;
			}//显示棋子图片并修改结构体信息

			link->next = Creat(CheckerStatus[row][line]);//为链表新建节点
			link = link->next;
			j++;//总步数增加
			getimage(&situation, 0, 0, 900, 600);
			temp = WhetherWin(CheckerStatus, row, line);//判断是否获胜
			if (temp != 0) {
				victorymenu(temp, head,j);//显示获胜菜单
				break;
			}
		}

		if (m.uMsg == WM_MOUSEMOVE) {//当鼠标悬停在文字上时显示下划线给予提示
			if (m.x > 550 && m.x < 750 && m.y>240 && m.y < 300) {
				drawAlpha(&line1, 560, 295);
				continue;
			}
			if (m.x > 600 && m.x < 700 && m.y>140 && m.y < 200) {
				drawAlpha(&line2, 600, 195);
				continue;
			}
			putimage(0, 0, &situation);


		}
	}
	return 0;
}

void saveGame(Point* head) {//保存游戏执行的函数
	FILE* fp;
	fp = fopen( "ChessGame.txt", "r+");
	fseek(fp, 0, SEEK_SET);//打开文件并移至开头


	while (head->next != NULL) {
		head = head->next;
		if (head->status == StatusBlank) {
			continue;
		}
		fprintf(fp, "%d %d %d\n", head->status,
			head->row, head->line);//将数据写入文件
	}
	IMAGE background, circle, save,exit;
	loadimage(&background, _T("image/background.png"), 900, 600);//加载背景图片
	loadimage(&circle, _T("image/victory.png"), 380, 380);//加载logo
	loadimage(&exit, _T("image/exitToMenu.png"), 300, 250);//加载返回文字图片
	loadimage(&save, _T("image/SaveOK.png"), 400, 400);//加载保存成功文字图片


	putimage(0, 0, &background);
	drawAlpha(&circle, 80, 90);
	drawAlpha(&save, 70, 90);
	drawAlpha(&exit, 500, 100);//将图片显示

	MOUSEMSG m;
	while (true) {
		m = GetMouseMsg();//获取鼠标信息
		if (m.uMsg == WM_LBUTTONUP) {
			if (m.x > 490 && m.x < 750 && m.y >200 && m.y < 250) {
				break;
			}
			//在单击返回时返回
		}
	}
	fclose(fp);//关闭文件
	return;
}

void loadGame(Point CheckerStatus[15][15]) {//加载游戏执行的函数
	IMAGE black, white;
	loadimage(&black, _T("image/black.png"), 20, 20);
	loadimage(&white, _T("image/white.png"), 20, 20);//加载黑白棋图片

	Point* head = (Point*)malloc(sizeof(Point));//设置链表头指针
	Point* link = head;

	FILE* fp;
	fp = fopen("ChessGame.txt", "r+");//打开文件
	fseek(fp, 0, SEEK_SET);
	int chess,row,line,num = 0,i,j;
	while (true) {
		fscanf(fp, "%d %d %d", &chess, &row, &line);
		CheckerStatus[row][line].status = chess;//从文件读取数据
		if (chess != StatusBlank)
			num++;
		link->next = Creat(CheckerStatus[row][line]);//为链表新建节点
		link = link->next;
		if (feof(fp))
			break;
	}
	num -= 1;//获取总数据数
	CheckerBoard();
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			row = i * 25 + 150;
			line = j * 25 + 100;
			if (CheckerStatus[i][j].status != StatusBlank) {
				if (CheckerStatus[i][j].status == StatusBlack) {
					drawAlpha(&black, row - 10, line - 10);
				}
				else if (CheckerStatus[i][j].status == StatusWhite) {
					drawAlpha(&white, row - 10, line - 10);
				}//根据数据在棋盘添加棋子
				else continue;
			}
		}
	}
	touch(CheckerStatus, num, head);//执行棋局
	fclose(fp);
	return;
}
