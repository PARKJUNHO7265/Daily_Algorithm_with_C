#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, T;
int arr[11];
int main() {
	scanf("%d", &T);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d\n", arr[N]);
	}
	return 0;
}
