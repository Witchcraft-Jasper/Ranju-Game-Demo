/*program name:main.cpp
programmer:������
student number:19301014
date:2020-07-11
use:�����������������ά�ֳ���Ľ���
*/

#include"mean.h"//�������Ӷ��塢ͼƬת������������Զ���ͷ�ļ�
#include"crucial.h"//�������ṹ�嶨�弰���ֺ����Ķ�����Զ���ͷ�ļ�

int main() {//�����������
	Point CheckerStatus[15][15];//���ڱ�ʾ���������������
	initgraph(900, 600);///��ʼ����ͼ����

	int  i, j;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			CheckerStatus[i][j].status = StatusBlank;
			CheckerStatus[i][j].row = i;
			CheckerStatus[i][j].line = j;
		}
	}//��ʼ���ṹ������

	mainmenu(CheckerStatus);//��ʾ���˵�
	
	return 0;
}