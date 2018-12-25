/*
date:2018/12/24
author:Better Me1
program:The Five Son Of Chess Games
compiler:Visual Studio 2013
*/

/*测试部分*/
#include "game.h"

void menu(){
	printf("************ 五子棋小游戏  ************\n");
	printf("******  1.进入游戏  2.退出游戏  ******\n");
	printf("**************************************\n");
}
void game(){
	char chess[ROW][COL] = { ' ' };
	InitBoard(chess, ROW, COL, ' ');//初始化
	DisplayBoard(chess, ROW, COL);//打印棋盘
	PlayGame(chess, ROW, COL);//玩游戏
}
void test(){
	int input = 0;
	while (input!=2){
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		system("cls");
		switch (input){
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入有误，请重新选择！\n");
			break;
		}
	}
}
void main(){
	test();
	system("pause");
}