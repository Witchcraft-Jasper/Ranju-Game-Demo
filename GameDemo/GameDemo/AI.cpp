/*program name:AI.cpp
programmer:吕炎明
student number:19301014
date:2020-07-11
use:用于电脑进行判断下棋位置
*/

#include"mean.h"//包含棋子定义、图片转化函数定义的自定义头文件
#include"crucial.h"//包含各结构体定义及各种函数的定义的自定义头文件
#include<time.h>//用于生成随机数

int HorizontalJudge(Point CheckerStatus[][15], int row, int line,int color) {//判断水平的函数
	int temp = line - 1;
	int counter = 1;
	int value = 0;
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;//获取自己和对方的颜色
	}
	while (temp >= 0) {
		if (CheckerStatus[row][temp].status == Comcolor) {
			temp--;
			counter++;
			if (temp < 0) {
				value++;
				break;
			}
		}
		else if (CheckerStatus[row][temp].status == color) {
			value++;
			break;
		}
		else break;
	}
	temp = line + 1;
	while (temp <= 14) {
		if (CheckerStatus[row][temp].status == Comcolor) {
			temp++;
			counter++;
			if (temp > 14) {
				value++;
				break;
			}
		}
		else if (CheckerStatus[row][temp].status == color) {
			value++;
			break;
		}
		else break;
	}
	if (value == 2)
		counter = 0;//当棋盘左右两侧都有棋子时返回0
	//分别循环看棋子左右两侧棋子相连数
	return counter;//返回棋子相连数
}

int VerticalJudge(point CheckerStatus[][15], int row, int line,int color) {//判断垂直时执行的函数
	int temp = row - 1;
	int counter = 1;
	int value = 0;
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;//获取自己和对方的颜色
	}
	while (temp >= 0) {
		if (CheckerStatus[temp][line].status == Comcolor) {
			temp--;
			counter++;
			if (temp < 0) {
				value++;
				break;
			}
		}
		else if (CheckerStatus[temp][line].status == color) {
			value++;
			break;
		}
		else break;
	}
	temp = row + 1;
	while (temp <= 14) {
		if (CheckerStatus[temp][line].status == Comcolor) {
			temp++;
			counter++;
			if (temp > 14) {
				value++;
				break;
			}
		}
		else if (CheckerStatus[temp][line].status == color) {
			value++;
			break;
		}
		else break;
	}
	//分别循环看棋子上下两侧棋子相连数
	if (value == 2)
		counter = 0;//当棋盘左右两侧都有棋子时返回0

	return counter;//返回棋子相连数
}

int DiagonalJudge(Point CheckerStatus[][15], int row, int line,int color) {//棋子对角线取胜执行的函数
	int temp1 = row - 1;
	int temp2 = line - 1;
	int counter = 1;
	int value = 0;
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;
	}//获取自己和对方的颜色
	while (temp1 >= 0 && temp2 >= 0) {
		if (CheckerStatus[temp1][temp2].status == Comcolor) {
			temp1--;
			temp2--;
			counter++;
			if (temp1 < 0||temp2 < 0){
				value++;
				break;
			}
		}
		else if (CheckerStatus[temp1][temp2].status == color) {
			value++;
			break;
		}
		else break;
	}
	temp1 = row + 1;
	temp2 = line + 1;
	while (temp1 <= 14 && temp2 <= 14) {
		if (CheckerStatus[temp1][temp2].status == Comcolor) {
			temp1++;
			temp2++;
			counter++;
			if (temp1 > 14 || temp2 > 14) {
				value++;
				break;
			}
		}
		else if (CheckerStatus[temp1][temp2].status == color) {
			value++;
			break;
		}
		else break;
	}
	//分别循环看左上角和右下角棋子相连数
	if (value == 2)
		counter = 0;//当棋盘左右两侧都有棋子时返回0
	return counter;//返回棋子相连数
}

int OppoDiagonalJudge(Point CheckerStatus[][15], int row, int line, int color) {//棋子反对角执行函数
	int temp1 = row - 1;
	int temp2 = line + 1;
	int counter = 1;
	int value = 0;
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;//获取自己和对方的颜色
	}
	while (temp1 >= 0 && temp2 <= 14) {
		if (CheckerStatus[temp1][temp2].status == Comcolor) {
			temp1--;
			temp2++;
			counter++;
			if (temp1 < 0 || temp2 > 14) {
				value++;
				break;
			}
		}
		else if (CheckerStatus[temp1][temp2].status == color) {
			value++;
			break;
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
			if (temp1 > 14 || temp2 < 0) {
				value++;
				break;
			}
		}
		else if (CheckerStatus[temp1][temp2].status == Comcolor) {
			value++;
			break;
		}
		else break;
	}
	//分别循环看右上角和左下角执行的函数
	if (value == 2)
		counter = 0;//当棋盘左右两侧都有棋子时返回0
	return counter;//返回棋子相连数
}

