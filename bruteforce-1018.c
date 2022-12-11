#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int M;
int min_B = 10000;
int min_W = 10000;
char arr[60][60];
void Input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}
}
void solution() {
	for (int a = 0; a <= N - 8; a++) {
		for (int b = 0; b <= M - 8; b++) {
			int zero_B = 0;
			int zero_W = 0;
			int sum = 0;
			for (int i = a; i < a + 8; i++) {
				for (int j = b; j < b + 8; j++) {
					if ((i + j) % 2 == 0) {
						if (arr[i][j] == 'B') {
							zero_B++;
						}
						else {
							zero_W++;
						}
					}
					else {
						if (arr[i][j] == 'W') {
							zero_B++;
						}
						else {
							zero_W++;
						}
					}
				}
			}
			if (min_B > zero_B) {
				min_B = zero_B;
			}
			if (min_W > zero_W) {
				min_W = zero_W;
			}
		}
	}
	if (min_B > min_W) {
		printf("%d", min_W);
	}
	else printf("%d", min_B);
}
int main() {
	Input();
	solution();
	return 0;
}
