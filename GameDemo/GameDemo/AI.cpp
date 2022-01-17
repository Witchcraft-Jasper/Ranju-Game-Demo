/*program name:AI.cpp
programmer:������
student number:19301014
date:2020-07-11
use:���ڵ��Խ����ж�����λ��
*/

#include"mean.h"//�������Ӷ��塢ͼƬת������������Զ���ͷ�ļ�
#include"crucial.h"//�������ṹ�嶨�弰���ֺ����Ķ�����Զ���ͷ�ļ�
#include<time.h>//�������������

int HorizontalJudge(Point CheckerStatus[][15], int row, int line,int color) {//�ж�ˮƽ�ĺ���
	int temp = line - 1;
	int counter = 1;
	int value = 0;
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;//��ȡ�Լ��ͶԷ�����ɫ
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
		counter = 0;//�������������඼������ʱ����0
	//�ֱ�ѭ��������������������������
	return counter;//��������������
}

int VerticalJudge(point CheckerStatus[][15], int row, int line,int color) {//�жϴ�ֱʱִ�еĺ���
	int temp = row - 1;
	int counter = 1;
	int value = 0;
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;//��ȡ�Լ��ͶԷ�����ɫ
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
	//�ֱ�ѭ��������������������������
	if (value == 2)
		counter = 0;//�������������඼������ʱ����0

	return counter;//��������������
}

int DiagonalJudge(Point CheckerStatus[][15], int row, int line,int color) {//���ӶԽ���ȡʤִ�еĺ���
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
	}//��ȡ�Լ��ͶԷ�����ɫ
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
	//�ֱ�ѭ�������ϽǺ����½�����������
	if (value == 2)
		counter = 0;//�������������඼������ʱ����0
	return counter;//��������������
}

int OppoDiagonalJudge(Point CheckerStatus[][15], int row, int line, int color) {//���ӷ��Խ�ִ�к���
	int temp1 = row - 1;
	int temp2 = line + 1;
	int counter = 1;
	int value = 0;
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;//��ȡ�Լ��ͶԷ�����ɫ
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
	//�ֱ�ѭ�������ϽǺ����½�ִ�еĺ���
	if (value == 2)
		counter = 0;//�������������඼������ʱ����0
	return counter;//��������������
}

