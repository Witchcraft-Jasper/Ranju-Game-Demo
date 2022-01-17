/*program name:crucial.h
programmer:������
student number:19301014
date:2020-07-11
use:�������ṹ�嶨�弰���ֺ����Ķ�����Զ���ͷ�ļ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Point {//��¼��������Ľṹ��
	int row;//��ʾ����
	int line;//��ʾ����
	int status;//��ʾ�������
	struct Point* next;//ָ����һ�ṹ��
}point;

typedef struct Top {//��¼�ɼ������Ľṹ��
	char name[50];//��ʾ�������
	int steps;//��ʾ�ܲ���
	struct Top* next;//ָ����һ�ṹ��
}top;


//��ʾ�˵�����
void mainmenu(Point[][15]);//��ʾ��������˵�
void victorymenu(int, Point*, int);//�����˻�ʤʱִ�еĺ���


//�������̶Ծֺ���
void CheckerBoard();//��ʾ���̵ĺ���
int JudgeChecker(Point[][15], int, int);//�ж��Ƿ����ӵ�������ظ����ӵĺ���
int WhetherWin(Point[][15], int, int);//�ж��Ƿ�ȡʤִ�к���
int touch(Point[][15], int, Point*);//�������˶�սִ�еĺ���
int Play(Point[][15], int, Point*);//�����˻���սִ�еĺ���


//���ӹ��ܺ���
Point* Creat(Point);//Ϊ��������½ڵ�ĺ���������ʵ����ֻع˹���
int Rendering(Point*);//���ڻع���ֶ�ս�ĺ���
void saveGame(Point*);//������Ϸִ�еĺ���
void loadGame(Point[][15]);//������Ϸִ�еĺ���
void PrintAgain(Point[][15]);//ִ�л��彫ǰһ�غ��������ִ�еĺ���
int TopList();//�鿴����ִ�еĺ���