#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col, char set){//��ʼ������
	memset(board, set, row*col*sizeof(board[0][0]));
}
void DisplayBoard(char board[ROW][COL], int row, int col){    //��ӡ����
	int i = 0;
	int j = 0;
	for (i = -1; i < row; i++){
		for (j = -1; j < col; j++){
			if (i == -1){
				printf(" %d ",j+1);
			}
			else if (j == -1){
				printf(" %d ", i+1);
			}
			else{
				printf(" %c ", board[i][j]);
			} 
			if (j != col - 1){
				printf("|");
			}
		}
		printf("\n");
		if (i != row - 1){
			printf("---+---+---+---+---+---+---+---+---+---");
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col){
	int i = 0;//������
	int j = 0;//������
	while (1){
		printf("������������ӵ�����(�磺a b):>");
		scanf("%d %d", &i, &j);
		if (i<1 || i>row || j<1 || j>col){
			printf("��������������������룡\n");
		}
		else if (board[i - 1][j - 1] != ' '){
			printf("�������ѱ�����ռ��!���������룡\n");
		}
		else{
			break;
		}
	}
	system("cls");
	printf("�����:\n");
	printf("\n");
	board[i - 1][j - 1] = 'X';
}
int FiveSon(char board[ROW][COL], int row, int col, int k, char a, char b, char c){
	int i = 0;//������
	int j = 0;//������
	//������еĳ�5����4/��4
	if (k == 1){
		for (i = 0; i < row; i++){
			for (j = 0; j < col - 4; j++){
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] &&
					board[i][j] == board[i][j + 3] && board[i][j] == a && board[i][j + 4] == b){
					board[i][j + 4] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] &&
					board[i][j] == board[i][j + 4] && board[i][j] == a && board[i][j + 3] == b){
					board[i][j + 3] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 3] &&
					board[i][j] == board[i][j + 4] && board[i][j] == a && board[i][j + 2] == b){
					board[i][j + 2] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] &&
					board[i][j] == board[i][j + 4] && board[i][j] == a && board[i][j + 1] == b){
					board[i][j + 1] = c;
					k = 0;
					break;
				}
				if (board[i][j + 1] == board[i][j + 2] && board[i][j + 1] == board[i][j + 3] &&
					board[i][j + 1] == board[i][j + 4] && board[i][j + 1] == a && board[i][j] == b){
					board[i][j] = c;
					k = 0;
					break;
				}
			}
			if (k == 0){
				break;
			}
		}
	}
	//������еĳ�5����4/��4
	if (k == 1){
		for (j = 0; j < col; j++){
			for (i = 0; i < row - 4; i++){
				if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] &&
					board[i][j] == board[i + 3][j] && board[i][j] == a && board[i + 4][j] == b){
					board[i + 4][j] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] &&
					board[i][j] == board[i + 4][j] && board[i][j] == a && board[i + 3][j] == b){
					board[i + 3][j] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 3][j] &&
					board[i][j] == board[i + 4][j] && board[i][j] == a && board[i + 2][j] == b){
					board[i + 2][j] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] &&
					board[i][j] == board[i + 4][j] && board[i][j] == a && board[i + 1][j] == b){
					board[i + 1][j] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j] == board[i + 2][j] && board[i + 1][j] == board[i + 3][j] &&
					board[i + 1][j] == board[i + 4][j] && board[i + 1][j] == a && board[i][j] == b){
					board[i][j] = c;
					k = 0;
					break;
				}
			}
			if (k == 0){
				break;
			}
		}
	}
	//���б���еĳ�5����4/��4
	//��б
	if (k == 1){
		for (int m = row - 5; m >= 0; m--){
			for (i = m, j = 0; i < row - 4; i++){
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] &&
					board[i][j] == board[i + 3][j + 3] && board[i][j] == a && board[i + 4][j + 4] == b){
					board[i + 4][j + 4] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] &&
					board[i][j] == board[i + 4][j + 4] && board[i][j] == a && board[i + 3][j + 3] == b){
					board[i + 3][j + 3] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 3][j + 3] &&
					board[i][j] == board[i + 4][j + 4] && board[i][j] == a && board[i + 2][j + 2] == b){
					board[i + 2][j + 2] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] &&
					board[i][j] == board[i + 4][j + 4] && board[i][j] == a && board[i + 1][j + 1] == b){
					board[i + 1][j + 1] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] == board[i + 3][j + 3] &&
					board[i + 1][j + 1] == board[i + 4][j + 4] && board[i + 1][j + 1] == a && board[i][j] == b){
					board[i][j] = c;
					k = 0;
					break;
				}
				j++;
			}
			if (k == 0){
				break;
			}
		}
	}
	if (k == 1){
		for (int n = 1; n <= col - 4; n++){
			for (i = 0, j = n; i < row - 4; i++){
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] &&
					board[i][j] == board[i + 3][j + 3] && board[i][j] == a && board[i + 4][j + 4] == b){
					board[i + 4][j + 4] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] &&
					board[i][j] == board[i + 4][j + 4] && board[i][j] == a && board[i + 3][j + 3] == b){
					board[i + 3][j + 3] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 3][j + 3] &&
					board[i][j] == board[i + 4][j + 4] && board[i][j] == a && board[i + 2][j + 2] == b){
					board[i + 2][j + 2] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] &&
					board[i][j] == board[i + 4][j + 4] && board[i][j] == a && board[i + 1][j + 1] == b){
					board[i + 1][j + 1] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] == board[i + 3][j + 3] &&
					board[i + 1][j + 1] == board[i + 4][j + 4] && board[i + 1][j + 1] == a && board[i][j] == b){
					board[i][j] = c;
					k = 0;
					break;
				}
				j++;
			}
			if (k == 0){
				break;
			}
		}
	}
	//��б
	if (k == 1){
		for (int m = row - 5; m >= 0; m--){
			for (i = m, j = col - 1; i < row - 4; i++){
				if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] &&
					board[i][j] == board[i + 3][j - 3] && board[i][j] == a && board[i + 4][j - 4] == b){
					board[i + 4][j - 4] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] &&
					board[i][j] == board[i + 4][j - 4] && board[i][j] == a && board[i + 3][j - 3] == b){
					board[i + 3][j - 3] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 3][j - 3] &&
					board[i][j] == board[i + 4][j - 4] && board[i][j] == a && board[i + 2][j - 2] == b){
					board[i + 2][j - 2] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] &&
					board[i][j] == board[i + 4][j - 4] && board[i][j] == a && board[i + 1][j - 1] == b){
					board[i + 1][j - 1] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 1][j - 1] == board[i + 3][j - 3] &&
					board[i + 1][j - 1] == board[i + 4][j - 4] && board[i + 1][j - 1] == a && board[i][j] == b){
					board[i][j] = c;
					k = 0;
					break;
				}
				j--;
			}
			if (k == 0){
				break;
			}
		}
	}
	if (k == 1){
		for (int n = col - 5; n < col - 1; n++){
			for (i = 0, j = n; i < row - 4; i++){
				if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] &&
					board[i][j] == board[i + 3][j - 3] && board[i][j] == a && board[i + 4][j - 4] == b){
					board[i + 4][j - 4] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] &&
					board[i][j] == board[i + 4][j - 4] && board[i][j] == a && board[i + 3][j - 3] == b){
					board[i + 3][j - 3] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 3][j - 3] &&
					board[i][j] == board[i + 4][j - 4] && board[i][j] == a && board[i + 2][j - 2] == b){
					board[i + 2][j - 2] = c;
					k = 0;
					break;
				}
				if (board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] &&
					board[i][j] == board[i + 4][j - 4] && board[i][j] == a && board[i + 1][j - 1] == b){
					board[i + 1][j - 1] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 1][j - 1] == board[i + 3][j - 3] &&
					board[i + 1][j - 1] == board[i + 4][j - 4] && board[i + 1][j - 1] == a && board[i][j] == b){
					board[i][j] = c;
					k = 0;
					break;
				}
				j--;
			}
			if (k == 0){
				break;
			}
		}
	}
	return k;
}
//���ڼ���3,��4
int ThreeSon(char board[ROW][COL], int row, int col, int k, char a, char b, char c){
	int i = 0;//������
	int j = 0;//������
	//��
	if (k == 1){
		for (i = 0; i < row; i++){
			for (j = 0; j < col - 4; j++){
				if (board[i][j + 1] == board[i][j + 2] && board[i][j + 1] == board[i][j + 3] &&
					board[i][j] == board[i][j + 4] && board[i][j + 1] == a && board[i][j + 4] == b){
					board[i][j + 4] = c;
					k = 0;
					break;
				}
				if (board[i][j + 1] == board[i][j + 2] && board[i][j + 1] == board[i][j + 4] &&
					board[i][j] == board[i][j + 3] && board[i][j + 1] == a && board[i][j + 3] == b){
					board[i][j + 3] = c;
					k = 0;
					break;
				}
				if (board[i][j + 1] == board[i][j + 3] && board[i][j + 1] == board[i][j + 4] &&
					board[i][j] == board[i][j + 2] && board[i][j + 1] == a && board[i][j + 2] == b){
					board[i][j + 2] = c;
					k = 0;
					break;
				}
			}
			if (k == 0){
				break;
			}
		}
	}
	//��
	if (k == 1){
		for (j = 0; j < col; j++){
			for (i = 0; i < row - 4; i++){
				if (board[i + 1][j] == board[i + 2][j] && board[i + 1][j] == board[i + 3][j] &&
					board[i][j] == board[i + 4][j] && board[i + 1][j] == a && board[i + 4][j] == b){
					board[i + 4][j] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j] == board[i + 2][j] && board[i + 1][j] == board[i + 4][j] &&
					board[i][j] == board[i + 3][j] && board[i + 1][j] == a && board[i + 3][j] == b){
					board[i + 3][j] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j] == board[i + 3][j] && board[i + 1][j] == board[i + 4][j] &&
					board[i][j] == board[i + 2][j] && board[i + 1][j] == a && board[i + 2][j] == b){
					board[i + 2][j] = c;
					k = 0;
					break;
				}
			}
			if (k == 0){
				break;
			}
		}
	}
	//б
	if (k == 1){
		for (int m = row - 5; m >= 0; m--){
			for (i = m, j = 0; i < row - 4; i++){
				if (board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] == board[i + 3][j + 3] &&
					board[i][j] == board[i + 4][j + 4] && board[i + 1][j + 1] == a && board[i + 4][j + 4] == b){
					board[i + 4][j + 4] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] == board[i + 4][j + 4] &&
					board[i][j] == board[i + 3][j + 3] && board[i + 1][j + 1] == a && board[i + 3][j + 3] == b){
					board[i + 3][j + 3] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j + 1] == board[i + 3][j + 3] && board[i + 1][j + 1] == board[i + 4][j + 4] &&
					board[i][j] == board[i + 2][j + 2] && board[i + 1][j + 1] == a && board[i + 2][j + 22] == b){
					board[i + 2][j + 2] = c;
					k = 0;
					break;
				}
				j++;
			}
			if (k == 0){
				break;
			}
		}
	}
	if (k == 1){
		for (int n = 1; n <= col - 4; n++){
			for (i = 0, j = n; i < row - 4; i++){
				if (board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] == board[i + 3][j + 3] &&
					board[i][j] == board[i + 4][j + 4] && board[i + 1][j + 1] == a && board[i + 4][j + 4] == b){
					board[i + 4][j + 4] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] == board[i + 4][j + 4] &&
					board[i][j] == board[i + 3][j + 3] && board[i + 1][j + 1] == a && board[i + 3][j + 3] == b){
					board[i + 3][j + 3] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j + 1] == board[i + 3][j + 3] && board[i + 1][j + 1] == board[i + 4][j + 4] &&
					board[i][j] == board[i + 2][j + 2] && board[i + 1][j + 1] == a && board[i + 2][j + 2] == b){
					board[i + 2][j + 2] = c;
					k = 0;
					break;
				}
				j++;
			}
			if (k == 0){
				break;
			}
		}
	}
	if (k == 1){
		for (int m = row - 5; m >= 0; m--){
			for (i = m, j = col - 1; i < row - 4; i++){
				if (board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 1][j - 1] == board[i + 3][j - 3] &&
					board[i][j] == board[i + 4][j - 4] && board[i + 1][j - 1] == a && board[i + 4][j - 4] == b){
					board[i + 4][j - 4] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 1][j - 1] == board[i + 4][j - 4] &&
					board[i][j] == board[i + 3][j - 3] && board[i + 1][j - 1] == a && board[i + 3][j - 3] == b){
					board[i + 3][j - 3] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j - 1] == board[i + 3][j - 3] && board[i + 1][j - 1] == board[i + 4][j - 4] &&
					board[i][j] == board[i + 2][j - 2] && board[i + 1][j - 1] == a && board[i + 2][j - 2] == b){
					board[i + 2][j - 2] = c;
					k = 0;
					break;
				}
				j--;
			}
			if (k == 0){
				break;
			}
		}
	}
	if (k == 1){
		for (int n = col - 5; n < col - 1; n++){
			for (i = 0, j = n; i < row - 4; i++){
				if (board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 1][j - 1] == board[i + 3][j - 3] &&
					board[i][j] == board[i + 4][j - 4] && board[i + 1][j - 1] == a && board[i + 4][j - 4] == b){
					board[i + 4][j - 4] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 1][j - 1] == board[i + 4][j - 4] &&
					board[i][j] == board[i + 3][j - 3] && board[i + 1][j - 1] == a && board[i + 3][j - 3] == b){
					board[i + 3][j - 3] = c;
					k = 0;
					break;
				}
				if (board[i + 1][j - 1] == board[i + 3][j - 3] && board[i + 1][j - 1] == board[i + 4][j - 4] &&
					board[i][j] == board[i + 2][j - 2] && board[i + 1][j - 1] == a && board[i + 2][j - 2] == b){
					board[i + 2][j - 2] = c;
					k = 0;
					break;
				}
				j--;
			}
			if (k == 0){
				break;
			}
		}
	}
	return k;
}
void ComputerMove(char board[ROW][COL], int row, int col) {
	int i = 0;//������;
	int j = 0;//������;
	int k = 1;//�жϵ����Ƿ������ӣ������������;
	k = FiveSon(board, row, col, k, '*', ' ', '*');//�����Ƿ�Ҫ����;
	k = FiveSon(board, row, col, k, 'X', ' ', '*');//����Ƿ�Ҫ����;
	k = ThreeSon(board, row, col, k, '*', ' ', '*');//�����Ƿ����;
	k = ThreeSon(board, row, col, k, 'X', ' ', '*');//����Ƿ����;
	if (k == 1){
		//���м�;
		if (board[row / 2][col / 2] == ' '){
			board[row / 2][col / 2] = '*';
		}
		//���м����Χ;
		else if (board[row / 2 - 1][col / 2 - 1] == ' '){
			board[row / 2 - 1][col / 2 - 1] = '*';
		}
		else if (board[row / 2 - 1][col / 2] == ' '){
			board[row / 2 - 1][col / 2] = '*';
		}
		else if (board[row / 2 - 1][col / 2 + 1] == ' '){
			board[row / 2 - 1][col / 2 + 1] = '*';
		}
		else if (board[row / 2][col / 2 - 1] == ' '){
			board[row / 2][col / 2 - 1] = '*';
		}
		else if (board[row / 2][col / 2 + 1] == ' '){
			board[row / 2][col / 2 + 1] = '*';
		}
		else if (board[row / 2 + 1][col / 2 - 1] == ' '){
			board[row / 2][col / 2 - 1] = '*';
		}
		else if (board[row / 2 + 1][col / 2] == ' '){
			board[row / 2 + 1][col / 2] = '*';
		}
		else if (board[row / 2 + 1][col / 2 + 1] == ' '){
			board[row / 2 + 1][col / 2 + 1] = '*';
		}
		else{
			while (1){
				i = rand() % row;
				j = rand() % col;
				if (board[i][j] == ' '){
					board[i][j] = '*';
					break;
				}
			}
		}
	}
	printf("������:>\n");
	printf("\n");
}
int CheckWiner(char board[ROW][COL], int row, int col){
	int count = 0;//����ʣ����Է����ӵ�λ��
	if (FiveSon(board, row, col, 1, '*', '*', '*') == 0){
		printf("���ź�������Ӯ��!\n");
		return 1;
	}
	if (FiveSon(board, row, col, 1, 'X', 'X', 'X') == 0){
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
		return 1;
	}
	for (int m = 0; m < row; m++){
		for (int n = 0; n < col; n++){
			if (board[m][n] == ' '){
				count++;
			}
		}
	}
	if (count == 0){//���̰���
		printf("ƽ��!\n");
		return 1;
	}
	return 0;
}
void PlayGame(char board[ROW][COL], int row, int col){
	srand(time(0));
	int isover = 0;
	while (1){
		PlayerMove(board, row, col);
		DisplayBoard(board, row, col);
		isover = CheckWiner(board, row, col);
		if (isover == 1){
			break;
		}
		Sleep(1200);
		system("cls");
		ComputerMove(board, row, col);
		DisplayBoard(board, row, col);
		isover = CheckWiner(board, row, col);
		if (isover == 1){
			break;
		}
	}
}
