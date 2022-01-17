/*program name:rendering.cpp
programmer:吕炎明
student number:19301014
date:2020-07-11
use:回顾棋局
*/

#include"mean.h"//包含棋子定义、图片转化函数定义的自定义头文件
#include"crucial.h"//包含各结构体定义及各种函数的定义的自定义头文件

Point* Creat(Point temp) {//为链表添加新节点的函数，便于实现棋局回顾功能
	Point* New = (Point*)malloc(sizeof(Point));
	New->next = NULL;
	New->line = temp.line;
	New->row = temp.row;
	New->status = temp.status;//将传入的结构体各值赋给新节点
	return New;//返回新节点的地址
}

int Rendering(Point* head) {//用于回顾棋局对战的函数
	IMAGE black, white,situation, BlackTurn, WhiteTurn;

	loadimage(&black, _T("image/black.png"), 20, 20);
	loadimage(&white, _T("image/white.png"), 20, 20);
	loadimage(&BlackTurn, _T("image/blackTurn.png"), 300, 250);
	loadimage(&WhiteTurn, _T("image/WhiteTurn.png"), 300, 250);
	//加载棋子图片及“黑/白棋回合”文字的图片

	int k = 0,row,line;//k用于判断走黑还是白棋，row和line表示行数列数
	CheckerBoard();//显示棋盘
	getimage(&situation, 0, 0, 900, 600);//获取当前棋局图片

	while (head->next != NULL) {//循环直至链表末尾
		putimage(0, 0, &situation);//展示当前棋局图片
		head = head->next;//后移指针
		row = head->row * 25 + 150;
		line = head->line * 25 + 100;//将像素点位置转化为行数和列数
		if (head->status == StatusBlack) {
			drawAlpha(&black, row - 10, line - 10);
			//输出黑棋图片
		}
		else if (head->status == StatusWhite) {
			drawAlpha(&white, row - 10, line - 10);//输出白棋图片
		}
		else continue;
		getimage(&situation, 0, 0, 900, 600);//获取当前棋局图片
		if (head->status == StatusBlack) {
			drawAlpha(&BlackTurn, 550, 50);//显示当前为黑棋回合
		}
		else drawAlpha(&WhiteTurn, 550, 50);//显示当前为白棋回合
		k++;
		k %= 2;//使k不断在0和1间循环
		Sleep(1000);//程序停顿
	}
	return 0;
}