int Defend(Point CheckerStatus[][15], int row, int line, int color,int mode) {//进行防守的函数
	switch (mode) {//获取防守方式
		//通过返回点的坐标来确定落子位置
	case 1: {//水平防守
		int tempLine = line - 1;
		for (; tempLine >= 0; tempLine--) {
			if (CheckerStatus[row][tempLine].status == color)
				break;
			if (CheckerStatus[row][tempLine].status == StatusBlank) {
				return (row * 100 + tempLine);
			}
		}
		tempLine = line + 1;
		for (; tempLine <= 14; tempLine++) {
			if (CheckerStatus[row][tempLine].status == color)
				break;
			if (CheckerStatus[row][tempLine].status == StatusBlank) {
				return (row * 100 + tempLine);
			}
		}
	}
	case 2: {//垂直防守
		int tempRow = row - 1;
		for (; tempRow >= 0; tempRow--) {
			if (CheckerStatus[tempRow][line].status == color)
				break;
			if (CheckerStatus[tempRow][line].status == StatusBlank) {
				return (tempRow * 100 + line);
			}
		}
		tempRow = row + 1;
		for (; tempRow <= 14; tempRow++) {
			if (CheckerStatus[tempRow][line].status == color)
				break;
			if (CheckerStatus[tempRow][line].status == StatusBlank) {
				return (tempRow * 100 + line);
			}
		}
	}
	case 3: {//对角防守
		int tempRow = row - 1;
		int tempLine = line - 1;
		for (; tempRow >= 0 && tempLine >= 0; tempRow--, tempLine--) {
			if (CheckerStatus[tempRow][tempLine].status == color)
				break;
			if (CheckerStatus[tempRow][tempLine].status == StatusBlank) {
				return (tempRow * 100 + tempLine);
			}
		}
		tempRow = row + 1;
		tempLine = line + 1;
		for (; tempRow <= 14 && tempLine <= 14; tempRow++, tempLine++) {
			if (CheckerStatus[tempRow][tempLine].status == color)
				break;
			if (CheckerStatus[tempRow][tempLine].status == StatusBlank) {
				return (tempRow * 100 + tempLine);
			}
		}
	}
	case 4: {//反对角防守
		int tempRow = row - 1;
		int tempLine = line + 1;
		for (; tempRow >= 0 && tempLine <= 14; tempRow--, tempLine++) {
			if (CheckerStatus[tempRow][tempLine].status == color)
				break;
			if (CheckerStatus[tempRow][tempLine].status == StatusBlank) {
				return (tempRow * 100 + tempLine);
			}
		}
		tempRow = row + 1;
		tempLine = line - 1;
		for (; tempRow <= 14 && tempLine >= 0; tempRow++, tempLine--) {
			if (CheckerStatus[tempRow][tempLine].status == color)
				break;
			if (CheckerStatus[tempRow][tempLine].status == StatusBlank) {
				return (tempRow * 100 + tempLine);
			}
		}
	}
	}
}

