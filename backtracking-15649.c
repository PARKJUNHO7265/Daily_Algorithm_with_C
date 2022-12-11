#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int visit[10] = { 0 };
int arr[10] = { 0 };
void DFS(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 1) {
				continue;
			}
			else {
				visit[i] = 1;
				arr[depth] = i;
				DFS(depth + 1); //깊이 우선 탐색
				visit[i] = 0;
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	DFS(0);
	return 0;
}
