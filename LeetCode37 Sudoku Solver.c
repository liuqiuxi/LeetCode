#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *getValidNum(char **board, int Row, int Col)
{
	int *map = (int*)malloc(sizeof(int) * 9); memset(map, 0, sizeof(int) * 9);
	for (int i = 0; i < 9; i++) if (board[Row][i] != '.') map[board[Row][i] - '0' - 1] = 1;
	for (int j = 0; j < 9; j++) if (board[j][Col] != '.') map[board[j][Col] - '0' - 1] = 1;
	for (int i = 3 * (Row / 3); i < 3 * (Row / 3 + 1); i++) for (int j = 3 * (Col / 3); j < 3 * (Col / 3 + 1); j++) if (board[i][j] != '.') map[board[i][j] - '0' - 1] = 1;
	return map;
}

bool SudoKu(char **board, int Row, int Col)
{
	if (Row == 8 && Col == 9) return true;
	if (Col == 9)
	{
		Row++;
		Col = 0;
	}
	if (board[Row][Col] != '.'){
		if (SudoKu(board, Row, Col + 1)) return true;
	}else {
		int *map = getValidNum(board, Row, Col);
		for (int i = 1; i < 10; i++)
		{
			if (map[i - 1] == 0)
			{
				board[Row][Col] = i + '0';
				if (SudoKu(board, Row, Col + 1)) return true;
				board[Row][Col] = '.';
			}
		}
		free(map);
	}
	return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize)
{
	SudoKu(board, 0, 0);
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
	solveSudoku(board, 9, 9);
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			printf("%c ", board[row][col]);
		}
		free(board[row]);
		printf("\n");
	}
	return 0;
}