int Attack(Point CheckerStatus[][15], int row, int line, int color, int mode) {//进行进攻的函数
	switch (mode) {//获取进攻方式
		//通过返回点的坐标来确定落子位置
	case 1: {//水平进攻
		int tempLine = line - 1;
		for (; tempLine >= 0; tempLine--) {
			if (CheckerStatus[row][tempLine].status == StatusBlank) {
				//CheckerStatus[row][tempLine].status = color;
				return (row * 100 + tempLine);
			}
		}
		tempLine = line + 1;
		for (; tempLine <= 14; tempLine++) {
			if (CheckerStatus[row][tempLine].status == StatusBlank)
				//CheckerStatus[row][tempLine].status = color;
			return (row * 100 + tempLine);
		}
	}
	case 2: {//垂直进攻
		int tempRow = row - 1;
		for (; tempRow >= 0; tempRow--) {
			if (CheckerStatus[tempRow][line].status == StatusBlank) {
				//CheckerStatus[tempRow][line].status = color;
				return (tempRow * 100 + line);
			}
		}
		tempRow = row + 1;
		for (; tempRow <= 14; tempRow++) {
			if (CheckerStatus[tempRow][line].status == StatusBlank)
				//CheckerStatus[tempRow][line].status = color;
			return (tempRow * 100 + line);
		}
	}
	case 3: {//对角进攻
		int tempRow = row - 1;
		int tempLine = line - 1;
		for (; tempRow >= 0 && tempLine >= 0; tempRow--, tempLine--) {
			if (CheckerStatus[tempRow][tempLine].status == StatusBlank) {
				//CheckerStatus[tempRow][tempLine].status = color;
				return (tempRow * 100 + tempLine);
			}
		}
		tempRow = row + 1;
		tempLine = line + 1;
		for (; tempRow <= 14 && tempLine <= 14; tempRow++, tempLine++) {
			if (CheckerStatus[tempRow][tempLine].status == StatusBlank)
				//CheckerStatus[tempRow][tempLine].status = color;
			return (tempRow * 100 + tempLine);
		}
	}
	case 4: {//反对角进攻
		int tempRow = row - 1;
		int tempLine = line + 1;
		for (; tempRow >= 0 && tempLine <= 14; tempRow--, tempLine++) {
			if (CheckerStatus[tempRow][tempLine].status == StatusBlank) {
				//CheckerStatus[tempRow][tempLine].status = color;
				return (tempRow * 100 + tempLine);
			}
		}
		tempRow = row + 1;
		tempLine = line - 1;
		for (; tempRow <= 14 && tempLine >= 0; tempRow++, tempLine--) {
			if (CheckerStatus[tempRow][tempLine].status == StatusBlank)
				//CheckerStatus[tempRow][tempLine].status = color;
			return (tempRow * 100 + tempLine);
		}
	}
	}
}


int AI(Point CheckerStatus[][15], int row, int line, int color) {//判断落子位置的函数
	int a, b, c, d;//用于储存不同位置的价值
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;
	}//获取自己和对方的颜色
	int position = 0;

	a = HorizontalJudge(CheckerStatus, row, line, color);
	b = VerticalJudge(CheckerStatus, row, line, color);
	c = DiagonalJudge(CheckerStatus, row, line, color);
	d = OppoDiagonalJudge(CheckerStatus, row, line,color);//获取对方下棋点的价值
	int value1 = d, value2 = 0;//用value1和value2表示自己和对方的棋子价值
	int mode1 = 4, mode2;//用于储存最终执行的下棋方式

	if (a > value1) {
		value1 = a;
		mode1 = 1;
	}
	if (b > value1) {
		value1 = b;
		mode1 = 2;
	}
	if (c > value1) {
		value1 = c;
		mode1 = 3;
	}//获取对方最大价值及下子方式

	int i, j;//用于循环语句
	int tempRow = 0, tempLine = 0, tempValue = 0, tempMode = 0;//用于储存值
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			if (CheckerStatus[i][j].status == color) {
				a = HorizontalJudge(CheckerStatus, i, j, Comcolor);
				b = VerticalJudge(CheckerStatus, i, j, Comcolor);
				c = DiagonalJudge(CheckerStatus, i, j, Comcolor);
				d = OppoDiagonalJudge(CheckerStatus, i, j, Comcolor);//遍历棋盘获取自己棋子价值
				tempValue = d;
				tempMode = 4;
				if (a > tempValue) {
					tempValue = a;
					tempMode = 1;
				}
				if (b > tempValue) {
					tempValue = b;
					tempMode = 2;
				}
				if (c > tempValue) {
					tempValue = c;
					tempMode = 3;
				}
				if (tempValue > value2) {
					value2 = tempValue;
					tempRow = i;
					tempLine = j;
					mode2 = tempMode;
				}//获取己方棋子最大棋子价值和下棋模式
			}
		}
	}
	if (value2 >= 4) {
		position = Attack(CheckerStatus, tempRow, tempLine, color, mode2);
	}
	else if (value1 >= 3 && value1 >= value2) {
		position = Defend(CheckerStatus, row, line, color, mode1);
	}
	else if(value2 >= 3 && value2 > value1){
		position = Attack(CheckerStatus, tempRow, tempLine, color, mode2);
	}
	else if (value2 >= value1 && value1 < 3) {//根据不同价值决定进攻或者防守
		position = Attack(CheckerStatus, tempRow, tempLine, color, mode2);
	}
	else {//当不满足上述条件时在玩家棋子周围落子
		int temp1 = 0, temp2 = 0;
		int random, seed;
		seed = time(NULL);
		srand((unsigned int)seed);
		i = row;
		j = line;
		if (i >= 1 && j >= 1) {
			temp1 = 1;
			temp2 = 1;
		}
		else if (i >= 1 && j < 1) {
			temp1 = 1;
		}
		else if (i < 1 && j >= 1) {
			temp2 = 1;
		}
		while (true) {
			random = rand() % 8;
			switch (random) {
			case 1: {
				if (CheckerStatus[i + 1][j].status == StatusBlank) {
					//CheckerStatus[i + 1][j].status = color;
					return ((i + 1) * 100 + j);
				}
				else break;
			}
			case 2: {	
				if (CheckerStatus[i - 1][j].status == StatusBlank && temp1 > 0) {
					//CheckerStatus[i - 1][j].status = color;
					return ((i - 1) * 100 + j);
				}
				else break;
			}
			case 3: {	
				if (CheckerStatus[i][j + 1].status == StatusBlank) {
					//CheckerStatus[i][j + 1].status = color;
					return (i * 100 + j + 1);
				}
				else break;
			}
			case 4: {
				if (CheckerStatus[i][j - 1].status == StatusBlank && temp2 > 0) {
					//CheckerStatus[i][j - 1].status = color;
					return (i * 100 + j - 1);
				}
				else break;
			}
			case 5: {
				if (CheckerStatus[i + 1][j + 1].status == StatusBlank) {
					//CheckerStatus[i + 1][j + 1].status = color;
					return ((i + 1) * 100 + j + 1);
				}
				else break;
			}
			case 6: {
				if (CheckerStatus[i - 1][j + 1].status == StatusBlank && temp1 > 0) {
					//CheckerStatus[i - 1][j + 1].status = color;
					return ((i - 1) * 100 + j + 1);
				}
				else break;
			}
			case 7: {
				if (CheckerStatus[i + 1][j - 1].status == StatusBlank && temp2 > 0) {
					//CheckerStatus[i + 1][j - 1].status = color;
					return ((i + 1) * 100 + j - 1);
				}
				else break;
			}
			case 8: {	
				if (CheckerStatus[i - 1][j - 1].status == StatusBlank && temp1 > 0 && temp2 > 0) {
					//CheckerStatus[i - 1][j - 1].status = color;
					return ((i - 1) * 100 + j - 1);
				}
				  else break;
			}
			}
		}
	}
	return position;//将位置坐标返回
}


