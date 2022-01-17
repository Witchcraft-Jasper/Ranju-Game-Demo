/*program name:main.cpp
programmer:吕炎明
student number:19301014
date:2020-07-11
use:程序的主函数，用于维持程序的进行
*/

#include"mean.h"//包含棋子定义、图片转化函数定义的自定义头文件
#include"crucial.h"//包含各结构体定义及各种函数的定义的自定义头文件

int main() {//程序的主函数
	Point CheckerStatus[15][15];//用于表示所有棋子落子情况
	initgraph(900, 600);///初始化绘图窗口

	int  i, j;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			CheckerStatus[i][j].status = StatusBlank;
			CheckerStatus[i][j].row = i;
			CheckerStatus[i][j].line = j;
		}
	}//初始化结构体数组

	mainmenu(CheckerStatus);//显示主菜单
	
	return 0;
}