/*program name:menu.cpp
programmer:吕炎明
student number:19301014
date:2020-07-11
use:向用户展示菜单
*/

#include"mean.h"//包含棋子定义、图片转化函数定义的自定义头文件
#include"crucial.h"//包含各结构体定义及各种函数的定义的自定义头文件
#pragma comment(lib,"Winmm.lib")//进行音乐播放函数的数据库

void getName(int steps) {//当用户选择保存成绩时执行的函数
	FILE* f1;
	f1 = fopen("TopList.txt", "r+");//打开储存排名的文件
	char name[100];


	InputBox(name, 50, "请输入您的姓名(仅可使用英文)");//通过提示框获取用户姓名
	fseek(f1, 0, SEEK_END);
	fprintf(f1, "\n%s %d", name, steps);//在文件末尾将数据写入文件
	fclose(f1);//关闭文件
	return;
}


void RulesMenu(int i) {
	IMAGE rules, back, menu,info;
	loadimage(&back, _T("image/background.png"), 900, 600);//加载背景图片
	loadimage(&rules, _T("image/DetailedRules.png"), 600, 400);//加载游戏规则图片
	loadimage(&menu, _T("image/exitToMenu.png"), 300, 250);//加载返回主菜单按钮图片
	loadimage(&info, _T("image/AuthorInfo.png"), 600, 400);//加载作者信息的图片
	
	
	putimage(0, 0, &back);//输出背景图片
	if (i == 1) { 
		drawAlpha(&rules, 150, 60); //当用户点击查看规则时
	}
	else drawAlpha(&info, 150, 60);//当用户点击查看作者时
	drawAlpha(&menu, 600, 450);//输出返回主菜单图片


	MOUSEMSG m;
	while (true) {
		m = GetMouseMsg();//获取鼠标信息
		if (m.uMsg == WM_LBUTTONUP) {
			if (m.x > 630 && m.x < 880 && m.y >550 && m.y < 600) {//当点击返回主菜单按钮时返回
				return;//返回
			}
		}
	}
}

