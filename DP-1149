#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int cost[1001][3];
int temp[1001][3];
int sum = 0;
int min = 100000000;
int compare(int a, int b) {
	return (a >= b) ? b : a;
}
void sol() {
	for (int i = 0; i < N; i++) {
		temp[i][0] = compare(temp[i - 1][1], temp[i - 1][2]) + cost[i][0];
		temp[i][1] = compare(temp[i - 1][0], temp[i - 1][2]) + cost[i][1];
		temp[i][2] = compare(temp[i - 1][0], temp[i - 1][1]) + cost[i][2];
	}
	for (int i = 0; i < 3; i++) {
		if (min > temp[N - 1][i]) {
			min = temp[N - 1][i];
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	temp[0][0] = cost[0][0];
	temp[0][1] = cost[0][1];
	temp[0][2] = cost[0][2];
	sol();
	printf("%d", min);
}