//int AI(Point CheckerStatus[][15], int row, int line, int color) {//进行
//	int value;
//	value = JudgeValue(CheckerStatus, row, line, color);
//	return value;
//}




int Play(Point CheckerStatus[15][15], int j, Point* head1) {//进行棋局的函数
	IMAGE black, white, save,  situation;
	loadimage(&black, _T("image/black.png"), 20, 20);//加载黑棋图片
	loadimage(&white, _T("image/white.png"), 20, 20);//加载白棋图片
	loadimage(&save, _T("image/save.png"), 300, 250);//加载保存棋局文字的图片


	Point* head = (Point*)malloc(sizeof(Point));//设置链表头指针
	Point* link = head;
	int row = -1, line = -1, temp, k = 0;//row和line获取下子位置、k记录下棋步数、temp判断是否获胜

	MOUSEMSG m;
	drawAlpha(&save, 500, 150);//显示图片

	getimage(&situation, 0, 0, 900, 600);//获取棋局图片
	while (true) {
		while (true) {
			m = GetMouseMsg();//获取鼠标信息
			if (m.uMsg == WM_LBUTTONUP) {
				if (m.x > 550 && m.x < 750 && m.y>240 && m.y < 300) {//如果点击保存棋局
					saveGame(head);//执行保存棋局函数
					return 0;
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
				drawAlpha(&black, m.x - 10, m.y - 10);
				CheckerStatus[row][line].status = StatusBlack;
				k++;
				link->next = Creat(CheckerStatus[row][line]);//为链表新建节点
				link = link->next;
				getimage(&situation, 0, 0, 900, 600);
				break;
			}
		}
		temp = WhetherWin(CheckerStatus, row, line);//判断是否获胜
		if (temp != 0) {
			victorymenu(temp, head,k);//显示获胜菜单
			break;
		}
		int position;
		while (true) {
			position = AI(CheckerStatus, row, line, StatusWhite);
			row = position / 100;
			line = position % 100;//获取位置坐标
			if (CheckerStatus[row][line].status != StatusBlank)
				continue;
			else break;
		}
		CheckerStatus[row][line].status = StatusWhite;//赋值
		k++;
		link->next = Creat(CheckerStatus[row][line]);//为链表新建节点
		link = link->next;
		int i, j;
		i = row * 25 + 150;
		j = line * 25 + 100;//数组坐标转化为像素坐标
		drawAlpha(&white, i - 10, j - 10);
		temp = WhetherWin(CheckerStatus, row, line);//判断是否获胜
		if (temp != 0) {
			victorymenu(temp, head, k);//显示获胜菜单
			break;
		}
	}
	return 0;
}