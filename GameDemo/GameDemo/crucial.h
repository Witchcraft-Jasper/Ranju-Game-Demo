/*program name:crucial.h
programmer:吕炎明
student number:19301014
date:2020-07-11
use:包含各结构体定义及各种函数的定义的自定义头文件
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Point {//记录落子情况的结构体
	int row;//表示行数
	int line;//表示列数
	int status;//表示落子情况
	struct Point* next;//指向下一结构体
}point;

typedef struct Top {//记录成绩排名的结构体
	char name[50];//表示玩家姓名
	int steps;//表示总步数
	struct Top* next;//指向下一结构体
}top;


//显示菜单函数
void mainmenu(Point[][15]);//显示程序的主菜单
void victorymenu(int, Point*, int);//当有人获胜时执行的函数


//进行棋盘对局函数
void CheckerBoard();//显示棋盘的函数
int JudgeChecker(Point[][15], int, int);//判断是否落子到界外和重复落子的函数
int WhetherWin(Point[][15], int, int);//判断是否取胜执行函数
int touch(Point[][15], int, Point*);//进行人人对战执行的函数
int Play(Point[][15], int, Point*);//进行人机对战执行的函数


//附加功能函数
Point* Creat(Point);//为链表添加新节点的函数，便于实现棋局回顾功能
int Rendering(Point*);//用于回顾棋局对战的函数
void saveGame(Point*);//保存游戏执行的函数
void loadGame(Point[][15]);//加载游戏执行的函数
void PrintAgain(Point[][15]);//执行悔棋将前一回合棋盘输出执行的函数
int TopList();//查看排名执行的函数