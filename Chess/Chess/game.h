#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define ROW 9
#define COL 9

void InitBoard(char board[ROW][COL], int row, int col, char set);
void DisplayBoard(char board[ROW][COL], int row,int col);
void PlayerMove(char board[ROW][COL], int row, int col);
int FiveSon(char board[ROW][COL], int row, int col, int k,char a,char b,char c);//���ڼ���5����4/��4
int ThreeSon(char board[ROW][COL], int row, int col, int k, char a, char b, char c);//���ڼ���3����4
void ComputerMove(char board[ROW][COL], int row, int col);
int CheckWiner(char board[ROW][COL], int row, int col);
void PlayGame(char board[ROW][COL], int row, int col);
