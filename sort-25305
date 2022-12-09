#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int K;
int score[10001];
int temp;
void Input() {
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
	}
}
int main() {
	Input();
	for (int i = 0; i < K; i++) {
		for (int j = i + 1; j < N; j++) {
			if (score[i] < score[j]) {
				temp = score[j];
				score[j] = score[i];
				score[i] = temp;
			}
		}
	}
	printf("%d", score[K - 1]);
	return 0;
}
