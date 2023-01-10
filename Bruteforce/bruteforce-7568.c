#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[100][3];
void Input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
}
void solution() {
	for (int i = 0; i < N; i++) {
		arr[i][2] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
				arr[i][2] += 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i][2]);
	}
}
int main() {
	Input();
	solution();
	return 0;
}
