/*program name:WhetherWin.cpp
programmer:吕炎明
student number:19301014
date:2020-07-11
use:判断用户是否取得胜利
*/

#include"mean.h"//包含棋子定义、图片转化函数定义的自定义头文件
#include"crucial.h"//包含各结构体定义及各种函数的定义的自定义头文件

int HorizontalWin(Point CheckerStatus[][15], int row, int line) {//判断水平取胜的函数
	int temp = line - 1;
	int counter = 1;
	while (temp >= 0) {
		if (CheckerStatus[row][temp].status == CheckerStatus[row][line].status) {
			temp--;
			counter++;
		}
		else break;
	}
	temp = line + 1;
	while (temp <= 14) {
		if (CheckerStatus[row][temp].status == CheckerStatus[row][line].status) {
			temp++;
			counter++;
		}
		else break;
	}
	//分别循环看棋子左右两侧棋子相连数

	return counter;//返回棋子相连数
}

int VerticalWin(Point CheckerStatus[][15], int row, int line) {//判断垂直取胜时执行的函数
	int temp = row - 1;
	int counter = 1;
	while (temp >= 0) {
		if (CheckerStatus[temp][line].status == CheckerStatus[row][line].status) {
			temp--;
			counter++;
		}
		else break;
	}
	temp = row + 1;
	while (temp <= 14) {
		if (CheckerStatus[temp][line].status == CheckerStatus[row][line].status) {
			temp++;
			counter++;
		}
		else break;
	}
	//分别循环看棋子上下两侧棋子相连数

	return counter;//返回棋子相连数
}

int DiagonalWin(Point CheckerStatus[][15], int row, int line) {//棋子对角线取胜执行的函数
	int temp1 = row - 1;
	int temp2 = line - 1;
	int counter = 1;
	while (temp1 >= 0 && temp2 >= 0) {
		if (CheckerStatus[temp1][temp2].status == CheckerStatus[row][line].status) {
			temp1--;
			temp2--;
			counter++;
		}
		else break;
	}
	temp1 = row + 1;
	temp2 = line + 1;
	while (temp1 <= 14 && temp2 <= 14) {
		if (CheckerStatus[temp1][temp2].status == CheckerStatus[row][line].status) {
			temp1++;
			temp2++;
			counter++;
		}
		else break;
	}
	//分别循环看左上角和右下角棋子相连数

	return counter;//返回棋子相连数
}

int OppoDiagonalWin(Point CheckerStatus[][15], int row, int line) {//棋子反对角取胜执行函数
	int temp1 = row - 1;
	int temp2 = line + 1;
	int counter = 1;
	while (temp1 >= 0 && temp2 <= 14) {
		if (CheckerStatus[temp1][temp2].status == CheckerStatus[row][line].status) {
			temp1--;
			temp2++;
			counter++;
		}
		else break;
	}
	temp1 = row + 1;
	temp2 = line - 1;
	while (temp1 <= 14 && temp2 >= 0) {
		if (CheckerStatus[temp1][temp2].status == CheckerStatus[row][line].status) {
			temp1++;
			temp2--;
			counter++;
		}
		else break;
	}
	//分别循环看右上角和左下角执行的函数

	return counter;//返回棋子相连数
}

int WhetherDraw(Point CheckerStatus[][15]) {//判断是否平局执行的函数
	int i, j;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			if (CheckerStatus[i][j].status != StatusBlank)
				return 0;
		}
	}
	return 1;
}

int WhetherWin(Point CheckerStatus[][15], int row, int line) {//判断是否取胜执行函数
	int value = 0;
	value = HorizontalWin(CheckerStatus, row, line);
	if (value >= 5) {
		if (CheckerStatus[row][line].status == StatusBlack)
			return 1;
		else return 2;
	}
	value = VerticalWin(CheckerStatus, row, line);
	if (value >= 5) {
		if (CheckerStatus[row][line].status == StatusBlack)
			return 1;
		else return 2;
	}
	value = DiagonalWin(CheckerStatus, row, line);
	if (value >= 5) {
		if (CheckerStatus[row][line].status == StatusBlack)
			return 1;
		else return 2;
	}
	value = OppoDiagonalWin(CheckerStatus, row, line);
	if (value >= 5) {
		if (CheckerStatus[row][line].status == StatusBlack)
			return 1;
		else return 2;
	}
	//分别执行以上函数看是否取胜并根据获胜棋子颜色返回不同值

	if (WhetherDraw(CheckerStatus))//看是否平局
		return 3;
	return 0;
}

int JudgeChecker(Point CheckerStatus[][15], int x, int y) {//判断是否落子到界外和重复落子的函数
	IMAGE occupy, outside;
	loadimage(&occupy, _T("image/occupy2.png"), 300, 200);//加载此处已落子文字的图片
	loadimage(&outside, _T("image/outside2.png"), 300, 200);//加载请不要在界外落子文字的图片
	if (x < 150 || y < 100 || x> 500 || y > 450) {
		drawAlpha(&outside, 530, 0);
		return 0;
	}
	else if (CheckerStatus[(x - 150) / 25][(y - 100) / 25].status != StatusBlank) {
		drawAlpha(&occupy, 530, 0);
		return 0;
	}//根据不同位置确定落子是否符合标准
	else return 1;
}