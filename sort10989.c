#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[10001] = { 0, };
int num;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 0) continue;
		for (int j = 1; j <= arr[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}
