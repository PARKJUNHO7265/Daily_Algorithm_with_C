#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int N;
int num[20];
int oper[4];
int result = 0;
int MAX = -100000000000;
int MIN = 100000000000;

void DFS(int plus, int minus, int multi, int divide, int depth, int result) {
	if (depth == N - 1) {
		if (MAX < result) {
			MAX = result;
		}
		if (MIN > result) {
			MIN = result;
		}
	}
	if (plus > 0) {
		DFS(plus - 1, minus, multi, divide, depth + 1, result + num[depth + 1]);
	}
	if (minus > 0) {
		DFS(plus, minus - 1, multi, divide, depth + 1, result - num[depth + 1]);
	}
	if (multi > 0) {
		DFS(plus, minus, multi - 1, divide, depth + 1, result * num[depth + 1]);
	}
	if (divide > 0) {
		DFS(plus, minus, multi, divide - 1, depth + 1, result / num[depth + 1]);
	}
}



int main() {
	int count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	DFS(oper[0], oper[1], oper[2], oper[3], 0, result);
	printf("%d\n", MAX);
	printf("%d\n", MIN);
	return 0;
}
