#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValidCol(char** board, int boardRowSize, int boardColSize)
{
	int array[9]; memset(array, 0, sizeof(array));
	for (int i = 0; i < boardRowSize; i++)
	{
		for (int j = 0; j < boardColSize; j++) if (board[i][j] != '.') array[board[i][j] - '0' - 1]++;
		for (int j = 0; j < boardColSize; j++) if (array[j] > 1) return false;
		memset(array, 0, sizeof(array));
	}
	return true;
}

bool isValidRow(char** board, int boardRowSize, int boardColSize)
{
	int array[9]; memset(array, 0, sizeof(array));
	for (int j = 0; j < boardColSize; j++)
	{
		for (int i = 0; i < boardColSize; i++) if (board[i][j] != '.') array[board[i][j] - '0' - 1]++;
		for (int i = 0; i < boardColSize; i++) if (array[i] > 1) return false;
		memset(array, 0, sizeof(array));
	}
	return true;
}

bool isValidArr(char** board, int boardRowSize, int boardColSize)
{
	int array[9]; memset(array, 0, sizeof(array));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int m = 0; m < 3; m++)
				{
					if (board[i * 3 + k][j * 3 + m] != '.') array[board[i * 3 + k][j * 3 + m] - '0' - 1]++;
				}
			}
			for (int n = 0; n < boardRowSize; n++) if (array[n] > 1) return false;
			memset(array, 0, sizeof(array));
		}
	}
	return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
	return isValidCol(board, boardRowSize, boardColSize) && isValidRow(board, boardRowSize, boardColSize) && isValidArr(board, boardRowSize, boardColSize);
}

int main()
{
	char example[9][9] = {
						 {'5','3','.','.','7','.','.','.','.'},
						 {'6','.','.','1','9','5','.','.','.'},
						 {'.','9','8','.','.','.','.','6','.'},
						 {'8','.','.','.','6','.','.','.','3'},
						 {'4','.','.','8','.','3','.','.','1'},
						 {'7','.','.','.','2','.','.','.','6'},
						 {'.','6','.','.','.','.','2','8','.'},
						 {'.','.','.','4','1','9','.','.','5'},
						 {'.','.','.','.','8','.','.','7','9'}
	                     };
	char **board = (char**)malloc(sizeof(char*) * 9);
	char *board0 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board0[i] = example[0][i]; board[0] = board0;
	char *board1 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board1[i] = example[1][i]; board[1] = board1;
	char *board2 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board2[i] = example[2][i]; board[2] = board2;
	char *board3 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board3[i] = example[3][i]; board[3] = board3;
	char *board4 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board4[i] = example[4][i]; board[4] = board4;
	char *board5 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board5[i] = example[5][i]; board[5] = board5;
	char *board6 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board6[i] = example[6][i]; board[6] = board6;
	char *board7 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board7[i] = example[7][i]; board[7] = board7;
	char *board8 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board8[i] = example[8][i]; board[8] = board8;
	char *board9 = (char*)malloc(sizeof(char) * 9); for (int i = 0; i < 9; i++) board9[i] = example[9][i]; board[9] = board9;
	bool result = isValidSudoku(board, 9, 9);
	printf("the result is %d", result);
	for (int i = 0; i < 9; i++) free(board[i]);
	return 0;
	
}