int Defend(Point CheckerStatus[][15], int row, int line, int color,int mode) {//���з��صĺ���
	switch (mode) {//��ȡ���ط�ʽ
		//ͨ�����ص��������ȷ������λ��
	case 1: {//ˮƽ����
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
	case 2: {//��ֱ����
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
	case 3: {//�ԽǷ���
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
	case 4: {//���ԽǷ���
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

int Attack(Point CheckerStatus[][15], int row, int line, int color, int mode) {//���н����ĺ���
	switch (mode) {//��ȡ������ʽ
		//ͨ�����ص��������ȷ������λ��
	case 1: {//ˮƽ����
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
	case 2: {//��ֱ����
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
	case 3: {//�Խǽ���
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
	case 4: {//���Խǽ���
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


int AI(Point CheckerStatus[][15], int row, int line, int color) {//�ж�����λ�õĺ���
	int a, b, c, d;//���ڴ��治ͬλ�õļ�ֵ
	int Comcolor = StatusBlank;
	if (color == StatusBlack) {
		Comcolor = StatusWhite;
	}
	if (color == StatusWhite) {
		Comcolor = StatusBlack;
	}//��ȡ�Լ��ͶԷ�����ɫ
	int position = 0;

	a = HorizontalJudge(CheckerStatus, row, line, color);
	b = VerticalJudge(CheckerStatus, row, line, color);
	c = DiagonalJudge(CheckerStatus, row, line, color);
	d = OppoDiagonalJudge(CheckerStatus, row, line,color);//��ȡ�Է������ļ�ֵ
	int value1 = d, value2 = 0;//��value1��value2��ʾ�Լ��ͶԷ������Ӽ�ֵ
	int mode1 = 4, mode2;//���ڴ�������ִ�е����巽ʽ

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
	}//��ȡ�Է�����ֵ�����ӷ�ʽ

	int i, j;//����ѭ�����
	int tempRow = 0, tempLine = 0, tempValue = 0, tempMode = 0;//���ڴ���ֵ
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			if (CheckerStatus[i][j].status == color) {
				a = HorizontalJudge(CheckerStatus, i, j, Comcolor);
				b = VerticalJudge(CheckerStatus, i, j, Comcolor);
				c = DiagonalJudge(CheckerStatus, i, j, Comcolor);
				d = OppoDiagonalJudge(CheckerStatus, i, j, Comcolor);//�������̻�ȡ�Լ����Ӽ�ֵ
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
				}//��ȡ��������������Ӽ�ֵ������ģʽ
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
	else if (value2 >= value1 && value1 < 3) {//���ݲ�ͬ��ֵ�����������߷���
		position = Attack(CheckerStatus, tempRow, tempLine, color, mode2);
	}
	else {//����������������ʱ�����������Χ����
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
	return position;//��λ�����귵��
}


//int AI(Point CheckerStatus[][15], int row, int line, int color) {//����
//	int value;
//	value = JudgeValue(CheckerStatus, row, line, color);
//	return value;
//}




int Play(Point CheckerStatus[15][15], int j, Point* head1) {//������ֵĺ���
	IMAGE black, white, save,  situation;
	loadimage(&black, _T("image/black.png"), 20, 20);//���غ���ͼƬ
	loadimage(&white, _T("image/white.png"), 20, 20);//���ذ���ͼƬ
	loadimage(&save, _T("image/save.png"), 300, 250);//���ر���������ֵ�ͼƬ


	Point* head = (Point*)malloc(sizeof(Point));//��������ͷָ��
	Point* link = head;
	int row = -1, line = -1, temp, k = 0;//row��line��ȡ����λ�á�k��¼���岽����temp�ж��Ƿ��ʤ

	MOUSEMSG m;
	drawAlpha(&save, 500, 150);//��ʾͼƬ

	getimage(&situation, 0, 0, 900, 600);//��ȡ���ͼƬ
	while (true) {
		while (true) {
			m = GetMouseMsg();//��ȡ�����Ϣ
			if (m.uMsg == WM_LBUTTONUP) {
				if (m.x > 550 && m.x < 750 && m.y>240 && m.y < 300) {//�������������
					saveGame(head);//ִ�б�����ֺ���
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
				//ͨ������仯��֤�������̽����ߴ�

				if (JudgeChecker(CheckerStatus, m.x, m.y) == 0) {//�ж������Ƿ��ں���λ��
					Sleep(1000);
					putimage(0, 0, &situation);
					continue;
				}
				row = (m.x - 150) / 25;
				line = (m.y - 100) / 25;//�����ص�����ת��Ϊ����������
				drawAlpha(&black, m.x - 10, m.y - 10);
				CheckerStatus[row][line].status = StatusBlack;
				k++;
				link->next = Creat(CheckerStatus[row][line]);//Ϊ�����½��ڵ�
				link = link->next;
				getimage(&situation, 0, 0, 900, 600);
				break;
			}
		}
		temp = WhetherWin(CheckerStatus, row, line);//�ж��Ƿ��ʤ
		if (temp != 0) {
			victorymenu(temp, head,k);//��ʾ��ʤ�˵�
			break;
		}
		int position;
		while (true) {
			position = AI(CheckerStatus, row, line, StatusWhite);
			row = position / 100;
			line = position % 100;//��ȡλ������
			if (CheckerStatus[row][line].status != StatusBlank)
				continue;
			else break;
		}
		CheckerStatus[row][line].status = StatusWhite;//��ֵ
		k++;
		link->next = Creat(CheckerStatus[row][line]);//Ϊ�����½��ڵ�
		link = link->next;
		int i, j;
		i = row * 25 + 150;
		j = line * 25 + 100;//��������ת��Ϊ��������
		drawAlpha(&white, i - 10, j - 10);
		temp = WhetherWin(CheckerStatus, row, line);//�ж��Ƿ��ʤ
		if (temp != 0) {
			victorymenu(temp, head, k);//��ʾ��ʤ�˵�
			break;
		}
	}
	return 0;
}