void submenu(Point CheckerStatus[15][15]) {
	IMAGE background, title, circle, PVP, PVC, line, situation,top;

	loadimage(&background, _T("image/background.jpg"), 900, 600);//显示背景图片
	loadimage(&title, _T("image/title.png"), 400, 400);//显示标题文字的图片
	loadimage(&circle, _T("image/temp.png"), 400, 400);//显示标题logo的图片
	loadimage(&PVP, _T("image/PVP.png"), 240, 200);//显示人人对战文字的图片
	loadimage(&PVC, _T("image/PVC.png"), 240, 200);//显示人机对战文字的图片
	loadimage(&line, _T("image/line.png"), 200, 15);//显示下划线的图片
	loadimage(&top, _T("image/top.png"), 240, 200);//显示查看排名文字的图片

	putimage(0, 0, &background);
	drawAlpha(&title, 10, 100);
	drawAlpha(&circle, 0, 100);
	drawAlpha(&PVP, 550, 50);
	drawAlpha(&PVC, 550, 200);
	drawAlpha(&top, 550, 350);//将以上文字输出
	getimage(&situation, 0, 0, 900, 600);//获取当前棋局图片

	MOUSEMSG m;
	while (true) {
		m = GetMouseMsg();//获取鼠标信息
		putimage(0, 0, &situation);
		if (m.uMsg == WM_LBUTTONUP) {
			if (m.x > 580 && m.x < 750 && m.y >130 && m.y < 170) {//当选择人人对战时
				CheckerBoard();//显示棋盘
				touch(CheckerStatus, 0, NULL);//开始棋局对战，黑棋先走
				break;
			}
			if (m.x > 580 && m.x < 750 && m.y >270 && m.y < 330) {//当选择人机对战时
				CheckerBoard();//显示棋盘
				Play(CheckerStatus, 0, NULL);//开始棋局对战，玩家先走
				break;
			}
			if (m.x > 580 && m.x < 750 && m.y >420 && m.y < 460) {//当选择查看排名时
				TopList();//显示排名
				break;
			}

		}
		if (m.uMsg == WM_MOUSEMOVE) {//当鼠标悬停在文字上时显示下划线给予提示
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

void mainmenu(Point CheckerStatus[15][15]) {//显示程序的主菜单
	IMAGE background,title,start,load,rules,exit,author,circle,musicon,musicoff,menu,line;
	loadimage(&background, _T("image/background.jpg"), 900, 600);//显示背景图片
	loadimage(&title, _T("image/title.png"), 400, 400);//显示标题文字的图片
	loadimage(&start, _T("image/start.png"), 240, 200);//显示开始游戏文字的图片
	loadimage(&load, _T("image/load.png"), 240, 200);//显示载入游戏文字的图片
	loadimage(&rules, _T("image/rules.png"), 240, 200);//显示规则的图片
	loadimage(&exit, _T("image/exit.png"), 240, 200);//显示退出游戏的图片
	loadimage(&author, _T("image/author.png"), 240, 200);//显示作者信息的图片
	loadimage(&circle, _T("image/temp.png"), 400, 400);//显示标题logo的图片
	loadimage(&musicon, _T("image/music1.png"), 50, 50);//显示音量开时的图片
	loadimage(&musicoff, _T("image/music2.png"), 50, 50);//显示音量关时的图片
	loadimage(&line, _T("image/line.png"), 200, 15);//显示下划线的图片
	

	mciSendString("open background.mp3 alias mymusic", 0, 0, 0);//打开音乐文件
	mciSendString("play mymusic repeat", 0, 0, 0);//循环播放音乐

	int i, j, k = 0;//用i和j进行后续循环、用k表示音乐播放状态

	while (true) {
		putimage(0, 0, &background);
		drawAlpha(&title, 10, 100);
		drawAlpha(&circle, 0, 100);
		drawAlpha(&start, 550, 50);
		drawAlpha(&load, 550, 150);
		drawAlpha(&rules, 550, 250);
		drawAlpha(&author, 550, 350);
		drawAlpha(&exit, 550, 450);//将以上加载的图片全部显示
		getimage(&menu, 0, 0, 900, 600);
		if (k == 0) { 
			drawAlpha(&musicon, 0, 550);
		}
		else drawAlpha(&musicoff, 0, 550);//根据音乐有无播放输出不同图片

		
		MOUSEMSG m;
		while (true) {
			m = GetMouseMsg();//获取鼠标信息
			putimage(0, 0, &menu);
			if (k == 0) {
				drawAlpha(&musicon, 0, 550);
			}
			else drawAlpha(&musicoff, 0, 550);//根据音乐有无播放输出不同图片
			if (m.uMsg == WM_LBUTTONUP) {
				for (i = 0; i < 15; i++) {
					for (j = 0; j < 15; j++) {
						CheckerStatus[i][j].status = StatusBlank;
						CheckerStatus[i][j].row = i;
						CheckerStatus[i][j].line = j;//初始化结构体数组
					}
				}
				if (m.x > 580 && m.x < 750 && m.y >130 && m.y < 170) {//单击开始游戏时
					submenu(CheckerStatus);//进入子菜单
					break;
				}
				if (m.x > 580 && m.x < 750 && m.y >230 && m.y < 270) {//单击载入游戏时
					loadGame(CheckerStatus);//载入对局
					break;
				}
				if (m.x > 580 && m.x < 750 && m.y >330 && m.y < 370) {//查看游戏规则时
					RulesMenu(1);//显示游戏规则
					break;
				}
				if (m.x > 580 && m.x < 750 && m.y >430 && m.y < 470) {//查看作者信息时
					RulesMenu(2);//显示作者信息
					break;
				}
				if (m.x > 580 && m.x < 750 && m.y >530 && m.y < 570) {//单击退出游戏时
					return;
				}
				if (m.x > 0 && m.x < 50 && m.y > 550 && m.y < 600) {//当点击音乐播放按钮时
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
					}//根据音乐有无播放输出不同图片并改变k值
				}
			}
			if (m.uMsg == WM_MOUSEMOVE) {//当鼠标悬停在文字上时显示下划线给予提示
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
		}//初始化结构体数组
	}
	mciSendString("close mymusic", 0, 0, 0);//停止播放音乐
}

void victorymenu(int i,Point *head,int steps) {//当有人获胜时执行的函数
	IMAGE background,victory,BlackWin,WhiteWin,rendering,exit,line,situation,save;
	loadimage(&background, _T("image/background.png"), 900, 600);//显示背景图片
	loadimage(&victory, _T("image/victory.png"), 380, 380);//显示胜利的logo图片
	loadimage(&BlackWin, _T("image/blackWin.png"), 400, 400);//显示黑方获胜的文字图片
	loadimage(&WhiteWin, _T("image/whiteWin.png"), 400, 400);//显示白方获胜的文字图片
	loadimage(&rendering, _T("image/rendering.png"), 300, 250);//显示回顾棋局文字的图片
	loadimage(&exit, _T("image/exitToMenu.png"), 300, 250);//显示退出文字的图片
	loadimage(&line, _T("image/line.png"), 220, 20);//显示下划线图片
	loadimage(&save, _T("image/SaveScore.png"), 300, 250);//显示保存成绩图片
	
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
		//将以上图片输出

		MOUSEMSG m;
		while (true) {
			m = GetMouseMsg();//获取鼠标信息
			putimage(0, 0, &situation);
			if (m.uMsg == WM_LBUTTONUP) {
				if (m.x > 490 && m.x < 750 && m.y >90 && m.y < 150) {//当点击回顾棋局时
					Rendering(head);//回顾棋局执行的函数
					break;
				}
				if (m.x > 470 && m.x < 780 && m.y >245 && m.y < 300) {//当点击保存成绩时
					getName(steps);
					break;
				}
				if (m.x > 470 && m.x < 780 && m.y >400 && m.y < 450) {//当点击返回主菜单时
					return;//返回
				}
			}
			if (m.uMsg == WM_MOUSEMOVE) {//当鼠标悬停在文字上时显示下划线给予提示
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

