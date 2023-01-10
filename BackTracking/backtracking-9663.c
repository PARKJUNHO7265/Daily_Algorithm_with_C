#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int N;
int board[20];
int count = 0;

void DFS(int depth) {
	if (depth == N) {
		count++;
		return;
	}
	else {
		int count = 0;
		for (int i = 0; i < N; i++) {
			int attackable = 0;
			for (int j = 0; j < depth; j++) {
				int column = board[j]; //좌표 (j,column)
				if (column == i || abs(depth - j) == abs(i - column)) {
					attackable = 1;
					break;
				}
			}
			if (!attackable) {
				board[depth] = i;
				DFS(depth + 1);
			}
		
		}
	}
}

int main() {
	scanf("%d", &N);
	DFS(0);
	printf("%d", count);
	return 0;
}
