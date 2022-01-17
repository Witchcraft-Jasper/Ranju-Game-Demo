/*program name:rendering.cpp
programmer:������
student number:19301014
date:2020-07-11
use:�ع����
*/

#include"mean.h"//�������Ӷ��塢ͼƬת������������Զ���ͷ�ļ�
#include"crucial.h"//�������ṹ�嶨�弰���ֺ����Ķ�����Զ���ͷ�ļ�

Point* Creat(Point temp) {//Ϊ��������½ڵ�ĺ���������ʵ����ֻع˹���
	Point* New = (Point*)malloc(sizeof(Point));
	New->next = NULL;
	New->line = temp.line;
	New->row = temp.row;
	New->status = temp.status;//������Ľṹ���ֵ�����½ڵ�
	return New;//�����½ڵ�ĵ�ַ
}

int Rendering(Point* head) {//���ڻع���ֶ�ս�ĺ���
	IMAGE black, white,situation, BlackTurn, WhiteTurn;

	loadimage(&black, _T("image/black.png"), 20, 20);
	loadimage(&white, _T("image/white.png"), 20, 20);
	loadimage(&BlackTurn, _T("image/blackTurn.png"), 300, 250);
	loadimage(&WhiteTurn, _T("image/WhiteTurn.png"), 300, 250);
	//��������ͼƬ������/����غϡ����ֵ�ͼƬ

	int k = 0,row,line;//k�����ж��ߺڻ��ǰ��壬row��line��ʾ��������
	CheckerBoard();//��ʾ����
	getimage(&situation, 0, 0, 900, 600);//��ȡ��ǰ���ͼƬ

	while (head->next != NULL) {//ѭ��ֱ������ĩβ
		putimage(0, 0, &situation);//չʾ��ǰ���ͼƬ
		head = head->next;//����ָ��
		row = head->row * 25 + 150;
		line = head->line * 25 + 100;//�����ص�λ��ת��Ϊ����������
		if (head->status == StatusBlack) {
			drawAlpha(&black, row - 10, line - 10);
			//�������ͼƬ
		}
		else if (head->status == StatusWhite) {
			drawAlpha(&white, row - 10, line - 10);//�������ͼƬ
		}
		else continue;
		getimage(&situation, 0, 0, 900, 600);//��ȡ��ǰ���ͼƬ
		if (head->status == StatusBlack) {
			drawAlpha(&BlackTurn, 550, 50);//��ʾ��ǰΪ����غ�
		}
		else drawAlpha(&WhiteTurn, 550, 50);//��ʾ��ǰΪ����غ�
		k++;
		k %= 2;//ʹk������0��1��ѭ��
		Sleep(1000);//����ͣ��
	}
	return 0;
}

