/*program name:TopList.cpp
programmer:吕炎明
student number:19301014
date:2020-07-11
use:查看和修改排名执行的函数
*/
#include"mean.h"//包含棋子定义、图片转化函数定义的自定义头文件
#include"crucial.h"//包含各结构体定义及各种函数的定义的自定义头文件

int TopList() {
	FILE* f1;
	f1 = fopen("TopList.txt", "r+");
	fseek(f1, 0, SEEK_SET);//打开排名文件并移动至开头

	Top* head = (Top*)malloc(sizeof(Top));
	Top* link = head;//设置链表头指针


	LOGFONT f;
	f.lfHeight = 40;
	f.lfWeight = 0;
	f.lfOrientation = 0;
	_tcscpy(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);//对字体的各项参数进行调整


	IMAGE background, call, rank, score,menu;//加载图片
	loadimage(&background, _T("image/background.jpg"), 900, 600);//加载背景图片
	loadimage(&call, _T("image/name.png"), 200, 160);//加载姓名文字的图片
	loadimage(&rank, _T("image/rank.png"), 200, 160);//加载排名文字的图片
	loadimage(&score, _T("image/score.png"), 200, 160);//加载步数文字的图片
	loadimage(&menu, _T("image/exitToMenu.png"), 300, 250);//加载返回主菜单的图片


	putimage(0, 0, &background);
	drawAlpha(&call, 320, 50);
	drawAlpha(&rank, 160, 50);
	drawAlpha(&score, 470, 50);
	drawAlpha(&menu, 600, 450);//将以上图片输出


	
	int total = 0;//用于记录总步数
	
	while (true) {
		Top* TempValue = (Top*)malloc(sizeof(Top));
		fscanf(f1, "%s %d", &TempValue->name, &TempValue->steps);//从文件中读取数据
		TempValue->next = NULL;
		link->next = TempValue;
		link = link->next;//为链表新建节点并赋予读取的值
		total++;
		if (feof(f1))
			break;//当读取至文件末尾时结束循环
	}
	setbkmode(TRANSPARENT);//设置文字背景透明
	settextcolor(BLACK);//设置文字颜色
	
	Top temp;
	Top* p1;
	Top* p2;//通过冒泡排序将链表按照步数从小到大的顺序排列
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
		total = 5;//当总数据大于5时只输出前5名

	TCHAR Rank[5];//用于名次的输出
	TCHAR num[5];//用于将步数输出
	int TempSteps;//用于承载链表每一节的步数
	int i;
	Top* head3 = head;//获取链表头指针
	for (i = 0; i < total; i++) {
		if (head3->next == NULL) {
			break;//当输出至链表末尾时结束
		}
		head3 = head3->next;
		TempSteps = head3->steps;
		_stprintf_s(Rank, _T("%d"), i + 1);
		_stprintf_s(num, _T("%d"), TempSteps);
		outtextxy(380, 150 + 65 * i, head3->name);
		outtextxy(560, 150 + 65 * i, num);
		outtextxy(230, 150 + 65 * i, Rank);//将玩家的姓名、排名、步数全部输出
	}

	MOUSEMSG m;
	while (true) {
		m = GetMouseMsg();//获取鼠标信息
		if (m.uMsg == WM_LBUTTONUP) {
			if (m.x > 630 && m.x < 880 && m.y >550 && m.y < 600) {//当点击返回主菜单按钮时返回
				break;//返回
			}
		}
	}

	fclose(f1);//关闭文件
	return 0;
}