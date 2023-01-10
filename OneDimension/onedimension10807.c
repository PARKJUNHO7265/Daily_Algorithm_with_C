#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[101];
int num;
int count = 0;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &num);
	for (int i = 0; i < N; i++) {
		if (arr[i] == num) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
