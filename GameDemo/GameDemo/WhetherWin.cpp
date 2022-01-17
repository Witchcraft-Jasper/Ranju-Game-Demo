/*program name:WhetherWin.cpp
programmer:������
student number:19301014
date:2020-07-11
use:�ж��û��Ƿ�ȡ��ʤ��
*/

#include"mean.h"//�������Ӷ��塢ͼƬת������������Զ���ͷ�ļ�
#include"crucial.h"//�������ṹ�嶨�弰���ֺ����Ķ�����Զ���ͷ�ļ�

int HorizontalWin(Point CheckerStatus[][15], int row, int line) {//�ж�ˮƽȡʤ�ĺ���
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
	//�ֱ�ѭ��������������������������

	return counter;//��������������
}

int VerticalWin(Point CheckerStatus[][15], int row, int line) {//�жϴ�ֱȡʤʱִ�еĺ���
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
	//�ֱ�ѭ��������������������������

	return counter;//��������������
}

int DiagonalWin(Point CheckerStatus[][15], int row, int line) {//���ӶԽ���ȡʤִ�еĺ���
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
	//�ֱ�ѭ�������ϽǺ����½�����������

	return counter;//��������������
}

int OppoDiagonalWin(Point CheckerStatus[][15], int row, int line) {//���ӷ��Խ�ȡʤִ�к���
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
	//�ֱ�ѭ�������ϽǺ����½�ִ�еĺ���

	return counter;//��������������
}

int WhetherDraw(Point CheckerStatus[][15]) {//�ж��Ƿ�ƽ��ִ�еĺ���
	int i, j;
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			if (CheckerStatus[i][j].status != StatusBlank)
				return 0;
		}
	}
	return 1;
}

int WhetherWin(Point CheckerStatus[][15], int row, int line) {//�ж��Ƿ�ȡʤִ�к���
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
	//�ֱ�ִ�����Ϻ������Ƿ�ȡʤ�����ݻ�ʤ������ɫ���ز�ֵͬ

	if (WhetherDraw(CheckerStatus))//���Ƿ�ƽ��
		return 3;
	return 0;
}

int JudgeChecker(Point CheckerStatus[][15], int x, int y) {//�ж��Ƿ����ӵ�������ظ����ӵĺ���
	IMAGE occupy, outside;
	loadimage(&occupy, _T("image/occupy2.png"), 300, 200);//���ش˴����������ֵ�ͼƬ
	loadimage(&outside, _T("image/outside2.png"), 300, 200);//�����벻Ҫ�ڽ����������ֵ�ͼƬ
	if (x < 150 || y < 100 || x> 500 || y > 450) {
		drawAlpha(&outside, 530, 0);
		return 0;
	}
	else if (CheckerStatus[(x - 150) / 25][(y - 100) / 25].status != StatusBlank) {
		drawAlpha(&occupy, 530, 0);
		return 0;
	}//���ݲ�ͬλ��ȷ�������Ƿ���ϱ�׼
	else return 1;
}