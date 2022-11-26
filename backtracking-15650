#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
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
			if (i <= arr[depth - 1]) {
				continue;
			}
			else {
				arr[depth] = i;
				DFS(depth + 1); //깊이 우선 탐색
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	DFS(0);
	return 0;
}
