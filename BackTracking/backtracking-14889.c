#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int N;
int S[21][21];
int visit[21] = { 0 };
int team[21];
int team2[21];
int sum = 0;
int sum2 = 0;
int total = 0;
int MIN = 10000000;
int temp;

void DFS(int depth, int start) {
	sum = 0;
	sum2 = 0;
	int state;
	int k = 0;
	if (depth == N/2) {
		for (int i = 0; i < N; i++) {
			state = 0;
			for (int j = 0; j < N / 2; j++) {
				if (i == team[j]) {
					state = 1;
				}
			}
			if (state == 0) {
				team2[k] = i;
				k++;
				state = 0;
			}
		}
		int k = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i != j) {
					sum += S[team[i]][team[j]];
				}
				if (i != j) {
					sum2 += S[team2[i]][team2[j]];
				}
			}
		}
		if (MIN > abs(sum - sum2)) {
			MIN = abs(sum - sum2);
		}
		temp = 0;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == 1||team[depth-1]>i) {
			continue;
		}
		else {
			visit[i] = 1;
			team[depth] = i;
			temp = team[depth];
			DFS(depth + 1, start);
			visit[i] = 0;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);
		}
	}
	DFS(0,0);
	printf("%d", MIN);
	return 0;
}
