#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[10001];
int X;
int main() {
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] < X) {
			printf("%d ", arr[i]);
		}
	}
	return 0;
}
