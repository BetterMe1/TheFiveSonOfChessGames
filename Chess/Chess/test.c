/*
date:2018/12/24
author:Better Me1
program:The Five Son Of Chess Games
compiler:Visual Studio 2013
*/

/*���Բ���*/
#include "game.h"

void menu(){
	printf("************ ������С��Ϸ  ************\n");
	printf("******  1.������Ϸ  2.�˳���Ϸ  ******\n");
	printf("**************************************\n");
}
void game(){
	char chess[ROW][COL] = { ' ' };
	InitBoard(chess, ROW, COL, ' ');//��ʼ��
	DisplayBoard(chess, ROW, COL);//��ӡ����
	PlayGame(chess, ROW, COL);//����Ϸ
}
void test(){
	int input = 0;
	while (input!=2){
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		system("cls");
		switch (input){
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("��������������ѡ��\n");
			break;
		}
	}
}
void main(){
	test();
	system("pause");
}